#include "codes.hxx"


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

pp::auto_patch lockJumpDirectionPatch(SMS_PORT_REGION(0x8024cad8, 0, 0, 0), BLR, false);
void CodeContainer::lockJumpDirection(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !lockJumpDirectionPatch.is_enabled())
        lockJumpDirectionPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        lockJumpDirectionPatch.set_enabled(false);
}

pp::auto_patch sadFLUDDPatch(SMS_PORT_REGION(0x8027ff0c, 0, 0, 0), NOP, false);
void CodeContainer::sadFLUDD(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !sadFLUDDPatch.is_enabled())
        sadFLUDDPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        sadFLUDDPatch.set_enabled(false);
}

pp::auto_patch landMovementLockPatch(SMS_PORT_REGION(0x802538e0, 0, 0, 0), BLR, false);
void CodeContainer::landMovementLock(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !landMovementLockPatch.is_enabled())
        landMovementLockPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        landMovementLockPatch.set_enabled(false);
}

pp::auto_patch forceTurboPatch(SMS_PORT_REGION(0x80252018, 0, 0, 0), NOP, false);
void CodeContainer::forceTurbo(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE) {
        u8 bitMask = 0b01000000;
        u32 state  = gpMarioOriginal->mState;
        if (state != TMario::State::STATE_JUMPSPINL && state != TMario::State::STATE_JUMPSPINR)
            gpMarioOriginal->mAttributes.mIsFluddEmitting = 1;
        
        if (!forceTurboPatch.is_enabled())
            forceTurboPatch.set_enabled(true);
    }
    else if (f == Code::FuncReset::TRUE)
        forceTurboPatch.set_enabled(false);
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

pp::auto_patch SPEENPatch(SMS_PORT_REGION(0x8025C39C, 0, 0, 0), NOP, false);
void CodeContainer::SPEEN(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !SPEENPatch.is_enabled())
        SPEENPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        SPEENPatch.set_enabled(false);
}

void CodeContainer::changeNozzleRandom(Code::FuncReset f) {
    u32 nozzle = rand() % 6;
    gpMarioOriginal->mFludd->mCurrentNozzle = nozzle;
    gpMarioOriginal->mFludd->mSecondNozzle = nozzle;

    Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_SLOT_SPIN);
}

void CodeContainer::giveCoins(Code::FuncReset f) {

    static bool execOnce = true;

	if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        return;
    }

	// give the coins lol
    if (execOnce) {
        TFlagManager::smInstance->setFlag(0x40002, TFlagManager::smInstance->getFlag(0x40002) + 99);
        execOnce = false;
    }
}

void CodeContainer::spawnYoshi(Code::FuncReset f) {

    static bool execOnce = true;
    static u8 codeId     = 17;

	if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        gpMarioOriginal->mYoshi->mState = TYoshi::State::EGG;
        return;
    }

    if (execOnce) {
        gpMarioOriginal->mYoshi->mState = TYoshi::State::MOUNTED;
        execOnce = false;
    }

    if (gpMarioOriginal->mYoshi->mState == TYoshi::State::EGG) {
        Code yoshiCode;
        if (codeContainer.getCodeFromName("Spawn Yoshi", yoshiCode)) {
            yoshiCode.timeCalled = currentTime - yoshiCode.duration;
            OSReport("YES!\n");
        }
    }
}