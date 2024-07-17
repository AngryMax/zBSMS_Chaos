#pragma once

#include <Dolphin/types.h>
#include <JUtility/JUTGamePad.hxx>

struct TMarioControllerWork {
    enum Buttons {
        R = 0x20,
        A = 0x100,
        B = 0x200,
        L = 0x4000,
    };

    s16 mStickHS16;
    s16 mStickVS16;
    Buttons mInput;
    Buttons mFrameInput;
    u8 mAnalogRU8;
    u8 mAnalogLU8;
    f32 mStickH;
    f32 mStickV;
    f32 mStickDist;
    f32 mAnalogL;
    f32 mAnalogR;
};

class TMarioGamePad : public JUTGamePad {
public:
    TMarioGamePad(EPadPort port) : JUTGamePad(port) {}
    virtual ~TMarioGamePad();

    void onNeutralMarioKey();
    void read();
    void reset();
    void updateMeaning();

    u32 _A4;
    f32 _A8;
    f32 _AC;
    f32 _B0;
    f32 _B4;
    f32 _B8;
    f32 _BC;
    f32 mStickX;  // _C0
    f32 mStickY;  // _C4
    f32 _C8;
    f32 _CC;
    u32 mMeaning;
    u32 mFrameMeaning;
    u32 _D8;
    u16 _DC;
    u16 _DE;
    u16 _E0;

    struct {
        u16 _00         : 8;
        bool mDisable   : 1;
        u8 _01          : 5;
        bool mReadInput : 1;
        u8 _02          : 1;
    } mState;  // 0x00E2

    u16 _E4;
    u16 _E6;  // padding?
    u32 _E8;
    u32 _EC;  // padding?

    static u16 mResetFlag;
};