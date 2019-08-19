#ifndef MATH_H
#define MATH_H 1

#define max(a,b)      (((a)>(b)) ? (a) : (b))
#define min(a,b)      (((a)<(b)) ? (a) : (b))
#define abs(a)        (((a)>=0) ? (a) : -(a))
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

    fmod — 浮動小数点どうしの商と剰余
    frexp — 「正規化された仮数部」と「2の累乗」への分解
    ldexp — 浮動小数点数と2の累乗との乗算
    modf — 整数部と小数部の分解

#endif /* MATH_H */
