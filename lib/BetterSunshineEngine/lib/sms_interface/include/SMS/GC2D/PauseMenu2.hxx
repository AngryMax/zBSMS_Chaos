#pragma once

#include <Dolphin/types.h>
#include <JSystem/JDrama/JDRViewObj.hxx>
#include <SMS/GC2D/CardSave.hxx>

class TPauseMenu2 : public JDrama::TViewObj {
public:
    TPauseMenu2();
    ~TPauseMenu2();

    u32 _10[0x108 / 4];
    TCardSave *mCardSave; // _118
};