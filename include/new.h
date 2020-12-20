#ifndef NEW_H
#define NEW_H

#ifdef __cplusplus
extern "C" {
#endif


void * New(const void * type, ...);
void Delete(void * item);

#ifdef __cplusplus
}
#endif

#endif