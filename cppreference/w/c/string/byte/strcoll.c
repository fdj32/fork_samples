
 #include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_COLLATE, "cs_CZ.iso88592");

    const char* s1 = "hrnec";
    const char* s2 = "chrt";

    printf("In the Czech locale: ");
    if(strcoll(s1, s2) < 0)
         printf("%s before%s\n", s1, s2);
    else
         printf("%s before%s\n", s2, s1);

    printf("In lexicographical comparison: ");
    if(strcmp(s1, s2) < 0)
         printf("%s before%s\n", s1, s2);
    else
         printf("%s before%s\n", s2, s1);
}
