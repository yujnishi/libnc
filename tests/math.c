#include <math.h>

void test_expdbl() {
    int sig;
    int exp;

    CU_ASSERT( expdbl(0,&sig,&exp) == 0 );
    CU_ASSERT( sig == 1 );
    CU_ASSERT( exp == 0 );
    CU_ASSERT( expdbl(2,&sig,&exp) == 0 );
    CU_ASSERT( sig == 1 );
    CU_ASSERT( exp == 1024 );
    CU_ASSERT( expdbl(1,&sig,&exp) == 0 );
    CU_ASSERT( sig == 1 );
    CU_ASSERT( exp == 1023 );
    CU_ASSERT( expdbl(0.5,&sig,&exp) == 0 );
    CU_ASSERT( sig == 1 );
    CU_ASSERT( exp == 1022 );
    CU_ASSERT( expdbl(-1,&sig,&exp) == 0 );
    CU_ASSERT( sig == -1 );
    CU_ASSERT( exp == 1023 );
}

void test_impdbl() {
    int sig;
    int exp;
    double d;

    CU_ASSERT( impdbl(1,0,0) == 0 );
    CU_ASSERT( impdbl(1,1023,0) == 1.0 );
    CU_ASSERT( impdbl(1,1024,0) == 2.0 );
    CU_ASSERT( impdbl(1,1022,0) == 0.5 );
    CU_ASSERT( impdbl(-1,1023,0) == -1.0 );

    d = impdbl(1,123,123);
    CU_ASSERT( expdbl(d,&sig,&exp) == 123 );
    CU_ASSERT( sig == 1 );
    CU_ASSERT( exp == 123 );
    d = impdbl(-1,123,123);
    CU_ASSERT( expdbl(d,&sig,&exp) == 123 );
    CU_ASSERT( sig == -1 );
    CU_ASSERT( exp == 123 );
}

void test_sin() {
    CU_ASSERT( sin(0.0)    == 0.0 );
    CU_ASSERT( sin(M_PI/6.0) == 0.5 );
    CU_ASSERT( sin(M_PI/4.0) == 0.707106781 );
    CU_ASSERT( sin(M_PI/3.0) == 0.866025404 );
    CU_ASSERT( sin(M_PI/2.0) == 1.0 );
    CU_ASSERT( sin(M_PI)     == 0.0 );
//fprintf(stderr,"%lf\n",sin(M_PI/6.0));
}
