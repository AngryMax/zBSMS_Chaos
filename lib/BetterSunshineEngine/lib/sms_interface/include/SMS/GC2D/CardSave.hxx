#pragma once

#include <Dolphin/types.h>

#include <JSystem/JDrama/JDRViewObj.hxx>
#include <JSystem/J2D/J2DTextBox.hxx>

#include <SMS/GC2D/CardLoad.hxx>
#include <SMS/Player/MarioGamePad.hxx>

class TCardSave : public JDrama::TViewObj {
public:
    TCardSave();
    ~TCardSave();

    virtual void load(JSUMemoryInputStream &) override;
    virtual void perform(u32, JDrama::TGraphics *) override;

    u32 changeMode(s32);
    s8 drawMessage(TEProgress);
    s8 drawMessageBM(TEProgress);
    void execMovement_();
    u8 getNextState();
    void init(int promptId);
    void initData(TMarioGamePad *);
    void setMessageC(J2DTextBox *, s32, u32);
    s8 waitForAnyKey(TEProgress);
    s8 waitForAnyKeyBM(TEProgress);
    s8 waitForChoice(TEProgress, TEProgress, s8);
    s8 waitForChoiceBM(TEProgress, TEProgress, s8);
    s8 waitForSelect2(TEProgress, TEProgress);
    s8 waitForSelect3(TEProgress, TEProgress, TEProgress);
    s8 waitForSelectOver();
    s8 waitForStop(TEProgress);

    u32 _10[0x180 / 4];
    J2DTextBox *mTextBox; // _190
    u32 _194[0x178 / 4];
    u32 mPromptId; // _308
    u32 _30C[0x18 / 4];
};