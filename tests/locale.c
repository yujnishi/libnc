#define LC_PATH "."
#include <locale.h>
#include <string.h>
#include <sys/stat.h>

/*
void test_setlocale() {
    struct __locale l;

    savelocale("hoge",&l,0);
    aliaslocale("fuga","hoge");
    CU_ASSERT(strcmp(setlocale(LC_ALL,"hoge"),"") == 0);
    CU_ASSERT(strcmp(setlocale(LC_ALL,"fuga"),"hoge") == 0);
}

void test_savelocale() {
    struct stat st;
    struct __locale l;

    CU_ASSERT(savelocale("aaa",&l,0) == 0);
    CU_ASSERT(stat("aaa",&st) == 0);
    CU_ASSERT(savelocale("aaa",&l,1) == 0);
    CU_ASSERT(savelocale("aaa",&l,0) == -1);
}
    
void test_aliaslocale() {
    struct stat st;
    struct __locale l;

    CU_ASSERT(savelocale("bbb",&l,0) == 0);
    CU_ASSERT(aliaslocale("ccc","bbb") == 0);
    CU_ASSERT(stat("ccc",&st) == 0);
}
*/
