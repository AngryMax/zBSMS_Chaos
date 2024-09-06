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

void CodeContainer::spawnYoshi(Code::FuncReset f) {		// TODO: refill yoshi's juice bar on execOnce

    static bool execOnce = true;
    static bool fludd    = true;

	if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        gpMarioOriginal->mYoshi->mState = TYoshi::State::EGG;
        return;		
    }

    if (execOnce) {
        if (gpMarioOriginal->STATUS_HASFLUDD)
            fludd = true;
        else
            fludd = false;

        gpMarioOriginal->mYoshi->mState = TYoshi::State::MOUNTED;
        execOnce = false;		
    }

    if (gpMarioOriginal->mYoshi->mState == TYoshi::State::EGG) {
        Code yoshiCode;
        if (!(codeContainer.getCodeFromID(SPAWN_YOSHI, yoshiCode))) {
            OSReport("[spawnYoshi] -> Could not find code with code id %d!\n", SPAWN_YOSHI);
            return;
        }
        codeContainer.endCode(SPAWN_YOSHI);
    }

	if (fludd)
        gpMarioOriginal->mAttributes.mHasFludd = true;
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
    Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_SLOT_SPIN);  // CURRENTLY THROWS AN INVALID READ
}

pp::auto_patch luigiSlidePatch(SMS_PORT_REGION(0x80255734, 0, 0, 0), BLR, false);
void CodeContainer::luigiSlide(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !luigiSlidePatch.is_enabled())
        luigiSlidePatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        luigiSlidePatch.set_enabled(false);
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
        memset(displayBuffer, 0, 144);  // clear buffer
        snprintf(displayBuffer, 144, "\x40 Pressed!");
        codeContainer.codeDisplay->draw(200, 100);
    }
    if (input & TMarioGamePad::B) {
        memset(displayBuffer, 0, 144);  // clear buffer
        snprintf(displayBuffer, 144, "\x23 Pressed!");
        codeContainer.codeDisplay->draw(200, 200);
    }
    if (input & TMarioGamePad::X) {
        memset(displayBuffer, 0, 144);  // clear buffer
        snprintf(displayBuffer, 144, "\x2B Pressed!");
        codeContainer.codeDisplay->draw(200, 300);
    }
    if (input & TMarioGamePad::Y) {
        memset(displayBuffer, 0, 144);  // clear buffer
        snprintf(displayBuffer, 144, "\xA5 Pressed!");
        codeContainer.codeDisplay->draw(200, 400);
    }

    codeContainer.codeDisplay->mGradientTop    = GRAY;
    codeContainer.codeDisplay->mGradientBottom = GRAY;
    codeContainer.codeDisplay->mCharSizeX      = 24;
    codeContainer.codeDisplay->mCharSizeY      = 24;

    if (input & TMarioGamePad::MAINSTICK_UP) {
        memset(displayBuffer, 0, 144);  // clear buffer
        snprintf(displayBuffer, 144, "Holding Up!");
        codeContainer.codeDisplay->draw(220, 140);
    }
    if (input & TMarioGamePad::MAINSTICK_DOWN) {
        memset(displayBuffer, 0, 144);  // clear buffer
        snprintf(displayBuffer, 144, "Holding Down!");
        codeContainer.codeDisplay->draw(220, 240);
    }
    if (input & TMarioGamePad::MAINSTICK_LEFT) {
        memset(displayBuffer, 0, 144);  // clear buffer
        snprintf(displayBuffer, 144, "Holding Left!");
        codeContainer.codeDisplay->draw(220, 340);
    }
    if (input & TMarioGamePad::MAINSTICK_RIGHT) {
        memset(displayBuffer, 0, 144);  // clear buffer
        snprintf(displayBuffer, 144, "Holding Right!");
        codeContainer.codeDisplay->draw(220, 440);
    }
}

pp::togglable_ppc_b reverseInputsPatch(SMS_PORT_REGION(0x803519a8, 0, 0, 0), (void *)codeContainer.reverseInputs, false);
void CodeContainer::reverseInputsToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !SPEENPatch.is_enabled())
        reverseInputsPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        reverseInputsPatch.set_enabled(false);
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
    static int randVal = 0;
    static int soundPlayed = 0;

	u32 randButtonBinary[4] = {TMarioGamePad::A, TMarioGamePad::B, TMarioGamePad::X, TMarioGamePad::Y};
    u8 randButton[4][2]   = {"\x40", "\x23", "\x2b", "\xa5"};

	if (f == Code::FuncReset::TRUE) {
        if (!inputMade)
            gpMarioOriginal->loserExec();

        execRNGOnce = true;
        inputMade   = false;
        soundPlayed = 0;
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
    memset(displayBuffer, 0, 144);

    switch ((u32)elapsedTime) {
        case 0:
            snprintf(displayBuffer, 144, "Angry_Max says.");
            Utils::drawCodeDisplay(PURPLE, 48, 50, 150);
            if (soundPlayed == 0 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                soundPlayed++;
            return;
        case 1:
            snprintf(displayBuffer, 144, "Angry_Max says..");
            Utils::drawCodeDisplay(PURPLE, 48, 50, 150);
            if (soundPlayed == 1 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                soundPlayed++;
            return;
        case 2:
            snprintf(displayBuffer, 144, "Angry_Max says...");
            Utils::drawCodeDisplay(PURPLE, 48, 50, 150);
            if (soundPlayed == 2 && Utils::playSound(MS_SOUND_EFFECT::MSD_SE_OBJ_AP_BUTTON))
                soundPlayed++;
            return;
        default:
            snprintf(displayBuffer, 144, "Press %s!", randButton[randVal]);
            Utils::drawCodeDisplay(PURPLE, 48, 200, 150);
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

	static int execOnce;

	// ==================== //
    // === Player Logic === //
    // ==================== //

	static f32 player_xPos = 200;
    static f32 player_yPos = 200;		

	// player movement
    const f32 MOVEMENT_MULTIPLIER = 2.5;
	player_xPos += gpMarioOriginal->mController->mControlStick.mStickX * MOVEMENT_MULTIPLIER;
    player_yPos -= gpMarioOriginal->mController->mControlStick.mStickY * MOVEMENT_MULTIPLIER;

	// keeps the player onscreen
	if (player_xPos < -100)
        player_xPos = -100;
    else if (player_xPos > 640)
        player_xPos = 640;
    if (player_yPos < 60)
        player_yPos = 60;
    else if (player_yPos > 465)
        player_yPos = 465;



	// ================== //
    // === Food Logic === //
    // ================== //

	static int food_xPos = 300;
    static int food_yPos = 300;    

	if (execOnce) {
        food_xPos = (rand() % 285) + 250;
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

	 if (lostGame && f == Code::FuncReset::TRUE)
         gpMarioOriginal->loserExec();

	 if (f == Code::FuncReset::TRUE) {
         player_xPos = 200;
         player_yPos = 200;
         execOnce    = true;
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
     f32 elapsedTime = currentTime - snakeGame.timeCalled;



	// ============ //
	// === Draw === //
    // ============ //

	char *displayBuffer = codeContainer.codeDisplay->getStringPtr();
    memset(displayBuffer, 0, 144);

	// player
    snprintf(displayBuffer, 144, "0");
    Utils::drawCodeDisplay(GREEN, 48, (int)player_xPos, (int)player_yPos);

	// food
    snprintf(displayBuffer, 144, "*");
    Utils::drawCodeDisplay(BLACK, 48, food_xPos + 3, food_yPos + 3);
    Utils::drawCodeDisplay(WHITE, 48, food_xPos, food_yPos);    

	// big timer
    snprintf(displayBuffer, 144, "%d", (int)(snakeGame.duration - (currentTime - snakeGame.timeCalled)));
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
        disableWaterColPatch.set_enabled(true);
    else if (f == Code::FuncReset::TRUE)
        disableWaterColPatch.set_enabled(false);
}
