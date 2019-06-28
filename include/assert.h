#ifndef ASSERT_H
#define ASSERT_H 1

#include <stdlib.h>

#define assert(expr) if(!(expr)){fprintf(stderr,"%s(%d): assert: "#expr"\n",__FILE__,__LINE__);abort();}

#endif /* ASSERT_H */
