#include <math.h>
#include <stdio.h>
int main(void)
{
    double result = 1.0/0.0;
    printf("1.0/0.0 = %f\n", result);
    if (result == HUGE_VAL)
        puts("1.0/0.0 == HUGE_VAL\n");
}