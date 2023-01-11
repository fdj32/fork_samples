#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
 
int main(void)
{
    wchar_t c = L'\u053d'; // Armenian capital letter xeh ('Խ')
    printf("in the default locale, iswupper(%#x) = %d\n", c, !!iswupper(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswupper(%#x) = %d\n", c, !!iswupper(c));
}