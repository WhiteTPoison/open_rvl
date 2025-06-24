#ifndef MSL_MBSTRING_H
#define MSL_MBSTRING_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

int mbtowc(s16*, const char*, size_t);
size_t mbstowcs(s16*, const char*, size_t);
size_t wcstombs(char*, const s16*, size_t);

#ifdef __cplusplus
}
#endif
#endif
