#pragma once

#include <Dolphin/MTX.h>
#include <Dolphin/types.h>
#include <JSystem/JDrama/JDRGraphics.hxx>

class TMario;

class TMarioCap {
public:
    TMarioCap(TMario *);

    virtual void perform(u32, JDrama::TGraphics *);

    void createMirrorModel();
    void mtxEffectHide();
    void mtxEffectShow();
};

extern const char *cDirtyFileName;
extern const char *cDirtyTexName;