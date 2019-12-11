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
    double _sin(double);
    CU_ASSERT( _sin(0.0)    == 0.0 );
    CU_ASSERT( _sin(M_PI/6.0) == 0.499999999999999944488848768742172978818416595458984375 );
    CU_ASSERT( _sin(M_PI/4.0) == 0.707106781186547461715008466853760182857513427734375 );
    CU_ASSERT( _sin(M_PI/3.0) == 0.86602540378443848556599959920276887714862823486328125 );
    CU_ASSERT( _sin(M_PI/2.0) == 1.0 );
    CU_ASSERT( _sin(M_PI)     == 0.0000000000000001224646799147353207173764029458396604625692124677580063796256126806838437914848327637 );
fprintf(stderr,"###%3.100lf\n",_sin(M_PI));
}
