#pragma once

namespace PADButtonBits {
    const unsigned short Start = 0x1000;
    const unsigned short Y = 0x800;
    const unsigned short X = 0x400;
    const unsigned short B = 0x200;
    const unsigned short A = 0x100;
    const unsigned short L = 0x40;
    const unsigned short R = 0x20;
    const unsigned short Z = 0x10;
    const unsigned short UpDPad = 0x8;
    const unsigned short DownDPad = 0x4;
    const unsigned short RightDPad = 0x2;
    const unsigned short LeftDPad = 0x1;
}

//This is the representation of the physical buttons pressed on a GC controller
union PADButtons {
    unsigned int bits;
    struct {
        unsigned int _none: 3;
        unsigned int Start: 1;
        unsigned int Y: 1;
        unsigned int X: 1;
        unsigned int B: 1;
        unsigned int A: 1;
        unsigned int _none2: 1;
        unsigned int L: 1;
        unsigned int R: 1;
        unsigned int Z: 1;
        unsigned int UpDPad: 1;
        unsigned int DownDPad: 1;
        unsigned int RightDPad: 1;
        unsigned int LeftDPad: 1;
    }__attribute__((packed, aligned(2)));
}__attribute__((packed, aligned(2)));

struct PADStatus {
    unsigned int button;
    signed char stickX;
    unsigned char stickY;
    signed char substickX;
    signed char substickY;
    unsigned char triggerLeft;
    unsigned char triggerRight;
    unsigned char analogA;
    unsigned char analogB;
    signed char  err;
}__attribute__((packed, aligned(2)));


#define PAD_ERR_NONE            0
#define PAD_ERR_NO_CONTROLLER   -1
#define PAD_ERR_NOT_READY       -2
#define PAD_ERR_TRANSFER        -3