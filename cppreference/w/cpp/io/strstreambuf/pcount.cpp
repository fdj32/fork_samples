#include <strstream>
#include <iostream>
 
int main()
{
    std::strstream dyn; // dynamically-allocated output buffer
    dyn << "Test: " << 1.23 << std::ends;
    std::strstreambuf* buf = dyn.rdbuf();
    std::cout << "The size of the output is "
              << buf->pcount() // or just buf.pcount()
              << " and it holds \"" << dyn.str() << "\"\n";
    dyn.freeze(false); // after calling .str() on a dynamic strstream
 
    char arr[10];
    std::ostrstream user(arr, 10); // user-provided output buffer
    buf = user.rdbuf();
    user << 1.23; // note: no std::ends
    std::cout.write(arr, buf->pcount()); // or just user.pcount()
    std::cout << '\n';
 
    std::istrstream lit("1 2 3"); // read-only fixed-size buffer
    buf = lit.rdbuf();
    // istrstream has no member pcount(), so lit.pcount() won't work
    std::cout << "Input-only pcount() = " << buf->pcount() << '\n';
}