#include <gtest/gtest.h>
#include "calgo_list.h"
#include "calgo_public.h"

template <typename T>
void CheckCalgoList(List *list, T *expArr, int32_t expNumCnt)
{
    EXPECT_EQ(LIST_COUNT(list), expNumCnt);
    
    int32_t idx = 0;
    ListIterator iter = {0};
    for (InitListForwardHeadIter(list, &iter);
         !IsListIterEnd(&iter);
         ListIterMoveNext(&iter)) {
        
        EXPECT_EQ(*(T *)(iter.current->data), expArr[idx]);
        ++idx;
    }
    EXPECT_EQ(LIST_COUNT(list), idx);

    idx = expNumCnt - 1;
    for (InitListReverseTailIter(list, &iter);
         !IsListIterEnd(&iter);
         ListIterMoveNext(&iter)) {
        
        EXPECT_EQ(*(T *)(iter.current->data), expArr[idx]);
        --idx;
    }
    EXPECT_EQ(idx, -1);

    idx = 0;
    for (InitListReverseHeadIter(list, &iter);
         !IsListIterEnd(&iter);
         ListIterMoveNext(&iter)) {
        
        EXPECT_EQ(*(T *)(iter.current->data), expArr[idx]);
        ++idx;
    }
    EXPECT_EQ(idx, 1);

    
}

TEST(test_calgo_list, create_empty_int_list)
{
    List *list = CreateList(sizeof(int32_t));

    EXPECT_EQ(LIST_COUNT(list), 0);
    EXPECT_EQ(list->dataSize, sizeof(int32_t));
    EXPECT_TRUE(list->head == NULL);
    EXPECT_TRUE(list->tail == NULL);

    DeleteList(list, NULL);
}

TEST(test_calgo_list, create_char_list_has_1_element)
{
    List *list = CreateList(sizeof(char));

    char chArr[] = {'a'};
    ListPushFront(list, &chArr[0]);

    CheckCalgoList(list, chArr, sizeof(chArr) / sizeof(char));

    DeleteList(list, NULL);
}

TEST(test_calgo_list, create_char_double_has_2_element)
{
    List *list = CreateList(sizeof(double_t));

    double_t doubleArr[] = {1.78, 2.11111111122211};
    ListPushFront(list, &doubleArr[0]);
    ListPushBack(list, &doubleArr[1]);

    CheckCalgoList(list, doubleArr, sizeof(doubleArr) / sizeof(double_t));

    DeleteList(list, NULL);
}

TEST(test_calgo_list, create_int_list_has_100_element)
{
    List *list = CreateList(sizeof(int32_t));
    
    int32_t numCnt = 100;
    int32_t expArr[numCnt];
    for (int i = 0; i < numCnt; ++i) {
        ListPushBack(list, &i);
        expArr[i] = i;
    }

    CheckCalgoList(list, expArr, numCnt);

    DeleteList(list, NULL);
}

