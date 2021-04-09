#include <gtest/gtest.h>
#include "calgo_vector.h"
#include "calgo_public.h"

TEST(test_calgo_vector, new_a_vector_and_delete_it)
{
    Vector *vec = CreateVector(sizeof(int));

    EXPECT_TRUE(vec != NULL);
    EXPECT_TRUE(vec->datas != NULL);
    EXPECT_EQ(vec->count, 0);
    EXPECT_EQ(vec->capacity, 1);
    
    DeleteVector(vec, NULL);
}

TEST(test_calgo_vector, give_some_double_num_into_vector)
{
    Vector *vec = CreateVector(sizeof(double));

    constexpr int32_t numCnt = 10;
    for (uint32_t i = 0; i < numCnt; ++i) {
        double_t val = i + 0.5;
        VectorPushBack(vec, &val);
    }

    for (uint32_t i = 0; i < numCnt; ++i) {
        double_t *valPtr = STATIC_CAST(double_t *, VectorAt(vec, i));
        EXPECT_DOUBLE_EQ(*valPtr, STATIC_CAST(double, i + 0.5));
    }
    uint32_t expCapacity = (1LL << (uint32_t)log2(numCnt));
    if (expCapacity < numCnt) {
        expCapacity *= 2;
    } 
    EXPECT_EQ(vec->count, numCnt);
    EXPECT_EQ(vec->capacity, expCapacity);

    DeleteVector(vec, NULL);
}

