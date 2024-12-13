#ifndef MSL_WSTRING_H
#define MSL_WSTRING_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

size_t wcslen(const wchar_t*);
wchar_t* wcscpy(wchar_t*, const wchar_t*);
wchar_t* wcsncpy(wchar_t*, const wchar_t*, size_t);
wchar_t* wcscat(wchar_t*, const wchar_t*);
int wcscmp(const wchar_t* s1, const wchar_t* s2) {
    wchar_t c1, c2;

    do
    {
        c1 = *s1++;
        c2 = *s2++;
        if (c2 == L'\0')
            return c1 - c2;
    }
    while (c1 == c2);

    return c1 < c2 ? -1 : 1;
};
wchar_t* wcschr(const wchar_t*, wchar_t);

#ifdef __cplusplus
}
#endif
#endif
