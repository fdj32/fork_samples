#include <stacktrace>
#include <iostream>
 
int nested_func(int c)
{
    std::cout << std::stacktrace::current() << '\n';
    return c+1;
}
 
int func(int b) {
    return nested_func(b+1);
}
 
int main() {
    std::cout << func(777);
}