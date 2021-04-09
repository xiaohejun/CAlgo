#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "calgo_vector.h"


Vector* CreateVector(size_t dataSize)
{
    assert(dataSize != 0);

    Vector *vec = malloc(sizeof(Vector)); 
    vec->dataSize = dataSize;
    vec->capacity = 1;
    vec->count = 0;
    vec->datas = malloc(dataSize * vec->capacity);
    
    return vec;
}

static void VectorTryExpan(Vector *vec)
{
    if (vec->count < vec->capacity) {
        return;
    }
    vec->capacity = vec->capacity * 2;
    void *oldDatas = vec->datas;
    vec->datas = malloc(vec->dataSize * vec->capacity);
    memcpy(vec->datas, oldDatas, vec->count * vec->dataSize);
    free(oldDatas);
}

void VectorSetValAt(Vector *vec, uint32_t index, void *val)
{
    assert(vec != NULL);
    assert(index < vec->count);
    assert(val != NULL);

    memcpy(VectorAt(vec, index), val, vec->dataSize);
}

void* VectorAt(Vector *vec, uint32_t index)
{
    assert(vec != NULL);
    assert(index < vec->count);

    return (void *)((char *)vec->datas + index * vec->dataSize);
}

void VectorPushBack(Vector *vec, void *val)
{
    assert(vec != NULL);
    assert(val != NULL);

    VectorTryExpan(vec);
    vec->count++;
    VectorSetValAt(vec, vec->count - 1, val);
}

void DeleteVector(Vector *vec, FreeFunc freeFunc)
{
    assert(vec != NULL);
    
    if (freeFunc != NULL) {
        for (uint32_t i = 0; i < VEC_COUNT(vec); ++i) {
            freeFunc(VectorAt(vec, i));
        }
    }
    free(vec->datas);
    free(vec);
}