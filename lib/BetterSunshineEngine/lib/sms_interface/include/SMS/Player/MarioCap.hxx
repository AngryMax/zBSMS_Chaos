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

    u32 _04;
    TMario *mario;              // 0x0008
    J3DModel *mCurrentCapModel;  // 0x000C
    J3DModel *mCap1Model;        // 0x0010
    J3DModel *mCap3Model;        // 0x0014
    J3DModel *mDiverHelmModel;   // 0x0018
    J3DModel *mGlass1Model;      // 0x001C
    u32 _20;
    u32 _24;
    u32 _28;
    u32 _2C;
    u32 *mTrembleModelEffect;    // 0x0030 TTrembleModelEffect *
    f32 _34;
};

extern const char *cDirtyFileName;
extern const char *cDirtyTexName;