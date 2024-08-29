#include <SMS/MSound/MSBGM.hxx>

#include "codes.hxx"

void CodeContainer::pauseWater(Code::FuncReset) { OSReport("\n\n -> PAUSE WATER!!!! \n\n <-"); }

void CodeContainer::setMusicVol(Code::FuncReset) {

    static int codeIndex = 14;

    if (codeData[codeIndex].isActive == false &&) {  // returns if code isnt active
        return;
    }

    u32 *trackOne = static_cast<u32 *>(MSBgm::smBgmInTrack[0]);
    if (*trackOne > 0x80000000)
        *trackOne = (trackOne + 0x5)[0];
    if (*trackOne > 0x80000000)
        *trackOne = (trackOne + 0xE)[0];

    u32 *trackTwo = static_cast<u32 *>(MSBgm::smBgmInTrack[1]);
    if (*trackTwo > 0x80000000)
        *trackTwo = (trackTwo + 0x5)[0];
    if (*trackTwo > 0x80000000)
        *trackTwo = (trackTwo + 0xE)[0];

    u32 *trackThree = static_cast<u32 *>(MSBgm::smBgmInTrack[2]);
    if (*trackThree > 0x80000000)
        *trackThree = (trackThree + 0x5)[0];
    if (*trackThree > 0x80000000)
        *trackThree = (trackThree + 0xE)[0];

    float *smMainVolume = (float *)(0x8040c1c0);

    if (trackOne > 0x80000000)
        if ((trackOne[0]) > 0x80000000)
            ((float *)trackOne[0] + 0x66)[0] = vol;
    if (trackTwo > 0x80000000)
        if ((trackTwo[0]) > 0x80000000)
            ((float *)trackTwo[0] + 0x66)[0] = vol;
    if (trackThree > 0x80000000)
        if ((trackThree[0]) > 0x80000000)
            ((float *)trackThree[0] + 0x66)[0] = vol;
    smMainVolume[0] = vol;

    for (int i = 0; i < 3; i++) {
        MSBgm::setTrackVolume(i, 10, 3, vol);
    }

}