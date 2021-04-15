#include <assert.h>
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "calgo_public.h"

inline void *GetVoidArraryVal(const void *arr, uint32_t index, size_t valSize)
{
    return (void *)((char *)(arr) + (index) * (valSize));
}

inline void *Swap(void *a, void *b, size_t valSize)
{
    return NULL;
}

inline void Assign(void *a, const void *b, size_t valSize)
{
    assert(a != NULL);
    assert(b != NULL);
    memcpy(a, b, valSize);
}