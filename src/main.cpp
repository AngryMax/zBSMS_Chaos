#include <Dolphin/CARD.h>
#include <Dolphin/OS.h>
#include <Dolphin/math.h>
#include <Dolphin/string.h>
#include <Dolphin/types.h>

#include <SMS/System/Application.hxx>
#include <SMS/macros.h>
#include <SMS/Player/Mario.hxx>

#include <BetterSMS/game.hxx>
#include <BetterSMS/module.hxx>
#include <BetterSMS/settings.hxx>
#include <BetterSMS/stage.hxx>

/*
/ Settings
*/

static const u8 sSaveBnr[] = {
    0x09, 0x00, 0x00, 0x60, 0x00, 0x20, 0x00, 0x00, 0x01, 0x02, 0x00, 0x88, 0x00, 0x00, 0x0c, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x06, 0x07, 0x07, 0x07, 0x08, 0x02, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x07, 0x07, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
    0x00, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x12, 0x06, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0x09, 0x06, 0x02, 0x00, 0x00, 0x00, 0x0a, 0x07, 0x13, 0x07, 0x02, 0x00, 0x00, 0x02, 0x06, 0x09,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02,
    0x07, 0x07, 0x0b, 0x00, 0x02, 0x0a, 0x07, 0x07, 0x09, 0x09, 0x07, 0x14, 0x0a, 0x09, 0x09, 0x09,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0a, 0x09, 0x08, 0x00, 0x00, 0x00, 0x12, 0x0a, 0x09,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00,
    0x07, 0x07, 0x07, 0x09, 0x07, 0x08, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x13, 0x06, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x16, 0x0c, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x0f, 0x10, 0x11, 0x00, 0x00, 0x00, 0x00, 0x17, 0x18, 0x19, 0x1a, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x07, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x09, 0x09,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x07, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08,
    0x09, 0x09, 0x07, 0x07, 0x09, 0x09, 0x09, 0x0a, 0x09, 0x09, 0x08, 0x05, 0x1f, 0x09, 0x09, 0x07,
    0x06, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x06, 0x09, 0x09, 0x09, 0x07, 0x07, 0x07, 0x09,
    0x1f, 0x09, 0x09, 0x09, 0x0a, 0x08, 0x24, 0x08, 0x09, 0x09, 0x09, 0x09, 0x07, 0x07, 0x07, 0x09,
    0x13, 0x08, 0x00, 0x00, 0x00, 0x0a, 0x09, 0x09, 0x1f, 0x02, 0x00, 0x00, 0x02, 0x06, 0x09, 0x09,
    0x02, 0x00, 0x00, 0x00, 0x0a, 0x09, 0x09, 0x09, 0x14, 0x00, 0x00, 0x02, 0x06, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x0a, 0x06, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x07, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x07, 0x09, 0x09, 0x09, 0x09, 0x07, 0x09, 0x09,
    0x13, 0x06, 0x02, 0x00, 0x0b, 0x07, 0x09, 0x09, 0x13, 0x07, 0x05, 0x00, 0x0a, 0x13, 0x09, 0x09,
    0x09, 0x13, 0x08, 0x00, 0x25, 0x13, 0x09, 0x09, 0x09, 0x13, 0x06, 0x08, 0x06, 0x13, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0a, 0x02, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0a,
    0x09, 0x0a, 0x0a, 0x09, 0x09, 0x09, 0x09, 0x09, 0x06, 0x02, 0x01, 0x0a, 0x13, 0x09, 0x09, 0x09,
    0x00, 0x16, 0x1b, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x20, 0x21, 0x22, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x03, 0x26, 0x27, 0x28, 0x00, 0x03, 0x29, 0x08, 0x2b, 0x0f, 0x2c, 0x2d, 0x26, 0x26, 0x2d,
    0x1c, 0x1d, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x23, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x19, 0x2a, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x2d, 0x2e, 0x00, 0x00, 0x00, 0x0c, 0x2f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x09, 0x09,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x09, 0x09,
    0x09, 0x09, 0x05, 0x12, 0x1f, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0a, 0x06, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x07, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x07, 0x07,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x13, 0x09, 0x09, 0x09, 0x09, 0x07, 0x07, 0x07, 0x06,
    0x07, 0x09, 0x09, 0x09, 0x0a, 0x08, 0x24, 0x12, 0x0a, 0x1f, 0x09, 0x09, 0x07, 0x07, 0x07, 0x07,
    0x06, 0x30, 0x00, 0x0a, 0x09, 0x09, 0x09, 0x07, 0x02, 0x00, 0x02, 0x06, 0x09, 0x09, 0x09, 0x0a,
    0x02, 0x01, 0x0a, 0x09, 0x09, 0x09, 0x09, 0x24, 0x07, 0x07, 0x07, 0x09, 0x09, 0x09, 0x0a, 0x01,
    0x0a, 0x06, 0x09, 0x09, 0x07, 0x0a, 0x06, 0x09, 0x02, 0x0a, 0x09, 0x09, 0x0b, 0x02, 0x0a, 0x09,
    0x00, 0x02, 0x0a, 0x0b, 0x00, 0x00, 0x0a, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x09,
    0x09, 0x13, 0x07, 0x25, 0x1f, 0x13, 0x09, 0x09, 0x09, 0x09, 0x09, 0x07, 0x07, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x13, 0x06, 0x06, 0x07, 0x09, 0x09, 0x09, 0x09, 0x13, 0x1f, 0x02, 0x05, 0x07, 0x13,
    0x09, 0x0a, 0x12, 0x0a, 0x09, 0x09, 0x09, 0x07, 0x09, 0x07, 0x07, 0x09, 0x09, 0x09, 0x09, 0x0a,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x40, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x07, 0x45,
    0x05, 0x0c, 0x29, 0x31, 0x2a, 0x32, 0x32, 0x19, 0x01, 0x11, 0x1b, 0x32, 0x0f, 0x3a, 0x3b, 0x3c,
    0x2f, 0x41, 0x42, 0x43, 0x3a, 0x0f, 0x2d, 0x3e, 0x42, 0x2c, 0x46, 0x3a, 0x47, 0x48, 0x49, 0x4a,
    0x33, 0x34, 0x35, 0x0e, 0x22, 0x22, 0x36, 0x37, 0x18, 0x3c, 0x3c, 0x18, 0x2c, 0x3d, 0x3e, 0x3f,
    0x3d, 0x2a, 0x3c, 0x33, 0x2a, 0x3e, 0x44, 0x00, 0x4b, 0x4c, 0x2d, 0x4d, 0x19, 0x4e, 0x0e, 0x00,
    0x38, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x09, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x13, 0x13, 0x09, 0x09, 0x09, 0x07, 0x08, 0x02, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08, 0x00, 0x00,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x06, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x13, 0x08, 0x00, 0x07, 0x09, 0x07, 0x14, 0x0a, 0x07, 0x24, 0x00,
    0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x09, 0x09, 0x13, 0x06, 0x02, 0x00, 0x02, 0x0a, 0x07, 0x07, 0x07, 0x08, 0x00, 0x00, 0x00, 0x02,
    0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x4f, 0x11, 0x0a, 0x07, 0x0a, 0x05, 0x02, 0x02, 0x00, 0x03,
    0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x26, 0x26, 0x50, 0x3b, 0x20, 0x30, 0x16, 0x51, 0x3f, 0x46, 0x29, 0x0f, 0x11, 0x54, 0x35, 0x29,
    0x57, 0x49, 0x0e, 0x3b, 0x0f, 0x47, 0x4e, 0x11, 0x59, 0x3f, 0x01, 0x04, 0x34, 0x3c, 0x33, 0x0f,
    0x12, 0x52, 0x2a, 0x19, 0x3a, 0x53, 0x00, 0x00, 0x02, 0x55, 0x3e, 0x3c, 0x56, 0x28, 0x00, 0x00,
    0x58, 0x4c, 0x2a, 0x4d, 0x56, 0x41, 0x57, 0x00, 0x51, 0x2c, 0x19, 0x56, 0x4d, 0x2c, 0x37, 0x29,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01,
    0x06, 0x07, 0x07, 0x07, 0x08, 0x00, 0x12, 0x06, 0x07, 0x5f, 0x5d, 0x5f, 0x5f, 0x14, 0x5e, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x07, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x5d, 0x12, 0x00, 0x00, 0x01, 0x24,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00,
    0x12, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05, 0x5e, 0x07, 0x5d, 0x5d, 0x5d, 0x5d, 0x5d, 0x0a,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02,
    0x00, 0x00, 0x00, 0x05, 0x06, 0x07, 0x07, 0x07, 0x01, 0x00, 0x60, 0x5f, 0x5d, 0x5d, 0x5d, 0x5d,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02,
    0x0b, 0x12, 0x00, 0x00, 0x0b, 0x07, 0x07, 0x07, 0x5d, 0x5d, 0x0b, 0x12, 0x60, 0x5d, 0x5d, 0x5d,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x08, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x5d, 0x60, 0x60, 0x07, 0x07, 0x07, 0x07, 0x60,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x54, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x0b, 0x07, 0x07, 0x5d, 0x0b, 0x00, 0x00, 0x00, 0x60, 0x5f, 0x5f, 0x5f, 0x0a, 0x00, 0x00, 0x00,
    0x3f, 0x41, 0x1c, 0x00, 0x5a, 0x0f, 0x34, 0x5b, 0x11, 0x20, 0x1c, 0x0b, 0x01, 0x03, 0x0e, 0x1a,
    0x00, 0x00, 0x00, 0x08, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x60, 0x5f, 0x5d, 0x5d, 0x5d,
    0x18, 0x34, 0x4d, 0x56, 0x56, 0x53, 0x0e, 0x11, 0x04, 0x5a, 0x17, 0x5c, 0x0e, 0x00, 0x00, 0x00,
    0x5e, 0x5e, 0x5e, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x5d, 0x61, 0x12, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x65, 0x63,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x54, 0x67, 0x71,
    0x63, 0x63, 0x63, 0x63, 0x63, 0x60, 0x5f, 0x5f, 0x63, 0x66, 0x67, 0x67, 0x67, 0x63, 0x63, 0x63,
    0x67, 0x6a, 0x6a, 0x6a, 0x6a, 0x6a, 0x6a, 0x67, 0x71, 0x71, 0x4b, 0x71, 0x71, 0x71, 0x71, 0x4b,
    0x5f, 0x5f, 0x5f, 0x24, 0x00, 0x00, 0x5e, 0x5f, 0x63, 0x63, 0x63, 0x58, 0x00, 0x01, 0x62, 0x63,
    0x67, 0x67, 0x67, 0x6c, 0x00, 0x01, 0x62, 0x67, 0x70, 0x70, 0x70, 0x6a, 0x65, 0x01, 0x45, 0x6a,
    0x5f, 0x5f, 0x5f, 0x63, 0x63, 0x5f, 0x5f, 0x5f, 0x63, 0x63, 0x67, 0x67, 0x67, 0x67, 0x63, 0x63,
    0x67, 0x67, 0x67, 0x68, 0x45, 0x67, 0x67, 0x67, 0x6a, 0x4b, 0x6d, 0x02, 0x54, 0x45, 0x70, 0x70,
    0x0b, 0x12, 0x5e, 0x63, 0x5f, 0x63, 0x63, 0x63, 0x63, 0x68, 0x62, 0x63, 0x66, 0x67, 0x67, 0x67,
    0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x6a, 0x6a, 0x6a, 0x4b, 0x4b, 0x71, 0x6d, 0x72,
    0x5f, 0x5f, 0x5f, 0x60, 0x5e, 0x63, 0x5f, 0x63, 0x63, 0x63, 0x63, 0x60, 0x69, 0x63, 0x63, 0x63,
    0x67, 0x67, 0x67, 0x62, 0x6b, 0x67, 0x67, 0x67, 0x45, 0x70, 0x6a, 0x6a, 0x6a, 0x6a, 0x6a, 0x6a,
    0x63, 0x60, 0x61, 0x5f, 0x5f, 0x5f, 0x5f, 0x60, 0x67, 0x68, 0x68, 0x63, 0x63, 0x63, 0x63, 0x61,
    0x67, 0x6c, 0x65, 0x6d, 0x67, 0x67, 0x67, 0x68, 0x6e, 0x6f, 0x01, 0x68, 0x6a, 0x67, 0x6a, 0x68,
    0x60, 0x63, 0x63, 0x63, 0x60, 0x00, 0x00, 0x00, 0x68, 0x67, 0x67, 0x67, 0x40, 0x00, 0x00, 0x00,
    0x68, 0x67, 0x6a, 0x6e, 0x68, 0x00, 0x00, 0x00, 0x6d, 0x6e, 0x6e, 0x71, 0x68, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x02, 0x64, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x58, 0x6a, 0x67, 0x67, 0x66, 0x67,
    0x00, 0x00, 0x6f, 0x70, 0x6a, 0x6a, 0x45, 0x68, 0x00, 0x00, 0x6f, 0x71, 0x4b, 0x4b, 0x4b, 0x6a,
    0x63, 0x63, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x63, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x6c, 0x6c, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6a, 0x6a, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x73, 0x71, 0x71, 0x00, 0x00, 0x00, 0x00, 0x54, 0x6a, 0x71, 0x71,
    0x00, 0x00, 0x00, 0x01, 0x79, 0x75, 0x75, 0x75, 0x00, 0x00, 0x00, 0x24, 0x64, 0x7c, 0x7c, 0x7c,
    0x71, 0x4b, 0x68, 0x4b, 0x71, 0x71, 0x74, 0x68, 0x71, 0x6c, 0x02, 0x73, 0x71, 0x75, 0x0b, 0x12,
    0x75, 0x12, 0x00, 0x24, 0x79, 0x6c, 0x00, 0x01, 0x6c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x6a, 0x71, 0x71, 0x71, 0x58, 0x58, 0x67, 0x71, 0x67, 0x71, 0x71, 0x71, 0x68, 0x73, 0x75, 0x71,
    0x79, 0x75, 0x75, 0x75, 0x75, 0x6c, 0x58, 0x79, 0x79, 0x7c, 0x7c, 0x7c, 0x7c, 0x58, 0x00, 0x12,
    0x71, 0x71, 0x71, 0x6f, 0x72, 0x73, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x74, 0x71, 0x71, 0x71,
    0x75, 0x75, 0x7a, 0x7a, 0x71, 0x71, 0x71, 0x71, 0x79, 0x7c, 0x7c, 0x75, 0x75, 0x75, 0x75, 0x7a,
    0x71, 0x74, 0x71, 0x71, 0x71, 0x71, 0x6f, 0x58, 0x71, 0x6d, 0x67, 0x71, 0x76, 0x76, 0x77, 0x73,
    0x71, 0x7b, 0x73, 0x71, 0x71, 0x71, 0x71, 0x71, 0x75, 0x6c, 0x6b, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a,
    0x45, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71,
    0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x7a, 0x7a, 0x75, 0x6a, 0x6a, 0x75, 0x7a, 0x7a,
    0x71, 0x6f, 0x54, 0x62, 0x70, 0x4b, 0x70, 0x6d, 0x71, 0x45, 0x45, 0x71, 0x71, 0x71, 0x71, 0x6d,
    0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x68, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x6d, 0x12,
    0x6d, 0x71, 0x71, 0x71, 0x68, 0x00, 0x00, 0x02, 0x6d, 0x71, 0x71, 0x71, 0x45, 0x58, 0x6d, 0x71,
    0x6d, 0x71, 0x71, 0x71, 0x71, 0x74, 0x71, 0x71, 0x61, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x75,
    0x02, 0x02, 0x68, 0x71, 0x74, 0x4b, 0x4b, 0x4b, 0x71, 0x78, 0x6d, 0x71, 0x74, 0x74, 0x74, 0x6a,
    0x71, 0x6b, 0x6d, 0x75, 0x75, 0x75, 0x73, 0x7b, 0x7a, 0x6d, 0x12, 0x6d, 0x75, 0x75, 0x75, 0x75,
    0x71, 0x45, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x6c, 0x72, 0x12, 0x01, 0x00, 0x00, 0x00, 0x00, 0x6a, 0x6a, 0x6a, 0x6d, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7d, 0x7e, 0x7e, 0x7e, 0x7f, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x24, 0x82,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x24, 0x80, 0x81, 0x7c, 0x7c, 0x24, 0x00, 0x00, 0x00, 0x7d, 0x7e, 0x7e, 0x7e, 0x85, 0x00, 0x00,
    0x00, 0x01, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x12, 0x82, 0x7c, 0x7c, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x12, 0x82, 0x7e, 0x6c, 0x12, 0x02, 0x02,
    0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x6c, 0x02, 0x83, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x00, 0x00, 0x86, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7c, 0x7c, 0x84, 0x12, 0x12, 0x6d, 0x7c, 0x7c, 0x7f, 0x6c, 0x01, 0x00, 0x00, 0x02, 0x86, 0x7f,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x6c, 0x00, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x84, 0x01, 0x00,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x84, 0x7c, 0x7c, 0x7c, 0x7c, 0x7f, 0x7f, 0x7f, 0x6c, 0x7e, 0x7e, 0x7e, 0x7e, 0x86, 0x12, 0x02,
    0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7c, 0x84, 0x00, 0x6c, 0x7c, 0x7c, 0x7c, 0x7c, 0x02, 0x00, 0x00, 0x87, 0x7e, 0x7e, 0x7e, 0x7e,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7c, 0x7c, 0x7c, 0x6b, 0x12, 0x00, 0x00, 0x00, 0x7e, 0x7e, 0x7f, 0x7f, 0x84, 0x00, 0x00, 0x00,
    0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x84, 0x43, 0x88, 0x65, 0x98, 0x81, 0xb9, 0x42, 0x88, 0xa9, 0x95, 0x55, 0x99, 0xba,
    0x8c, 0xcd, 0x99, 0xbc, 0x91, 0x31, 0x95, 0x0f, 0x90, 0x60, 0x98, 0xc3, 0xa4, 0xe2, 0xe6, 0xa9,
    0xef, 0x4f, 0xa9, 0x05, 0x88, 0x86, 0x99, 0xdd, 0x90, 0xee, 0xb9, 0xcb, 0xca, 0x4e, 0xc5, 0x83,
    0xff, 0xae, 0xfb, 0x6d, 0xad, 0x23, 0xe6, 0xf2, 0xa9, 0x4a, 0xef, 0x30, 0xb1, 0x22, 0x95, 0x78,
    0xb5, 0x66, 0xf2, 0xec, 0xb9, 0xa6, 0xeb, 0x53, 0x8c, 0xc9, 0x91, 0x34, 0xe6, 0xce, 0xff, 0xf2,
    0xd2, 0x05, 0xc9, 0xc6, 0xff, 0xd5, 0xa0, 0xa0, 0xfb, 0xb4, 0xff, 0xb1, 0xd6, 0x29, 0xc5, 0xa5,
    0x80, 0x24, 0xf3, 0x0d, 0xfb, 0x71, 0xf6, 0xc9, 0xff, 0x4a, 0xda, 0xaa, 0xd1, 0xe9, 0xfb, 0xba,
    0xfb, 0xbc, 0xb9, 0xaa, 0xea, 0x45, 0xee, 0x86, 0xfb, 0x29, 0xff, 0xfc, 0xff, 0xfa, 0xda, 0x8e,
    0xa1, 0x70, 0xf3, 0x31, 0xf3, 0x55, 0xea, 0x68, 0xc6, 0x0e, 0xb6, 0x36, 0xe2, 0xad, 0xd6, 0x48,
    0xa5, 0x47, 0xd6, 0x91, 0xef, 0x9c, 0xc2, 0xbb, 0xeb, 0x7a, 0xf6, 0xc6, 0xe6, 0xeb, 0x8d, 0x11,
    0xd5, 0xe5, 0xda, 0xcd, 0xc2, 0x33, 0xda, 0x03, 0x90, 0xa7, 0xca, 0x56, 0xf2, 0x84, 0xb9, 0xcc,
    0x90, 0xc9, 0xc1, 0xa8, 0xc1, 0x62, 0xff, 0xce, 0xd5, 0xe3, 0x9d, 0xd9, 0x99, 0x96, 0xa1, 0xfa,
    0x99, 0x51, 0x9d, 0x92, 0xa9, 0xf5, 0xaa, 0x1a, 0xaa, 0x59, 0x90, 0xa8, 0xb2, 0x3a, 0xb6, 0x7a,
    0xa5, 0xb1, 0xa5, 0xb4, 0xba, 0x9b, 0xaa, 0x15, 0x99, 0x4d, 0xa9, 0xd2, 0xbe, 0xbc, 0xa1, 0x6e,
    0xc2, 0xbc, 0xc6, 0xfc, 0x99, 0x0b, 0xb6, 0x57, 0xc2, 0xdb, 0xb6, 0xdb, 0xcf, 0x1d, 0xb2, 0x13,
    0xb1, 0xf4, 0xaa, 0x56, 0xba, 0xfc, 0xa1, 0x8f, 0xaa, 0xda, 0x96, 0x13, 0x9e, 0x98, 0xa2, 0xb9,
    0x9e, 0x76, 0x9e, 0xd9, 0x9a, 0x34, 0xa2, 0x13, 0x95, 0x8f, 0x88, 0xc7, 0x95, 0xd1, 0x8d, 0x2b};

static const u8 sSaveIcon[] = {
    0x09, 0x00, 0x00, 0x20, 0x00, 0x40, 0x00, 0x00, 0x01, 0x02, 0x00, 0xa4, 0x00, 0x00, 0x08, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x0b, 0x0c, 0x0c, 0x0d, 0x02, 0x00, 0x00, 0x02, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x05, 0x06,
    0x01, 0x00, 0x00, 0x04, 0x0e, 0x0f, 0x10, 0x11, 0x0b, 0x01, 0x17, 0x0e, 0x18, 0x19, 0x1a, 0x1b,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x05, 0x08, 0x00, 0x00, 0x00, 0x00,
    0x11, 0x12, 0x13, 0x0e, 0x05, 0x00, 0x00, 0x00, 0x1c, 0x11, 0x1d, 0x0f, 0x1e, 0x06, 0x09, 0x09,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x0a, 0x00, 0x00, 0x00,
    0x09, 0x14, 0x15, 0x16, 0x09, 0x00, 0x00, 0x00, 0x09, 0x1f, 0x20, 0x21, 0x09, 0x09, 0x09, 0x00,
    0x00, 0x00, 0x0b, 0x0c, 0x0d, 0x0b, 0x0b, 0x0d, 0x00, 0x00, 0x0b, 0x0c, 0x0b, 0x00, 0x00, 0x0b,
    0x00, 0x00, 0x0b, 0x0c, 0x0b, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x0b, 0x0c, 0x0d, 0x0b, 0x0b, 0x0d,
    0x0c, 0x02, 0x22, 0x0e, 0x23, 0x24, 0x25, 0x25, 0x0c, 0x0b, 0x22, 0x29, 0x2a, 0x12, 0x2b, 0x12,
    0x0c, 0x0b, 0x10, 0x29, 0x2a, 0x22, 0x11, 0x2e, 0x0c, 0x02, 0x22, 0x29, 0x2a, 0x31, 0x31, 0x26,
    0x10, 0x22, 0x1a, 0x26, 0x13, 0x1e, 0x09, 0x27, 0x2b, 0x19, 0x25, 0x26, 0x2c, 0x2d, 0x09, 0x15,
    0x24, 0x1c, 0x2f, 0x1d, 0x2c, 0x2d, 0x09, 0x1f, 0x26, 0x31, 0x31, 0x1d, 0x2c, 0x2d, 0x09, 0x09,
    0x16, 0x21, 0x20, 0x15, 0x16, 0x16, 0x28, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x00,
    0x21, 0x15, 0x20, 0x20, 0x21, 0x30, 0x28, 0x00, 0x09, 0x30, 0x20, 0x30, 0x09, 0x09, 0x09, 0x00,
    0x00, 0x00, 0x0b, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x02, 0x0c, 0x0c, 0x0c, 0x0c, 0x0b,
    0x00, 0x00, 0x01, 0x02, 0x0b, 0x0b, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x22, 0x2f,
    0x0b, 0x01, 0x32, 0x0e, 0x0f, 0x2b, 0x0f, 0x10, 0x01, 0x22, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
    0x22, 0x1e, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x10, 0x12, 0x12, 0x0f, 0x13, 0x2d, 0x33, 0x2d, 0x1e, 0x1e, 0x0e, 0x0e, 0x1e, 0x2d, 0x2d, 0x2d,
    0x2d, 0x2d, 0x2d, 0x33, 0x33, 0x2d, 0x33, 0x2d, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x09, 0x16, 0x15, 0x16, 0x09, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00,
    0x2d, 0x2d, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x1e, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x2d, 0x2d,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x2d, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x2d, 0x33,
    0x33, 0x33, 0x35, 0x36, 0x35, 0x37, 0x38, 0x38, 0x3a, 0x3b, 0x3c, 0x3d, 0x35, 0x3d, 0x3e, 0x3f,
    0x40, 0x40, 0x3f, 0x3e, 0x41, 0x42, 0x3f, 0x43, 0x3e, 0x46, 0x47, 0x1c, 0x1c, 0x1c, 0x3e, 0x47,
    0x38, 0x38, 0x29, 0x39, 0x35, 0x35, 0x33, 0x33, 0x3f, 0x3e, 0x37, 0x36, 0x3c, 0x35, 0x3c, 0x3a,
    0x43, 0x43, 0x42, 0x37, 0x3f, 0x40, 0x44, 0x45, 0x43, 0x3e, 0x1c, 0x1c, 0x1c, 0x47, 0x3e, 0x41,
    0x33, 0x33, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2d, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x2d, 0x2d, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x33, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x40, 0x39,
    0x00, 0x00, 0x00, 0x00, 0x55, 0x3f, 0x3f, 0x33, 0x00, 0x00, 0x00, 0x00, 0x03, 0x4b, 0x23, 0x33,
    0x4b, 0x4c, 0x1c, 0x1c, 0x4d, 0x4e, 0x23, 0x47, 0x2e, 0x2e, 0x1c, 0x51, 0x1c, 0x52, 0x53, 0x46,
    0x2e, 0x2e, 0x1c, 0x56, 0x57, 0x36, 0x41, 0x4b, 0x4b, 0x4b, 0x1c, 0x56, 0x54, 0x5e, 0x4c, 0x4c,
    0x43, 0x3e, 0x4e, 0x4d, 0x26, 0x1c, 0x3e, 0x3f, 0x43, 0x3f, 0x52, 0x1c, 0x54, 0x1c, 0x3e, 0x41,
    0x47, 0x3e, 0x58, 0x59, 0x5a, 0x1c, 0x3e, 0x3f, 0x2e, 0x5f, 0x3f, 0x54, 0x54, 0x1c, 0x3e, 0x3e,
    0x4f, 0x33, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x29, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x4a, 0x5b, 0x5c, 0x5d, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x3b, 0x40, 0x5d, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x5b, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x5b, 0x29,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x41, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x47,
    0x41, 0x41, 0x3e, 0x2a, 0x4b, 0x1c, 0x1c, 0x2e, 0x3d, 0x3c, 0x29, 0x3e, 0x2e, 0x1c, 0x4c, 0x5f,
    0x39, 0x36, 0x36, 0x38, 0x2e, 0x4c, 0x5f, 0x46, 0x37, 0x36, 0x36, 0x3d, 0x4b, 0x2e, 0x46, 0x3e,
    0x4b, 0x47, 0x61, 0x61, 0x2a, 0x5e, 0x3e, 0x38, 0x4b, 0x43, 0x64, 0x65, 0x61, 0x38, 0x3d, 0x36,
    0x3f, 0x3f, 0x64, 0x29, 0x5b, 0x36, 0x36, 0x36, 0x3f, 0x67, 0x68, 0x65, 0x3d, 0x36, 0x36, 0x3d,
    0x42, 0x39, 0x41, 0x62, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3b, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x29, 0x61, 0x5d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6a,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x4b, 0x38, 0x3c, 0x3c, 0x37, 0x47, 0x47, 0x3f, 0x4b, 0x4b, 0x3d, 0x6b, 0x6c, 0x5b, 0x29, 0x65,
    0x69, 0x4b, 0x4b, 0x40, 0x53, 0x6f, 0x6f, 0x3d, 0x00, 0x69, 0x47, 0x4b, 0x47, 0x40, 0x29, 0x53,
    0x67, 0x65, 0x68, 0x5b, 0x3c, 0x36, 0x42, 0x64, 0x3a, 0x6d, 0x3b, 0x6b, 0x6b, 0x6b, 0x44, 0x68,
    0x3d, 0x6f, 0x6b, 0x44, 0x29, 0x44, 0x5b, 0x44, 0x53, 0x37, 0x38, 0x29, 0x29, 0x5b, 0x44, 0x62,
    0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x5d, 0x53, 0x47, 0x47, 0x47, 0x47, 0x00, 0x00, 0x00, 0x00, 0x71, 0x41, 0x47, 0x47,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x6a, 0x72, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3f, 0x40, 0x38, 0x29, 0x37, 0x70, 0x55, 0x00, 0x41, 0x53, 0x29, 0x72, 0x03, 0x00, 0x00, 0x00,
    0x73, 0x72, 0x5d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x74, 0x74, 0x74, 0x00,
    0x00, 0x00, 0x74, 0x7c, 0x7d, 0x7d, 0x7e, 0x74, 0x00, 0x00, 0x74, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x76, 0x77, 0x78,
    0x74, 0x00, 0x00, 0x76, 0x13, 0x1d, 0x11, 0x1b, 0x80, 0x74, 0x81, 0x0e, 0x2a, 0x2e, 0x2f, 0x25,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x79, 0x7a, 0x7b, 0x00, 0x00, 0x00, 0x00,
    0x1c, 0x12, 0x1d, 0x18, 0x7f, 0x00, 0x00, 0x00, 0x25, 0x22, 0x1a, 0x26, 0x1e, 0x06, 0x09, 0x09,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x0a, 0x00, 0x00, 0x00,
    0x09, 0x14, 0x15, 0x16, 0x09, 0x00, 0x00, 0x00, 0x09, 0x1f, 0x20, 0x21, 0x09, 0x09, 0x09, 0x00,
    0x00, 0x00, 0x7c, 0x7d, 0x82, 0x7c, 0x7c, 0x7e, 0x00, 0x00, 0x7c, 0x7d, 0x7c, 0x00, 0x00, 0x7c,
    0x00, 0x00, 0x7c, 0x7d, 0x7c, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x7c, 0x7d, 0x82, 0x7c, 0x7c, 0x7e,
    0x7d, 0x74, 0x22, 0x0e, 0x31, 0x2b, 0x12, 0x19, 0x7d, 0x7c, 0x22, 0x13, 0x23, 0x22, 0x19, 0x1c,
    0x7d, 0x7c, 0x22, 0x0e, 0x2c, 0x11, 0x23, 0x23, 0x7d, 0x74, 0x22, 0x0e, 0x1e, 0x83, 0x1e, 0x1e,
    0x11, 0x19, 0x2f, 0x31, 0x18, 0x2d, 0x09, 0x27, 0x1c, 0x26, 0x2f, 0x11, 0x3a, 0x2d, 0x09, 0x15,
    0x23, 0x2a, 0x11, 0x45, 0x1e, 0x2d, 0x09, 0x1f, 0x1e, 0x1e, 0x13, 0x0e, 0x2d, 0x2d, 0x09, 0x09,
    0x16, 0x21, 0x20, 0x15, 0x16, 0x16, 0x28, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x00,
    0x21, 0x15, 0x20, 0x20, 0x21, 0x30, 0x28, 0x00, 0x09, 0x30, 0x20, 0x30, 0x09, 0x09, 0x09, 0x00,
    0x00, 0x00, 0x7c, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x00, 0x00, 0x74, 0x7d, 0x7d, 0x7d, 0x7d, 0x7c,
    0x00, 0x00, 0x74, 0x74, 0x7c, 0x7c, 0x74, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x1e, 0x33,
    0x80, 0x74, 0x1e, 0x2d, 0x2d, 0x2d, 0x33, 0x33, 0x74, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x35, 0x33, 0x33, 0x6d, 0x37, 0x44, 0x44, 0x33, 0x85, 0x35, 0x36, 0x3c, 0x37, 0x53, 0x45,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x2d, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x35, 0x33, 0x33,
    0x44, 0x44, 0x44, 0x6d, 0x4a, 0x33, 0x33, 0x33, 0x45, 0x53, 0x37, 0x3c, 0x35, 0x4a, 0x3a, 0x33,
    0x09, 0x16, 0x15, 0x16, 0x09, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00,
    0x33, 0x33, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x2d, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x2d, 0x33,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x2d, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6a, 0x33, 0x39,
    0x6d, 0x44, 0x35, 0x3d, 0x39, 0x39, 0x41, 0x3f, 0x3f, 0x38, 0x40, 0x3e, 0x3f, 0x38, 0x3f, 0x47,
    0x47, 0x4b, 0x3e, 0x1c, 0x1c, 0x1c, 0x43, 0x47, 0x2e, 0x2e, 0x1c, 0x1c, 0x54, 0x5a, 0x3e, 0x4b,
    0x3f, 0x40, 0x3c, 0x3c, 0x3c, 0x36, 0x5b, 0x6d, 0x43, 0x41, 0x38, 0x3f, 0x3f, 0x29, 0x44, 0x38,
    0x43, 0x43, 0x1c, 0x1c, 0x1c, 0x3e, 0x3f, 0x40, 0x47, 0x3e, 0x5a, 0x54, 0x1c, 0x1c, 0x3e, 0x41,
    0x33, 0x33, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x4a, 0x2d, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x33, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8b, 0x40, 0x4a,
    0x00, 0x00, 0x00, 0x00, 0x55, 0x47, 0x41, 0x33, 0x00, 0x00, 0x00, 0x00, 0x03, 0x4b, 0x38, 0x4f,
    0x2e, 0x2e, 0x1c, 0x51, 0x1c, 0x52, 0x23, 0x4b, 0x2e, 0x2e, 0x1c, 0x54, 0x8c, 0x36, 0x41, 0x4b,
    0x4b, 0x4b, 0x1c, 0x54, 0x5a, 0x2a, 0x4c, 0x4c, 0x38, 0x42, 0x5e, 0x51, 0x4b, 0x1c, 0x4c, 0x2e,
    0x46, 0x41, 0x52, 0x1c, 0x56, 0x1c, 0x3e, 0x40, 0x46, 0x41, 0x36, 0x8d, 0x54, 0x1c, 0x3e, 0x40,
    0x2e, 0x47, 0x45, 0x5a, 0x54, 0x1c, 0x43, 0x3f, 0x4b, 0x47, 0x3e, 0x41, 0x51, 0x47, 0x38, 0x29,
    0x39, 0x29, 0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x29, 0x65, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x33, 0x42, 0x29, 0x5d, 0x00, 0x00, 0x00, 0x00, 0x4f, 0x4f, 0x29, 0x5d, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x6d, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8f, 0x3f, 0x43,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x23, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x92, 0x4b,
    0x42, 0x36, 0x39, 0x41, 0x4c, 0x4c, 0x2e, 0x47, 0x42, 0x36, 0x36, 0x38, 0x2e, 0x2e, 0x47, 0x3e,
    0x3f, 0x6b, 0x36, 0x44, 0x5f, 0x46, 0x3e, 0x3e, 0x5f, 0x40, 0x3c, 0x6b, 0x41, 0x47, 0x3f, 0x3f,
    0x43, 0x43, 0x67, 0x8e, 0x53, 0x6d, 0x36, 0x3d, 0x3e, 0x3f, 0x8e, 0x8e, 0x44, 0x36, 0x36, 0x3d,
    0x3f, 0x67, 0x8e, 0x64, 0x3d, 0x36, 0x36, 0x42, 0x67, 0x67, 0x64, 0x44, 0x6c, 0x36, 0x5b, 0x8e,
    0x29, 0x4f, 0x29, 0x62, 0x00, 0x00, 0x00, 0x00, 0x29, 0x65, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x68, 0x37, 0x91, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6a,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x5f, 0x4b, 0x42, 0x3c, 0x3d, 0x29, 0x61, 0x65, 0x5e, 0x2e, 0x4b, 0x41, 0x38, 0x3d, 0x3d, 0x3d,
    0x97, 0x47, 0x5f, 0x5f, 0x23, 0x98, 0x99, 0x99, 0x00, 0x69, 0x43, 0x4b, 0x47, 0x4a, 0x3a, 0x3a,
    0x65, 0x3a, 0x5b, 0x95, 0x3c, 0x6b, 0x68, 0x68, 0x3d, 0x3d, 0x6f, 0x44, 0x37, 0x6d, 0x68, 0x44,
    0x99, 0x59, 0x9a, 0x37, 0x68, 0x68, 0x6d, 0x57, 0x3a, 0x3a, 0x4a, 0x5b, 0x3a, 0x6d, 0x9a, 0x62,
    0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x9b, 0x41, 0x4b, 0x29, 0x2d, 0x83, 0x00, 0x00, 0x00, 0x00, 0x9c, 0x4b, 0x29, 0x9d,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x50, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x83, 0x2d, 0x3a, 0x65, 0x5b, 0x70, 0x55, 0x00, 0x9d, 0x3a, 0x29, 0x9e, 0x55, 0x00, 0x00, 0x00,
    0xa1, 0xa2, 0xa3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xad, 0x41, 0xb5, 0x61, 0x11, 0x11, 0x33, 0x13, 0x45, 0x13, 0x66, 0x00, 0x56, 0x01,
    0x21, 0x12, 0x70, 0x20, 0x60, 0x20, 0xb9, 0x81, 0xe6, 0xa4, 0xc1, 0xc2, 0xd8, 0x00, 0xdd, 0x08,
    0xe5, 0x4a, 0xee, 0x31, 0xe9, 0x8c, 0xd4, 0x41, 0x71, 0x60, 0x9b, 0x21, 0x8e, 0x01, 0x56, 0x12,
    0xd4, 0xc6, 0xf6, 0xb5, 0xf6, 0x73, 0xfe, 0xf7, 0xff, 0xff, 0xef, 0x39, 0xc8, 0x00, 0x92, 0x41,
    0x9b, 0x41, 0x96, 0xe1, 0xe8, 0x00, 0xea, 0x72, 0xf7, 0xbd, 0xe4, 0x44, 0xef, 0xbd, 0x71, 0x70,
    0x70, 0x30, 0xd9, 0x89, 0xe6, 0xb5, 0xe5, 0x08, 0xd5, 0x4a, 0xb0, 0x00, 0xff, 0x79, 0xe4, 0x42,
    0x92, 0x81, 0xe7, 0x7b, 0xf8, 0x00, 0xa4, 0x00, 0x55, 0x13, 0x90, 0x00, 0x80, 0x00, 0xcd, 0x89,
    0xd9, 0xca, 0xa4, 0x81, 0xc8, 0xc4, 0xb0, 0xc4, 0x94, 0x42, 0xa4, 0xc4, 0xfe, 0xae, 0xfa, 0x6d,
    0xee, 0x2c, 0xee, 0x6d, 0xb9, 0x06, 0xfe, 0xb1, 0xc9, 0x48, 0xd9, 0xcc, 0xff, 0x33, 0xfe, 0xf3,
    0x43, 0x13, 0x66, 0x12, 0xa4, 0x40, 0xff, 0x36, 0xff, 0xbb, 0x9a, 0x39, 0xa1, 0xd5, 0xb0, 0xc2,
    0x59, 0x76, 0xcf, 0x3d, 0x88, 0xc8, 0xde, 0x2c, 0xb2, 0xfd, 0x10, 0x00, 0xbb, 0x3d, 0xb1, 0x4e,
    0x88, 0x44, 0xc6, 0x31, 0xaa, 0x77, 0xc9, 0x46, 0xe5, 0xc8, 0x33, 0x24, 0xee, 0xb3, 0xff, 0x77,
    0x6d, 0x99, 0xee, 0x2a, 0x11, 0x12, 0x47, 0x55, 0xed, 0x46, 0xd9, 0x46, 0x6a, 0x76, 0xf9, 0xc8,
    0xd9, 0x04, 0x57, 0x55, 0x22, 0x23, 0x94, 0x84, 0x98, 0x82, 0xc5, 0x06, 0x45, 0x45, 0x98, 0xc5,
    0x55, 0x34, 0x45, 0x34, 0x55, 0x45, 0x67, 0x55, 0xc4, 0xae, 0x12, 0x00, 0x34, 0x00, 0x47, 0x22,
    0x69, 0x65, 0x58, 0x32, 0x45, 0x00, 0x22, 0x00, 0xd0, 0xd1, 0xf5, 0xdd, 0xd8, 0xf4, 0x46, 0x00,
    0xcc, 0xd0, 0x58, 0x00, 0xdd, 0x15, 0xc8, 0x42, 0x53, 0x01, 0xb8, 0x84, 0x64, 0x00, 0xa8, 0x46,
    0x43, 0x35, 0x69, 0x53, 0x23, 0x32, 0x5a, 0x64, 0xb9, 0x8e, 0xa9, 0x4c, 0xfd, 0x86, 0x45, 0x56,
    0x66, 0x57, 0x32, 0x23, 0x33, 0x35, 0x54, 0x37, 0x57, 0x67, 0xa0, 0x84, 0x44, 0x37, 0x56, 0x57,
    0xcd, 0xcc, 0xd6, 0x73, 0xb9, 0x4a, 0x35, 0x34, 0x48, 0x54, 0xc4, 0x82, 0x57, 0x43, 0x24, 0x33,
    0x6b, 0x87, 0x6b, 0x64, 0x58, 0x53, 0x34, 0x32};

/*
/ Settings
*/

static BetterSMS::Settings::SettingsGroup sSettingsGroup(1, 0, BetterSMS::Settings::Priority::MODE);

static bool sDummyBool = false;
static BetterSMS::Settings::BoolSetting sDummySetting("Dummy", &sDummyBool);

/*
/ Module Info
*/

static BetterSMS::ModuleInfo sModuleInfo("Chaos", 1, 1, &sSettingsGroup);

/*
/ Callbacks
*/


// Module definition

static void initModule() {
    OSReport("Initializing Module...\n");

    // Register callbacks
    //BetterSMS::Game::addBootCallback(autoDebug);
    //BetterSMS::Stage::addUpdateCallback(removeSetting);

    // Register settings
    sSettingsGroup.addSetting(&sDummySetting);

    {
        auto &saveInfo        = sSettingsGroup.getSaveInfo();
        saveInfo.mSaveName    = BetterSMS::Settings::getGroupName(sSettingsGroup);
        saveInfo.mBlocks      = 1;
        saveInfo.mGameCode    = 'GMSB';
        saveInfo.mCompany     = 0x3031;  // '01'
        saveInfo.mBannerFmt   = CARD_BANNER_CI;
        saveInfo.mBannerImage = reinterpret_cast<const ResTIMG *>(sSaveBnr);
        saveInfo.mIconFmt     = CARD_ICON_CI;
        saveInfo.mIconSpeed   = CARD_SPEED_SLOW;
        saveInfo.mIconCount   = 2;
        saveInfo.mIconTable   = reinterpret_cast<const ResTIMG *>(sSaveIcon);
        saveInfo.mSaveGlobal  = true;
    }
    BetterSMS::registerModule(sModuleInfo);
}

/* static void deinitModule() {
    OSReport("Deinitializing Module...\n");

    // Cleanup callbacks
    //BetterSMS::Game::deregisterBootCallback("BetterDebugEntry_autoDebug");
    //BetterSMS::Stage::deregisterUpdateCallback("BetterDebugEntry_removeSetting");
} */

// Definition block
KURIBO_MODULE_BEGIN("Chaos", "Angry_Max, MasterMattK", "v0.1") {
    // Set the load and unload callbacks to our registration functions
    KURIBO_EXECUTE_ON_LOAD { initModule(); }
}
KURIBO_MODULE_END()
