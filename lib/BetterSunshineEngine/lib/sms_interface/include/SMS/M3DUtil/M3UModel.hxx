#pragma once

#include <Dolphin/types.h>
#include <JSystem/J3D/J3DModel.hxx>
#include <JSystem/JDrama/JDRGraphics.hxx>

class M3UMtxCalcSetInfo {};

class M3UModel {
public:
    virtual void changeMtxCalcAnmTransform(int, u8);
    virtual void changeAnmTexPattern(int, u8);
    virtual void setMtxCalc(const M3UMtxCalcSetInfo &);
    virtual void updateIn();
    virtual void updateOut();
    virtual void entryIn();
    virtual void entryOut();

    void perform(u32, JDrama::TGraphics *);
    void updateInMotion();
    void updateInTexPatternAnm();

    void *_04;                 // 0x0000
    J3DModel *mModel;          // 0x0008
    J3DFrameCtrl *mFrameCtrl;  // 0x000C
    u32 _10;
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 _20;
    u16 *_24;
    u32 _28;
    u32 _2C;
    u32 _30;
    u32 _34;
    u32 _38;
    u32 mLightID;  // _3C
    u8 _40;
    u32 mLightType;  // _44
};

class M3UModelCommon {
public:
    virtual M3UMtxCalcSetInfo *getMtxCalc(const M3UMtxCalcSetInfo &) const;
};