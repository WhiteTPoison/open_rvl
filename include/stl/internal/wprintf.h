#ifndef MSL_WPRINTF_H
#define MSL_WPRINTF_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

int vswprintf(s16*, size_t, const s16*, va_list);
int swprintf(s16*, size_t, const s16*, ...);

#ifdef __cplusplus
}
#endif
#endif
