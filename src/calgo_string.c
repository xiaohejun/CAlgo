#include <stdarg.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calgo_string.h"
#include "calgo_clazz.h"

static void * CALGO_String_Ctor(void *, va_list *);
static void * CALGO_String_Dtor(void *);
static void * CALGO_String_Clone(const void *);
static int CALGO_String_Differ(const void *, const void *);

static const CALGO_Clazz_s _CALGO_String = {
    sizeof(CALGO_String_s), // size of class
    CALGO_String_Ctor,      // constructor
    CALGO_String_Dtor,      // destructor
    CALGO_String_Clone,     // deeply clone
    CALGO_String_Differ     // difference
};

const void * CALGO_String = &_CALGO_String;

static void * CALGO_String_Ctor(void *_self, va_list *ap)
{
    CALGO_String_s *self = _self;
    const char *text = va_arg(*ap, const char *);

    self->text = malloc(strlen(text) + 1);
    assert(self->text != NULL);

    strcpy(self->text, text);
    return self;
}

static void * CALGO_String_Dtor(void *_self)
{
    CALGO_String_s *self = _self;
    if (self->text != NULL) {
        free(self->text);
    }
    self->text = NULL;
    return self;
}

static void * CALGO_String_Clone(const void *_self)
{
    const CALGO_String_s *self = _self;

    assert(self->clazz == CALGO_String);
    
    return New(CALGO_String, self->text);
}

static int CALGO_String_Differ(const void *_self, const void *_other)
{
    const CALGO_String_s *self = _self;
    const CALGO_String_s *other = _other;
    if (self == other) {
        return 0;
    }
    if (other == NULL || other->clazz != CALGO_String) {
        return 1;
    }
    return strcmp(self->text, other->text);
}