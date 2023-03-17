
 #include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main(void)
{
    wchar_t c = L'\u0444'; // Cyrillic small letter ef ('ф')
    printf("in the default locale, iswlower(%#x) =%d\n", c, !!iswlower(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswlower(%#x) =%d\n", c, !!iswlower(c));
}
