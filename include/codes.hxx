#include <Dolphin/MTX.h>
#include <Dolphin/types.h>

#include <Dolphin/CARD.h>
#include <Dolphin/OS.h>
#include <Dolphin/math.h>
#include <Dolphin/string.h>
#include <Dolphin/types.h>

#include <SMS/System/Application.hxx>
#include <SMS/macros.h>
#include <SMS/Player/Mario.hxx>
#include <SMS/raw_fn.hxx>
#include <SMS/rand.h>
#include <SMS/MSound/MSBGM.hxx>
#include <SMS/Manager/FlagManager.hxx>
#include <SMS/Manager/ModelWaterManager.hxx>
#include <SMS/MSound/MSoundSESystem.hxx>
#include <SMS/MSound/MSModBgm.hxx>
#include <SMS/MSound/MSound.hxx>

#include <BetterSMS/game.hxx>
#include <BetterSMS/module.hxx>
#include <BetterSMS/settings.hxx>
#include <BetterSMS/stage.hxx>
#include <BetterSMS/memory.hxx>

#include <Kuribo/sdk/kuribo_sdk.h>

const static int CODE_NAME_BUFFER_SIZE = 30;
const static int CODE_COUNT            = 30;

static float currentTime = 0.0;  // unit = seconds

// instructions
#define NOP 0x60000000
#define BLR 0x4e800020

class Code  // we might want to add a member for display name
{    

public:
    u8 codeID;                          // unique code id
    char name[CODE_NAME_BUFFER_SIZE];   // unique code display name
    bool isActive;                      // whether the code is active
    bool isGraced;                      // whether the code is in grace period
    u32 rarity;                         // rarity of code 1-100 (1 = rarest, 100 = most common)
    float duration;                     // code duration in seconds
    float timeCalled;                   // var used to store when a code is activated
    bool fIsResettable;                 // whether or not a code needs to be reset at the end of its duration
    
    enum FuncReset { NO_RESET, TRUE, FALSE };
    void (*pFunc)(FuncReset);

    Code() {
    }

	Code(u8 c, const char *n, u32 r, float d, bool fr, void (*pf)(FuncReset)=nullptr) { 

        codeID = c;
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
    u32 maxActiveCodes;
    u32 baseMaxActiveCodes;
    u32 activeCodes;

    CodeContainer() {
        activeCodes     = 0; 
        maxActiveCodes  = 4;
        baseMaxActiveCodes = maxActiveCodes;
        gracePeriod     = 7;
    }

    bool addCode(Code c) {
        if (currentCodeCount < CODE_COUNT) {
            codeList[currentCodeCount] = c;
            currentCodeCount++;
            return true;
        } else
            return false;
    }

    // checks if code with specified id is active
    bool isCodeActive(u8 id) {
        for (Code c : codeList) {
            if (c.codeID == id && c.isActive == true)
                return true;
        }
        
        return false;
    }

    bool getCodeFromName(const char name[30], Code output) {
        for (Code &c : codeList) {
            if (strcmp(c.name, name) == 0) {
                output = c;

                return true;
            }
        }

        return false;
    }

    void activateCodes() {
        while (activeCodes < maxActiveCodes && activeCodes < currentCodeCount) {
            int rollWinner = getWeightedRand();
            
            if (codeList[rollWinner].isActive || codeList[rollWinner].isGraced) {
                continue;
            }
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
        for (auto &c : codeList) {
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
    int currentCodeCount = 0;

	int getRand() { return (rand() % currentCodeCount); }

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

// all specific code functions
public:
    static void pauseWater(Code::FuncReset);        
    static void dummyThiccMario(Code::FuncReset);   
    static void noMarioRedraw(Code::FuncReset);
    static void whiteMarioSilhouette(Code::FuncReset);
    static void noMActorModels(Code::FuncReset);
    static void moveTLiveActorDraw(Code::FuncReset);
    static void stopControlInputs(Code::FuncReset);
    static void spamSprayCentral(Code::FuncReset);
    static void addCodeSlot(Code::FuncReset);
    static void smallJumps(Code::FuncReset);
    static void lockJumpDirection(Code::FuncReset);
    static void sadFLUDD(Code::FuncReset);
    static void landMovementLock(Code::FuncReset);
    static void forceTurbo(Code::FuncReset);
    static void setMusicVol(Code::FuncReset);       
    static void SPEEN(Code::FuncReset);
    static void changeNozzleRandom(Code::FuncReset);       
    static void giveCoins(Code::FuncReset);
    static void spawnYoshi(Code::FuncReset);
    static void sunglassesAndShineShirt(Code::FuncReset);
    static void speedUpTempo(Code::FuncReset);
    static void tpMarioBack(Code::FuncReset);
    static void hpRoulette(Code::FuncReset);
    static void luigiSlide(Code::FuncReset);
    static void wrongFramerateNPC(Code::FuncReset);
    static void ascend(Code::FuncReset);
    static void doubleTime(Code::FuncReset);
    static void messUpTextures(Code::FuncReset);
};

namespace Utils {

    // plays the sound of soundId as long as the gate is open
    static bool playSound(u32 soundId) {
        if (gpMSound->gateCheck(0)) {
            MSoundSESystem::MSoundSE::startSoundSystemSE(soundId, 0, 0, 0);
            return true;
        } else
            return false;
    }
}

// Single instance of CodeContainer that's accessed throughout whole project
extern CodeContainer codeContainer;