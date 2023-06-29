/******************************************************************************
 * https://hpc-tutorials.llnl.gov/posix/samples/hello32.c
 * FILE: hello32.c
 * DESCRIPTION:
 *   A "hello world" Pthreads program which creates a large number of
 *   threads per process.  A sleep() call is used to insure that all
 *   threads are in existence at the same time.  Each Hello thread does some
 *   work to demonstrate how the OS scheduler behavior affects thread
 *   completion order.
 * AUTHOR: Blaise Barney
 * LAST REVISED: 01/29/09
 ******************************************************************************/
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define NTHREADS 32

void *Hello(void *threadid)
{
    int i;
    double result = 0.0;
    // sleep(3);
    for (i = 0; i < 10000; i++)
    {
        result = result + sin(i) * tan(i);
    }
    printf("%ld: Hello World!\n", (long)threadid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NTHREADS];
    int rc;
    long t;
    void *status;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    for (t = 0; t < NTHREADS; t++)
    {
        rc = pthread_create(&threads[t], &attr, Hello, (void *)t);
        if (rc)
        {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            printf("Code %d= %s\n", rc, strerror(rc));
            exit(-1);
        }
    }
    pthread_attr_destroy(&attr);

    printf("main(): Created %ld threads.\n", t);

    for (t = 0; t < NTHREADS; t++)
    {
        rc = pthread_join(threads[t], &status);
        if (rc)
        {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}