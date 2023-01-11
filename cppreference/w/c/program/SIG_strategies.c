#include <signal.h>
#include <stdio.h>
 
int main(void)
{
    /* using the default signal handler */
    raise(SIGTERM);
    printf("Exit main()\n");   /* never reached */
}