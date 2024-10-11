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

#define DEV_MODE true

// color definitions have been moved to codes.hxx :)

CodeContainer codeContainer;
float currentTime;