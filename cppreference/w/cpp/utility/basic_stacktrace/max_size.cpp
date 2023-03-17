
 #include <iostream>
#include <stacktrace>

int main()
{
    std::stacktrace trace;
    std::cout << "Maximum size of a 'basic_stacktrace' is " << trace.max_size() << "\n";
}
