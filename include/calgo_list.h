#ifndef CALGO_LIST_H
#define CALGO_LIST_H

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "calgo_public.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LIST_COUNT(list) ((list)->count)

typedef struct ListNode_ {
    struct ListNode_ *pre;
    struct ListNode_ *next;

    void *data;
} ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;

    size_t dataSize;
    uint32_t count;
} List;

typedef enum {
    FORWARD,
    REVERSE
} ListDirection;

typedef struct {
    List *list;
    ListNode *current;
    ListNode *next;
    ListDirection direction;
} ListIterator;

void InitListForwardHeadIter(List *list, ListIterator *iter);
void InitListForwardTailIter(List *list, ListIterator *iter);
void InitListReverseHeadIter(List *list, ListIterator *iter);
void InitListReverseTailIter(List *list, ListIterator *iter);
void ListIterMoveNext(ListIterator *iter);
bool IsListIterEnd(ListIterator *iter);

List* CreateList(size_t dataSize);
void ListInsert(ListIterator *iter, void* data);
void ListErase(ListIterator *iter, FreeFunc freeFunc);
bool ListEmpty(List *list);
void ListPushBack(List *list, void *data);
void ListPushFront(List *list, void *data);
void DeleteList(List *list, FreeFunc freeFunc);

#ifdef __cplusplus
}
#endif

#endif