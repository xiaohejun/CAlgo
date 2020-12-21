#ifndef CALGO_STRING_H
#define CALGO_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const void *clazz;
    char *text;
} CALGO_String_s;

extern const void * CALGO_String;

#ifdef __cplusplus
}
#endif

#endif