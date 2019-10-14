#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

int strcvf(char* dst,float src,int base) {
    dst[0] = '\0';
    return 0;
}

int _printf(const char* fmt,...) {
    va_list ap,ap_bak,ap_src;
    const char* p;
    int prefix_flag  = 0;
    int zero_flag    = 0;
    int left_flag    = 0;
    int space_flag   = 0;
    int sign_flag    = 0;
    int comma_flag   = 0;
    int lcnum_flag   = 0;
    int field_size   = 0;
    int precise_size = 0;
    int wide         = 0;
    int type         = 0;
    char argpos[64];
    int now_arg = 1;
    int i;
    int base;
    char buf[64];
    int size = 0;

    va_start(ap_src,fmt);
    va_copy(ap,ap_src);
        
    for ( p = fmt; *p; p++ ) {
        if ( *p != '%' ) { fputc(*p,stdout); size++; continue; }
        
        for ( p++; *p; p++ ) {
            char num[64];

            argpos[0] = '\0';
            p += strpul(num,p,"{}_[[alnum]]*");

            switch ( *p ) {
            case '#':  prefix_flag = 1; break;
            case '0':  zero_flag   = 1; break;
            case '-':  left_flag   = 1; break;
            case ' ':  space_flag  = 1; break;
            case '+':  sign_flag   = 1; break;
            case '\'': comma_flag = 1; break;
            case 'I':  lcnum_flag  = 1; break;
            case '$':  strcpy(argpos,num); break;
            case '.':  field_size = strtol(num,NULL,10); break;
            case 'h':
            case 'l':
            case 'L': 
            case 'j':
            case 'z':
            case 't':
                if ( num[0] != '\0' && field_size == 0 ) field_size   = strtol(num,NULL,10);
                else                                     precise_size = strtol(num,NULL,10);

                if ( *p == 'h' )      wide = (wide=='h')?'c':'h';
                else if ( *p == 'l' ) wide = (wide=='l')?'L':'l';
                else                  wide = *p;

                break;

            case 'd':
            case 'i':
            case 'o':
            case 'u':
            case 'x':
            case 'X':
            case 'e':
            case 'E':
            case 'f':
            case 'F':
            case 'g':
            case 'G':
            case 'a':
            case 'A':
            case 'c':
            case 's':
            case 'C':
            case 'S':
            case 'P':
            case 'n':
            case 'm':
            case '%':
                if ( num[0] != '\0' && field_size == 0 ) field_size   = strtol(num,NULL,10);
                else                                     precise_size = strtol(num,NULL,10);

                type = *p;
                break;
            default:
                return -1;
            }
        }
        
        if ( argpos[0] == '{' ) {
            if ( type != 's' ) return -1;
            strdel(argpos,"{}");
            size += strlen(strdef(getenv(argpos),""));
            fputs(strdef(getenv(argpos),""),stdout);
            continue;
        } 

        if ( isdigit(argpos[0]) ) {
            int i;

            va_copy(ap_bak,ap);
            va_end(ap);
            va_copy(ap,ap_src);
            for ( i = 0; i < strtol(argpos,NULL,10); i++ ) va_arg(ap,int);
        }

        switch ( type ) {
        case 'o':
            base = 8;
            if ( prefix_flag ) base *= -1;
            size += strcvl(buf,va_arg(ap,int),base);
            fputs(buf,stdout);
            break;
        case 'd':
            base = 10;
            if ( prefix_flag ) base *= -1;
            size += strcvl(buf,va_arg(ap,int),base);
            fputs(buf,stdout);
            break;
        case 'x':
            base = 16;
            if ( prefix_flag ) base *= -1;
            size += strcvl(buf,va_arg(ap,int),base);
            fputs(buf,stdout);
            break;
        case 'f':
            base = 10;
            if ( prefix_flag ) base *= -1;
            size += strcvf(buf,va_arg(ap,double),base);
            fputs(buf,stdout);
            break;
        case 'c':
            fputc(va_arg(ap,int),stdout);
            size++;
            break;
        case 's':
            p = va_arg(ap,char*);
            size += strlen(p);
            fputs(p,stdout);
            break;
        }

        if ( isdigit(argpos[0]) ) {
            va_end(ap);
            va_copy(ap,ap_bak);
            va_end(ap_bak);
        }

    } 
    va_end(ap);

    return size;
}
