#ifndef CTYPE_H
#define CTYPE_H 1

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
#define isxdigit(c) (isdigit(c)||(((c)>='A'&&(c)<='F')||((c)>='a'&&(c)<='f'))
#define isgraph(c) ((c)>' ')
#define islower(c) ((c)>='a'&&(c)<='z')
#define isupper(c) ((c)>='A'&&(c)<='Z')
#define isprint(c) (isgraph(c))
#define ispunct(c) (((c)>='!'&&(c)<='$')||((c)>=':'&&(c)<='`')||((c)>='{'&&(c)<='}'))
#define isspace(c) ((c)==' '||(c)=='\t'||(c)=='\r'||(c)=='\n')

#define toupper(c) ((c) - (islower(c) ? 'a'-'A' : 0))
#define tolower(c) ((c) + (isupper(c) ? 'a'-'A' : 0))

#endif /* CTYPE_H */
