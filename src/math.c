#include <stdio.h>
#include <math.h>

unsigned long long int expdbl(double d,int* sig,int* exp) {
    unsigned long long int val;

    *sig = d>=0.0 ? 1 : -1;
    *exp = ((*(unsigned long long int*)&d)>>52)&0x07ff;
    val = *(unsigned long long int*)&d;
    val &= 0x3ffffffffffff;
    return val;
}

double impdbl(int sig,int exp,unsigned long long int val) {
    unsigned long long int d;

    sig = sig>=0 ? 0 : 1;

    d = 0;
    d |= ((unsigned long long int)(sig&1))<<63;
    d |= ((unsigned long long int)(exp&0x07ff))<<52;
    d |= ((unsigned long long int)(val&0x3ffffffffffff));
    return *((double*)&d);
}

double fabs(double x) {
    return (x>=0) ? x : -x;
}

double _sin(double x) {
    int i,n,f;
    double result;
    double d,t,q;

    x = fabs(x);
    if ( x >= 2.0*M_PI ) return _sin(x-(2.0*M_PI));
    if ( x >= M_PI )   return -_sin(x-M_PI);
    if ( x >= M_PI/2.0 )   return 1-_sin(x-(M_PI/2.0));

    result = 0;
    t = 1.0;
    f = 1;
    for ( n = 1; t != 0.0; n += 2 ) {
        // 分子
        q = 1;
        for ( i = 0; i < n; i++ ) q *= x;

        // 分母
        d = 1;
        for ( i = 2; i <= n; i++ ) d *= i;

        t = q/d;
        result += f*t;

        f *= -1;
    } 
//fprintf(stderr,"max is %d:%lf:%lf\n",n,result,t);

    return result;
}
double __sin(double x) {
    int i,n,f;
    double result;
    double d,t,q;

    result = 0;
    t = 1.0;
    f = 1;
    for ( n = 1; t != 0.0; n += 2 ) {
        // 分子
        q = 1;
        for ( i = 0; i < n; i++ ) q *= x;

        // 分母
        d = 1;
        //for ( i = 2; i <= n; i++ ) d *= i;
        t = q;
        for ( i = 2; i <= n; i++ ) t /= (double)i;;

        //t = q/d;
        result += f*t;

        f *= -1;
    } 
fprintf(stderr,"max is %d\n",n);

    return result;
}

double cos(double);
double tan(double);

double acos(double);
double asin(double);
double atan(double);
double atan2(double,double);

double sinh(double);
double cosh(double);
double tanh(double);

double log(double);
double log10(double);
double exp(double);


double pow(double,double);
double sqrt(double);
double fabs(double);

double ceil(double);
double floor(double);

double fmod(double,double);

