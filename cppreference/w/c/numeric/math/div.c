#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
 
void reverse(char* first, char* last) {
    for (--last; first < last; ++first, --last) {
        char c = *last;
        *last = *first;
        *first = c;
    }    
}
 
// demo only: does not check for buffer overflow
char* itoa(int n, int base, char* buf)
{
    assert(2 <= base && base <= 16);
    div_t dv = {.quot = n};
    char* p = buf;
    do {
        dv = div(dv.quot, base);
        *p++ = "0123456789abcdef"[abs(dv.rem)];
    } while(dv.quot);
    if(n<0) *p++ = '-';
    *p = '\0';
    reverse(buf, p);
    return buf;
}
 
int main(void)
{
    char buf[100];
    printf("%s\n", itoa(0, 2, buf));
    printf("%s\n", itoa(007, 3, buf));
    printf("%s\n", itoa(12346, 10, buf));
    printf("%s\n", itoa(-12346, 10, buf));
    printf("%s\n", itoa(-42, 2, buf));
    printf("%s\n", itoa(INT_MAX, 16, buf));
    printf("%s\n", itoa(INT_MIN, 16, buf));
}