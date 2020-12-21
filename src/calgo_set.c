// #include "calgo_set.h"
// #include <stdio.h>
// #include <assert.h>

// #if (! defined MANY) || (MANY < 1)
// #define MANY 10
// #endif

// static int g_heap[MANY];

// void * New(const void * type, ...)
// {
//     int *p;
//     for (p = g_heap + 1; p < g_heap + MANY; ++p) {
//         if (*p == 0) {
//             break;
//         }
//     }
//     assert(p < g_heap + MANY);
//     *p = MANY;
//     return p;
// }

// void Delete(void * _item)
// {
//     int *item = _item;
//     if (item != NULL) {
//         assert(item > g_heap);
//         assert(item < g_heap + MANY);
//         *item = 0;
//     }
// }

// void * Add(void * _set, const void * _element) 
// {
//     int *set = _set;
//     const int *element = _element;

//     assert(set > g_heap);
//     assert(set < g_heap + MANY);
//     assert(*set == MANY);
//     assert(element > g_heap);
//     assert(element < g_heap + MANY);

//     if (*element == MANY) {
//         *(int *)element = set - g_heap;
//     } else {
//         assert(*element == set - g_heap);
//     }
//     return (void *)element;
// }

// void * Find(const void * _set, const void * _element)
// {
//     const int *set = _set;
//     const int *element = _element;

//     assert(set > g_heap);
//     assert(set < g_heap + MANY);
//     assert(*set == MANY);
//     assert(element > g_heap);
//     assert(element < g_heap + MANY);   
//     assert(*element);

//     return *element == set - g_heap ? (void *)element : NULL;
// }

// int Contains(const  void * _set, const void * _element)
// {
//     return Find(_set, _element) != NULL;
// }

// void * Drop(void * _set, const void * _element)
// {
//     int *element = Find(_set, _element);

//     if (element != NULL) {
//         *element = MANY;
//     }
//     return element;
// }

// int Differ(const void * a, const void * b)
// {
//     return a != b;
// }