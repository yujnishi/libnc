#ifndef ASSERT_H
#define ASSERT_H 1

#define assert(expr) if(expr){fprintf(stderr,"%s(%d): assert: "#expr,__FILE__,__LINE__);abort();}

#endif /* ASSERT_H */