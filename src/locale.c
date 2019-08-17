#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>

struct __locale __current_locale;
char lang[64] = "C";
char lang_bk[64] = "";

char* setlocale(int cat,const char* lc) {
    struct __locale l;
    FILE* fi;
    char fname[PATH_MAX];

    if ( (strlen(lc)+1) > sizeof(lang) ) return NULL;

    snprintf(fname,sizeof(fname),"%s/%s",strdef(getenv("LC_PATH"),LC_PATH),lc);
    fi = fopen(fname,"rb");
printf("SETLOCALE fopen\n");
    if ( fi == NULL ) return NULL;
printf("SETLOCALE fread\n");
    if ( fread(&l,sizeof(l),1,fi) != 1 ) {
        fclose(fi);
        return NULL;
    }
    fclose(fi);

    switch(cat) {
    case LC_ALL:        memcpy(&__current_locale,&l,sizeof(l)); break;
#define COPY(cat,field)  case cat:                         \
                         memcpy(&__current_locale.field,   \
                                &l.field,                  \
                                sizeof(l.field));          \
                                break
    COPY(LC_ADDRESS,address);
    COPY(LC_COLLATE,collate);
    COPY(LC_CTYPE,ctype);
    COPY(LC_MEASUREMENT,measurement);
    COPY(LC_MONETARY,monetary);
    COPY(LC_NUMERIC,numeric);
    COPY(LC_TELEPHONE,telephone);
    COPY(LC_TIME,time);
    default: return NULL;
#undef COPY
    }

    strcpy(lang_bk,lang);
    strcpy(lang,lc);

    return lang_bk;
}

int savelocale(const char* lc,const struct __locale* l,int overwrite) {
    struct stat st;
    char fname[PATH_MAX];
    FILE* fi;

    snprintf(fname,sizeof(fname),"%s/%s",strdef(getenv("LC_PATH"),LC_PATH),lc);
    if ( !overwrite && stat(fname,&st) == 0 ) return -1;

    fi = fopen(fname,"w");
    if ( fi == NULL ) return -1;

    if ( fwrite(l,sizeof(struct __locale),1,fi) != 1 ) {
        fclose(fi);
        return -1;
    }

    fclose(fi);
    return 0;
}

int aliaslocale(const char* lc,const char* src) {
    char fname[PATH_MAX];

    snprintf(fname,sizeof(fname),"%s/%s",strdef(getenv("LC_PATH"),LC_PATH),lc);
    return symlink(src,fname);
}


