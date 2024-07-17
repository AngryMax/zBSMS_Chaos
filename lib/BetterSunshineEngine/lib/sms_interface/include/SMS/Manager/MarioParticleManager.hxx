#pragma once

#include <Dolphin/types.h>
#include <JSystem/JDrama/JDRGraphics.hxx>
#include <JSystem/JDrama/JDRViewObj.hxx>
#include <JSystem/JGadget/Allocator.hxx>
#include <JSystem/JGadget/List.hxx>
#include <JSystem/JParticle/JPABaseEmitter.hxx>
#include <JSystem/JSupport/JSUMemoryStream.hxx>
#include <SMS/Enemy/EffectObjBase.hxx>
#include <SMS/Strategic/HitActor.hxx>
#include <SMS/Strategic/ObjChara.hxx>

/* Size -- 0x34 */
class TMarioParticleManager : public JDrama::TViewObj {
public:
    struct TInfo {};

    TMarioParticleManager(const char *);
    virtual ~TMarioParticleManager();

    virtual void perform(u32, JDrama::TGraphics *) override;

    TInfo *createEffectInfoAry(int);
    JPABaseEmitter *emit(s32 effect, const TVec3f *, u8, const void *);
    JPABaseEmitter *emitAndBindToMtx(s32 effect, Mtx matrix, u8, const void *);
    JPABaseEmitter *emitAndBindToMtxPtr(s32 effect, Mtx matrix, u8, const void *);
    JPABaseEmitter *emitAndBindToPosPtr(s32 effect, const TVec3f *, u8, const void *);
    JPABaseEmitter *emitAndBindToSRTMtxPtr(s32 effect, Mtx matrix, u8, const void *);
    JPABaseEmitter *
    emitParticleCallback(s32 effect, const TVec3f *, u8,
                         void * /*JPACallBackBase2<JPABaseEmitter *, JPABaseParticle *> **/,
                         const void *);
    void emitTry(s32 effect, TInfo *info, u8);
    JPABaseEmitter *emitWithRotate(s32 effect, const TVec3f *, s16 x, s16 y, s16 z, u8,
                                   const void *);
    s32 getAvailableIdx(s32 effect, u8, const void *);
};

extern TMarioParticleManager *gpMarioParticleManager;