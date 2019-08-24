#include <math.h>

void test_sin() {
    CU_ASSERT( sin(0.0)    == 0.0 );
    CU_ASSERT( sin(PI/6.0) == 0.5 );
    CU_ASSERT( sin(PI/4.0) == 0.707106781 );
    CU_ASSERT( sin(PI/3.0) == 0.866025404 );
    CU_ASSERT( sin(PI/2.0) == 1.0 );
    CU_ASSERT( sin(PI)     == 0.0 );
//fprintf(stderr,"%lf\n",sin(PI/6.0));
}
