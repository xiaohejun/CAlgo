#ifndef OBJECT_H
#define OBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

extern const void * g_object;

int Differ(const void * a, const void * b);

#ifdef __cplusplus
}
#endif

#endif