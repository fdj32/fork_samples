
 #include <iostream>
#include <strstream>

int main()
{
    std::strstream dyn; // dynamically-allocated read/write buffer
    dyn << "Test: " << 1.23 << std::ends;
    std::strstreambuf* buf = dyn.rdbuf();
    std::cout << "R/W buffer holds [" << buf->str() // or dyn.str()
              << "]\n";
    dyn.freeze(false); // after calling .str() on a dynamic strstream

    char arr[10];
    std::ostrstream user(arr, 10); // fixed-size write-only buffer
    buf = user.rdbuf();
    user << 1.23 << std::ends;
    std::cout << "Write-only buffer holds [" << buf->str() // or user.str()
              << "]\n";

    std::istrstream lit("1 2 3"); // fixed-size read-only buffer
    buf = lit.rdbuf();
    std::cout << "Read-only buffer holds [" << buf->str() // or lit.str()
              << "]\n";
}
