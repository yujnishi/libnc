#ifndef MATH_H
#define MATH_H 1

#define M_PI (3.14159265358979323846)

#define max(a,b)      (((a)>(b)) ? (a) : (b))
#define min(a,b)      (((a)<(b)) ? (a) : (b))
#define range(o,l,h)  ((o)>=(l)&&(o)<=(h))

double sin(double);
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

#endif /* MATH_H */
