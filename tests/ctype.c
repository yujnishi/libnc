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
    CU_ASSERT(