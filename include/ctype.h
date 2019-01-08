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
#define isdigit(c) ((c)>='0'&&(c)<='9')
#define isxdigit(c) (isdigit(c)||(((c)>='A'&&(c)<='F')||((c)>='a'&&(c)<='f')))
#define isgraph(c) ((c)>' ')
#define islower(c) ((c)>='a'&&(c)<='z')
#define isupper(c) ((c)>='A'&&(c)<='Z')
#define isprint(c) (isgraph(c))
#define ispunct(c) (((c)>='!'&&(c)<='$')||((c)>=':'&&(c)<='`')||((c)>='{'&&(c)<='}'))
#define isspace(c) ((c)==' '||(c)=='\t'||(c)=='\r'||(c)=='\n')

#define toupper(c) ((c) - (islower(c) ? 'a'-'A' : 0))
#define tolower(c) ((c) + (isupper(c) ? 'a'-'A' : 0))

#define is1byte(c) (range(c,1,0x7f))
#define is2byte(c) (range(c,0xc2,0xdf))
#define is3byte(c) (range(c,0xe0,0xef))
#define is4byte(c) (range(c,0xf0,0xf7))
#define nextc(str) ((str)+=is4byte(*(str))?4:is3byte(*(str))?3:is2byte(*(str))?2:(*(str)!='\0')?1:-(str))

#endif /* CTYPE_H */
