#ifndef CTYPE_H
#define CTYPE_H 1

#include <math.h>

#define isalnum(c) (isalpha(c)||isdigit(c))
#define isalpha(c) (isupper(c)||islower(c))
#ifndef isoscntl
#define isoscntl(c) (0)
#endif
#ifndef istermcntl
#define istermcntl(c) (0)
#endif
#define iscntl(c) (((c)<' '&&!isspace(c))||isoscntl(c)||istermcntl(c))
#define isdigit(c) range(c,'0','9')
#define isxdigit(c) (isdigit(c)||range(c,'A','F')||range(c,'a','f'))
#define isgraph(c) ((c)>' ')
#define islower(c) range(c,'a','z')
#define isupper(c) range(c,'A','Z')
#define isprint(c) (isgraph(c))
#define ispunct(c) (((c)=='.')||((c)>='!'&&(c)<='$')||((c)>=':'&&(c)<='`')||((c)>='{'&&(c)<='}'))
#define isspace(c) ((c)==' '||(c)=='\t'||(c)=='\r'||(c)=='\n')

#define toupper(c) ((c) - (islower(c) ? 'a'-'A' : 0))
#define tolower(c) ((c) + (isupper(c) ? 'a'-'A' : 0))

#define is1byte(c) (range(c,1,0x7f))
#define is2byte(c) (range(c,0xc2,0xdf))
#define is3byte(c) (range(c,0xe0,0xef))
#define is4byte(c) (range(c,0xf0,0xf7))
#define nextc(str) (((str)==NULL||*(str)=='\0')?NULL:is4byte(*(str))?(str)+4:is3byte(*(str))?(str)+3:is2byte(*(str))?(str)+2:(str)+1)

#endif /* CTYPE_H */
