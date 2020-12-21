#ifndef CALGO_CLAZZ_H
#define CALGO_CLAZZ_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <ctype.h>

typedef struct {
    size_t size;
    void * (* ctor)(void *self, va_list *app);
    void * (* dtor)(void *self);
    void * (* clone)(const void *self);
    int (* differ)(const void *self, const void *b);
} CALGO_Clazz_s;
 

size_t sizeOf(const void *item);
void * New(const void * type, ...);
void Delete(void * item);
void * Clone(void *item);
int Differ(const void * a, const void * b);


#ifdef __cplusplus
}
#endif

#endif