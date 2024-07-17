#include <Dolphin/MTX.h>
#include <Dolphin/types.h>

#include <JSystem/JDrama/JDRGraphics.hxx>
#include <JSystem/JDrama/JDRViewObj.hxx>
#include <JSystem/JGadget/Vector.hxx>
#include <JSystem/JSupport/JSUMemoryStream.hxx>

class TCubeManagerBase : public JDrama::TViewObj {
public:
    TCubeManagerBase(const char *name, const char *);
    TCubeManagerBase(const char *name, u8);
    ~TCubeManagerBase() override;

    void load(JSUMemoryInputStream &) override;
    void perform(u32, JDrama::TGraphics *) override;

    void calcPointInCubeRatio(const Vec &, s32, f32 *, f32 *, f32 *) const;
    s32 getDataNo(s32) const;
    s32 getInCubeNo(const Vec &pos) const;
    bool isInCube(const Vec &pos, s32) const;

    u8 mCubeMax;
    JGadget::TVector_pointer_void *mCubes;
    const char *_18;
};

extern TCubeManagerBase *gpCubeMirror;
extern TCubeManagerBase *gpCubeCamera;
extern TCubeManagerBase *gpCubeWire;
extern TCubeManagerBase *gpCubeStream;
extern TCubeManagerBase *gpCubeShadow;
extern TCubeManagerBase *gpCubeArea;
extern TCubeManagerBase *gpCubeFastA;
extern TCubeManagerBase *gpCubeFastB;
extern TCubeManagerBase *gpCubeFastC;
extern TCubeManagerBase *gpCubeSoundChange;
extern TCubeManagerBase *gpCubeSoundEffect;