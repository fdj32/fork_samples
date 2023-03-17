
 #include <locale.h>
#include <stdio.h>

int main(void)
{
    setlocale(LC_ALL, "ja_JP.UTF-8");
    struct lconv *lc = localeconv();
    printf("Japanese currency symbol:%s(%s)\n", lc->currency_symbol, lc->int_curr_symbol);
}
