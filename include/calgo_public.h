#ifndef CALGO_PUBLIC_H
#define CALGO_PUBLIC_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*FreeFunc)(void *);

#define STATIC_CAST(type, val) ((type)(val))

inline void *GetArraryVal(const void *arr, uint32_t index, size_t valSize);

inline void *Swap(void *a, void *b, size_t valSize);

inline void Assign(void *a, const void *b, size_t valSize);
#ifdef __cplusplus
}
#endif

#endif