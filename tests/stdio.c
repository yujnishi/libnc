#include <stdio.h>

void test_printf() {
    CU_ASSERT(printf("abc\n") == 4);
    CU_ASSERT(printf("%d\n",123) == 4);
    CU_ASSERT(printf("%c\n",' ') == 2);
    CU_ASSERT(printf("%s\n","abc") == 4);

    CU_ASSERT(printf("%2$d\n",1,22,333) == 3);
    CU_ASSERT(printf("%3$d\n",1,22,333) == 4);

    CU_ASSERT(printf("%{PATH}$s\n") == 3);
}
