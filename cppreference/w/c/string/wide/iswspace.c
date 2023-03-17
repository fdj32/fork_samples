
 #include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main(void)
{
    wchar_t c = L'\u2003'; // Unicode character 'EM SPACE'
    printf("in the default locale, iswspace(%#x) =%d\n", c, !!iswspace(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswspace(%#x) =%d\n", c, !!iswspace(c));
}
