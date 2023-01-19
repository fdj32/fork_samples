#include <strstream>
#include <iostream>
 
int main()
{
    std::strstream dyn; // dynamically-allocated output buffer
    dyn << "Test: " << 1.23 << std::ends;
    std::cout << "The size of the output is " << dyn.pcount()
              << " and it holds \"" << dyn.str() << "\"\n";
    dyn.freeze(false);
 
    char buf[10];
    std::strstream user(buf, 10); // user-provided output buffer
    user << 1.23; // note: no std::ends
    std::cout.write(buf, user.pcount());
    std::cout << '\n';
}