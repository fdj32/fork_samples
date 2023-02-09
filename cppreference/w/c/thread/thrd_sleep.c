#ifndef __clang__
#include <threads.h>
#endif
#include <time.h>
#include <stdio.h>

int main(void)
{
    printf("Time: %s", ctime(&(time_t){time(NULL)}));
#ifndef __clang__
    thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL); // sleep 1 sec
#endif
    printf("Time: %s", ctime(&(time_t){time(NULL)}));
}