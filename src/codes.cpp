#include "codes.hxx"


pp::auto_patch pauseWaterPatch(SMS_PORT_REGION(0x8027bedc, 0, 0, 0), NOP, false);
void CodeContainer::pauseWater(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !pauseWaterPatch.is_enabled())
        pauseWaterPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        pauseWaterPatch.disable();
}

pp::auto_patch dummyThiccMarioPatch(SMS_PORT_REGION(0x80349a6c, 0, 0, 0), NOP, false);
void CodeContainer::dummyThiccMario(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !dummyThiccMarioPatch.is_enabled())
        dummyThiccMarioPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        dummyThiccMarioPatch.disable();
}

pp::auto_patch noMarioRedrawPatch(SMS_PORT_REGION(0x802446c0, 0, 0, 0), BLR, false);
void CodeContainer::noMarioRedraw(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !noMarioRedrawPatch.is_enabled())
        noMarioRedrawPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        noMarioRedrawPatch.disable();
}

pp::auto_patch whiteMarioSilhouettePatch(SMS_PORT_REGION(0x8024da58, 0, 0, 0), NOP, false);
void CodeContainer::whiteMarioSilhouette(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !whiteMarioSilhouettePatch.is_enabled())
        whiteMarioSilhouettePatch.enable();
    else if (f == Code::FuncReset::TRUE)
        whiteMarioSilhouettePatch.disable();
}

pp::auto_patch noMActorModelsPatch(SMS_PORT_REGION(0x802391bc, 0, 0, 0), BLR, false);
void CodeContainer::noMActorModels(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !noMActorModelsPatch.is_enabled())
        noMActorModelsPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        noMActorModelsPatch.disable();
}

pp::auto_patch moveTLiveActorDrawPatch(SMS_PORT_REGION(0x80217ec0, 0, 0, 0), BLR, false);
void CodeContainer::moveTLiveActorDraw(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !moveTLiveActorDrawPatch.is_enabled())
        moveTLiveActorDrawPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        moveTLiveActorDrawPatch.disable();
}

pp::auto_patch stopControlInputsPatch(SMS_PORT_REGION(0x802c93ec, 0, 0, 0), BLR, false);
void CodeContainer::stopControlInputs(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !stopControlInputsPatch.is_enabled())
        stopControlInputsPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        stopControlInputsPatch.disable();
}

pp::auto_patch spamSprayCentralPatch(SMS_PORT_REGION(0x8026c320, 0, 0, 0), NOP, false);
void CodeContainer::spamSprayCentral(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !spamSprayCentralPatch.is_enabled())
        spamSprayCentralPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        spamSprayCentralPatch.disable();
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
        smallJumpsPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        smallJumpsPatch.disable();
}

pp::auto_patch lockJumpDirectionPatch(SMS_PORT_REGION(0x8024cad8, 0, 0, 0), BLR, false);
void CodeContainer::lockJumpDirection(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !lockJumpDirectionPatch.is_enabled())
        lockJumpDirectionPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        lockJumpDirectionPatch.disable();
}

pp::auto_patch sadFLUDDPatch(SMS_PORT_REGION(0x8027ff0c, 0, 0, 0), NOP, false);
void CodeContainer::sadFLUDD(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !sadFLUDDPatch.is_enabled())
        sadFLUDDPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        sadFLUDDPatch.disable();
}

pp::auto_patch landMovementLockPatch(SMS_PORT_REGION(0x802538e0, 0, 0, 0), BLR, false);
void CodeContainer::landMovementLock(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !landMovementLockPatch.is_enabled())
        landMovementLockPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        landMovementLockPatch.disable();
}

pp::auto_patch forceTurboPatch(SMS_PORT_REGION(0x80252018, 0, 0, 0), NOP, false);
void CodeContainer::forceTurbo(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE) {
        u8 bitMask = 0b01000000;
        u32 state  = gpMarioOriginal->mState;
        if (state != TMario::State::STATE_JUMPSPINL && state != TMario::State::STATE_JUMPSPINR)
            gpMarioOriginal->mAttributes.mIsFluddEmitting = 1;
        
        if (!forceTurboPatch.is_enabled())
            forceTurboPatch.enable();
    }
    else if (f == Code::FuncReset::TRUE)
        forceTurboPatch.disable();
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
        SPEENPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        SPEENPatch.disable();
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
    static bool fludd    = true;

	if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        gpMarioOriginal->mYoshi->mState = TYoshi::State::EGG;
        if (fludd)
            gpMarioOriginal->mAttributes.mHasFludd = true;
        return;		
    }

    if (execOnce) {
        if (gpMarioOriginal->STATUS_HASFLUDD)
            fludd = true;
        else
            fludd = false;
        gpMarioOriginal->mYoshi->mCurJuice = gpMarioOriginal->mYoshi->mMaxJuice;
        gpMarioOriginal->mYoshi->mState = TYoshi::State::MOUNTED;
        execOnce = false;		
    }

	if (fludd)
        gpMarioOriginal->mAttributes.mHasFludd = true;

    if (gpMarioOriginal->mYoshi->mState == TYoshi::State::EGG) {
        Code yoshiCode;
        if (!(codeContainer.getCodeFromID(SPAWN_YOSHI, yoshiCode))) {
            OSReport("[spawnYoshi] -> Could not find code with code id %d!\n", SPAWN_YOSHI);
            return;
        }
        codeContainer.endCode(SPAWN_YOSHI);
    }	
}

void CodeContainer::sunglassesAndShineShirt(Code::FuncReset f) {

	static bool execOnce = true;

	if (f == Code::FuncReset::TRUE) {
        gpMarioOriginal->takeOffGlass();	

		gpMarioOriginal->mAttributes.mIsShineShirt = 0;

        execOnce = true;
        return;
	}

	if (execOnce) {
        gpMarioOriginal->wearGlass();

		gpMarioOriginal->mAttributes.mIsShineShirt = 1;

        execOnce = false;
	}	
}

void CodeContainer::speedUpTempo(Code::FuncReset f) {

	static bool execOnce = true;

	if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        return;
    }

	if (execOnce)
	{
        u8 tempo = rand() % 3;
        gpMSound->mModBgm->changeTempo(tempo, 0);
        execOnce = false;
	}
}

void CodeContainer::tpMarioBack(Code::FuncReset f) {

	static bool execOnce = true;
    static TVec3f prevPos;

	if (f == Code::FuncReset::TRUE) {
        *gpMarioPos = prevPos;

        execOnce = true;
        return;
    }

	if (execOnce) {
		prevPos = *gpMarioPos;
        execOnce = false;
	}
}

void CodeContainer::hpRoulette(Code::FuncReset f) {

	gpMarioAddress->mHealth = rand() % 8 + 1;
    Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_SLOT_SPIN);
}

pp::auto_patch luigiSlidePatch(SMS_PORT_REGION(0x80255734, 0, 0, 0), BLR, false);
void CodeContainer::luigiSlide(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !luigiSlidePatch.is_enabled())
        luigiSlidePatch.enable();
    else if (f == Code::FuncReset::TRUE)
        luigiSlidePatch.disable();
}

void CodeContainer::emitFireball(Code::FuncReset f) {
    gpMarioOriginal->emitBlurHipDropSuper();
    gpMarioOriginal->emitGetEffect();
    gpMarioOriginal->emitSmoke(gpMarioOriginal->mAngle.y);
}

void CodeContainer::ascend(Code::FuncReset f) {

	*gpMarioSpeedY = 20.0;		// extrememly simplified code from the ckit version, even though it seems to function exactly the same

}

void CodeContainer::doubleTime(Code::FuncReset f) {		// might never be called


}


#define IdentityMtx ((f32 *)0x803db210)
void CodeContainer::messUpTextures(Code::FuncReset f) {

	static int lastTime = 0;

	
	if (f == Code::FuncReset::TRUE)
	{
        // reset it back to an actual Identity Matrix
        IdentityMtx[0] = 1;
        IdentityMtx[1] = 0;
        IdentityMtx[2] = 0;
        IdentityMtx[3] = 0;
        
        IdentityMtx[4] = 0;
        IdentityMtx[5] = 1;
        IdentityMtx[6] = 0;
        IdentityMtx[7] = 0;

	 	IdentityMtx[8] = 0;
        IdentityMtx[9] = 0;
        IdentityMtx[10] = 1;
        IdentityMtx[11] = 0;

        return;
	}

	if ((int)currentTime != lastTime && (int)currentTime % 4 == 0)
	{
        lastTime = (int)currentTime;
		int offset = rand() % 12;
        float randVal = (rand() % 4) + 2;

		IdentityMtx[offset] = randVal;
	} 
}

// allows 1ups to decrement visually
pp::auto_patch liveLiveCounter(SMS_PORT_REGION(0x801426d8, 0, 0, 0), 0x418200B0, true);

void CodeContainer::changeLives(Code::FuncReset f) {

	static bool execOnce = true;

	if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        return;
    }

    if (execOnce) {
        int randVal;
        
        while (true) {
            randVal = (rand() % 3) - 1;
            if (randVal == 0)
                continue;
            else
                break;
        }

        if (TFlagManager::smInstance->Type2Flag.mLifeCount + randVal < 0) {
            randVal = 1;
        }

		TFlagManager::smInstance->Type2Flag.mLifeCount += randVal;

		execOnce = false;
    }

}

void CodeContainer::helpfulInputDisplay(Code::FuncReset f) {
    char *displayBuffer = codeContainer.codeDisplay->getStringPtr();

    codeContainer.codeDisplay->mGradientTop    = RED;
    codeContainer.codeDisplay->mGradientBottom = RED;
    codeContainer.codeDisplay->mCharSizeX      = 32;
    codeContainer.codeDisplay->mCharSizeY      = 32;

    u32 input           = gpMarioOriginal->mController->mButtons.mInput;

    if (input & TMarioGamePad::A) {
        memset(displayBuffer, 0, NORMAL_BUF);  // clear buffer
        snprintf(displayBuffer, NORMAL_BUF, "\x40 Pressed!");
        codeContainer.codeDisplay->draw(200, 100);
    }
    if (input & TMarioGamePad::B) {
        memset(displayBuffer, 0, NORMAL_BUF);  // clear buffer
        snprintf(displayBuffer, NORMAL_BUF, "\x23 Pressed!");
        codeContainer.codeDisplay->draw(200, 200);
    }
    if (input & TMarioGamePad::X) {
        memset(displayBuffer, 0, NORMAL_BUF);  // clear buffer
        snprintf(displayBuffer, NORMAL_BUF, "\x2B Pressed!");
        codeContainer.codeDisplay->draw(200, 300);
    }
    if (input & TMarioGamePad::Y) {
        memset(displayBuffer, 0, NORMAL_BUF);  // clear buffer
        snprintf(displayBuffer, NORMAL_BUF, "\xA5 Pressed!");
        codeContainer.codeDisplay->draw(200, 400);
    }

    codeContainer.codeDisplay->mGradientTop    = GRAY;
    codeContainer.codeDisplay->mGradientBottom = GRAY;
    codeContainer.codeDisplay->mCharSizeX      = 24;
    codeContainer.codeDisplay->mCharSizeY      = 24;

    if (input & TMarioGamePad::MAINSTICK_UP) {
        memset(displayBuffer, 0, NORMAL_BUF);  // clear buffer
        snprintf(displayBuffer, NORMAL_BUF, "Holding Up!");
        codeContainer.codeDisplay->draw(220, 140);
    }
    if (input & TMarioGamePad::MAINSTICK_DOWN) {
        memset(displayBuffer, 0, NORMAL_BUF);  // clear buffer
        snprintf(displayBuffer, NORMAL_BUF, "Holding Down!");
        codeContainer.codeDisplay->draw(220, 240);
    }
    if (input & TMarioGamePad::MAINSTICK_LEFT) {
        memset(displayBuffer, 0, NORMAL_BUF);  // clear buffer
        snprintf(displayBuffer, NORMAL_BUF, "Holding Left!");
        codeContainer.codeDisplay->draw(220, 340);
    }
    if (input & TMarioGamePad::MAINSTICK_RIGHT) {
        memset(displayBuffer, 0, NORMAL_BUF);  // clear buffer
        snprintf(displayBuffer, NORMAL_BUF, "Holding Right!");
        codeContainer.codeDisplay->draw(220, 440);
    }
}

pp::togglable_ppc_b reverseInputsPatch(SMS_PORT_REGION(0x803519a8, 0, 0, 0), (void *)codeContainer.reverseInputs, false);
void CodeContainer::reverseInputsToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !reverseInputsPatch.is_enabled())
        reverseInputsPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        reverseInputsPatch.disable();
}
void CodeContainer::reverseInputs() {

    PADStatus *originalInput;
    SMS_FROM_GPR(31, originalInput);

    bool aButton = originalInput->mButton & TMarioGamePad::A;
    bool bButton = originalInput->mButton & TMarioGamePad::B;

    if (aButton != bButton) {
        originalInput->mButton ^= TMarioGamePad::A;
        originalInput->mButton ^= TMarioGamePad::B;
    }
}

void CodeContainer::simonSays(Code::FuncReset f) {

	static bool execRNGOnce = true;
    static bool inputMade = false;
    static bool wasCodeInterrupted = true;
    static int randVal = 0;
    static int soundPlayed = 0;

	u32 randButtonBinary[4] = {TMarioGamePad::A, TMarioGamePad::B, TMarioGamePad::X, TMarioGamePad::Y};
    u8 randButton[4][2]   = {"\x40", "\x23", "\x2b", "\xa5"};

	if (f == Code::FuncReset::TRUE) {
        if (!inputMade && !wasCodeInterrupted)
            gpMarioOriginal->loserExec();

        execRNGOnce = true;
        inputMade   = false;
        soundPlayed = 0;
        wasCodeInterrupted = true;
        return;
    }

    // get randVal when the code first activates
	if (execRNGOnce)
	{
        randVal = (rand() % 4);
        execRNGOnce = false;
	}

    u32 maskedInput = gpMarioOriginal->mController->mButtons.mInput & ~4294963455; // this masks the input to just the a, b, x, and y buttons!

    Code simonSays;
    if (!(codeContainer.getCodeFromID(SIMON_SAYS, simonSays))){
        OSReport("[simonSays] -> Could not find code with code id %d!\n", SIMON_SAYS);
        return;
    }
    f32 elapsedTime = currentTime - simonSays.timeCalled;

    char *displayBuffer = codeContainer.codeDisplay->getStringPtr();	
    memset(displayBuffer, 0, NORMAL_BUF);

    switch ((u32)elapsedTime) {
        case 0:
            snprintf(displayBuffer, NORMAL_BUF, "Angry_Max says.");
            Utils::drawCodeDisplay(PURPLE, 48, 50, 150);
            if (soundPlayed == 0 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                soundPlayed++;
            return;
        case 1:
            snprintf(displayBuffer, NORMAL_BUF, "Angry_Max says..");
            Utils::drawCodeDisplay(PURPLE, 48, 50, 150);
            if (soundPlayed == 1 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                soundPlayed++;
            return;
        case 2:
            snprintf(displayBuffer, NORMAL_BUF, "Angry_Max says...");
            Utils::drawCodeDisplay(PURPLE, 48, 50, 150);
            if (soundPlayed == 2 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                soundPlayed++;
            return;
        default:
            snprintf(displayBuffer, NORMAL_BUF, "Press %s!", randButton[randVal]);
            Utils::drawCodeDisplay(PURPLE, 48, 200, 150);
            wasCodeInterrupted = false;
            break;
    }
    
	
	// if an input was made
    if (maskedInput) {
        inputMade = true;

        // kills mario if the selected input isn't made
        if (!(maskedInput & randButtonBinary[randVal]))
            gpMarioOriginal->loserExec();
        // kills mario if other inputs are being made while the selected input is also made
        else if (maskedInput & ~randButtonBinary[randVal])
            gpMarioOriginal->loserExec();

		codeContainer.endCode(SIMON_SAYS);
        return;
    }
}


void CodeContainer::lockMarioAnim(Code::FuncReset f) {

    gpMarioOriginal->mModelData->_24[2] = 175;

}

void CodeContainer::scaleMario(Code::FuncReset f) {

    if (f == Code::FuncReset::TRUE) {
        gpMarioOriginal->mModelData->mModel->mBaseScale.x = 1.0;
        gpMarioOriginal->mModelData->mModel->mBaseScale.y = 1.0;
        gpMarioOriginal->mModelData->mModel->mBaseScale.z = 1.0;

		return;
    }

    gpMarioOriginal->mModelData->mModel->mBaseScale.x = 5.0;
    gpMarioOriginal->mModelData->mModel->mBaseScale.y = 5.0;
    gpMarioOriginal->mModelData->mModel->mBaseScale.z = 5.0;

}

void CodeContainer::snakeGame(Code::FuncReset f) {		// TODO: test this w/o fullscreen

	static bool execOnce;
    static bool wasCodeInterrupted = true;

	// ==================== //
    // === Player Logic === //
    // ==================== //

	static f32 player_xPos = 200;
    static f32 player_yPos = 200;		

	// player movement
    const f32 MOVEMENT_MULTIPLIER = 2.5;
	player_xPos += gpMarioOriginal->mController->mControlStick.mStickX * MOVEMENT_MULTIPLIER;
    player_yPos -= gpMarioOriginal->mController->mControlStick.mStickY * MOVEMENT_MULTIPLIER;

	// keeps the player onscreen(tuned for widescreen, but it doesnt matter since the player should never leave the screen)
	if (player_xPos < -100)
        player_xPos = -100;
    else if (player_xPos > 640)
        player_xPos = 640;
    if (player_yPos < 60)
        player_yPos = 60;
    else if (player_yPos > 465)
        player_yPos = 465;

	OSReport("X: %f\n", player_xPos);
	OSReport("Y: %f\n", player_yPos);



	// ================== //
    // === Food Logic === //
    // ================== //

	static int food_xPos = 300;
    static int food_yPos = 300;    

	if (execOnce) {
        food_xPos = (rand() % 251) + 250;
        food_yPos = (rand() % 205) + 250;		
		execOnce = false;
	}



	// ===================== //
    // === Outcome Logic === //
    // ===================== //

	bool lostGame = true;
    const int EAT_DIAMETER = 40;

	 if (((food_xPos - EAT_DIAMETER) < player_xPos) && (player_xPos < (food_xPos + EAT_DIAMETER)) &&	// its messy, but checks if the player is close enough to eat the food
        ((food_yPos - EAT_DIAMETER) < player_yPos) && (player_yPos < (food_yPos + EAT_DIAMETER))) {
    
		 codeContainer.endCode(SNAKE);
		 lostGame = false;
	 }

	 if (lostGame && f == Code::FuncReset::TRUE && !wasCodeInterrupted)
         gpMarioOriginal->loserExec();

	 if (f == Code::FuncReset::TRUE) {
         player_xPos = 200;
         player_yPos = 200;
         execOnce    = true;
         wasCodeInterrupted = true;
         return;
     }



	 // =================== //
     // === Timer Logic === //
     // =================== //

	 Code snakeGame;
     if (!(codeContainer.getCodeFromID(SNAKE, snakeGame))) {
         OSReport("[snakeGame] -> Could not find code with code id %d!\n", SNAKE);
         return;
     }
     f32 timeLeft = snakeGame.duration - (currentTime - snakeGame.timeCalled);

	 if (timeLeft <= 0.5)  // if the code was prematurely ended for any reason, makes sure the
                             // player doesnt get killed
         wasCodeInterrupted = false;



	// ============ //
	// === Draw === //
    // ============ //

	char *displayBuffer = codeContainer.codeDisplay->getStringPtr();
    memset(displayBuffer, 0, NORMAL_BUF);

	// player
    snprintf(displayBuffer, NORMAL_BUF, "0");
    Utils::drawCodeDisplay(GREEN, 48, (int)player_xPos, (int)player_yPos);

	// food
    snprintf(displayBuffer, NORMAL_BUF, "*");
    Utils::drawCodeDisplay(BLACK, 48, food_xPos + 3, food_yPos + 3);
    Utils::drawCodeDisplay(WHITE, 48, food_xPos, food_yPos);    

	// big timer
    snprintf(displayBuffer, NORMAL_BUF, "%d", (int)timeLeft);
    Utils::drawCodeDisplay(RED, 60, 255, 150);
	
}

void CodeContainer::moonGravity(Code::FuncReset f) {
    if (f == Code::FuncReset::TRUE) {
        gpMarioOriginal->mJumpParams.mGravity.set(1.0);
        return;
    }

    gpMarioOriginal->mJumpParams.mGravity.set(0.5);
}

void CodeContainer::crazyGravity(Code::FuncReset f) {
    if (f == Code::FuncReset::TRUE) {
        gpMarioOriginal->mJumpParams.mGravity.set(1.0);
        return;
    }

    gpMarioOriginal->mJumpParams.mGravity.set(cosf(currentTime));
}

void CodeContainer::chaosCode(Code::FuncReset f) {
    static bool execOnce = true;

    if (f == Code::FuncReset::TRUE) {
        codeContainer.maxActiveCodes = codeContainer.baseMaxActiveCodes;
        execOnce = true;
        return;
    }

    if (execOnce) {
        codeContainer.endCode(NO_MARIO_REDRAW);
        codeContainer.endCode(SIMON_SAYS);
        codeContainer.endCode(SNAKE);
        execOnce = false;
        return;
    }

    codeContainer.maxActiveCodes = codeContainer.currentCodeCount;
}

pp::auto_patch disableWaterColPatch(SMS_PORT_REGION(0x8024efe4, 0, 0, 0), BLR, false);
void CodeContainer::disableWaterCol(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !disableWaterColPatch.is_enabled())
        disableWaterColPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        disableWaterColPatch.disable();
}

void CodeContainer::shuffleObjects(Code::FuncReset f) {
    static int objectsShuffled = 0;
    static int soundPlayed = 0;

    if (f == Code::FuncReset::TRUE) {
        objectsShuffled = 0;
        soundPlayed     = 0;
    }

    Code shuffleObjects;
    if (!(codeContainer.getCodeFromID(SHUFFLE_OBJECTS, shuffleObjects))) {
        OSReport("[shuffleObjects] -> Could not find code with code id %d!\n", SHUFFLE_OBJECTS);
        return;
    }
    f32 elapsedTime = currentTime - shuffleObjects.timeCalled;

    switch ((u32)elapsedTime) {
        case 0:
            if (objectsShuffled == 0) {
                if (soundPlayed == 0 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                    soundPlayed++;
                objectsShuffled++;
                break;
            } else {
                if (soundPlayed == 0 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                    soundPlayed++;
                return;
            }
        case 1:
            if (objectsShuffled == 1) {
                if (soundPlayed == 1 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                    soundPlayed++;
                objectsShuffled++;
                break;
            } else {
                if (soundPlayed == 1 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                    soundPlayed++;
                return;
            }
        case 2:
            if (objectsShuffled == 2) {
                if (soundPlayed == 2 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                    soundPlayed++;
                objectsShuffled++;
                break;
            } else {
                if (soundPlayed == 2 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                    soundPlayed++;
                return;
            }
        default:
            return;
    }

    for (int i = 0; i < 300; i++) {
        int managerListSize = gpConductor->mManagerList.size();
        int managerOneIndex = rand() % managerListSize;
        int managerTwoIndex = rand() % managerListSize;
        bool noObjectsFound = false;

        TLiveManager *managerOne = nullptr;
        TLiveManager *managerTwo = nullptr;
        int currentIndex = 0;
        for (auto iter = gpConductor->mManagerList.begin(); iter != gpConductor->mManagerList.end(); iter++) {
            if (currentIndex == managerOneIndex) {
                if ((*iter)->mObjCount < 1) {
                    noObjectsFound = true;
                    break;
                }
                managerOne = *iter;
            }
            if (currentIndex == managerTwoIndex) {
                if ((*iter)->mObjCount < 1) {
                    noObjectsFound = true;
                    break;
                }
                managerTwo = *iter;
            }

            currentIndex++;
        }

        // if one of the managers doesn't have any objs, we just continue
        if (noObjectsFound)
            continue;

        
        int objOneIndex = rand() % managerOne->mObjCount;
        int objTwoIndex = rand() % managerTwo->mObjCount;
        TLiveActor *objOne = static_cast<TLiveActor *>(managerOne->mObjAry[objOneIndex]);
        TLiveActor *objTwo = static_cast<TLiveActor *>(managerTwo->mObjAry[objTwoIndex]);

        TVec3f temp = objOne->mTranslation;
        objOne->mTranslation = objTwo->mTranslation;
        objTwo->mTranslation = temp;
    }

    
}

pp::auto_patch crazyCollisionPatch(SMS_PORT_REGION(0x8018c1b4, 0, 0, 0), NOP, false);
void CodeContainer::crazyCollision(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !crazyCollisionPatch.is_enabled())
        crazyCollisionPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        crazyCollisionPatch.disable();
}


pp::togglable_ppc_b invertWaterMomentumPatch(SMS_PORT_REGION(0x80269444, 0, 0, 0), (void *)codeContainer.invertWaterMomentum, false);
void CodeContainer::invertWaterToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !invertWaterMomentumPatch.is_enabled())
        invertWaterMomentumPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        invertWaterMomentumPatch.disable();
}

void CodeContainer::invertWaterMomentum(TWaterGun *waterGun, int _, TVec3f *pos, TVec3f *dir, TVec3f *speed) {

	dir->x *= -1;
    dir->y *= -1;
    dir->z *= -1;
}

// struct used for the moveShines code
typedef struct ShineData {
    TShine *addr;
    TVec3f pos;
    f32 angleOffset;
    bool wasVisible;
} ShineData;

void CodeContainer::moveShines(Code::FuncReset f) {
    static bool execOnce = true;
    static ShineData shineArr[12] = { {nullptr, {}, 0.0f, false} };

    if (f == Code::FuncReset::TRUE) {
        for (int i = 0; i < 12; i++) {
            if (shineArr[i].addr == nullptr)
                continue;

            shineArr[i].addr->mTranslation = shineArr[i].pos;

            // reset shines back to original visibility
            if (!shineArr[i].wasVisible)
                shineArr[i].addr->kill();

            shineArr[i].addr = nullptr;
        }

        execOnce = true;
        return;
    }

    if (execOnce) {
        u32 shineCount = 0;

        for (auto iter = gpConductor->mManagerList.begin();
             iter != gpConductor->mManagerList.end(); iter++) {

            if (shineCount >= 12)
                break;

            TLiveManager *manager = *iter;
            for (int i = 0; i < manager->mObjCount; i++) {

                if (shineCount >= 12)
                    break;

                JDrama::TViewObj *obj = manager->mObjAry[i];
                u32 vtable = *(u32 *)obj;
                if (vtable != 0x803c97ec) // if the vtable isn't the TShine vtable
                    continue;
                TShine *shineObj = static_cast<TShine *>(obj);

                shineArr[shineCount].addr = shineObj;
                shineArr[shineCount].pos = shineObj->mTranslation;
                shineArr[shineCount].angleOffset = (rand() % 628) / 100.0f; // 6.28 is about 2pi
                shineArr[shineCount].wasVisible  = !shineObj->mStateFlags.asFlags.mIsObjDead;

                // we want all shines to be visible for the duration of the code
                if (!shineArr[shineCount].wasVisible)
                    shineObj->appear();

                shineCount++;
            }
        }

        execOnce = false;
    }

    for (int i = 0; i < 12; i++) {
        if (shineArr[i].addr == nullptr)
            continue;

        shineArr[i].addr->mTranslation.x = gpMarioPos->x + (200.0 * sinf(currentTime + shineArr[i].angleOffset));
        shineArr[i].addr->mTranslation.y = gpMarioPos->y;
        shineArr[i].addr->mTranslation.z = gpMarioPos->z + (200.0 * cosf(currentTime + shineArr[i].angleOffset));
    }
}

void CodeContainer::paintRandomCollision(Code::FuncReset f) {

	static bool execOnce = true;
    static bool ifRoulette = false;

	static int randCol = 0;
    const int COL_ARRAY[] = {0, 1, 2, 4, 7, 10, 265, 1793, 16384};	// normal, slippery, no slide, wet, bounce, no fall damage, water, sand, shadow

	if (f == Code::FuncReset::TRUE)
	{
        execOnce = true;
        ifRoulette = false;
        return;
	}

	if (execOnce)
	{
		// roll for collision
        randCol = rand() % 10;
		if (randCol == 9)
		{
            ifRoulette = true;
            randCol    = rand() % 9;	// prevents a crash
		}

		if (!ifRoulette)
            execOnce = false;

	}

    ((TBGCheckData *)gpMarioOriginal->mFloorTriangle)->mType = COL_ARRAY[randCol]; // have to cast it to a non const ptr

	if (COL_ARRAY[randCol] == 7)  // if bounce collision, we set the bounce height here(otherwise it (most of the time) defaults to 0, which isn't bouncy at all!)
        ((TBGCheckData *)gpMarioOriginal->mFloorTriangle)->mValue = 8500; // have to cast it to a non const ptr
}

pp::auto_patch tankControlsPatch(SMS_PORT_REGION(0x80251de0, 0, 0, 0), NOP, false);
void CodeContainer::tankControls(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !tankControlsPatch.is_enabled())
        tankControlsPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        tankControlsPatch.disable();
}

pp::auto_patch weirdCameraPatchX(SMS_PORT_REGION(0x80023600, 0, 0, 0), NOP, false);
pp::auto_patch weirdCameraPatchY(SMS_PORT_REGION(0x80023608, 0, 0, 0), NOP, false);
pp::auto_patch weirdCameraPatchZ(SMS_PORT_REGION(0x80023610, 0, 0, 0), NOP, false);
void CodeContainer::weirdCamera(Code::FuncReset f) {

	static bool execOnce = true;

	if (execOnce)
	{
        int randVal = (rand() % 3);
        execOnce = false;

		if (randVal == 0)
            weirdCameraPatchX.enable();
		else if (randVal == 1)
            weirdCameraPatchY.enable();
		else if (randVal == 2)
            weirdCameraPatchZ.enable();
	}

	if (f == Code::FuncReset::TRUE)
	{
        execOnce = true;

		weirdCameraPatchX.disable();
		weirdCameraPatchY.disable();
		weirdCameraPatchZ.disable();
    }
}

void CodeContainer::objectVortex(Code::FuncReset f) {
    for (auto iter = gpConductor->mManagerList.begin(); iter != gpConductor->mManagerList.end(); iter++) {

        TLiveManager *manager = *iter;
        for (int i = 0; i < manager->mObjCount; i++) {
            TLiveActor *obj = static_cast<TLiveActor *>(manager->mObjAry[i]);

            TVec3f dif = *gpMarioPos;
            dif.sub(obj->mTranslation);
            dif.normalize();
            dif.scale(5.0);
            obj->mTranslation.add(dif);

            // Get 1 degree in radians
            f32 angle = M_PI / 180.0;

            // Get the x and z of the object relative to mario's x and z
            f32 relativeX = obj->mTranslation.x - gpMarioPos->x;
            f32 relativeZ = obj->mTranslation.z - gpMarioPos->z;

			// Calc new coords after rotation
            obj->mTranslation.x = relativeX * cosf(angle) - relativeZ * sinf(angle);
            obj->mTranslation.z = relativeX * sinf(angle) + relativeZ * cosf(angle);

			// Translate point back to its original position
            obj->mTranslation.x += gpMarioPos->x;
            obj->mTranslation.z += gpMarioPos->z;
        }
    }
}
																			// li r0, 1
pp::auto_patch doublePerspectivePatch(SMS_PORT_REGION(0x802def34, 0, 0, 0), 0x38000001, false);
void CodeContainer::doublePerspective(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !doublePerspectivePatch.is_enabled())
        doublePerspectivePatch.enable();
    else if (f == Code::FuncReset::TRUE)
        doublePerspectivePatch.disable();
}

pp::auto_patch streeeeetchPatch(SMS_PORT_REGION(0x802d3404, 0, 0, 0), BLR, false);
void CodeContainer::streeeeetch(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !streeeeetchPatch.is_enabled())
        streeeeetchPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        streeeeetchPatch.disable();
}

void CodeContainer::smsWiki(Code::FuncReset f) {

	static float textPos = 480;
    static int currentParagraph = 0;

	const int PARAGRAPH_TOTAL = 11;

	const float SCROLL_SPEED = 1;

	if (f == Code::FuncReset::TRUE)
	{
		textPos = 480;
        currentParagraph++;
	}

    char *displayBuffer = codeContainer.codeDisplay->getStringPtr();
    memset(displayBuffer, 0, MAX_BUF);  // clear buffer

    switch (currentParagraph % PARAGRAPH_TOTAL) {
        case 0:
			snprintf(displayBuffer, MAX_BUF, "Super Mario Sunshine is a 2002 platform game developed\nand published by Nintendo for the GameCube. It is the\nsecond 3D game in the Mario series, following Super\nMario 64 (1996). The game was directed by Yoshiaki\nKoizumi and Kenta Usui, produced by series creators\nShigeru Miyamoto and Takashi Tezuka, written by Makoto\nWada, and scored by Koji Kondo and Shinobu Tanaka.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
        case 1:
			snprintf(displayBuffer, MAX_BUF, "The game takes place on the tropical Isle Delfino, where\nMario, Peach and co. are vacationing. A villain, known\nas Shadow Mario, pollutes the island with graffiti and\nMario is wrongfully convicted for the mess. Mario is\nordered to clean up Isle Delfino, using a device called\nthe Flash Liquidizer Ultra Dousing Device (FLUDD), while\nsaving Princess Peach from Shadow Mario.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
        case 2:
			snprintf(displayBuffer, MAX_BUF, "Super Mario Sunshine received critical acclaim, with\nreviewers praising the game's graphics, gameplay,\nstory,soundtrack, and the addition of F.L.U.D.D. as\na mechanic, though some criticized the game's camera\nand F.L.U.D.D.'s gimmicky nature, the high\ndifficulty, as well as the decision to use full\nvoice acting for some characters.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
        case 3:
			snprintf(displayBuffer, MAX_BUF, "The game sold over five million copies worldwide by\n2006, making it one of the best-selling GameCube\ngames. The game was re-released as a part of the\nPlayer's Choice brand in 2003. Nintendo EPD re-released\nit alongside Super Mario 64 and Super Mario Galaxy in\nthe Super Mario 3D All-Stars collection for the\nNintendo Switch in 2020.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
        case 4:
			snprintf(displayBuffer, MAX_BUF, "Sunshine shares many similar gameplay elements with\nSuper Mario 64 while also introducing various new\nfeatures. Players control Mario as he tries to obtain 120 Shine\nSprites in order to bring light back to Isle Delfino\nand prove his innocence after Bowser Jr.\n(disguised as Mario) steals the Shine Sprites and covers\nthe island in toxic goop.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
        case 5:
			snprintf(displayBuffer, MAX_BUF, "Mario starts off in the hub world of Delfino Plaza and\naccess various worlds via portals which become\navailable as the game progresses. Like collecting Stars in\nSM64, players obtain Shine Sprites by clearing a mission\nwith a specific objective. Unlike SM64, most other\nmission Shines cannot be collected until the previous\nmissions are completed.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
        case 6:
			snprintf(displayBuffer, MAX_BUF, "There are also various hidden areas and challenges\nacross Isle Delfino where more Shine Sprites can be\nobtained. Throughout the game, players may also find\nBlue Coins hidden across the island, which can be\nexchanged for more Shine Sprites in the boathouse at\nDelfino Plaza.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
		case 7:
			snprintf(displayBuffer, MAX_BUF, "In this game, Mario and a robotic backpack named\nFLUDD(Flash Liquidizing Ultra Dousing Device) use water\nto clean goop and help Mario reach new places. Mario\nstarts with two default nozzles for FLUDD, Squirt and\nHover, which he can switch between. The Squirt nozzle\nlets Mario spray a stream of water which is used to clean\nsludge, attack enemies, and activate certain mechanisms.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
		case 8:
			snprintf(displayBuffer, MAX_BUF, "The Hover nozzle lets Mario hover in the air for a\nshort period of time, allowing him to cross large gaps\nwhile spraying things directly below him. As the game\nprogresses, Mario unlocks two additional nozzles for\nFLUDD which can replace the Hover nozzle: the Rocket\nnozzle, which shoots Mario high up into the air; and the\nTurbo nozzle, which moves Mario at high speeds.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
		case 9:
			snprintf(displayBuffer, MAX_BUF, "Each of FLUDD's nozzles use water from its tank, which\ncan be refilled at water sources. There are secret\ncourses where FLUDD is taken, forcing Mario to rely on\nhis natural platforming skills. Unlike SM64, Mario can\nno longer long jump, but he can spin-jump by twirling\nthe stick and jumping, allowing him to jump higher.\nMario can also now dive at any time, which lets him\nslide quickly across wet surfaces.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
		case 10:
			snprintf(displayBuffer, MAX_BUF, "Mario may find a Yoshi egg that hatches after being\nbrought a specific fruit. Yoshi can be ridden and can\nspit juice that clears obstacles that water can't.\nYoshi can also use his tongue to eat enemies or other\npieces of fruit which change his color depending on\nthe type eaten. Yoshi will vanish if he runs out of\njuice or falls into water. Juice is replenished by eating\nmore fruit.");
            Utils::drawCodeDisplay(WHITE, GREEN, 16, 0, textPos);
            break;
    }

    textPos -= SCROLL_SPEED;

}

void CodeContainer::keepAccelerating(Code::FuncReset f) {

	static bool execOnce  = true;
    static float accelAdd = 0.0f;

	if (f == Code::FuncReset::TRUE)
	{
		execOnce = true;
		
        gpMarioOriginal->mDeParams.mRunningMax.set(80.0);
        gpMarioOriginal->mRunParams.mAddBase.set(1.1);
        gpMarioOriginal->mDeParams.mClashSpeed.set(40.0);

        accelAdd = 0;

		return;
    }

	if (execOnce)
	{
        gpMarioOriginal->mDeParams.mRunningMax.set(200.0);
        //gpMarioOriginal->mRunParams.mAddBase.set(1.1);
        gpMarioOriginal->mDeParams.mClashSpeed.set(5001.0);

		execOnce = false;
	}

    if (gpMarioOriginal->mForwardSpeed > 0.0) {
        if (accelAdd < 0.0)
            accelAdd = 0.0;

        accelAdd = accelAdd + 0.004;
    } else
        accelAdd = accelAdd - 0.2;

    gpMarioOriginal->mRunParams.mAddBase.set(gpMarioOriginal->mRunParams.mAddBase.get() + accelAdd);

    if (gpMarioOriginal->mRunParams.mAddBase.get() > 400.0)
        gpMarioOriginal->mRunParams.mAddBase.set(400.0);
    else if (gpMarioOriginal->mRunParams.mAddBase.get() < 1.1)
        gpMarioOriginal->mRunParams.mAddBase.set(1.1);
}

void CodeContainer::icePhysics(Code::FuncReset f) {		// not really ice physics but good enough?

	gpMarioOriginal->checkGraffitoSlip();
}


pp::auto_patch changeWallsPatch(SMS_PORT_REGION(0x802505f4, 0, 0, 0), NOP, false);
void CodeContainer::changeWalls(Code::FuncReset f) {

	static bool execOnce = true;

    if (f == Code::FuncReset::FALSE && !changeWallsPatch.is_enabled())
        changeWallsPatch.enable();
    else if (f == Code::FuncReset::TRUE) {
        changeWallsPatch.disable();
        execOnce = true;
        return;
	}

	if (execOnce)
	{
        bool isThin = rand() % 2;
		
		if (isThin)
			gpMarioOriginal->mCollisionXZSize = 5;
		else
            gpMarioOriginal->mCollisionXZSize = 200;

		execOnce = false;
	}
}

// struct used for the moveShines code
typedef struct ObjectData {
    TLiveActor *addr;
    TVec3f pos;
    TVec3f rot;
    u32 objectType;
    bool isShine;
    bool wasVisible;
    
} ObjectData;

void CodeContainer::makeMarioAnObject(Code::FuncReset f) {					// TODO: fix bug where this code causes inactive shines to suddenly become active(even if they arent chosenObj)
    static bool execOnce = true;
    static ObjectData chosenObj = {nullptr, {}, {}, 0, false, false};

    if (f == Code::FuncReset::TRUE) {
        if (chosenObj.addr != nullptr) {
            chosenObj.addr->mTranslation = chosenObj.pos;
            chosenObj.addr->mRotation = chosenObj.rot;
            chosenObj.addr->mObjectType  = chosenObj.objectType;
            if (chosenObj.isShine && !chosenObj.wasVisible)
                static_cast<TShine *>(chosenObj.addr)->kill();

            chosenObj.addr = nullptr;
        }
        chosenObj.isShine = false;

        execOnce = true;
        gpMarioOriginal->mAttributes.mIsVisible = false;
        return;
    }

    if (execOnce) {
        auto iter = gpConductor->mManagerList.begin();
        while (true) {
            if (iter == gpConductor->mManagerList.end())
                iter = gpConductor->mManagerList.begin();

            TLiveManager *manager = *iter;
            for (int i = 0; i < manager->mObjCount; i++) {

                JDrama::TViewObj *obj = manager->mObjAry[i];
                u32 vtable            = *(u32 *)obj;
                switch (vtable) {
                    case (0x803c97ec):  // TShine
                        chosenObj.addr       = static_cast<TLiveActor *>(obj);
                        chosenObj.isShine = true;
                        chosenObj.wasVisible = !chosenObj.addr->mStateFlags.asFlags.mIsObjDead;
                        if (!chosenObj.wasVisible)
                            static_cast<TShine *>(chosenObj.addr)->makeObjAppeared();

                    case (0x803d8448): // TBaseNpc
                    case (0x803abe78): // TAnimalBird
                    case (0x803abb70): // TAnimalBase
                    case (0x803cb06c): // TMapObjBillboard
                        chosenObj.addr = static_cast<TLiveActor *>(obj);
                        OSReport("Manager: 0x%x, Object: 0x%x\n", manager, obj);
                        break;
                }

                if (chosenObj.addr != nullptr) {
                    // only break some of the time to pick a random object
                    if (rand() % 10 == 0)
                        break;
                    else {
                        chosenObj.addr = nullptr;
                        chosenObj.isShine = false;
                    }
                }
                    break;
            }

            if (chosenObj.addr != nullptr)
                break;

            iter++;
        }

        gpMarioOriginal->mAttributes.mIsVisible = true;
        
        chosenObj.pos = chosenObj.addr->mTranslation;
        chosenObj.rot = chosenObj.addr->mRotation;
        chosenObj.objectType = chosenObj.addr->mObjectType;
        
        execOnce = false;
    }

    chosenObj.addr->mObjectType |= 1;
    chosenObj.addr->mTranslation = *gpMarioPos;
    chosenObj.addr->mRotation    = gpMarioAddress->mRotation;
    chosenObj.addr->mRidingInfo.mHitActor = nullptr;
}

void CodeContainer::popupSavePrompt(Code::FuncReset f) {
    static bool execOnce = true;

    if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        return;
    }

    if (execOnce) {
        if (gpMarioOriginal->mState == TMario::STATE_INACTIVE)
            return;

        gpMarDirector->mPauseMenu->mCardSave->init(rand() % 6);

		execOnce = false;
		
    }
}

void CodeContainer::pingLag(Code::FuncReset f) {
    static TVec3f marPrevPos;
    static f32 timeToWait    = 0;
    static f32 timeStarted   = 0;
    static bool execOnce     = true;
    static bool getMarioPos  = true;

	if (gpMarDirector->mCurState != TMarDirector::Status::STATE_NORMAL)		// prevents coordinates from previous stages translating into the next stage(when changing stages)
        f = Code::FuncReset::TRUE;

    if (f == Code::FuncReset::TRUE) {
        timeToWait = 0;
        execOnce   = true;
        getMarioPos = true;
        return;
    }

	if (execOnce) {
        marPrevPos = *gpMarioPos;
        execOnce   = false;
    }

    if (timeToWait == 0) {
        timeToWait = ((rand() % 10) + 1) / 10.0;
        timeStarted = currentTime;

    }

    if ((currentTime - timeStarted) >= timeToWait) {
        if (getMarioPos) {
            marPrevPos = *gpMarioPos;
            getMarioPos = false;
        } else {
            *gpMarioPos = marPrevPos;
            getMarioPos = true;
        }
        timeToWait     = 0;
    }
}

void CodeContainer::noGracePeriods(Code::FuncReset f) {

	static bool execOnce = true;

	if (execOnce)
	{
        codeContainer.gracePeriod = 0;
        codeContainer.maxActiveCodes++;
        execOnce = false;
	}

	if (f == Code::FuncReset::TRUE)
	{
        codeContainer.gracePeriod = codeContainer.baseGracePeriod;
        codeContainer.maxActiveCodes--;
        execOnce = true;
	}
}

void CodeContainer::earthquake(Code::FuncReset f) {

	for (auto iter = gpConductor->mManagerList.begin(); iter != gpConductor->mManagerList.end(); iter++) {

        TLiveManager *manager = *iter;
        for (int i = 0; i < manager->mObjCount; i++) {
            TLiveActor *obj = static_cast<TLiveActor *>(manager->mObjAry[i]);

            int xJitter = rand() % 21;
            xJitter     = xJitter - 10;
            int zJitter = rand() % 21;
            zJitter     = zJitter - 10;

			obj->mTranslation.x += xJitter;
			obj->mTranslation.z += zJitter;
        }

		Utils::playSound(MSD_SE_OBJ_QUAKE);
        gpCameraShake->startShake(static_cast<EnumCamShakeMode>(rand() % 0x28), 0.1);
    }
}
																			 // li r5, 2
pp::auto_patch sometimesDoubleCoinsPatch(SMS_PORT_REGION(0x801becd4, 0, 0, 0), 0x38a00002, false);
void CodeContainer::sometimesDoubleCoins(Code::FuncReset f) {
    if (f == Code::FuncReset::TRUE) {
        sometimesDoubleCoinsPatch.disable();
        return;
    }

    if ((u32)currentTime % 2 == 0) {
        sometimesDoubleCoinsPatch.enable();
    } else
        sometimesDoubleCoinsPatch.disable();
}

void CodeContainer::reverseRarities(Code::FuncReset f) {
	
static bool execOnce = true;

    if (execOnce) {			// adds a code slot so that the affect of this code can actually be felt
        codeContainer.maxActiveCodes++;
        execOnce = false;
    }

    if (f == Code::FuncReset::TRUE) {
        codeContainer.maxActiveCodes--;
        execOnce = true;
    }
}

pp::togglable_ppc_bl changeScreenColorPatch(SMS_PORT_REGION(0x8017d0e8, 0, 0, 0), (void *)codeContainer.changeScreenColor, false);
void CodeContainer::changeScreenColorToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !changeScreenColorPatch.is_enabled())
        changeScreenColorPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        changeScreenColorPatch.disable();
}
void CodeContainer::changeScreenColor(TSunGlass *sunglass, JDrama::TRect &rect, JUtility::TColor color) {

    static u8 newColor[4] = {0xA0, 0xA0, 0xA0, 0x80};
    static bool rCountUp = true;
    static bool gCountUp = true;
    static bool bCountUp = true;



    if (rCountUp && newColor[0] >= 249)
        rCountUp = false;
    else if (!rCountUp && newColor[0] <= 6)
        rCountUp = true;

    if (gCountUp && newColor[1] >= 249)
        gCountUp = false;
    else if (!gCountUp && newColor[1] <= 6)
        gCountUp = true;

    if (bCountUp && newColor[2] >= 249)
        bCountUp = false;
    else if (!bCountUp && newColor[2] <= 6)
        bCountUp = true;

    u8 val = rand() % 6;
    if (rCountUp)
        newColor[0] += val;
    else
        newColor[0] -= val;

    val = rand() % 6;
    if (gCountUp)
        newColor[1] += val;
    else
        newColor[1] -= val;

    val = rand() % 6;
    if (bCountUp)
        newColor[2] += val;
    else
        newColor[2] -= val;

    color.set(newColor[0], newColor[1], newColor[2], newColor[3]);

    sunglass->draw(rect, color);
}

pp::togglable_ppc_bl upsideDownCamPatch(SMS_PORT_REGION(0x8002380c, 0, 0, 0), (void *)codeContainer.upsideDownCam, false);
void CodeContainer::upsideDownCamToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !upsideDownCamPatch.is_enabled())
        upsideDownCamPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        upsideDownCamPatch.disable();
}
void CodeContainer::upsideDownCam() {

	gpCamera->mProjectionFovy = (f32)310;
}


void CodeContainer::joyconDrift(Code::FuncReset f) {
	 
	static bool execOnce = true;
    static f32 xDrift_control;
    static f32 yDrift_control;
    static f32 xDrift_camera;
    static f32 yDrift_camera;

	if (f == Code::FuncReset::TRUE)
	{
		execOnce = true;
		return;
	}

	if (execOnce)
	{
        xDrift_control = (((rand() % 101)) - 50) / 100.0;
        yDrift_control = (((rand() % 101)) - 50) / 100.0;
        xDrift_camera = (((rand() % 101)) - 50) / 100.0;
        yDrift_camera = (((rand() % 101)) - 50) / 100.0;

		execOnce = false;
	}

	if (gpMarioOriginal->mController->mControlStick.mStickX == 0 && gpMarioOriginal->mController->mControlStick.mStickY == 0)
	{
        gpMarioOriginal->mController->mControlStick.mStickX += xDrift_control;
        gpMarioOriginal->mController->mControlStick.mStickY += yDrift_control;
    }

	if (gpMarioOriginal->mController->mStickX == 0 && gpMarioOriginal->mController->mStickY == 0)
	{
        gpMarioOriginal->mController->mStickX += xDrift_camera;
        gpMarioOriginal->mController->mStickY += yDrift_camera;
    }

}

void CodeContainer::sineMomentum(Code::FuncReset f) {

    gpMarioOriginal->mBaseAcceleration = cosf(currentTime);
}

void CodeContainer::windyDay(Code::FuncReset f) {

	gpMarioOriginal->setPlayerVelocity(50 * cosf(currentTime));
    gpMarioOriginal->mSpeed.y *= cosf(currentTime);

	Utils::playSound(MS_SOUND_EFFECT::MSD_SE_EN_KAZEKUN_WAIT);
}

void CodeContainer::brawl(Code::FuncReset f) {

	static bool execOnce = true;
	static bool execRNG = true;
    static f32 tripTimer = 0;
    static f32 lastTrip = 0;

	if (f == Code::FuncReset::TRUE)
	{
        execOnce = true;
        return;
	}

	if (execOnce)
	{
        lastTrip = currentTime;
        execOnce = false;
	}
	
	if (execRNG)
	{
        tripTimer = (rand() % 91) / 10;
        execRNG   = false;
	}

	Code brawl;
    if (!(codeContainer.getCodeFromID(BRAWL, brawl))) {
        OSReport("[brawl] -> Could not find code with code id %d!\n", BRAWL);
        return;
    }

	f32 elapsedTime = currentTime - lastTrip;

	if (elapsedTime >= tripTimer) {
        gpMarioOriginal->oilSlip();
        execRNG = true;
        lastTrip = currentTime;
    }

}

void CodeContainer::noclip(Code::FuncReset f) {

	static bool execOnce = true;

	if (f == Code::FuncReset::TRUE)
	{
        gpMarioOriginal->mState = TMario::State::STATE_IDLE;
		execOnce = true;
        return;
	}

	if (execOnce) {

        gpMarioOriginal->mState = 0xF000FFFF;	// bettersms debug state
		execOnce = false;
    }
}

void CodeContainer::jumpscare(Code::FuncReset f) {		// TODO: make the visual part of the jumpscare

	static bool execOnce = true;

	if (f == Code::FuncReset::TRUE)
	{
        execOnce = true;
        return;
	}
	
	if (execOnce)
	{
        MS_SOUND_EFFECT soundArray[] = {MSD_SE_BS_MKP_EXPLOSION_S,   MSD_SE_BS_TELESA_DAMAGE,
                                        MSD_SE_EN_GATEKEEPER_APPEAR, MSD_SE_NB_UNG_VOICE_M_CRY,
                                        MSD_SE_NB_UNG_VOICE_W_CRY};

        u8 randSound = rand() % 5;

        Utils::playSound(soundArray[randSound]);

        //char *c = "\x83\x7d\x83\x8a\x83\x49"; // mario in shift-jis
        //gpMarDirector->fireStartDemoCamera(c, gpMarioPos, -1, 0, true, nullptr, 0, 0, 0);
        execOnce = false;
    }
}

void CodeContainer::smallWorld(Code::FuncReset f) {

	static bool execOnce = true;

	if (f == Code::FuncReset::TRUE)
	{
        execOnce = true;
        return;
	}


	if (execOnce) {

        for (auto iter = gpConductor->mManagerList.begin(); iter != gpConductor->mManagerList.end();
             iter++) {

            TLiveManager *manager = *iter;
            for (int i = 0; i < manager->mObjCount; i++) {
                TLiveActor *obj = static_cast<TLiveActor *>(manager->mObjAry[i]);

                if (obj->mScale.x > 0.1)
                    obj->mScale.x -= 0.1;
                if (obj->mScale.y > 0.1)
                    obj->mScale.y -= 0.1;
                if (obj->mScale.z > 0.1)
                    obj->mScale.z -= 0.1;
            }
        }
        execOnce = false;
    }
}

pp::auto_patch randomSprayPatch(SMS_PORT_REGION(0x8027fe78, 0, 0, 0), NOP, false);
void CodeContainer::randomSpray(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !randomSprayPatch.is_enabled())
        randomSprayPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        randomSprayPatch.disable();
}

void CodeContainer::playAllSounds(Code::FuncReset f) {

	Utils::playSound(rand() % (MSD_SE_SHINE_EXIST + 1));

}

//pp::auto_patch pickUpPatch1(SMS_PORT_REGION(0x802137D0, 0, 0, 0), 0x64A50010, false);	// oris	r5, r5, 0x0010		// currently, once these patch, all npcs become pick up able regard
//pp::auto_patch pickUpPatch2(SMS_PORT_REGION(0x802137D4, 0, 0, 0), 0x90A300F0, false);   // stw	r5, 0x00F0 (r3)
void CodeContainer::pickUpObj(Code::FuncReset f) {

	static bool execOnce = true;
	static bool isBird = false;
    static bool isGrabSuccess   = false;
    static ObjectData chosenObj = {nullptr, {}, {}, 0, false, false};

    if (f == Code::FuncReset::TRUE)
	{
        //pickUpPatch1.disable();
        //pickUpPatch2.disable();
        chosenObj.addr->mStateFlags.asFlags.mCanBeTaken = false;

        f32 **mPtrSaveNormal = (f32 **)(0x8040DFA0);
        mPtrSaveNormal[0][0x1d0 / 4] = 3.5; // mThrowSpeedXZ for npcs
        mPtrSaveNormal[0][0x1e4 / 4] = 2.5; // mThrowSpeedY for npcs

		isBird   = false;
        isGrabSuccess = false;
        execOnce = true;
        return;
	}

	if (execOnce)
	{
		auto iter = gpConductor->mManagerList.begin();
        while (true) {
            if (iter == gpConductor->mManagerList.end())
                iter = gpConductor->mManagerList.begin();

            TLiveManager *manager = *iter;
            for (int i = 0; i < manager->mObjCount; i++) {

                JDrama::TViewObj *obj = manager->mObjAry[i];
                u32 vtable            = *(u32 *)obj;
                switch (vtable) {               
                case (0x803abe78):  // TAnimalBird | works but is weird
                    isBird = true;
                case (0x803d8448):  // TBaseNpc
                //case (0x803abb70):  // TAnimalBase | doesnt work
                //case (0x803cb06c):  // TMapObjBillboard | crashes
                    chosenObj.addr = static_cast<TLiveActor *>(obj);
                    OSReport("Manager: 0x%x, Object: 0x%x\n", manager, obj);
                    break;
                }

                if (chosenObj.addr != nullptr) {
                    // only break some of the time to pick a random object
                    if (rand() % 10 == 0)
                        break;
                    else {
                        chosenObj.addr    = nullptr;
                        isBird         = false;
                    }
                }
                break;
            }

            if (chosenObj.addr != nullptr)
                break;

            iter++;
        }

		

        chosenObj.objectType = chosenObj.addr->mObjectType;
        chosenObj.addr->mStateFlags.asFlags.mCanBeTaken = true;

        f32 **mPtrSaveNormal = (f32 **)(0x8040DFA0);
        mPtrSaveNormal[0][0x1d0 / 4] = 16.0; // mThrowSpeedXZ for npcs
        mPtrSaveNormal[0][0x1e4 / 4] = 13.5; // mThrowSpeedY for npcs        
	}

	if (!isGrabSuccess && (gpMarioOriginal->mState == TMario::State::STATE_RUNNING		  ||
                           gpMarioOriginal->mState == TMario::State::STATE_IDLE			  ||
                           gpMarioOriginal->mState == TMario::State::STATE_STOP			  ||
                           gpMarioOriginal->mState == TMario::State::STATE_DIVESLIDE	  ||
                           gpMarioOriginal->mState == TMario::State::STATE_G_POUND_RECOVER))
	{
        gpMarioOriginal->mGrabTarget = chosenObj.addr;
        gpMarioOriginal->mState      = TMario::State::STATE_GRABBING;
        isGrabSuccess                = true;
        execOnce                     = false;
	}

	if (isBird) 
        chosenObj.addr->mStateFlags.asU32 &= 0x4;
}

void CodeContainer::rotateObjs(Code::FuncReset f) {

	static bool execOnce = true;

    if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        return;
    }

    if (execOnce) {		

        for (auto iter = gpConductor->mManagerList.begin(); iter != gpConductor->mManagerList.end();
             iter++) {

            TLiveManager *manager = *iter;
            for (int i = 0; i < manager->mObjCount; i++) {
                TLiveActor *obj = static_cast<TLiveActor *>(manager->mObjAry[i]);

                obj->mRotation.x +=  rand() % 11;
                obj->mRotation.y +=  rand() % 11;
                obj->mRotation.z +=  rand() % 11;
            }
        }
        execOnce = false;
    }
}

pp::togglable_ppc_bl quakeProPatch(SMS_PORT_REGION(0x8002380c, 0, 0, 0), (void *)codeContainer.quakePro, false);
void CodeContainer::quakeProToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !quakeProPatch.is_enabled())
        quakeProPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        quakeProPatch.disable();
}

void CodeContainer::quakePro() {

	gpCamera->mProjectionFovy = (f32)160;
}

void CodeContainer::rollin(Code::FuncReset f) {

    static bool execOnce = true;
	static int numAxis;

    if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        return;
    }

    if (execOnce) {

		numAxis = (rand() % 3) + 1;  

        execOnce = false;
    }

	for (auto iter = gpConductor->mManagerList.begin(); iter != gpConductor->mManagerList.end();
         iter++) {

        TLiveManager *manager = *iter;
        for (int i = 0; i < manager->mObjCount; i++) {
            TLiveActor *obj = static_cast<TLiveActor *>(manager->mObjAry[i]);

			switch(numAxis) {
            case 3:
                obj->mRotation.x += 0.5;
            case 2:
                obj->mRotation.y += 0.5;
            case 1:
                obj->mRotation.z += 0.5;
            }
        }
    }
}

void CodeContainer::shrinkRay(Code::FuncReset f) {

    const int RANGE = 300;

    TWaterGun *pTWaterGun = gpMarioOriginal->mFludd;

    OSReport("-> X: %f\n", gpModelWaterManager->mStaticHitActor.mTranslation.x);
    OSReport("-> Y: %f\n", gpModelWaterManager->mStaticHitActor.mTranslation.y);
    OSReport("-> Z: %f\n", gpModelWaterManager->mStaticHitActor.mTranslation.z);

    for (auto iter = gpConductor->mManagerList.begin(); iter != gpConductor->mManagerList.end();
         iter++) {

        TLiveManager *manager = *iter;
        for (int i = 0; i < manager->mObjCount; i++) {
            TLiveActor *obj = static_cast<TLiveActor *>(manager->mObjAry[i]);

            TVec3f objPos = obj->mTranslation;

            if (pTWaterGun->mIsEmitWater) {
                TVec3f waterPos = gpModelWaterManager->mStaticHitActor.mTranslation;
                if (waterPos.x >= objPos.x - RANGE && waterPos.x <= objPos.x + RANGE &&
                    waterPos.y >= objPos.y - RANGE && waterPos.y <= objPos.y + RANGE &&
                    waterPos.z >= objPos.z - RANGE && waterPos.z <= objPos.z + RANGE) {
                    obj->mScale.x -= 0.01;
                    obj->mScale.y -= 0.01;
                    obj->mScale.z -= 0.01;
                }
            }
        }
    }
}