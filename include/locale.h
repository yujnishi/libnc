#ifndef LOCALE_H
#define LOCALE_H 1

#ifndef LC_PATH
#define LC_PATH "/usr/share/libnc/locale"
#endif

#define LC_ALL             (0)   /* 全てのロケール */
#define LC_ADDRESS         (1)   /* 住所と地理関連の要素のフォーマット */
#define LC_COLLATE         (2)   /* 文字の照合順序 */
#define LC_CTYPE           (3)   /* 文字の分類 */
#define LC_MEASUREMENT     (4)   /* ロケールの説明メタデータ */
#define LC_MONETARY        (5)   /* 金額の表示方法 */
#define LC_NUMERIC         (6)   /* 金額以外の数値の表示方法 */
#define LC_TELEPHONE       (7)   /* 電話サービスで使用されるフォーマット */
#define LC_TIME            (8)   /* 日付と時刻の表示方法 */

struct __locale_address {
    char a[1];
};
struct __locale_collate {
    char a[1];
};
struct __locale_ctype {
    char a[1];
};
struct __locale_measurement {
    char a[1];
};
struct __locale_monetary {
    char a[1];
};
struct __locale_numeric {
    char a[1];
};
struct __locale_telephone {
    char a[1];
};
struct __locale_time {
    char a[1];
};
struct __locale {
    struct __locale_address address;
    struct __locale_collate collate;
    struct __locale_ctype ctype;
    struct __locale_measurement measurement;
    struct __locale_monetary monetary;
    struct __locale_numeric numeric;
    struct __locale_telephone telephone;
    struct __locale_time time;
};

extern struct __locale _current_locale;

char* setlocale(int,const char*);
int savelocale(const char*,const struct __locale*,int);
int aliaslocale(const char*,const char*);

#endif /* LOCALE_H */
