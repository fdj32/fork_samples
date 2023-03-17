
 #include <csetjmp>
#include <iostream>

std::jmp_buf my_jump_buffer;

[[noreturn]] void foo(int status) 
{
    std::cout << "foo(" << status << ") called\n";
    std::longjmp(my_jump_buffer, status + 1); // setjmp() will return status + 1
}

int main()
{
    volatile int count = 0; // modified locals in setjmp scope must be volatile
    if (setjmp(my_jump_buffer) != 5) // equality against constant expression in an if
    {
        count = count + 1; // ++count, count += 1, etc on 'volatile'-qualified
                           // left operand are deprecated since C++20 (P1152),
                           // but they are de-deprecated since C++23 (P2327).
        foo(count); // This will cause setjmp() to exit
    }
}
