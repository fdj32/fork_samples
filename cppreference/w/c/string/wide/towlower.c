#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
 
int main(void)
{
    wchar_t wc = L'\u0190'; // Latin capital open E ('Ɛ')
    printf("in the default locale, towlower(%#x) = %#x\n", wc, towlower(wc));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, towlower(%#x) = %#x\n", wc, towlower(wc));
}