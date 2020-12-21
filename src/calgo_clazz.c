#include "calgo_clazz.h"
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

size_t sizeOf(const void *_self)
{
    const CALGO_Clazz_s * const * cp = _self;

    assert(_self != NULL);
    assert(*cp != NULL);

    return (*cp)->size;
}

void * New(const void * _clazz, ...)
{
    const CALGO_Clazz_s *clazz = _clazz;
    void *p  = calloc(1, clazz->size);

    assert(p != NULL);
    // TODO
    *(const struct clazz **)p = clazz;

    if (clazz->ctor != NULL) {
        va_list ap;
        va_start(ap, _clazz);
        p = clazz->ctor(p, &ap);
        va_end(ap);
    }
    return p;
}

void Delete(void * _self)
{
    // TODO
    const CALGO_Clazz_s **cp = _self;
    if (_self != NULL && (*cp)->dtor != NULL) {
        _self = (*cp)->dtor(_self);
    }
    free(_self);
}

void * Clone(void *_self)
{
    // TODO
    const CALGO_Clazz_s * const *cp = _self;
    
    assert(_self != NULL);
    assert(*cp != NULL);
    assert((*cp)->clone != NULL);

    return (*cp)->clone(_self);
}

int Differ(const void *_self, const void *_other)
{
    // TODO
    const CALGO_Clazz_s * const *cp = _self;
    
    assert(_self != NULL);
    assert(*cp != NULL);
    assert((*cp)->differ != NULL);

    return (*cp)->differ(_self, _other);
}