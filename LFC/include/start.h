
#ifndef START_H
#define START_H
/* I had to add this or gcc goes brr*/

#include <stddef.h>

#ifndef START_C
extern void start_ranlux(int level, int seed);
#endif

#ifndef UTILS_C
extern void error(int test, int no, char *name, char *text);
extern void *amalloc(size_t size, int p);
extern void afree(void *addr);
#endif

#endif
