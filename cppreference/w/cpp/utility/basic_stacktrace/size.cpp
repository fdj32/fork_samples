
 #include <stacktrace>
#include <iostream>

int main()
{ 
    auto trace = std::stacktrace::current();

    std::cout << "trace contains " << trace.size() << " entries.\n";
}
