#ifndef Vector_H
#define Vector_H

#include <ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

#define VEC_COUNT(vec) ((vec)->count)

typedef void (*FreeFunc)(void *);

typedef struct Vector_ {
    void *datas;
    size_t dataSize;

    uint32_t count;
    uint32_t capacity;
} Vector;

Vector * CreateVector(size_t dataSize);
void DeleteVector(Vector *vec, FreeFunc freeFunc);
void VectorPushBack(Vector *vec, void *val);
void* VectorAt(Vector *vec, uint32_t index);
void VectorSetValAt(Vector *vec, uint32_t index, void *val);

#ifdef __cplusplus
}
#endif

#endif