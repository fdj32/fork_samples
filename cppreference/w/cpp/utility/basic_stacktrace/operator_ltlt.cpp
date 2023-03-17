
 #include <stacktrace>
#include <iostream>

int main()
{
    std::cout << "The stacktrace obtained in the main function:\n";
    std::cout << std::stacktrace::current() << '\n';
    []{
        std::cout << "The stacktrace obtained in a nested lambda:\n";
        std::cout << std::stacktrace::current() << '\n';
    }();
}
