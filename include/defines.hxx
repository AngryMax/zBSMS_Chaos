#include <BetterSMS/memory.hxx>
#include <Dolphin/string.h>
#include <SMS/rand.h>

const static int CODE_NAME_BUFFER_SIZE = 30;
const static int CODE_COUNT            = 10;

static float currentTime = 0.0;  // unit = seconds

class Code  // we might want to add a member for display name
{    

public:
    char name[CODE_NAME_BUFFER_SIZE];
    bool isActive;
    bool isGraced;
    int rarity;
    float duration;
    float timeCalled;
    bool fIsResettable;
    
    enum FuncReset { NO_RESET, TRUE, FALSE };
    void (*pFunc)(FuncReset);

    Code() {
    }

	Code(const char *n, int r, float d, bool fr, void (*pf)(FuncReset)=nullptr) { 

        strncpy(name, n, CODE_NAME_BUFFER_SIZE);
        isActive			= false;
        isGraced            = false;
        rarity              = r;
        duration            = d;
        timeCalled          = 0;
        fIsResettable       = fr;
        pFunc               = pf;
	}
};

class CodeContainer {
public:
    Code codeList[CODE_COUNT];

    float gracePeriod;
    int maxActiveCodes;
    int activeCodes;

    CodeContainer() {
        activeCodes     = 0; 
        maxActiveCodes  = 4;
        gracePeriod     = 7;
    }

    bool addCode(Code c) {
        if (currentCodeListIndex < CODE_COUNT) {
            codeList[currentCodeListIndex] = c;
            currentCodeListIndex++;
            return true;
        } else
            return false;
    }

    void activateCodes() {
        if (activeCodes < maxActiveCodes) {
            int rollWinner = getWeightedRand();

            codeList[rollWinner].isActive = true;
            codeList[rollWinner].timeCalled = currentTime;
            activeCodes++;
        }
    }

    void iterateThroughCodes() {
        for (auto c : codeList) {
            if (c.isActive && c.pFunc != nullptr) {
                c.pFunc(c.fIsResettable ? Code::FuncReset::FALSE : Code::FuncReset::NO_RESET);
            }
        }
    }

    void checkCodeTimers() {
        for (auto c : codeList) {
            float elapsedTime = currentTime - c.timeCalled;
            if (c.isActive && c.duration <= elapsedTime) {
                if (c.pFunc != nullptr)
                    c.pFunc(Code::FuncReset::TRUE);

                c.isActive = false;
                c.isGraced = true;
            } else if (c.isGraced && c.duration - elapsedTime <= -gracePeriod) {
                activeCodes--;
                c.isGraced = false;
            }
        }
    }

private:
    int currentCodeListIndex = 0;

	int getRand() { return (rand() % CODE_COUNT); }

	int getWeightedRand() {

        int roll;

        while (true) {

            roll = getRand();

            //if (codeList[60].isActive == true)  // if reverseRarities is active, low rarity values are now valued over higher ones for getting rolled
            //{
                if (codeList[roll].rarity < rand() % 101)
                    return roll;
            //}
                else if (codeList[roll].rarity > rand() % 101)
					return roll;
        }
	}
};

CodeContainer codeContainer;