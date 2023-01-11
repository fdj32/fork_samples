#include <stdio.h>
#include <setjmp.h>
#include <stdnoreturn.h>
 
jmp_buf my_jump_buffer;
 
noreturn void foo(int count) 
{
    printf("foo(%d) called\n", count);
    longjmp(my_jump_buffer, count+1); // will return count+1 out of setjmp
}
 
int main(void)
{
    volatile int count = 0; // modified local vars in setjmp scope must be volatile
    if (setjmp(my_jump_buffer) != 5) // compare against constant in an if
        foo(++count);
}