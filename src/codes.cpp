#include "codes.hxx"
#include <Kuribo/sdk/kuribo_sdk.h>


pp::auto_patch pauseWaterPatch(SMS_PORT_REGION(0x8027bedc, 0, 0, 0), NOP, false);
void CodeContainer::pauseWater(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !pauseWaterPatch.is_enabled())
        pauseWaterPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        pauseWaterPatch.set_enabled(false);
}

pp::auto_patch dummyThiccMarioPatch(SMS_PORT_REGION(0x80349a6c, 0, 0, 0), NOP, false);
void CodeContainer::dummyThiccMario(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !dummyThiccMarioPatch.is_enabled())
        dummyThiccMarioPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        dummyThiccMarioPatch.set_enabled(false);
}

pp::auto_patch noMarioRedrawPatch(SMS_PORT_REGION(0x802446c0, 0, 0, 0), BLR, false);
void CodeContainer::noMarioRedraw(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !noMarioRedrawPatch.is_enabled())
        noMarioRedrawPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        noMarioRedrawPatch.set_enabled(false);
}

pp::auto_patch whiteMarioSilhouettePatch(SMS_PORT_REGION(0x8024da58, 0, 0, 0), NOP, false);
void CodeContainer::whiteMarioSilhouette(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !whiteMarioSilhouettePatch.is_enabled())
        whiteMarioSilhouettePatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        whiteMarioSilhouettePatch.set_enabled(false);
}

pp::auto_patch noMActorModelsPatch(SMS_PORT_REGION(0x802391bc, 0, 0, 0), BLR, false);
void CodeContainer::noMActorModels(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !noMActorModelsPatch.is_enabled())
        noMActorModelsPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        noMActorModelsPatch.set_enabled(false);
}

pp::auto_patch moveTLiveActorDrawPatch(SMS_PORT_REGION(0x80217ec0, 0, 0, 0), BLR, false);
void CodeContainer::moveTLiveActorDraw(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !moveTLiveActorDrawPatch.is_enabled())
        moveTLiveActorDrawPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        moveTLiveActorDrawPatch.set_enabled(false);
}

pp::auto_patch stopControlInputsPatch(SMS_PORT_REGION(0x802c93ec, 0, 0, 0), BLR, false);
void CodeContainer::stopControlInputs(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !stopControlInputsPatch.is_enabled())
        stopControlInputsPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        stopControlInputsPatch.set_enabled(false);
}

pp::auto_patch spamSprayCentralPatch(SMS_PORT_REGION(0x8026c320, 0, 0, 0), NOP, false);
void CodeContainer::spamSprayCentral(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !spamSprayCentralPatch.is_enabled())
        spamSprayCentralPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        spamSprayCentralPatch.set_enabled(false);
}

void CodeContainer::addCodeSlot(Code::FuncReset f) {
    if (f == Code::FuncReset::TRUE) {
        codeContainer.maxActiveCodes = codeContainer.baseMaxActiveCodes;
    } else if (f == Code::FuncReset::FALSE && codeContainer.maxActiveCodes == codeContainer.baseMaxActiveCodes) {
        codeContainer.maxActiveCodes = codeContainer.baseMaxActiveCodes + 2;
    }
}

pp::auto_patch smallJumpsPatch(SMS_PORT_REGION(0x80252098, 0, 0, 0), NOP, false);
void CodeContainer::smallJumps(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !smallJumpsPatch.is_enabled())
        smallJumpsPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        smallJumpsPatch.set_enabled(false);
}

void CodeContainer::setMusicVol(Code::FuncReset f) {
    /*float vol = 0.75;    

    if (f == Code::FuncReset::TRUE) {
        vol = 0.75;
        OSReport("-> FuncReset is TRUE!\n");
    } else if (f == Code::FuncReset::FALSE) {
        vol = 5;
        OSReport("-> FuncReset is FALSE!\n");
    }

    u32 *trackOne = static_cast<u32 *>(MSBgm::smBgmInTrack[0]);
    if ((u32)trackOne > 0x80000000)
        trackOne = (u32 *)((trackOne + 0x5)[0]);
    if ((u32)trackOne > 0x80000000)
        trackOne = (u32 *)((trackOne + 0xE)[0]);

    u32 *trackTwo = static_cast<u32 *>(MSBgm::smBgmInTrack[1]);
    if ((u32)trackTwo > 0x80000000)
        trackTwo = (u32 *)((trackTwo + 0x5)[0]);
    if ((u32)trackTwo > 0x80000000)
        trackTwo = (u32 *)((trackTwo + 0xE)[0]);

    u32 *trackThree = static_cast<u32 *>(MSBgm::smBgmInTrack[2]);
    if ((u32)trackThree > 0x80000000)
        trackThree = (u32 *)((trackThree + 0x5)[0]);
    if ((u32)trackThree > 0x80000000)
        trackThree = (u32 *)((trackThree + 0xE)[0]);

    if ((u32)trackOne > 0x80000000)
        if ((trackOne[0]) > 0x80000000)
            ((float *)trackOne[0] + 0x66)[0] = vol;
    if ((u32)trackTwo > 0x80000000)
        if ((trackTwo[0]) > 0x80000000)
            ((float *)trackTwo[0] + 0x66)[0] = vol;
    if ((u32)trackThree > 0x80000000)
        if ((trackThree[0]) > 0x80000000)
            ((float *)trackThree[0] + 0x66)[0] = vol;

    MSBgm::smMainVolume = vol;

    for (int i = 0; i < 3; i++) {
        MSBgm::setTrackVolume(i, 10, 3, vol);
    }*/

}

void CodeContainer::giveCoins(Code::FuncReset f) {

    static bool execOnce = true;

	u32 *i = (u32 *)0x80349a6c;
    i[0]   = 0x60000000;

	if (f == Code::FuncReset::TRUE) {
        execOnce = true;

        i[0] = 0xf1850000;
        return;
    }

	// give the coins lol
    if (execOnce) {
        TFlagManager::smInstance->setFlag(0x40002, TFlagManager::smInstance->getFlag(0x40002) + 99);
        execOnce = false;
    }
}