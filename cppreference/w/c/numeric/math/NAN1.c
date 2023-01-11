#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
 
int main(void)
{
    double f = NAN;
    uint64_t fn; memcpy(&fn, &f, sizeof f);
    printf("NAN:   %f %" PRIx64 "\n", f, fn);
}