#include <Dolphin/MTX.h>
#include <Dolphin/types.h>

#include <Dolphin/CARD.h>
#include <Dolphin/OS.h>
#include <Dolphin/math.h>
#include <Dolphin/string.h>
#include <Dolphin/types.h>
#include <Dolphin/MTX.h>
#include <Dolphin/PAD.h>

#include <JSystem/JDrama/JDRRect.hxx>
#include <JSystem/J3D/J3DTransform.hxx>

#include <SMS/System/Application.hxx>
#include <SMS/macros.h>
#include <SMS/Player/Mario.hxx>
#include <SMS/Player/MarioGamePad.hxx>
#include <SMS/Player/Watergun.hxx>
#include <SMS/raw_fn.hxx>
#include <SMS/rand.h>
#include <SMS/MSound/MSBGM.hxx>
#include <SMS/Manager/FlagManager.hxx>
#include <SMS/Manager/ModelWaterManager.hxx>
#include <SMS/MSound/MSoundSESystem.hxx>
#include <SMS/MSound/MSModBgm.hxx>
#include <SMS/MSound/MSound.hxx>
#include <SMS/Enemy/Conductor.hxx>
#include <SMS/MoveBG/Shine.hxx>
#include <SMS/GC2D/CardSave.hxx>
#include <SMS/GC2D/SunGlass.hxx>
#include <SMS/GC2D/SMSFader.hxx>
#include <SMS/Camera/CameraShake.hxx>
#include <SMS/Camera/PolarSubCamera.hxx>
#include <SMS/NPC/NpcBase.hxx>
#include <SMS/MapObj/MapObjBase.hxx>
#include <SMS/MarioUtil/MathUtil.hxx>
#include <SMS/Manager/MarioParticleManager.hxx>
#include <SMS/MarioUtil/LightUtil.hxx>
#include <SMS/MarioUtil/DrawUtil.hxx>
#include <SMS/Manager/ModelWaterManager.hxx>
#include <SMS/Manager/ItemManager.hxx>
#include <SMS/Manager/MarioParticleManager.hxx>

#include <BetterSMS/game.hxx>
#include <BetterSMS/module.hxx>
#include <BetterSMS/settings.hxx>
#include <BetterSMS/stage.hxx>
#include <BetterSMS/memory.hxx>
//#include <BetterSMS/debug/p_debug.hxx>

#include <Kuribo/sdk/kuribo_sdk.h>

const static int CODE_NAME_BUFFER_SIZE = 30;
const static int CODE_COUNT            = 100;

extern float currentTime;  // unit = seconds

#define NORMAL_BUF 144
#define MAX_BUF 410 // the string buffer is this large for smsWiki

// instructions
#define NOP 0x60000000
#define BLR 0x4e800020

// colors
#define RED {0xff, 0, 0, 0xff}
#define GRAY {0x77, 0x77, 0x77, 0xff}
#define GRAY_TRANSP {0x77, 0x77, 0x77, 0x88}
#define PURPLE {0xff, 0x00, 0xff, 0xff}
#define GREEN {0, 0xff, 0, 0xff}
#define GREEN_TOP {0, 0xff, 0, 0xff}
#define GREEN_BOTTOM {100, 0xff, 100, 0xff}
#define BLACK {0, 0, 0, 0xff}
#define BLACK_TRANSP {0, 0, 0, 0x88}
#define WHITE {0xff, 0xff, 0xff, 0xff}
#define ORANGE {0xff, 0x77, 0x00, 0xff}

// code ids
#define PAUSE_WATER             0
#define DUMMY_THICC_MARIO       1
#define NO_MARIO_REDRAW         2
#define HOLD_CAP				3
#define NO_MACTOR_MODELS        4
#define STOP_TLIVEACTOR_PERFORM 5
#define STOP_CONTROL_INPUTS     6
#define SPAM_SPRAY_CENTRAL      7
#define ROLL_EXTRA_CODE          8
#define SMALL_JUMPS             9
#define CLUMSY_JUMPS            10
#define PATHETIC_FLUDD          11
#define LAND_MOVEMENT_LOCK      12
#define UNLIMITED_TURBO         13
#define CRESCENDO               14
#define SPEEN_ID                15
#define NOZZLE_ROLL             16
#define GIVE_COINS              17
#define SPAWN_YOSHI             18
#define SUN_DRIP                19
#define SPEED_UP_TEMPO          20
#define TP_MARIO_BACK           21
#define HP_ROULETTE             22
#define LUIGI_SLIDE             23
#define FIREBALL                24
#define ASCEND                  25
#define DOUBLE_TIME             26
#define SCRAMBLE_TEXTURES       27
#define CHANGE_LIVES            28
#define HELPFUL_INPUT_DISPLAY   29
#define REVERSE_INPUTS          30
#define SIMON_SAYS              31
#define DOOR_STUCK              32
#define GIANT_MARIO             33
#define SNAKE                   34
#define MOON_GRAVITY            35
#define CRAZY_GRAVITY           36
#define CHAOS_CODE              37
#define DISABLE_WATER_COL       38
#define	SHUFFLE_OBJECTS			39
#define CRAZY_COLLISION			40
#define INV_WATER_MOMENTUM		41
#define MOVE_SHINES		        42
#define PAINT_RANDOM_COLLISION	43
#define TANK_CONTROLS			44
#define WEIRD_CAMERA			45
#define OBJECT_VORTEX           46
#define DOUBLE_PERSPECTIVE		47
#define STREEEEETCH				48
#define SMS_WIKI				49
#define KEEP_ACCELERATING		50
#define ICE_PHYSICS				51
#define CHANGE_WALLS			52
#define MAKE_MARIO_OBJ			53
#define POPUP_SAVE_PROMPT		54
#define PING_LAG				55
#define HALVE_ROLL_TIME			56
#define EARTHQUAKE				57
#define SOMETIMES_DOUBLE_COINS  58
#define REVERSE_RARITIES	    59
#define CHANGE_SCREEN_COLOR	    60
#define UPSIDEDOWN_CAM		    61
#define JOYCON_DRIFT		    62
#define SINE_MOMENTUM		    63
#define WINDY_DAY			    64
#define BRAWL					65
#define NOCLIP					66
#define JUMPSCARE				67
#define SMALL_WORLD				68
#define RANDOM_SPRAY		    69
#define PLAY_SOUNDS				70
#define PICK_UP_OBJ				71
#define ROTATE_OBJS				72
#define QUAKE_PRO				73
#define ROLLIN					74
#define SHRINK_RAY				75
#define CS_PLAYERS				76
#define INVERT_MARIO			77
#define FIRE_MOVEMENT			78
#define LOL						79
#define TILTED					80
#define POPUP_UX				81
#define SUPERPOSITION			82
#define WIDE_MARIO				83
#define SIGHTSEER				84
#define STAR_POWER				85
#define TRIPPY_TEXTURES			86
#define IMA_TIRED				87
#define FREEZE_ANIMS			88
#define FAST_N_FURIOUS			89
#define DIVING_MODE				90
#define PAUSE_TIMERS			91
#define CHANGE_MUSIC			92
#define OFFSET_MARIO			93
#define REVERSE_MARIO			94
#define FAKE_DEATH				95
#define TINY_MARIO				96
#define SELFIE_STICK			97
#define RAINBOW_WATER			98
#define OUT_OF_BODY				99

#define NO_WHITELIST		   255		// used to stay in DEV_MODE w/o a whitelist

class Code  // we might want to add a member for display name
{    

public:
    u8 codeID;                              // unique code id
    char name[CODE_NAME_BUFFER_SIZE];       // unique code display name
    bool isActive;                          // whether the code is active
    u8 rarity;                              // rarity of code 1-100 (1 = rarest, 100 = most common)
    float duration;                         // code duration in seconds
    float timeCalled;                       // var used to store when a code is activated
    
    enum FuncReset { FALSE, TRUE };
    void (*pFunc)(FuncReset);

    Code() {
    }

	Code(u8 c, const char *n, u8 r, float d, void (*pf)(FuncReset)=nullptr) { 

        codeID = c;
        strncpy(name, n, CODE_NAME_BUFFER_SIZE);
        isActive			= false;
        rarity              = r;
        duration            = d;
        timeCalled          = 0;
        pFunc               = pf;
	}
};

class CodeContainer {
public:
    int currentCodeCount = 0;
    Code codeList[CODE_COUNT];
		
    float rollTime;			
    float baseRollTime;
    float lastRollTime;

    J2DTextBox *codeDisplay;

    CodeContainer() {
        rollTime           = 8;
        baseRollTime = rollTime;
        lastRollTime       = -rollTime;
        codeDisplay = nullptr;
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

    void endCode(u8 id) {
        for (Code &c: codeList) {
            if (c.codeID == id && c.isActive == true) {
                c.timeCalled = currentTime - c.duration;
            }
        }
    }

    void resetCode(u8 id) {
        Code code;
        if (!(getCodeFromID(id, code))) {
            OSReport("[resetCode] -> Could not find code with code id %d!\n",
                     id);
            return;
        }
        code.pFunc(Code::FuncReset::TRUE);
    }

    // returns reference to code with code id in cout
    bool getCodeFromID(u8 id, Code &cout) {
        for (Code &c : codeList) {
            if (c.codeID == id) {
                cout = c;
                return true;
            }    
        }
        return false;
    }

    bool activateCode() {
        int rollWinner = getWeightedRand();

        if (codeList[rollWinner].isActive)
            return false;

        if (isConflictingCodeActive(codeList[rollWinner].codeID))
            return false;

        codeList[rollWinner].isActive   = true;
        codeList[rollWinner].timeCalled = currentTime;
        return true;
    }

	bool optionSZSActivateCode() {
        int rollWinner = getWeightedRand();

        if (codeList[rollWinner].isActive)
            return false;

        if (isConflictingCodeActive(codeList[rollWinner].codeID))
            return false;

		if (!isOptionSZSCode(codeList[rollWinner].codeID))
            return false;

        codeList[rollWinner].isActive   = true;
        codeList[rollWinner].timeCalled = currentTime;
        return true;
    }

    void iterateThroughCodes() {
        for (auto c : codeList) {
            if (c.isActive && c.pFunc != nullptr) {
                c.pFunc(Code::FuncReset::FALSE);
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
            }
        }
    }

	bool isConflictingCodeActive(int codeID) {
        switch (codeID) {

            case NO_MARIO_REDRAW:
                if (isCodeActive(CHAOS_CODE) || isCodeActive(TILTED))
                    return true;
                break;

            case SCRAMBLE_TEXTURES:
                if (isCodeActive(SIMON_SAYS) || isCodeActive(SNAKE) || isCodeActive(FAST_N_FURIOUS))
                    return true;
                if (isCodeActive(CHAOS_CODE) && rand() % 100 != 0)
                    return true;
                break;

            case SIMON_SAYS:
                if (isCodeActive(SCRAMBLE_TEXTURES) || isCodeActive(CHAOS_CODE))
                    return true;
                break;

            case SNAKE:
                if (isCodeActive(CHAOS_CODE) || isCodeActive(SCRAMBLE_TEXTURES))
                    return true;
                break;

            case MOON_GRAVITY:
                if (isCodeActive(CRAZY_GRAVITY))
                    return true;
                break;

            case CRAZY_GRAVITY:
                if (isCodeActive(MOON_GRAVITY))
                    return true;
                if (isCodeActive(FIRE_MOVEMENT) && rand() % 10 != 0)
                    return true;
                break;

            case UPSIDEDOWN_CAM:
                if (isCodeActive(QUAKE_PRO) || isCodeActive(CS_PLAYERS))
                    return true;
                break;

            case QUAKE_PRO:
                if (isCodeActive(UPSIDEDOWN_CAM) || isCodeActive(CS_PLAYERS))
                    return true;
                break;

            case CS_PLAYERS:
                if (isCodeActive(QUAKE_PRO) || isCodeActive(UPSIDEDOWN_CAM))
                    return true;
                break;

            case ASCEND:
                if (isCodeActive(FIRE_MOVEMENT) && rand() % 10 != 0)
                    return true;
                break;

            case FIRE_MOVEMENT:
                if (isCodeActive(ASCEND) && rand() % 10 != 0)
                    return true;
                if (isCodeActive(CRAZY_GRAVITY) && rand() % 10 != 0)
                    return true;
                break;

            case POPUP_SAVE_PROMPT:
                if (isCodeActive(CHAOS_CODE))
                    return true;
                break;

            case TILTED:
                if (isCodeActive(NO_MARIO_REDRAW))
                    return true;
                break;

            case GIANT_MARIO:
                if (isCodeActive(WIDE_MARIO) || isCodeActive(TINY_MARIO))
                    return true;
                break;

            case WIDE_MARIO:
                if (isCodeActive(GIANT_MARIO))
                    return true;
                break;

            case SIGHTSEER:
                if (isCodeActive(PING_LAG))
                    return true;
                break;

            case WINDY_DAY:
                if (isCodeActive(FAST_N_FURIOUS))
                    return true;
                break;

            case TANK_CONTROLS:
                if (isCodeActive(FAST_N_FURIOUS) && rand() % 10 != 0)
                    return true;
                break;

            case FAST_N_FURIOUS:
                if ((isCodeActive(TANK_CONTROLS) && rand() % 10 != 0) || isCodeActive(CHAOS_CODE) ||
                    isCodeActive(SCRAMBLE_TEXTURES) || isCodeActive(WINDY_DAY))
                    return true;
                break;

            case OFFSET_MARIO:
                if (isCodeActive(REVERSE_MARIO))
                    return true;
                break;

            case REVERSE_MARIO:
                if (isCodeActive(OFFSET_MARIO))
                    return true;
                break;

            case TINY_MARIO:
                if (isCodeActive(GIANT_MARIO) || isCodeActive(WIDE_MARIO))
                    return true;
                break;

			case FAKE_DEATH:
                if (isCodeActive(CHAOS_CODE) || isCodeActive(PAUSE_TIMERS))
                    return true;
                break;

			case HALVE_ROLL_TIME:
                if (isCodeActive(CHAOS_CODE))
                    return true;
                break;

			case PAUSE_TIMERS:
                if (isCodeActive(CHAOS_CODE) || isCodeActive(FAKE_DEATH))
                    return true;
                break;

			case DOUBLE_PERSPECTIVE:
                if (isCodeActive(CHAOS_CODE))
                    return true;
                break;
        }

		return false;
	}

	bool isOptionSZSCode(int codeID) {

		switch (codeID) {
            case PAUSE_WATER:
            case SPAM_SPRAY_CENTRAL:
            case PATHETIC_FLUDD:
            case SPEEN_ID:
            case HP_ROULETTE:
            case SIMON_SAYS:
            case SNAKE:
            case CHAOS_CODE:
            case DISABLE_WATER_COL:
            case CRAZY_COLLISION:
            case INV_WATER_MOMENTUM:
            case MOVE_SHINES:
            case TANK_CONTROLS:
            case PAINT_RANDOM_COLLISION:
            case SOMETIMES_DOUBLE_COINS:
            case NOCLIP:
            case JUMPSCARE:
            case RANDOM_SPRAY:
            case SHRINK_RAY:
            case LOL:
            case FAST_N_FURIOUS:
			case DIVING_MODE:
                return false;
		}

		return true;
	}

private:
	int getRand() { return (rand() % currentCodeCount); }

	int getWeightedRand() {
        int roll;

        while (true) {

            roll = getRand();

            if (isCodeActive(REVERSE_RARITIES)) {
                if (codeList[roll].rarity < rand() % 101)
                    return roll;
            } else {
                if (codeList[roll].rarity > rand() % 101)
                    return roll;
            }
            
        }
	}

// all specific code functions
public:
    static void pauseWater(Code::FuncReset);        
    static void dummyThiccMario(Code::FuncReset);   
    static void noMarioRedraw(Code::FuncReset);
    static void holdCapToggle(Code::FuncReset);	 // this function is split into 2
    static void holdCap();
    static void noMActorModels(Code::FuncReset);
    static void stopTLiveActorPerform(Code::FuncReset);
    static void stopControlInputs(Code::FuncReset);
    static void spamSprayCentral(Code::FuncReset);
    static void rollExtraCode(Code::FuncReset);
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
    static void emitFireball(Code::FuncReset);
    static void ascend(Code::FuncReset);
    static void doubleTime(Code::FuncReset);
    static void messUpTextures(Code::FuncReset);
    static void changeLives(Code::FuncReset);
    static void helpfulInputDisplay(Code::FuncReset);
    static void reverseInputsToggle(Code::FuncReset);
    static void reverseInputs();
    static void simonSays(Code::FuncReset);
    static void lockMarioAnim(Code::FuncReset);
    static void giantMario(Code::FuncReset);
    static void snakeGame(Code::FuncReset);
    static void moonGravity(Code::FuncReset);
    static void crazyGravity(Code::FuncReset);
    static void chaosCode(Code::FuncReset);
    static void disableWaterCol(Code::FuncReset);
    static void shuffleObjects(Code::FuncReset);
    static void crazyCollision(Code::FuncReset);    
    static void invertWaterToggle(Code::FuncReset);
    static void invertWaterMomentum(TWaterGun *, int, TVec3f *, TVec3f *, TVec3f *); // this function is split into 2
    static void moveShines(Code::FuncReset );
    static void paintRandomCollision(Code::FuncReset);
    static void tankControls(Code::FuncReset);
    static void weirdCamera(Code::FuncReset);
    static void objectVortex(Code::FuncReset);
    static void doublePerspective(Code::FuncReset);
    static void streeeeetch(Code::FuncReset);
    static void smsWiki(Code::FuncReset);
    static void keepAccelerating(Code::FuncReset);
    static void icePhysics(Code::FuncReset);
    static void changeWalls(Code::FuncReset);
    static void makeMarioAnObject(Code::FuncReset);
    static void popupSavePrompt(Code::FuncReset);
    static void pingLag(Code::FuncReset);
    static void halveRollTime(Code::FuncReset);
    static void earthquake(Code::FuncReset);
    static void sometimesDoubleCoins(Code::FuncReset);
    static void reverseRarities(Code::FuncReset);
    static void changeScreenColorToggle(Code::FuncReset);
    static void changeScreenColor(TSunGlass *, JDrama::TRect &, JUtility::TColor);
    static void upsideDownCamToggle(Code::FuncReset);
    static void upsideDownCam();
    static void joyconDrift(Code::FuncReset);
    static void sineMomentum(Code::FuncReset);
    static void windyDay(Code::FuncReset);
    static void brawl(Code::FuncReset);
    static void noclip(Code::FuncReset);
    static void jumpscare(Code::FuncReset);
    static void smallWorld(Code::FuncReset);
    static void randomSpray(Code::FuncReset);
    static void playAllSounds(Code::FuncReset);
    static void pickUpObj(Code::FuncReset);
    static void rotateObjs(Code::FuncReset);
    static void quakeProToggle(Code::FuncReset);
    static void quakePro();	  // this function is split into 2
    static void rollin(Code::FuncReset);
    static void shrinkRay(Code::FuncReset);
    static void csPlayers(Code::FuncReset);
    static void invertMario(Code::FuncReset);
    static void fireMovement(Code::FuncReset);
    static void lol(Code::FuncReset);
    static void tilted(Code::FuncReset);
    static void popUpUX(Code::FuncReset);
    static void superposition(Code::FuncReset);
    static void wideMario(Code::FuncReset);
    static void sightseer(Code::FuncReset);
    static void starPowerToggle(Code::FuncReset);
    static void starPower();
    static void trippyTextures(Code::FuncReset);
    static void imaTired(Code::FuncReset);
    static void freezeAnims(Code::FuncReset);
    static void fastNFurious(Code::FuncReset);
    static void divingMode(Code::FuncReset);
    static void pauseTimers(Code::FuncReset);
    static void changeMusic(Code::FuncReset);
    static void offsetMarioToggle(Code::FuncReset);
    static void offsetMario(J3DTransformInfo &, Mtx);
    static void fakeDeath(Code::FuncReset);
    static void reverseMarioToggle(Code::FuncReset);
    static void reverseMario(J3DTransformInfo &, Mtx);
    static void tinyMario(Code::FuncReset);
    static void selfieStick(Code::FuncReset);
    static void rainbowWater(Code::FuncReset);
    static void outOfBody(Code::FuncReset);
    static void outOfBodyViewCheck();
};

// Single instance of CodeContainer that's accessed throughout whole project
extern CodeContainer codeContainer;

// this struct is found and used by the python script to read active codes
struct ChaosPtrs{
    const char *uniqueStr = "CHAOS 1.0";
    const CodeContainer *codeContainerPtr = &codeContainer;
    const float *currentTimePtr = &currentTime;
};
static ChaosPtrs chaosPtrs;

namespace Utils {

    static void printChaosPtrAddr() {
        OSReport("chaosPtrs: 0x%x\n", &chaosPtrs);
    }

    // plays the sound of soundId as long as the gate is open
    static bool playSound(u32 soundId) {
        if (gpMSound->gateCheck(0)) {
            MSoundSESystem::MSoundSE::startSoundSystemSE(soundId, 0, 0, 0);
            return true;
        } else
            return false;
    }

    // updates the color and fontsize of codeDisplay before drawing it to the given coords
    // you still have to clear and set the string buffer for codeDisplay yourself
    static void drawCodeDisplay(JUtility::TColor color, int fontSize, int x, int y) {
        codeContainer.codeDisplay->mGradientTop    = color;
        codeContainer.codeDisplay->mGradientBottom = color;
        codeContainer.codeDisplay->mCharSizeX      = fontSize;
        codeContainer.codeDisplay->mCharSizeY      = fontSize;

        codeContainer.codeDisplay->draw(x, y);
    }

    static void drawCodeDisplay(JUtility::TColor topColor, JUtility::TColor bottomColor, int fontSize, int x, int y) {
        codeContainer.codeDisplay->mGradientTop    = topColor;
        codeContainer.codeDisplay->mGradientBottom = bottomColor;
        codeContainer.codeDisplay->mCharSizeX      = fontSize;
        codeContainer.codeDisplay->mCharSizeY      = fontSize;

        codeContainer.codeDisplay->draw(x, y);
    }

	static void endAllCodes() {
		for ( u8 i = 0; i < CODE_COUNT; i++)
		{
            if(codeContainer.isCodeActive(i))
				codeContainer.endCode(i);
		}
	}

    // this updates the draw location for objects like trees which don't auto update
    static bool updateDrawLocation(TLiveActor *liveActor) {
        if (liveActor->mActorData != nullptr) {
            liveActor->calcRootMatrix();
            liveActor->mActorData->mModel->calc();
            return true;
        } else
            return false;
    }

    // this returns whether this is a regualar mario as opposed to shadow mario or piantissimo
    static bool isRegularMario(TMario *mario) {
        u32 vtable = *(u32 *)mario;
        if (vtable == 0x803DD660)
            return true;
        else
            return false;
    }
}