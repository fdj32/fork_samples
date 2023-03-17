
 #include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main(void)
{
    wchar_t c = L'\u3000'; // Ideographic space ('　')
    printf("in the default locale, iswblank(%#x) =%d\n", c, !!iswblank(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswblank(%#x) =%d\n", c, !!iswblank(c));
}
