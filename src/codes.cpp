#include "codes.hxx"

SMS_PATCH_BL(SMS_PORT_REGION(0x8027bedc, 0, 0, 0), CodeContainer::pauseWater);
void CodeContainer::pauseWater(TModelWaterManager *modelWaterManager) { 
    static u8 codeID = 0; 

    if (codeContainer.isCodeActive(codeID)) {
        return;
    } else {
        modelWaterManager->move();
    }
}


//SMS_PATCH_BL(SMS_PORT_REGION(0x80349a6c, 0, 0, 0), CodeContainer::dummyThiccMario);
void CodeContainer::dummyThiccMario() {
    static u32 codeID = 1;

    if (codeContainer.isCodeActive(codeID)) {
        // do nothing
    } else {
        
    }
}

void CodeContainer::setMusicVol(Code::FuncReset f) {
    /*float vol = 0.75;    

    if (f == Code::FuncReset::TRUE) {
        vol = 0.75;
        OSReport("-> FuncReset is TRUE!\n");
    } else if (f == Code::FuncReset::FALSE) {
        vol = 5;
        OSReport("-> FuncReset is FALSE!\n");
    }

    u32 *trackOne = static_cast<u32 *>(MSBgm::smBgmInTrack[0]);
    if ((u32)trackOne > 0x80000000)
        trackOne = (u32 *)((trackOne + 0x5)[0]);
    if ((u32)trackOne > 0x80000000)
        trackOne = (u32 *)((trackOne + 0xE)[0]);

    u32 *trackTwo = static_cast<u32 *>(MSBgm::smBgmInTrack[1]);
    if ((u32)trackTwo > 0x80000000)
        trackTwo = (u32 *)((trackTwo + 0x5)[0]);
    if ((u32)trackTwo > 0x80000000)
        trackTwo = (u32 *)((trackTwo + 0xE)[0]);

    u32 *trackThree = static_cast<u32 *>(MSBgm::smBgmInTrack[2]);
    if ((u32)trackThree > 0x80000000)
        trackThree = (u32 *)((trackThree + 0x5)[0]);
    if ((u32)trackThree > 0x80000000)
        trackThree = (u32 *)((trackThree + 0xE)[0]);

    if ((u32)trackOne > 0x80000000)
        if ((trackOne[0]) > 0x80000000)
            ((float *)trackOne[0] + 0x66)[0] = vol;
    if ((u32)trackTwo > 0x80000000)
        if ((trackTwo[0]) > 0x80000000)
            ((float *)trackTwo[0] + 0x66)[0] = vol;
    if ((u32)trackThree > 0x80000000)
        if ((trackThree[0]) > 0x80000000)
            ((float *)trackThree[0] + 0x66)[0] = vol;

    MSBgm::smMainVolume = vol;

    for (int i = 0; i < 3; i++) {
        MSBgm::setTrackVolume(i, 10, 3, vol);
    }*/

}

void CodeContainer::giveCoins(Code::FuncReset f) {

    static bool execOnce = true;

	u32 *i = (u32 *)0x80349a6c;
    i[0]   = 0x60000000;

	if (f == Code::FuncReset::TRUE) {
        OSReport("-> FuncReset is TRUE!\n");
        execOnce = true;

        i[0] = 0xf1850000;
        return;
    }

	// give the coins lol
    if (execOnce) {
        TFlagManager::smInstance->setFlag(0x40002, TFlagManager::smInstance->getFlag(0x40002) + 99);
        execOnce = false;
    }
}