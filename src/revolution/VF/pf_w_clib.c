#include <revolution/VF.h>

size_t VFipf_w_strlen(const s16* str) {
    const s16* it = str;
    ptrdiff_t diff;

    // Find end of string
    for (; *it != L'\0'; it++) {
        ;
    }

    // Calculate size
    diff = (uintptr_t)it - (uintptr_t)str;
    return diff >> 1;
}

s16* VFipf_w_strcpy(s16* dst, const s16* src) {
    // Preserve original pointer
    s16* work_dst = dst;

    for (; *work_dst = *src, *work_dst != L'\0'; src++, work_dst++) {
        ;
    }

    return dst;
}

int VFipf_w_strncmp(const s16* s1, const s16* s2, size_t n) {

    for (; n > 0; n--, s1++, s2++) {
        if (*s1 == '\0' || *s2 == '\0' || *s1 != *s2) {
            return *s1 - *s2;
        }
    }

    return 0;
}
