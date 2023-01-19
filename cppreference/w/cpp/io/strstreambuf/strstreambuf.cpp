#include <strstream>
#include <iostream>
 
int main()
{
    std::strstreambuf dyn; // dynamic
    std::strstream dyn_s; // equivalent stream
    dyn_s << 1.23 << std::ends;
    std::cout << dyn_s.str() << '\n';
    dyn_s.freeze(false);
 
    char buf[10];
    std::strstreambuf user(buf, 10, buf); // user-provided output buffer
    std::ostrstream user_s(buf, 10); // equivalent stream
    user_s << 1.23 << std::ends;
    std::cout << buf << '\n';
 
    std::strstreambuf lit("1 2 3", 5); // constant
    std::istrstream lit_s("1 2 3"); // equivalent stream
    int i, j, k;
    lit_s >> i >> j >> k;
    std::cout << i << ' ' << j << ' ' << k << '\n';
}