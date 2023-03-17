
 #include <stacktrace>
#include <string>
#include <iostream>

int main()
{
    auto trace = std::stacktrace::current();
    std::cout << std::to_string(trace) << '\n';
}
