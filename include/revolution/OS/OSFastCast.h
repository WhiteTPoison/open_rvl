#ifndef RVL_SDK_OS_FAST_CAST_H
#define RVL_SDK_OS_FAST_CAST_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GQR_TYPE_U8 4
#define OS_GQR_TYPE_U16 5
#define OS_GQR_TYPE_S8 6
#define OS_GQR_TYPE_S16 7

static inline void OSInitFastCast(void) {
    // clang-format off
    asm(
        "li r3, 4\n\t"
        "oris r3, r3, 4\n\t"
        "mtspr 0x392, r3\n\t"
        "li r3, 5\n\t"
        "oris r3, r3, 5\n\t"
        "mtspr 0x393, r3\n\t"
        "li r3, 6\n\t"
        "oris r3, r3, 6\n\t"
        "mtspr 0x394, r3\n\t"
        "li r3, 7\n\t"
        "oris r3, r3, 7\n\t"
        "mtspr 0x395, r3\n\t"
    );
    // clang-format on
}

static inline void OSSetGQR6(register u32 type, register u32 scale) {
    register u32 val = ((scale << 8 | type) << 16) | ((scale << 8) | type);

    // clang-format off
    asm (
        "mtspr 0x396, val\n\t"
    );
    // clang-format on
}

static inline void OSSetGQR7(register u32 type, register u32 scale) {
    register u32 val = ((scale << 8 | type) << 16) | ((scale << 8) | type);

    // clang-format off
    asm(
        "mtspr 0x397, val\n\t"
    );
    // clang-format on
}

/******************************************************************************
 *
 * Convert from U8
 *
 ******************************************************************************/
static inline f32 __OSu8tof32(register u8* in) {
    register f32 ret;

    // clang-format off
    asm(
        "psq_l ret, 0(in), 1, 2\n\t"
    );
    // clang-format on

    return ret;
}

static inline void OSu8tof32(u8* in, volatile f32* out) {
    *out = __OSu8tof32(in);
}

/******************************************************************************
 *
 * Convert from U16
 *
 ******************************************************************************/
static inline f32 __OSu16tof32(register u16* arg) {
    register f32 ret;

    // clang-format off
    asm(
        "psq_l ret, 0(arg), 1, 3\n\t"
    );
    // clang-format on

    return ret;
}

static inline void OSu16tof32(u16* in, volatile f32* out) {
    *out = __OSu16tof32(in);
}

/******************************************************************************
 *
 * Convert from S16
 *
 ******************************************************************************/
static inline f32 __OSs16tof32(register s16* arg) {
    register f32 ret;

    // clang-format off
    asm(
        "psq_l ret, 0(arg), 1, 5\n\t"
    );
    // clang-format on

    return ret;
}

static inline void OSs16tof32(s16* in, volatile f32* out) {
    *out = __OSs16tof32(in);
}

/******************************************************************************
 *
 * Convert from F32
 *
 ******************************************************************************/
static inline u8 __OSf32tou8(register f32 arg) {
    f32 a;
    register f32* ptr = &a;
    u8 r;

    // clang-format off
    asm ("psq_st arg, 0(ptr), 1, 2\n\t");
    // clang-format on

    r = *(u8*)ptr;
    return r;
}

static inline void OSf32tou8(f32* in, volatile u8* out) {
    *out = __OSf32tou8(*in);
}

static inline u16 __OSf32tou16(register f32 arg) {
    f32 a;
    register f32* ptr = &a;
    u16 r;

    // clang-format off
    asm(
        "psq_st arg, 0(ptr), 1, 3\n\t"
    );
    // clang-format on

    r = *(u16*)ptr;
    return r;
}

static inline void OSf32tou16(f32* in, volatile u16* out) {
    *out = __OSf32tou16(*in);
}

static f32 __OSs16tof32(register const s16* arg) {
    register f32 ret;

    // clang-format off
    asm(
        "psq_l ret, 0(arg), 1, 5\n\t"
    );
    // clang-format on

    return ret;
}

static void OSs16tof32(const s16* in, f32* out) { *out = __OSs16tof32(in); }

static s16 __OSf32tos16(register f32 arg) {
    f32 a;
    register f32* ptr = &a;
    s16 r;

    // clang-format off
    asm (
        "psq_st arg, 0(ptr), 1, 5\n\t"
    );
    // clang-format on

    r = *(s16*)ptr;
    return r;
}

static inline void OSf32tos16(f32* in, volatile s16* out) {
    *out = __OSf32tos16(*in);
}

#ifdef __cplusplus
}
#endif
#endif
