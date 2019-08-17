#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int strpul( char* dst, const char* src, const char* coll) {
    char* p;
    char* q;
    const char* r;
    int f_isalnum     = 0;
    int f_isalpha     = 0;
    int f_isoscntl    = 0;
    int f_istermcntl  = 0;
    int f_iscntl      = 0;
    int f_isdigit     = 0;
    int f_isxdigit    = 0;
    int f_isgraph     = 0;
    int f_islower     = 0;
    int f_isupper     = 0;
    int f_isprint     = 0;
    int f_ispunct     = 0;
    int f_isspace     = 0;
    char s_isalnum[]     = "[[isalnum]]";
    char s_isalpha[]     = "[[isalpha]]";
    char s_isoscntl[]    = "[[isoscnt]]";
    char s_istermcntl[]  = "[[istermcntl]]";
    char s_iscntl[]      = "[[iscntl]]";
    char s_isdigit[]     = "[[isdigit]]";
    char s_isxdigit[]    = "[[isxdigit]]";
    char s_isgraph[]     = "[[isgraph]]";
    char s_islower[]     = "[[islower]]";
    char s_isupper[]     = "[[isupper]]";
    char s_isprint[]     = "[[isprint]]";
    char s_ispunct[]     = "[[ispunct]]";
    char s_isspace[]     = "[[isspace]]";

    coll = strdup(coll);

#define check(isfunc)                    \
    if ( (p=strstr(coll,s_##isfunc)) ) {  \
        f_##isfunc = 1;                     \
        q = p;                           \
        r = p+sizeof(s_##isfunc)-1;       \
        for ( ; *r ; q++,r++ ) *q = *r;  \
    }

    check(isalnum);
    check(isalpha);
    check(isoscntl);
    check(istermcntl);
    check(iscntl);
    check(isdigit);
    check(isxdigit);
    check(isgraph);
    check(islower);
    check(isupper);
    check(isprint);
    check(ispunct);
    check(isspace);
#undef check

    q = dst;
    r = src;
    for ( ; *r ; q++,r++ ) {
        *q = *r;
        if ( strchr(coll,*r) ) continue;
#define if_match(isfunc) if ( f_##isfunc && isfunc(*r) )
        if_match(isalnum)     continue;
        if_match(isalpha)     continue;
        if_match(isoscntl)    continue;
        if_match(istermcntl)  continue;
        if_match(iscntl)      continue;
        if_match(isdigit)     continue;
        if_match(isxdigit)    continue;
        if_match(isgraph)     continue;
        if_match(islower)     continue;
        if_match(isupper)     continue;
        if_match(isprint)     continue;
        if_match(ispunct)     continue;
        if_match(isspace)     continue;
#undef if_match
        *q = '\0';
        break;
    }
    *q = '\0';

    free((char*)coll);
    return (int)(q-dst);
}

char* strrdel(char* s,const char* coll) {
    char* p;

    p = s + strlen(s)-1;
    for ( ; p >= s; p-- ) {
        if ( strchr(coll,*p) ) *p = '\0';
        else break;
    }

    return s;
}

char* strldel(char* s,const char* coll) {
    char* p;
    char* q;

    p = q = s;
    for ( ; *p; p++ ) if ( !strchr(coll,*p) ) break;
    for ( ; *p; p++,q++ ) *q = *p;
    *q = '\0';

    return s;
}

char* strdel(char* s,const char* coll) {
    return strldel(strrdel(s,coll),coll);
}

char* strdef(char* s1,char* s2) {
    if ( s1 ) return s1;
    return s2;
}

char* strrvs(char* s) {
    char* p;
    char* q;
    char* dup;

    dup = strdup(s);
    p = s;
    q = dup + strlen(dup)-1;
    for ( ; q >= dup; p++,q-- ) *p = *q;

    free(dup);
    return s;
}

int strcvl(char* dst,int src,int base) {
    int i = 0;
    int sign;
    int prefix;
    char* num;
    char num_normal[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char num_base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    sign = (src < 0) ? -1 : 1;
    src *= sign;

    prefix = (base < 0) ? 1 : 0;
    base *= (base < 0) ? -1 : 1;

    num = num_normal;
    if ( base == 64 ) num = num_base64;
    else if ( base < 2 || base >= sizeof(num_normal) ) return -1;

    while ( src > 0 ) {
        int n;

        n = src % base;
        dst[i] = num[n];
        i++;
        src -= n;
        src /= base;
    }
    if ( prefix ) {
        if ( base == 8  ) { dst[i] = '0'; i++; }
        if ( base == 16 ) { dst[i] = 'x'; dst[i+1] = '0'; i+= 2; }
    }
    if ( sign == -1 ) { dst[i] = '-'; i++; }
    dst[i] = '\0';

    strrvs(dst);
    return i;
}
