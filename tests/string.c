#include <string.h>


int strcvl(char* dst,int src,int base);
char* strdef(char* s1,char* s2);
char* strdel(char* s,const char* coll);
char* strldel(char* s,const char* coll);
int strpul( char* dst, const char* src, const char* coll);
char* strrdel(char* s,const char* coll);
char* strrvs(char* s);


void test_strcvl() {
    char buf[256];

    CU_ASSERT(strcvl(buf,123,8) == 3);
    CU_ASSERT(!strcmp(buf,"173"));
    CU_ASSERT(strcvl(buf,123,10) == 3);
    CU_ASSERT(!strcmp(buf,"123"));
    CU_ASSERT(strcvl(buf,123,16) == 2);
    CU_ASSERT(!strcmp(buf,"7b"));

    CU_ASSERT(strcvl(buf,-123,8) == 4);
    CU_ASSERT(!strcmp(buf,"-173"));
    CU_ASSERT(strcvl(buf,-123,10) == 4);
    CU_ASSERT(!strcmp(buf,"-123"));
    CU_ASSERT(strcvl(buf,-123,16) == 3);
    CU_ASSERT(!strcmp(buf,"-7b"));

    CU_ASSERT(strcvl(buf,123,-8) == 4);
    CU_ASSERT(!strcmp(buf,"0173"));
    CU_ASSERT(strcvl(buf,123,-10) == 3);
    CU_ASSERT(!strcmp(buf,"123"));
    CU_ASSERT(strcvl(buf,123,-16) == 4);
    CU_ASSERT(!strcmp(buf,"0x7b"));

    CU_ASSERT(strcvl(buf,-123,-8) == 5);
    CU_ASSERT(!strcmp(buf,"-0173"));
    CU_ASSERT(strcvl(buf,-123,-10) == 4);
    CU_ASSERT(!strcmp(buf,"-123"));
    CU_ASSERT(strcvl(buf,-123,-16) == 5);
    CU_ASSERT(!strcmp(buf,"-0x7b"));

    CU_ASSERT(strcvl(buf,123,36) == 2);
    CU_ASSERT(!strcmp(buf,"3f"));
    CU_ASSERT(strcvl(buf,456,36) == 2);
    CU_ASSERT(!strcmp(buf,"co"));
    CU_ASSERT(strcvl(buf,789,36) == 2);
    CU_ASSERT(!strcmp(buf,"lx"));

    CU_ASSERT(strcvl(buf,123,64) == 2);
    CU_ASSERT(!strcmp(buf,"B7"));
    CU_ASSERT(strcvl(buf,456,64) == 2);
    CU_ASSERT(!strcmp(buf,"HI"));
    CU_ASSERT(strcvl(buf,789,64) == 2);
    CU_ASSERT(!strcmp(buf,"MV"));
    
    CU_ASSERT(strcvl(buf,123,-1) == -1);
    CU_ASSERT(strcvl(buf,123,37) == -1);
}

void test_strdef() {
    char* s1 = "abc";
    char* s2 = "def";

    CU_ASSERT(strdef(s1,s2) == s1);
    CU_ASSERT(strdef(NULL,s2) == s2);
    CU_ASSERT(strdef(NULL,NULL) == NULL);
}

void test_strrdel() {
    char buf1[] = " ..  abc . def ..  ";
    char buf2[] = "abc . def";

    CU_ASSERT(strrdel(buf1," .") == buf1);
    CU_ASSERT(!strcmp(buf1," ..  abc . def"));
    CU_ASSERT(strrdel(buf2," .") == buf2);
    CU_ASSERT(!strcmp(buf2,"abc . def"));

    CU_ASSERT(strrdel(buf2,"xyz") == buf2);
    CU_ASSERT(!strcmp(buf2,"abc . def"));
}

void test_strldel() {
    char buf1[] = " ..  abc . def ..  ";
    char buf2[] = "abc . def";

    CU_ASSERT(strldel(buf1," .") == buf1);
    CU_ASSERT(!strcmp(buf1,"abc . def ..  "));
    CU_ASSERT(strldel(buf2," .") == buf2);
    CU_ASSERT(!strcmp(buf2,"abc . def"));

    CU_ASSERT(strldel(buf2,"xyz") == buf2);
    CU_ASSERT(!strcmp(buf2,"abc . def"));
}

void test_strdel() {
    char buf1[] = " ..  abc . def ..  ";
    char buf2[] = "abc . def";
    char buf3[] = "123_abcdef";
    char buf4[] = "123_abcdef";

    CU_ASSERT(strdel(buf1," .") == buf1);
    CU_ASSERT(!strcmp(buf1,"abc . def"));
    CU_ASSERT(strdel(buf2," .") == buf2);
    CU_ASSERT(!strcmp(buf2,"abc . def"));

    CU_ASSERT(strdel(buf2,"xyz") == buf2);
    CU_ASSERT(!strcmp(buf2,"abc . def"));
}

void test_strrvs() {
    char buf[] = "123456789";
    char empty[] = "";

    CU_ASSERT(strrvs(buf) == buf);
    CU_ASSERT(!strcmp(buf,"987654321"));
    CU_ASSERT(strrvs(empty) == empty);
    CU_ASSERT(empty[0] == '\0');
}

void test_strpul() {
    char buf[256];

    CU_ASSERT(strpul(buf,"abcdef","abc") == 3);
    CU_ASSERT(!strcmp(buf,"abc"));
    CU_ASSERT(strpul(buf,"abcdef","123") == 0);
    CU_ASSERT(!strcmp(buf,""));

    CU_ASSERT(strpul(buf,"123abcdef","[[isdigit]]") == 3);
    CU_ASSERT(!strcmp(buf,"123"));
}
