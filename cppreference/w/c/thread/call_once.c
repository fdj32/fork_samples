#include <stdio.h>
#ifndef __clang__
#include <threads.h>

void do_once(void)
{
    puts("called once");
}

static once_flag flag = ONCE_FLAG_INIT;
int func(void *data)
{
    call_once(&flag, do_once);
}
#endif
int main(void)
{
#ifndef __clang__
    thrd_t t1, t2, t3, t4;
    thrd_create(&t1, func, NULL);
    thrd_create(&t2, func, NULL);
    thrd_create(&t3, func, NULL);
    thrd_create(&t4, func, NULL);

    thrd_join(t1, NULL);
    thrd_join(t2, NULL);
    thrd_join(t3, NULL);
    thrd_join(t4, NULL);
#endif
}