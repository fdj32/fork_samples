#include <stacktrace>
#include <iostream>
 
int main()
{
    for (const auto &f : std::stacktrace::current())
        std::cout << f << '\n';
}