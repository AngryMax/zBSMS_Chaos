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
pp::togglable_ppc_bl holdCapPatch1(SMS_PORT_REGION(0x80244c48, 0, 0, 0), (void *)codeContainer.holdCap, false);
pp::auto_patch holdCapPatch2(SMS_PORT_REGION(0x80244d5c, 0, 0, 0), NOP, false);
void CodeContainer::holdCapToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !whiteMarioSilhouettePatch.is_enabled()) {
        whiteMarioSilhouettePatch.enable();
        holdCapPatch1.enable();
        holdCapPatch2.enable();
    } else if (f == Code::FuncReset::TRUE) {
        whiteMarioSilhouettePatch.disable();
        holdCapPatch1.disable();
        holdCapPatch2.disable();
    }
}

void CodeContainer::holdCap() {
    TMario *mario;
    SMS_FROM_GPR(30, mario);

    if (Utils::isRegularMario(mario)) {
        SMS_TO_GPR(0, 0x12d);
    } else {
        SMS_TO_GPR(0, mario->mAnimationID);
    }
}

pp::auto_patch noMActorModelsPatch(SMS_PORT_REGION(0x802391bc, 0, 0, 0), BLR, false);
void CodeContainer::noMActorModels(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !noMActorModelsPatch.is_enabled())
        noMActorModelsPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        noMActorModelsPatch.disable();
}

pp::auto_patch moveTLiveActorDrawPatch(SMS_PORT_REGION(0x80217ec0, 0, 0, 0), BLR, false);
void CodeContainer::stopTLiveActorPerform(Code::FuncReset f) {
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

void CodeContainer::rollExtraCode(Code::FuncReset f) {
    static int codesCalled = 0;

	if (f == Code::FuncReset::TRUE) {
        codesCalled = 0;
		return;
	}

	if (codesCalled < 2 && codeContainer.activateCode())
        codesCalled++;

	if (codesCalled >= 2) {        
		codeContainer.endCode(ROLL_EXTRA_CODE);
		return;
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
    for (int i = 0; i < 3; i++) {
        MSBgm::setTrackVolume(i, (sinf(currentTime) + 1) * 1.5, 12, 3); // dunno what the 12 or 3 do tbh
    }
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

void CodeContainer::giantMario(Code::FuncReset f) {

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

void CodeContainer::snakeGame(Code::FuncReset f) {

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

	//OSReport("X: %f\n", player_xPos);
	//OSReport("Y: %f\n", player_yPos);



	// ================== //
    // === Food Logic === //
    // ================== //

	static int food_xPos = 300;
    static int food_yPos = 300;    

	if (execOnce) {
        food_xPos = (rand() % 251) + 300;
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

    gpMarioOriginal->mJumpParams.mGravity.set(cosf(currentTime) * 0.5);
}

void CodeContainer::chaosCode(Code::FuncReset f) {
    static bool execOnce = true;

    if (f == Code::FuncReset::TRUE) {
        codeContainer.rollTime = codeContainer.baseRollTime;
        execOnce = true;
        return;
    }	

    if (execOnce) {
        codeContainer.endCode(NO_MARIO_REDRAW);
        codeContainer.endCode(SIMON_SAYS);
        codeContainer.endCode(SNAKE);
        codeContainer.endCode(FAST_N_FURIOUS);
        codeContainer.endCode(SCRAMBLE_TEXTURES);
        codeContainer.endCode(PAUSE_TIMERS);
        if (codeContainer.isCodeActive(HALVE_ROLL_TIME)) {
            codeContainer.endCode(HALVE_ROLL_TIME);
            codeContainer.resetCode(HALVE_ROLL_TIME);
        }
        codeContainer.rollTime = 99999;
        execOnce = false;
        return;
    }

    Code chaosCode;
    if (!(codeContainer.getCodeFromID(CHAOS_CODE, chaosCode))) {
        OSReport("[chaosCode] -> Could not find code with code id %d!\n", CHAOS_CODE);
        return;
    }

    float timeSinceRolled = currentTime - chaosCode.timeCalled;
    if (timeSinceRolled < 3) {
        char *displayBuffer = codeContainer.codeDisplay->getStringPtr();
        memset(displayBuffer, 0, NORMAL_BUF);
        snprintf(displayBuffer, NORMAL_BUF, "Prepare for");
        Utils::drawCodeDisplay(RED, WHITE, 48, 145, 150);
        snprintf(displayBuffer, NORMAL_BUF, "CHAOS");
        Utils::drawCodeDisplay(RED, 60, 170, 220);
    } else
        codeContainer.rollTime = 0;
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

        Utils::updateDrawLocation(objOne);
        Utils::updateDrawLocation(objTwo);
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

            Utils::updateDrawLocation(obj);
        }
    }
}
																			// li r0, 1
pp::auto_patch doublePerspectivePatch(SMS_PORT_REGION(0x802def34, 0, 0, 0), 0x38000001, false);
void CodeContainer::doublePerspective(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !doublePerspectivePatch.is_enabled() && (int)currentTime % 5)
        doublePerspectivePatch.enable();
    else if (f == Code::FuncReset::TRUE || !((int)currentTime % 5))
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
    bool isMapObj;
    bool wasVisible;
    
} ObjectData;

void CodeContainer::makeMarioAnObject(Code::FuncReset f) {
	static bool execOnce = true;
    static ObjectData chosenObj = {nullptr, {}, {}, 0, false, false};

    if (f == Code::FuncReset::TRUE) {
        if (chosenObj.addr != nullptr) {
            chosenObj.addr->mTranslation = chosenObj.pos;
            chosenObj.addr->mRotation    = chosenObj.rot;
            chosenObj.addr->mObjectType  = chosenObj.objectType;
            if (chosenObj.isMapObj && !chosenObj.wasVisible)
                static_cast<TMapObjBase *>(chosenObj.addr)->kill();

            Utils::updateDrawLocation(chosenObj.addr);

            chosenObj.addr = nullptr;
        }
        chosenObj.isMapObj = false;

        execOnce                                = true;
        gpMarioOriginal->mAttributes.mIsVisible = false;
        return;
    }

    if (execOnce) {
        // loop through manager list to find all npc and bird managers
        JGadget::TList<TLiveManager *> mgrList;
        for (auto iter = gpConductor->mManagerList.begin(); iter != gpConductor->mManagerList.end();
             iter++) {

            TLiveManager *manager = *iter;
            u32 vtable            = *(u32 *)manager;
            switch (vtable) {
                case 0x803c8d48:  // TMapObjBaseManager
                case 0x803c8eec:  // TMapObjManager

                // Seagulls
                case 0x803abc88:  // TMewManager

                // Piantas
                case 0x803d8a98:  // TMonteMAManager
                case 0x803d8a40:  // TMonteMBManager
                case 0x803d89e8:  // TMonteMCManager
                case 0x803d8990:  // TMonteMDManager
                case 0x803d8938:  // TMonteMEManager
                case 0x803d9018:  // TMonteMFManager
                case 0x803d8fc0:  // TMonteMGManager
                case 0x803d8f68:  // TMonteMHManager
                case 0x803d8af0:  // TMonteMManager
                case 0x803d8888:  // TMonteWAManager
                case 0x803d8830:  // TMonteWBManager
                case 0x803d8f10:  // TMonteWCManager
                case 0x803d88e0:  // TMonteWManager

                // Nokis
                case 0x803d8eb8:  // TMareMAManager
                case 0x803d8e60:  // TMareMBManager
                case 0x803d8e08:  // TMareMCManager
                case 0x803d8db0:  // TMareMDManager
                case 0x803df920:  // TMareMManager
                case 0x803d8d58:  // TMareWAManager
                case 0x803d8d00:  // TMareWBManager
                case 0x803df8c8:  // TMareWManager

                // Toad, Toadsworth, & Peach
                case 0x803d8ca8:  // TKinopioManager
                case 0x803d8c50:  // TKinojiManager
                case 0x803d8bf8:  // TPeachManager

                // Item Birds
                case 0x803abe24:  // TAnimalBirdManager

                // Raccoon Dogs
                case 0x803d8ba0:  // TRaccoonDogManager

                // NPC Manager
                case 0x803d9228:  // TNPCManager
                    if (manager->mObjCount > 0) {
                        // OSReport("Manager: 0x%x\n", manager);
                        mgrList.push_front(manager);
                    }
            }
        }

        // if no objects are present, just end the code
        if (mgrList.size() == 0) {
            codeContainer.endCode(MAKE_MARIO_OBJ);
            return;
        }

        u32 randMgrInd = rand() % mgrList.size();  // pick a random manager from the list
        u32 currMgrInd = 0;
        for (auto iter = mgrList.begin(); iter != mgrList.end(); iter++) {
            if (currMgrInd != randMgrInd) {
                currMgrInd++;
                continue;
            }

            TLiveManager *manager = *iter;
            u32 randObjInd        = rand() % manager->mObjCount;
            TLiveActor *obj       = static_cast<TLiveActor *>(manager->mObjAry[randObjInd]);

            chosenObj.addr = obj;
            u32 mgrVtable  = *(u32 *)manager;
            if (mgrVtable == 0x803c8d48 || mgrVtable == 0x803c8eec)  // TMapObjBaseManager or TMapObjManager
            {
                chosenObj.isMapObj = true;
                chosenObj.wasVisible = !chosenObj.addr->mStateFlags.asFlags.mIsObjDead;
                if (!chosenObj.wasVisible)
                    static_cast<TMapObjBase *>(chosenObj.addr)->makeObjAppeared();
            }

            OSReport("Manager: 0x%x, Object: 0x%x\n", manager, obj);

            break;
        }

        gpMarioOriginal->mAttributes.mIsVisible = true;

        chosenObj.pos        = chosenObj.addr->mTranslation;
        chosenObj.rot        = chosenObj.addr->mRotation;
        chosenObj.objectType = chosenObj.addr->mObjectType;

        execOnce = false;
    }

    if (chosenObj.addr != nullptr) {
        if (!Utils::updateDrawLocation(chosenObj.addr)) {
            // if the chosen obj doesn't have a model, reset the code to roll again
            OSReport("Obj 0x%x didn't have a model! Resetting!\n", chosenObj.addr);
            codeContainer.resetCode(MAKE_MARIO_OBJ);
            return;
        }

        chosenObj.addr->mObjectType |= 1;
        chosenObj.addr->mTranslation          = *gpMarioPos;
        chosenObj.addr->mRotation             = gpMarioAddress->mRotation;
        chosenObj.addr->mRidingInfo.mHitActor = nullptr;
    }
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

void CodeContainer::halveRollTime(Code::FuncReset f) {

	static bool execOnce = true;

	if (execOnce)
	{
        codeContainer.rollTime = codeContainer.baseRollTime / 2;
        execOnce = false;
	}

	if (f == Code::FuncReset::TRUE)
	{
        codeContainer.rollTime = codeContainer.baseRollTime;
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

void CodeContainer::reverseRarities(Code::FuncReset f) {			// actual funcionality for this code is in getWeightedRand()
	
	static bool isNewCodeRolled = false;

    if (!isNewCodeRolled && codeContainer.activateCode())			// calls a code slot so that the affect of this code can actually be felt
        isNewCodeRolled = true;

    if (f == Code::FuncReset::TRUE)
        isNewCodeRolled = false;
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

pp::auto_patch jumpscarePatch(SMS_PORT_REGION(0x80029d5c, 0, 0, 0), BLR, false);
pp::auto_patch jumpscarePatch2(SMS_PORT_REGION(0x8024de38, 0, 0, 0), BLR, false);
pp::auto_patch jumpscarePatch3(SMS_PORT_REGION(0x80244800, 0, 0, 0), BLR, false);
void CodeContainer::jumpscare(Code::FuncReset f) {

	static bool execOnce = true;
    static TVec3f mTargetPos;
    static TVec3f mTranslation;
    static TVec3f projectedPos;
    int **cameraType = (int **)0x8040D0A8;

	if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        jumpscarePatch.disable();
        jumpscarePatch2.disable();
        jumpscarePatch3.disable();
        return;
    }
	
	if (execOnce)
	{
        mTargetPos = *gpMarioPos;
        mTargetPos.y += 100;
        mTranslation = gpCamera->mTranslation;

        gpMarioOriginal->mModelData->_24[2] = 62;

		jumpscarePatch.enable();
        jumpscarePatch2.enable();

        MS_SOUND_EFFECT soundArray[] = {MSD_SE_BS_MKP_EXPLOSION_S,   MSD_SE_BS_TELESA_DAMAGE,
                                        MSD_SE_EN_GATEKEEPER_APPEAR, MSD_SE_NB_UNG_VOICE_M_CRY,
                                        MSD_SE_NB_UNG_VOICE_W_CRY};

        u8 randSound = rand() % 5;

        Utils::playSound(soundArray[randSound]);

		projectedPos = *gpMarioPos;
        f32 yawRadians = (gpMarioOriginal->mAngle.y * M_PI) / 32768.0f;
       

        projectedPos.x += 200 * sinf(yawRadians);
        projectedPos.z += 200 * cosf(yawRadians);

        //char *c = "\x83\x7d\x83\x8a\x83\x49"; // mario in shift-jis
        //gpMarDirector->fireStartDemoCamera(c, gpMarioPos, -1, 0, true, nullptr, 0, 0, 0);
        execOnce = false;
        return;
    }
    jumpscarePatch3.enable();

    gpMarioOriginal->mModelData->_24[2] = 62;

	gpCamera->mTargetPos.set(mTargetPos);
    gpCamera->mTranslation.set(projectedPos);
    //*gpMarioPos = mTranslation;
    //gpMarioPos->y -= 100;
    //*gpMarioAngleY = gpCamera->mHorizontalAngle;    
    //cameraType[0][0x50 / 4] = 33;  // gpCamera offset 0x50 = camera type. it's technically defined in the header interface, but they're doin something weird with it
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

                Utils::updateDrawLocation(obj);
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
 
void CodeContainer::pickUpObj(Code::FuncReset f) {

	static bool execOnce = true;
	static bool isBird = false;
    static bool isGrabSuccess   = false;
    static ObjectData chosenObj = {nullptr, {}, {}, 0, false, false};

    if (f == Code::FuncReset::TRUE) {
        if (chosenObj.addr != nullptr) {
            chosenObj.addr->mStateFlags.asFlags.mCanBeTaken = false;
        }

        chosenObj.addr = nullptr;
        isBird         = false;
        isGrabSuccess  = false;
        execOnce       = true;
        return;
    }

    if (execOnce) {
        // loop through manager list to find all npc and bird managers
        JGadget::TList<TLiveManager *> pickUpMgrList;
        for (auto iter = gpConductor->mManagerList.begin(); iter != gpConductor->mManagerList.end(); iter++) {

            TLiveManager *manager = *iter;
            u32 vtable            = *(u32 *)manager;
            switch (vtable) {               

                // Piantas
                case 0x803d8a98:  // TMonteMAManager
                case 0x803d8a40:  // TMonteMBManager
                case 0x803d89e8:  // TMonteMCManager
                case 0x803d8990:  // TMonteMDManager
                case 0x803d8938:  // TMonteMEManager
                case 0x803d9018:  // TMonteMFManager
                case 0x803d8fc0:  // TMonteMGManager
                case 0x803d8f68:  // TMonteMHManager
                case 0x803d8af0:  // TMonteMManager
                case 0x803d8888:  // TMonteWAManager
                case 0x803d8830:  // TMonteWBManager
                case 0x803d8f10:  // TMonteWCManager
                case 0x803d88e0:  // TMonteWManager

                // Nokis
                case 0x803d8eb8:  // TMareMAManager
                case 0x803d8e60:  // TMareMBManager
                case 0x803d8e08:  // TMareMCManager
                case 0x803d8db0:  // TMareMDManager
                case 0x803df920:  // TMareMManager
                case 0x803d8d58:  // TMareWAManager
                case 0x803d8d00:  // TMareWBManager
                case 0x803df8c8:  // TMareWManager

                // Toad, Toadsworth, & Peach
                case 0x803d8ca8:  // TKinopioManager
                case 0x803d8c50:  // TKinojiManager
                case 0x803d8bf8:  // TPeachManager

				// Item Birds
                case 0x803abe24:  // TAnimalBirdManager

                // Raccoon Dogs
                case 0x803d8ba0:  // TRaccoonDogManager

                // NPC Manager
                case 0x803d9228:  // TNPCManager
                    if (manager->mObjCount > 0) {
                        //OSReport("Manager: 0x%x\n", manager);
                        pickUpMgrList.push_front(manager);
                    }
            }
        }

        // if no carryable objects are present, just end the code
        if (pickUpMgrList.size() == 0) {
            codeContainer.endCode(PICK_UP_OBJ);
            return;
        }

        u32 randMgrInd = rand() % pickUpMgrList.size();  // pick a random manager from the list
        u32 currMgrInd = 0;
        for (auto iter = pickUpMgrList.begin(); iter != pickUpMgrList.end(); iter++) {
            if (currMgrInd != randMgrInd) {
                currMgrInd++;
                continue;
            }

            TLiveManager *manager = *iter;
            u32 randObjInd        = rand() % manager->mObjCount;
            TLiveActor *obj       = static_cast<TLiveActor *>(manager->mObjAry[randObjInd]);

            chosenObj.addr = obj;
            u32 mgrVtable  = *(u32 *)manager;
            if (mgrVtable == 0x803abe24)  // TAnimalBirdManager
                isBird = true;

            Utils::updateDrawLocation(chosenObj.addr);

            break;
        }

        execOnce = false;
    }

	chosenObj.objectType = chosenObj.addr->mObjectType;
    chosenObj.addr->mStateFlags.asFlags.mCanBeTaken = true;

    f32 **mPtrSaveNormal = (f32 **)(0x8040DFA0);
    mPtrSaveNormal[0][0x1d0 / 4] = 16.0;  // mThrowSpeedXZ for npcs
    mPtrSaveNormal[0][0x1e4 / 4] = 13.5;  // mThrowSpeedY for npcs          

	if (!isGrabSuccess && (gpMarioOriginal->mState == TMario::State::STATE_RUNNING		  ||
                           gpMarioOriginal->mState == TMario::State::STATE_IDLE			  ||
                           gpMarioOriginal->mState == TMario::State::STATE_STOP			  ||
                           gpMarioOriginal->mState == TMario::State::STATE_DIVESLIDE	  ||
                           gpMarioOriginal->mState == TMario::State::STATE_G_POUND_RECOVER))
	{
        gpMarioOriginal->mGrabTarget = chosenObj.addr;
        gpMarioOriginal->mState      = TMario::State::STATE_GRABBING;
        chosenObj.addr->mTranslation = *gpMarioPos;
        isGrabSuccess                = true;
	}

	if (isBird && gpMarioOriginal->mHeldObject == chosenObj.addr) {
        chosenObj.addr->mStateFlags.asU32 &= 0x4;
        chosenObj.addr->mTranslation = gpMarioOriginal->mTranslation;
    }
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
                Utils::updateDrawLocation(obj);
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

	gpCamera->mProjectionFovy = (f32)140;
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

            Utils::updateDrawLocation(obj);
        }
    }
}

void CodeContainer::shrinkRay(Code::FuncReset f) {

    const int RANGE = 300;

    TWaterGun *pTWaterGun = gpMarioOriginal->mFludd;

    //OSReport("-> X: %f\n", gpModelWaterManager->mStaticHitActor.mTranslation.x);
    //OSReport("-> Y: %f\n", gpModelWaterManager->mStaticHitActor.mTranslation.y);
    //OSReport("-> Z: %f\n", gpModelWaterManager->mStaticHitActor.mTranslation.z);

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
                    Utils::updateDrawLocation(obj);
                }
            }
        }
    }
}

void CodeContainer::csPlayers(Code::FuncReset f) {

	static bool execOnce = true;
    static f32 origAspect;	// easiest way to satisfy all possible aspect ratios

	if (f == Code::FuncReset::TRUE) {
        gpCamera->mProjectionAspect = origAspect;
        execOnce                    = true;
        return;
    }

	if (execOnce)
	{
        origAspect = gpCamera->mProjectionAspect;
        execOnce   = false;
	}

	Code csPlayers;
    if (!(codeContainer.getCodeFromID(CS_PLAYERS, csPlayers))) {
        OSReport("[csPlayers] -> Could not find code with code id %d!\n", CS_PLAYERS);
        return;
    }

	gpCamera->mProjectionAspect = (2.25 * sinf((currentTime - csPlayers.timeCalled - 1.75) / 4)) + 2.75;	// range: .5 - 5
}

void CodeContainer::invertMario(Code::FuncReset f) {

	if (f == Code::FuncReset::TRUE)
	{
        gpMarioOriginal->mModelData->mModel->mBaseScale.x *= -1;
        gpMarioOriginal->mModelData->mModel->mBaseScale.y *= -1;
        gpMarioOriginal->mModelData->mModel->mBaseScale.z *= -1;
        return;
	}

	if (gpMarioOriginal->mModelData->mModel->mBaseScale.x > 0)
        gpMarioOriginal->mModelData->mModel->mBaseScale.x *= -1;
    if (gpMarioOriginal->mModelData->mModel->mBaseScale.y > 0)
        gpMarioOriginal->mModelData->mModel->mBaseScale.y *= -1;
    if (gpMarioOriginal->mModelData->mModel->mBaseScale.z > 0)
        gpMarioOriginal->mModelData->mModel->mBaseScale.z *= -1;
}

void CodeContainer::fireMovement(Code::FuncReset f) {

	static bool execOnce = true;
    static u8 mDamage_Orig;
    static f32 mFireDownForce;
    static f32 mFireDownControl;
    static f32 mFireBackVelocity;
    static f32 mFireHeight;

	if (f == Code::FuncReset::TRUE)
	{
        gpMarioOriginal->mDmgGraffitoFireParams.mDamage.set(mDamage_Orig);
        gpMarioOriginal->mJumpParams.mFireDownForce.set(mFireDownForce);
        gpMarioOriginal->mJumpParams.mFireDownControl.set(mFireDownControl);
        gpMarioOriginal->mJumpParams.mFireBackVelocity.set(mFireBackVelocity);
        gpMarioOriginal->mGraffitoParams.mFireHeight.set(mFireHeight);

		execOnce = true;
        return;
	}

	if (execOnce)
	{
        mDamage_Orig		= gpMarioOriginal->mDmgGraffitoFireParams.mDamage.get();
        mFireDownForce		= gpMarioOriginal->mJumpParams.mFireDownForce.get();
        mFireDownControl	= gpMarioOriginal->mJumpParams.mFireDownControl.get();
        mFireBackVelocity	= gpMarioOriginal->mJumpParams.mFireBackVelocity.get();		
        mFireHeight			= gpMarioOriginal->mGraffitoParams.mFireHeight.get();		

		execOnce = false;
	}

	gpMarioOriginal->mDmgGraffitoFireParams.mDamage.set(0);
    gpMarioOriginal->mJumpParams.mFireDownForce.set(60);
    gpMarioOriginal->mJumpParams.mFireDownControl.set(1);
    gpMarioOriginal->mJumpParams.mFireBackVelocity.set(20);		// might not actually be doing anything :p
	gpMarioOriginal->mGraffitoParams.mFireHeight.set(25);
    
    Vec temp;
    temp.x = gpMarioPos->x + gpMarioOriginal->mSpeed.x;
    temp.y = gpMarioPos->y + gpMarioOriginal->mSpeed.y;
    temp.z = gpMarioPos->z + gpMarioOriginal->mSpeed.z;
	TBGCheckData *wall = gpMarioOriginal->checkWallPlane(&temp, 30, gpMarioOriginal->mCollisionXZSize);

    if (gpMarioOriginal->mTranslation.y - gpMarioOriginal->mFloorBelow <= 25) {
        gpMarioOriginal->changePlayerStatus(TMario::STATE_FIRE_HIT, 1, true);
        gpMarioParticleManager->emitAndBindToPosPtr(6, gpMarioPos, 0, nullptr);
    } else if (wall) {
        gpMarioOriginal->mSpeed.y = 52;
        gpMarioOriginal->mAngle.y -= 0x8000;
        gpMarioOriginal->changePlayerStatus(TMario::STATE_FIRE_HIT, 1, true);
        gpMarioParticleManager->emitAndBindToPosPtr(6, gpMarioPos, 0, nullptr);
    }
}

#define atntable ((u32 *)0x803da838)
void CodeContainer::lol(Code::FuncReset f) {

    if (f == Code::FuncReset::TRUE) {
       
        atntable[0] = 0x10;

        return;
    }

    atntable[0] = NOP;
}

void CodeContainer::tilted(Code::FuncReset f) {

	if (f == Code::FuncReset::TRUE)			// TODO? idkk, it might be kinda funny to not reset this code...
	{
        *gpMarioAngleX = 0;
        *gpMarioAngleZ = 0;
        return;
	}

	*gpMarioAngleX = *gpMarioAngleY;
	*gpMarioAngleZ = gpCamera->mHorizontalAngle; 

}

void CodeContainer::popUpUX(Code::FuncReset f) {

	//gpMarDirector->mGCConsole->mIsResetTimer = true;

	int randAppear = rand() % 7;

	switch (randAppear) {
		case 0:
			gpMarDirector->mGCConsole->startAppearCoin();
			break;

        case 1:
            gpMarDirector->mGCConsole->startAppearJetBalloon(1, 10);
			break;

        case 2:
            gpMarDirector->mGCConsole->startAppearLife(1);
            break;

        case 3:
            gpMarDirector->mGCConsole->startAppearMario(false);
            break;

        case 4:
            gpMarDirector->mGCConsole->startAppearRedCoin();
            break;

        case 5:
            gpMarDirector->mGCConsole->startAppearStar();
            break;

        case 6:
            gpMarDirector->mGCConsole->startAppearTank();
            break;

        case 7:
            gpMarDirector->mGCConsole->startAppearTelop(true);
            break;
	}
}

void CodeContainer::superposition(Code::FuncReset f) {

	static TVec3f marPrevPos;
    static f32 timeToWait   = 0;
    static f32 timeStarted  = 0;
    static bool execOnce    = true;

    if (f == Code::FuncReset::TRUE) {
        timeToWait  = 0;
        execOnce    = true;
        return;
    }

    if (execOnce) {
        marPrevPos = *gpMarioPos;
        execOnce   = false;
    }

    if (timeToWait == 0) {
        timeToWait  = 3;
        timeStarted = currentTime;
    }

    // get marios position before teleporting him to his last position
    if ((currentTime - timeStarted) >= timeToWait) {
        TVec3f temp = marPrevPos;
        marPrevPos  = *gpMarioPos;
        *gpMarioPos = temp;
        timeToWait = 0;
    }
}

void CodeContainer::wideMario(Code::FuncReset f) {

	float xAdd;		// these var overcomplicate this func to hell. at first, it was to originally make this code and scaleMario not mutually exclusive(which they now are), but now it's b/c of the below comment
	float yAdd;
    static float xTotal;
    static float yTotal;

	if (f == Code::FuncReset::TRUE)
	{
        gpMarioOriginal->mModelData->mModel->mBaseScale.x -= xTotal;		// i think b/c of precision loss, mario ends up being slightly the wrong size? thats ok tbh
        gpMarioOriginal->mModelData->mModel->mBaseScale.z -= yTotal;

		xTotal = 0;
		yTotal = 0;
	}

	xAdd = sinf(currentTime) / 2;
    yAdd = sinf(currentTime * 1.3) / 2;

	xTotal += xAdd;
	yTotal += yAdd;

	gpMarioOriginal->mModelData->mModel->mBaseScale.x += xAdd;
	gpMarioOriginal->mModelData->mModel->mBaseScale.z += yAdd;

}

void CodeContainer::sightseer(Code::FuncReset f) {

	TVec3f airstrip   = {-6600, 3360, -600};
    TVec3f plaza      = {0, 4500, -7500};
    TVec3f bianco     = {8250, 10620, -12900};
    TVec3f ricco      = {-3900, 3950, -1100};
    TVec3f gelato     = {-4160, 6860, -4200};
    TVec3f pinnaBeach = {13800, 375, 1160};
    TVec3f pinnaPark  = {6500, 10200, -7850};
    TVec3f sirena     = {-50, 2250, -2600};
    TVec3f delfino    = {-2150, 1870, -330};
    TVec3f casino     = {2910, 91, -1960};
    TVec3f noki       = {1485, 9210, 7370};
    TVec3f pianta     = {-990, 455, -5900};

	switch (gpMarDirector->mAreaID) {

		case 0:
			*gpMarioPos = airstrip;
            break;
        case 1:
            *gpMarioPos = plaza;
            break;
        case 2:
            *gpMarioPos = bianco;
            break;
        case 3:
            *gpMarioPos = ricco;
            break;
        case 4:
            *gpMarioPos = gelato;
            break;
        case 5:
            *gpMarioPos = pinnaBeach;
            break;
        case 6:
            *gpMarioPos = sirena;
            break;
        case 7:
            *gpMarioPos = delfino;
            break;
        case 8:
            *gpMarioPos = pianta;
            break;
        case 9:
            *gpMarioPos = noki;
            break;
        case 13:
            *gpMarioPos = pinnaPark;
            break;
        case 14:
            *gpMarioPos = casino;
            break;
	}	

	codeContainer.endCode(SIGHTSEER);
}
//                                                                    li r3, 1
pp::auto_patch starPowerPatch1(SMS_PORT_REGION(0x80255f50, 0, 0, 0), 0x38600001, false);
pp::togglable_ppc_b starPowerPatch2(SMS_PORT_REGION(0x8024db08, 0, 0, 0), (void *)codeContainer.starPower, false);
void CodeContainer::starPowerToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::TRUE) {
        starPowerPatch1.disable();
        starPowerPatch2.disable();
        return;
    } else {
        starPowerPatch1.enable();
        starPowerPatch2.enable();
    }
}

void CodeContainer::starPower() {

    u8 sinVal = (sinf(currentTime) + 1) * 127;
    u8 cosVal = (cosf(currentTime) + 1) * 127;

    JDrama::TGraphics *graphics;
    SMS_FROM_GPR(30, graphics);

    // add rainbow damage fog to body
    J3DModel *bodyModel = gpMarioOriginal->mModelData->mModel;
    for (int i = 0; i < bodyModel->mModelData->mMaterialNum; i++) {
        J3DFogInfo *currFog = bodyModel->mModelData->mMaterials[i]->mPEBlockFull->getFog();

        currFog->r = sinVal;
        currFog->g = cosVal;
        currFog->b = sinVal;
        currFog->a = cosVal;
    }
    SMS_AddDamageFogEffect(bodyModel->mModelData, *gpMarioPos, graphics);

    // add rainbow damage fog to cap
    if (gpMarioOriginal->mCap != 0) {
        J3DModel *capModel = gpMarioOriginal->mCap->mCurrentCapModel;
        for (int i = 0; i < capModel->mModelData->mMaterialNum; i++) {
            J3DFogInfo *currFog = capModel->mModelData->mMaterials[i]->mPEBlockFull->getFog();

            currFog->r = sinVal;
            currFog->g = cosVal;
            currFog->b = sinVal;
            currFog->a = cosVal;
        }
        SMS_AddDamageFogEffect(capModel->mModelData, *gpMarioPos, graphics);
    }

    // add rainbow damage fog to hands
    if (gpMarioOriginal->mHandModel2R != 0) {
        J3DModel **handModelPtrs = &gpMarioOriginal->mHandModel2R;
        for (int i = 0; i < 5; i++) {
            J3DModel *handModel = handModelPtrs[i];
            for (int i = 0; i < handModel->mModelData->mMaterialNum; i++) {
                J3DFogInfo *currFog = handModel->mModelData->mMaterials[i]->mPEBlockFull->getFog();

                currFog->r = sinVal;
                currFog->g = cosVal;
                currFog->b = sinVal;
                currFog->a = cosVal;
            }
            SMS_AddDamageFogEffect(handModel->mModelData, *gpMarioPos, graphics);
        }
    }

    // add rainbow damage fog to fludd
    /*if (gpMarioOriginal->mFludd != 0) {
        J3DModel *fluddModel = gpMarioOriginal->mFludd->mMActor->mModel;
        for (int i = 0; i < fluddModel->mModelData->mMaterialNum; i++) {
            J3DFogInfo *currFog = fluddModel->mModelData->mMaterials[i]->mPEBlockFull->getFog();

            currFog->r = sinVal;
            currFog->g = cosVal;
            currFog->b = sinVal;
            currFog->a = cosVal;
        }
        SMS_AddDamageFogEffect(fluddModel->mModelData, *gpMarioPos, graphics);
    }*/
}

pp::auto_patch trippyPatch1(SMS_PORT_REGION(0x802f4260, 0, 0, 0), BLR, false);
pp::auto_patch trippyPatch2(SMS_PORT_REGION(0x802f417c, 0, 0, 0), BLR, false);
void CodeContainer::trippyTextures(Code::FuncReset f) {

	static bool execOnce = true;
    static u8 rng        = 0;

	if (execOnce)
	{
        rng = rand() % 3;
        execOnce = false;
	}

    if (f == Code::FuncReset::FALSE && !trippyPatch1.is_enabled() && !trippyPatch2.is_enabled()) {
		switch (rng)
		{ 
			case 0:
				trippyPatch1.enable();
            case 1:
                trippyPatch2.enable();
                break;
            case 2:
                trippyPatch1.enable();
		}
    } else if (f == Code::FuncReset::TRUE) {
        trippyPatch1.disable();
        trippyPatch2.disable();
        execOnce = true;
    }

}

pp::auto_patch imaTiredPatch(SMS_PORT_REGION(0x80251494, 0, 0, 0), BLR, false);
void CodeContainer::imaTired(Code::FuncReset f) {

	gpMarioOriginal->sleeping();
    gpMarioOriginal->mState = 0xC000203;	// sleep

	if (f == Code::FuncReset::FALSE && !imaTiredPatch.is_enabled())
        imaTiredPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        imaTiredPatch.disable();

}

pp::auto_patch freezeAnimsPatch(SMS_PORT_REGION(0x802e1730, 0, 0, 0), BLR, false);
void CodeContainer::freezeAnims(Code::FuncReset f) {
    static int calledNum = 0;
	if (f == Code::FuncReset::FALSE && !freezeAnimsPatch.is_enabled())
        freezeAnimsPatch.enable();
    else if (f == Code::FuncReset::TRUE || calledNum % 4 == 0)
        freezeAnimsPatch.disable();

	calledNum++;
}

void CodeContainer::fastNFurious(Code::FuncReset f) {

    const f32 SPEED_MIN = 40;
    const f32 SPEED_ADD = 85;
    f32 mForwardSpeed   = gpMarioOriginal->mForwardSpeed;
    static f32 depletionHP = -200;  // depletionHP starts at -200, if it hits 0 you die.
    u8 speed_meterX  = 150;
    u16 speed_meterY = 400;
	u16 depletion_meterX  = 465;
    u16 depletion_meterY   = 208;

    if (f == Code::FuncReset::TRUE) {
        depletionHP = -200;
        return;
    }

	if (gpMarDirector->mCurState == 7)
        codeContainer.endCode(FAST_N_FURIOUS);

    if (gpMarDirector->mCurState != 4)
        return;

    if (mForwardSpeed <= 0)
        mForwardSpeed = 1;

    if (mForwardSpeed < SPEED_MIN)
        depletionHP += 0.425;   
	else if (mForwardSpeed > SPEED_ADD && depletionHP > -200)
        depletionHP -= 0.075;   

	if (depletionHP >= 0) {
        gpMarioOriginal->loserExec();
        codeContainer.endCode(FAST_N_FURIOUS);        
    }

    // speed meter
    J2DFillBox(speed_meterX - 6, speed_meterY - 4, 100 * 3 + 12, 18, GRAY_TRANSP);
    J2DFillBox(speed_meterX, speed_meterY, (int)mForwardSpeed * 3, 10, {(u8)(mForwardSpeed * -2.5), (u8)(mForwardSpeed * 2.5), 0, 0xff});

    // depletion meter
    J2DFillBox(depletion_meterX, depletion_meterY, 28, 100 * 2 + 6, GRAY_TRANSP);
    J2DFillBox(depletion_meterX + 4, depletion_meterY + 203, 20, depletionHP, {(u8)(depletionHP * 1.275), (u8)(depletionHP * -1.275), 0, 0xff});

	// target speed notch
    J2DFillBox(speed_meterX + 116, speed_meterY - 7, 8, 24, BLACK_TRANSP);

	// labels
    char *displayBuffer = codeContainer.codeDisplay->getStringPtr();
    memset(displayBuffer, 0, NORMAL_BUF);

    snprintf(displayBuffer, NORMAL_BUF, "Speed:");
    Utils::drawCodeDisplay(WHITE, GRAY, 32, speed_meterX - 10, speed_meterY - 10);

	snprintf(displayBuffer, NORMAL_BUF, "HP:");
    Utils::drawCodeDisplay(WHITE, GRAY, 32, depletion_meterX - 12, depletion_meterY - 5);
}

pp::auto_patch divingModePatch(SMS_PORT_REGION(0x80140cd0, 0, 0, 0), NOP, false);
void CodeContainer::divingMode(Code::FuncReset f) {

	if (f == Code::FuncReset::TRUE) {
        gpMarioOriginal->mAttributes.mGainHelmetFlwCamera = false;		// its not a bug, it's a feature ;^)
        divingModePatch.disable();
        return;
    } 

    divingModePatch.enable();
	gpMarioOriginal->mAttributes.mGainHelmetFlwCamera = true;
}

void CodeContainer::pauseTimers(Code::FuncReset f) {
    // all the logic for this is in the chaos engine itself
}

void CodeContainer::changeMusic(Code::FuncReset f) {

	static bool execOnce = true;

	if (f == Code::FuncReset::TRUE) {
        execOnce = true;
        return;
	}

	if (execOnce) {
		
		for (int i = 0; i < 3; i++) {
            MSBgm::stopTrackBGM(i, 0);
            //OSReport("-> %d\n", i);
        }

		u32 track = 0x80010000 + (rand() % 0x2e) + 1;
        OSReport("-> Track: %x\n", track);

		MSBgm::startBGM(track);

		execOnce = false;
	}	
}


pp::togglable_ppc_bl offsetMarioPatch(SMS_PORT_REGION(0x80245b14, 0, 0, 0), (void *)codeContainer.offsetMario, false);
void CodeContainer::offsetMarioToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !offsetMarioPatch.is_enabled())
        offsetMarioPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        offsetMarioPatch.disable();
}

void CodeContainer::offsetMario(J3DTransformInfo &transformInfo, Mtx mtx) {
    transformInfo.tx += 250;
    transformInfo.ty += 50;
    transformInfo.tz += 250;
    J3DGetTranslateRotateMtx(transformInfo, mtx);
}

pp::togglable_ppc_bl reverseMarioPatch(SMS_PORT_REGION(0x80245b14, 0, 0, 0), (void *)codeContainer.reverseMario, false);
void CodeContainer::reverseMarioToggle(Code::FuncReset f) {
    if (f == Code::FuncReset::FALSE && !reverseMarioPatch.is_enabled())
        reverseMarioPatch.enable();
    else if (f == Code::FuncReset::TRUE)
        reverseMarioPatch.disable();
}

void CodeContainer::reverseMario(J3DTransformInfo &transformInfo, Mtx mtx) {
    transformInfo.ry += 32768;
    J3DGetTranslateRotateMtx(transformInfo, mtx);
}

pp::auto_patch fakeDeathPatch1(SMS_PORT_REGION(0x8024314c, 0, 0, 0), NOP, false);
pp::auto_patch fakeDeathPatch2(SMS_PORT_REGION(0x80032630, 0, 0, 0), 0x38600001, false);
void CodeContainer::fakeDeath(Code::FuncReset f) {

	static bool execOnce = true;
    static u32 stageMusic;

	if (f == Code::FuncReset::TRUE) {		
        execOnce = true;
        gpMarioOriginal->mState = TMario::STATE_IDLE;
        fakeDeathPatch1.disable();
        fakeDeathPatch2.disable();
        gpApplication.mFader->setFadeStatus(TSMSFader::EFadeStatus::FADE_OFF);
        MSBgm::startBGM(stageMusic);
        gpMarioOriginal->mHealth = gpMarioOriginal->mDeParams.mHPMax.get();
        return;
	}


    if (execOnce) {     
        fakeDeathPatch1.enable();
        fakeDeathPatch2.enable();

        gpMarDirector->mGCConsole->mConsoleStr->startAppearMiss();
        gpApplication.mFader->startWipe(TSMSFader::WipeRequest::FADE_UP_DOWN_OUT, 0.0f, 2.2f);
        MSBgm::startBGM(MSStageInfo::BGM_MISS);

		stageMusic = gStageBGM;
        ((u16 *)gpCamera->_21C)[0x62 / 2] = 1; // _27E this value triggers the fov zoom

        execOnce = false;
    }

    gpMarioOriginal->loserExec();
}

pp::auto_patch tinyMarioPatch1(SMS_PORT_REGION(0x802557ac, 0, 0, 0), NOP, false);
pp::auto_patch tinyMarioPatch2(SMS_PORT_REGION(0x802557bc, 0, 0, 0), NOP, false);
void CodeContainer::tinyMario(Code::FuncReset f) {

	if (f == Code::FuncReset::TRUE) {
        gpMarioOriginal->mModelData->mModel->mBaseScale.x = 1.0;
        gpMarioOriginal->mModelData->mModel->mBaseScale.y = 1.0;
        gpMarioOriginal->mModelData->mModel->mBaseScale.z = 1.0;

		tinyMarioPatch1.disable();
        tinyMarioPatch2.disable();

		gpMarioOriginal->mAttackRadius = 80;
		gpMarioOriginal->mAttackHeight = 50;
		gpMarioOriginal->mAttackHeight = 42;
		gpMarioOriginal->mAttackHeight = 130;

        return;
    }

	if (!tinyMarioPatch1.is_enabled()) {
        tinyMarioPatch1.enable();
        tinyMarioPatch2.enable();
    }

    gpMarioOriginal->mModelData->mModel->mBaseScale.x = 0.5;
    gpMarioOriginal->mModelData->mModel->mBaseScale.y = 0.5;
    gpMarioOriginal->mModelData->mModel->mBaseScale.z = 0.5;

	gpMarioOriginal->mAttackRadius = 40;
    gpMarioOriginal->mAttackHeight = 25;
    gpMarioOriginal->mAttackHeight = 21;
    gpMarioOriginal->mAttackHeight = 65;
}

void CodeContainer::selfieStick(Code::FuncReset f) {

    static TVec3f mTargetPos;
    static TVec3f mTranslation;
    static TVec3f projectedPos;
    
    mTargetPos = *gpMarioPos;
    mTargetPos.y += 100;
    mTranslation = gpCamera->mTranslation;

    projectedPos   = *gpMarioPos;
    f32 yawRadians = (gpMarioOriginal->mAngle.y * M_PI) / 32768.0f;

    projectedPos.x += 400 * sinf(yawRadians);
    projectedPos.z += 400 * cosf(yawRadians);    

    gpCamera->mTargetPos.set(mTargetPos);
    gpCamera->mTranslation.set(projectedPos);
}

void CodeContainer::rainbowWater(Code::FuncReset f) {
    static u8 newColor[4] = {0xB0, 0x10, 0x50, 0xFF};
    static bool rCountUp  = true;
    static bool gCountUp  = true;
    static bool bCountUp  = true;

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

    waterColor->r = newColor[0];
    waterColor->g = newColor[1];
    waterColor->b = newColor[2];
    waterColor->a = newColor[3];
}

bool isMarioInCam = true;
TVec3f currentCoords;

pp::auto_patch outOfBodyPatch(SMS_PORT_REGION(0x8023793c, 0, 0, 0), NOP, false);
pp::togglable_ppc_b outOfBodyViewCheckPatch(SMS_PORT_REGION(0x80217fc4, 0, 0, 0), (void *)codeContainer.outOfBodyViewCheck, false);
void CodeContainer::outOfBody(Code::FuncReset f) { 
    static bool execOnce = true;

	if (f == Code::FuncReset::TRUE) {
        outOfBodyPatch.disable();
        outOfBodyViewCheckPatch.disable();
        execOnce = true;
        return;
	}

    if (execOnce) {
        currentCoords = *gpMarioPos;
        execOnce = false;
    }

    if (!isMarioInCam) {
        TVec3f dif = *gpMarioPos;
        dif.sub(currentCoords);
        dif.normalize();
        dif.scale(30.0);
        currentCoords.add(dif);

        dif = *gpMarioPos;
        dif.sub(currentCoords);
        s16 yaw = ((atan2f(dif.x, dif.z) * 32768.0f) / M_PI);
        f32 horizontalDistance = sqrtf(dif.x * dif.x + dif.z * dif.z);
        s16 pitch = ((atan2f(horizontalDistance, dif.y) * 32768.0f) / M_PI) - 16384.0f;

        Mtx newMtx;
        J3DTransformInfo transformInfo = {1.0, 1.0, 1.0, pitch, yaw, 
            gpMarioOriginal->mAngle.z, currentCoords.x, currentCoords.y, currentCoords.z};
        J3DGetTranslateRotateMtx(transformInfo, newMtx);
        PSMTXCopy(newMtx, gpMarioOriginal->mModelData->mModel->mBaseMtx);
        gpMarioOriginal->mModelData->mModel->calc();
    }

	outOfBodyPatch.enable();
    outOfBodyViewCheckPatch.enable();
}

void CodeContainer::outOfBodyViewCheck() {
    JDrama::TGraphics *graphics;
    SMS_FROM_GPR(31, graphics);

    SetViewFrustumClipCheckPerspective(gpCamera->mProjectionFovy, gpCamera->mProjectionAspect,
                                       ((f32 *)graphics)[0xe8 / 4], 10000.0);

    if (ViewFrustumClipCheck(graphics, (Vec *)(&currentCoords), 200.0f)) {
        isMarioInCam = true;
    }
    else
        isMarioInCam = false;
}