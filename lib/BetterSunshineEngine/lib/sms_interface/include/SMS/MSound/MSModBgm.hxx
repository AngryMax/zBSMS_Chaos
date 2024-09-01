#pragma once

#include <Dolphin/types.h>
#include <JSystem/JAudio/JAISound.hxx>

class MSModBgm {
public:
    static void changeTempo(u8, u8);
    void loop();
    JAISound *modBgm(u8, u8);
};