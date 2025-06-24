#ifndef RVL_SDK_VF_PF_W_CLIB_H
#define RVL_SDK_VF_PF_W_CLIB_H
#include <revolution/types.h>
#ifdef __cplusplus
extern "C" {
#endif

size_t VFipf_w_strlen(const s16* str);
s16* VFipf_w_strcpy(s16* dst, const s16* src);
int VFipf_w_strncmp(const s16* s1, const s16* s2, size_t n);

#ifdef __cplusplus
}
#endif
#endif
