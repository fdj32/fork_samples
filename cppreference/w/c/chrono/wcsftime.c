#include <stdio.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
 
int main(void)
{
    wchar_t buff[40];
    struct tm my_time = { .tm_year=112, // = year 2012
                          .tm_mon=9,    // = 10th month
                          .tm_mday=9,   // = 9th day
                          .tm_hour=8,   // = 8 hours
                          .tm_min=10,   // = 10 minutes
                          .tm_sec=20    // = 20 secs
    };
 
    if (wcsftime(buff, sizeof buff, L"%A %c", &my_time)) {
        printf("%ls\n", buff);
    } else {
        puts("wcsftime failed");
    }
 
    char * sl = setlocale(LC_ALL, "zh_CN"); // do not use ja_JP.utf8, use ja_JP, zh_CN

    printf("%s\n", sl);

    if (wcsftime(buff, sizeof buff, L"%A %c", &my_time)) {
        printf("%ls\n", buff);
    } else {
        puts("wcsftime failed");
    }
}