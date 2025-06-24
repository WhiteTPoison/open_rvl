#ifndef MSL_WSTRING_H
#define MSL_WSTRING_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

size_t wcslen(const s16*);
s16* wcscpy(s16*, const s16*);
s16* wcsncpy(s16*, const s16*, size_t);
s16* wcscat(s16*, const s16*);
int wcscmp(const s16*, const s16*);
s16* wcschr(const s16*, s16);

#ifdef __cplusplus
}
#endif
#endif
