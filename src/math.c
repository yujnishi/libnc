#include <stdio.h>
#include <math.h>

double _sin(double x) {
    int i,n,f;
    double result;
    double d,t,q;

    result = 0;
    t = 1;
    f = 1;
    for ( n = 1; t != 0; n += 2 ) {
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

