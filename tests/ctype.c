#include <ctype.h>

void test_isalnum() {
    CU_ASSERT(isalnum('A'));
    CU_ASSERT(isalnum('a'));
    CU_ASSERT(isalnum('0'));
    CU_ASSERT(!isalnum('!'));
}

void test_isalpha() {
    CU_ASSERT(isalpha('A'));
    CU_ASSERT(isalpha('a'));
    CU_ASSERT(!isalpha('0'));
}

void test_iscntl() {
    CU_ASSERT(iscntl('\b'));
    CU_ASSERT(!iscntl('a'));
}

void test_isdigit() {
    CU_ASSERT(isdigit('0'));
    CU_ASSERT(isdigit('9'));
    CU_ASSERT(!isdigit('a'));
}

void test_isxdigit() {
    CU_ASSERT(isxdigit('0'));
    CU_ASSERT(isxdigit('9'));
    CU_ASSERT(isxdigit('f'));
    CU_ASSERT(isxdigit('F'));
    CU_ASSERT(!isxdigit('g'));
}

void test_isgraph() {
    CU_ASSERT(isgraph('a'));
    CU_ASSERT(isgraph('"'));
    CU_ASSERT(isgraph('@'));
    CU_ASSERT(!isgraph('\t'));
}

void test_islower() {
    CU_ASSERT(islower('a'));
    CU_ASSERT(islower('z'));
    CU_ASSERT(!islower('A'));
}

void test_isupper() {
    CU_ASSERT(isupper('A'));
    CU_ASSERT(isupper('Z'));
    CU_ASSERT(!isupper('a'));
}

void test_isprint() {
    CU_ASSERT(isprint('a'));
    CU_ASSERT(isprint('"'));
    CU_ASSERT(isprint('@'));
    CU_ASSERT(!isprint('\t'));
}

void test_punct() {
    CU_ASSERT(ispunct('!'));
    CU_ASSERT(ispunct('.'));
    CU_ASSERT(!ispunct('a'));
}

void test_isspace() {
    CU_ASSERT(isspace(' '));
    CU_ASSERT(isspace('\t'));
    CU_ASSERT(!isspace('\b'));
}

void test_nextc() {
    unsigned char str[] = "aαあ𠮷";
    unsigned char* p;

    p = str;
    CU_ASSERT(strcmp(p=nextc(p),"αあ𠮷") == 0);
    CU_ASSERT(strcmp(p=nextc(p),"あ𠮷") == 0);
   CU_ASSERT(strcmp(p=nextc(p),"𠮷") == 0);
    CU_ASSERT( *p == '\0' );
    CU_ASSERT( nextc(p) == NULL );
}