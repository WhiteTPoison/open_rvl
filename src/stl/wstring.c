#include "internal/wstring.h"

int wcscmp(const s16* s1, const s16* s2) {
    s16 c1, c2;

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
