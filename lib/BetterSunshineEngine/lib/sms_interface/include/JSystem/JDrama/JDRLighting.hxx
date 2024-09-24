#pragma once

#include <Dolphin/types.h>
#include <JSystem/JDrama/JDRGraphics.hxx>
#include <JSystem/JDrama/JDRViewObj.hxx>
#include <JSystem/JSupport/JSUMemoryStream.hxx>
#include <JSystem/JDrama/JDRAmbColor.hxx>
#include <JSystem/JDrama/JDRPlacement.hxx>
#include <JSystem/JStage/JSGLight.hxx>

namespace JDrama {

    class TLight : TPlacement, JStage::TLight {
    public:
        TLight(char *);
        virtual ~TLight();

        // vtable _20
        u32 _24;
        u32 _28;
        u32 _2C;
        u8 r; // _30
        u8 g; // _31
        u8 b; // _32
        u8 a; // _33
        u8 _[0x48];
        
    };

    class TIdxLight : public TLight {
    public:
        TIdxLight();
        virtual ~TIdxLight();
    };

	class TAmbAry : public TViewObj {
    public:
        virtual ~TAmbAry();

		virtual void load(JSUMemoryInputStream &stream) override;
        virtual void perform(u32, TGraphics *) override;
        virtual TNameRef *searchF(u16, const char *) override;

        void setAmbNum(s32 num);

        TAmbColor *mAmbColorAry;
        s32 mAmbColorCount;
	};

    class TLightAry : public TViewObj {
    public:
        virtual ~TLightAry();

        virtual void load(JSUMemoryInputStream &stream) override;
        virtual void perform(u32, TGraphics *) override;
        virtual TNameRef *searchF(u16, const char *) override;

        void setLightNum(s32 num);

        TIdxLight *mLightColorAry;
        s32 mLightColorCount;
    };

} // namespace JDrama