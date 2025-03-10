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

#include <BetterSMS/game.hxx>
#include <BetterSMS/module.hxx>
#include <BetterSMS/settings.hxx>
#include <BetterSMS/stage.hxx>
#include <BetterSMS/memory.hxx>
//#include <BetterSMS/p_settings.hxx>


#include "codes.hxx"

#define DEV_MODE false

// color definitions have been moved to codes.hxx :)

CodeContainer codeContainer;
float currentTime;

pp::auto_patch skippableCutscenesPatch1(SMS_PORT_REGION(0x802B5EF4, 0, 0, 0), 0x38600001, false);
pp::auto_patch skippableCutscenesPatch2(SMS_PORT_REGION(0x802B5E8C, 0, 0, 0), 0x38600001, false);

#if DEV_MODE
#else
// replaces the bettersms patch that allows the player to toggle the ui with dpad down back with the vanilla asm
pp::auto_patch removeToggleUIButton(SMS_PORT_REGION(0x80140844, 0, 0, 0), 0x548007ff, true);
#endif