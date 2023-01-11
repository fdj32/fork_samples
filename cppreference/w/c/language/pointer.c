#include <stdio.h>
int f(int n)
{
    printf("%d\n", n);
    return n*n;
}
int main(void)
{
    int (*p)(int) = f;
    int x = p(7);
}