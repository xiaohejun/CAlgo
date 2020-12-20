#ifndef SET_H
#define SET_H

#ifdef __cplusplus
extern "C" {
#endif

extern const void * g_object;

void * Add(void * set, const void * element);
void * Find(const void * set, const void * element);
void * Drop(void * set, const void * element);
int Contains(const  void * set, const void * element);

#ifdef __cplusplus
}
#endif

#endif /* SET_H */