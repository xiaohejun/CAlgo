#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "calgo_list.h"

static void InitListHeadIter(List *list, ListIterator *iter)
{
    iter->list = list;
    iter->current = NULL;
    iter->next = NULL;
    iter->current = list->head;
    if (iter->current != NULL) {
        iter->next = iter->current->next;
    }
}

static void InitListTailIter(List *list, ListIterator *iter)
{
    iter->list = list;
    iter->current = NULL;
    iter->next = NULL;
    iter->current = list->tail;
    if (iter->current != NULL) {
        iter->next = iter->current->pre;
    }
}

void InitListForwardHeadIter(List *list, ListIterator *iter)
{
    assert(list != NULL);
    assert(iter != NULL);

    InitListHeadIter(list, iter);
    iter->direction = FORWARD;
}

void InitListForwardTailIter(List *list, ListIterator *iter)
{
    assert(list != NULL);
    assert(iter != NULL);

    InitListTailIter(list, iter);
    iter->direction = FORWARD;
}

void InitListReverseHeadIter(List *list, ListIterator *iter)
{
    assert(list != NULL);
    assert(iter != NULL);

    InitListHeadIter(list, iter);
    iter->direction = REVERSE;
}

void InitListReverseTailIter(List *list, ListIterator *iter)
{
    assert(list != NULL);
    assert(iter != NULL);

    InitListTailIter(list, iter);
    iter->direction = REVERSE;
}

void ListIterMoveNext(ListIterator *iter)
{
    assert(iter != NULL);

    if (iter->direction == FORWARD) {
        iter->current = iter->current->next;
        if (iter->current != NULL) {
            iter->next = iter->current->next;
        } else {
            iter->next = NULL;
        }
        return;
    }
    if (iter->direction == REVERSE) {
        iter->current = iter->current->pre;
        if (iter->current != NULL) {
            iter->next = iter->current->pre;
        } else {
            iter->next = NULL;
        }
        return;
    }
}

bool IsListIterEnd(ListIterator *iter)
{
    assert(iter != NULL);

    return iter->current == NULL;
}

List* CreateList(size_t dataSize)
{
    assert(dataSize != 0);

    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->dataSize = dataSize;
    list->count = 0;
    return list;
}

static ListNode* CreateListNode(void *data, size_t dataSize)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->pre = NULL;
    node->next = NULL;
    node->data = malloc(dataSize);
    memcpy(node->data, data, dataSize);
    return node;
}

void ListInsert(ListIterator *iter, void* data)
{
    assert(iter != NULL);
    assert(IsListIterEnd(iter) == false);

    ListNode *node = CreateListNode(data, iter->list->dataSize);
    ListNode *current = iter->current;
    if (iter->direction == FORWARD) {
        if (current->next == NULL) {
            current->next = node;
            node->pre = current;
        } else {
            current->next->pre = node;
            node->next = current->next;
            node->pre = current;
            current->next = node;
        }
        if (current == iter->list->tail) {
            iter->list->tail = node;
        }
        iter->list->count++;
        return;
    }
    if (iter->direction == REVERSE) {
        if (current->pre == NULL) {
            current->pre = node;
            node->next = current;
        } else {
            current->pre->next = node;
            node->pre = current->pre;
            node->next = current;
            current->pre = node;
        }
        if (current == iter->list->head) {
            iter->list->head = node;
        }
        iter->list->count++;
        return;
    }
}

void ListErase(ListIterator *iter, FreeFunc freeFunc)
{
    assert(iter != NULL);
    assert(IsListIterEnd(iter) == false);

    ListNode *current = iter->current;
    if (current->pre != NULL) {
        current->pre->next = current->next;
    }
    if (current->next != NULL) {
        current->next->pre = current->pre;
    }
    if (freeFunc != NULL) {
        freeFunc(current->data);
    }
    if (current == iter->list->head) {
        iter->list->head = current->next;
    }
    if (current == iter->list->tail) {
        iter->list->tail = current->pre;
    }
    iter->list->count--;
    free(current);
}

bool ListEmpty(List *list)
{
    return list->count == 0;
}

static void EmptyListPush(List *list, void *data)
{
    ListNode *node = CreateListNode(data, list->dataSize);
    list->head = node;
    list->tail = list->head;
    list->count++;
}

void ListPushBack(List *list, void *data)
{
    if (ListEmpty(list)) {
        EmptyListPush(list, data);
        return;
    }
    ListIterator iter = {0};
    InitListForwardTailIter(list, &iter);
    ListInsert(&iter, data);
}

void ListPushFront(List *list, void *data)
{
    if (ListEmpty(list)) {
        EmptyListPush(list, data);
        return;
    }
    ListIterator iter = {0};
    InitListReverseHeadIter(list, &iter);
    ListInsert(&iter, data);
}

void DeleteList(List *list, FreeFunc freeFunc)
{
    ListIterator iter = {0};
    for (InitListForwardHeadIter(list, &iter); 
         !IsListIterEnd(&iter); 
         ListIterMoveNext(&iter)) {
        
        if (freeFunc != NULL) {
            freeFunc(iter.current->data);
        }
        free(iter.current);
    }
    free(list);
}