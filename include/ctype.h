#ifndef 

#de
iscntrl - 制御文字かどうかの判別
isdigit - 数字かどうかの判別
isgraph - 空白（' '）を除く表示文字かどうかの判別
islower - 小文字かどうかの判別
isprint - 表示文字かどうかの判別
ispunct - 区切り文字かどうかの判別
isspace - 空白類文字かどうかの判別
isupper - 大文字かどうかの判別
isxdigit - 16進数字かどうかの判別
tolower
#define toupper(c) ((c) + (islower(c) ? 'a'-'A' : 0))

#define isalnum(c) (isalpha(c)||isdigit(c))
#define isalpha(c) (isupper(c)||islower(c))
#ifndef isoscntl
#define isoscntl(c) (0)
#endif
#ifndef istermcntl
#define istermcntl(c) (0)
#define iscntl(c) (((c)<' '&&!isspace(c))||isoscntl(c)||istermcntl(c))