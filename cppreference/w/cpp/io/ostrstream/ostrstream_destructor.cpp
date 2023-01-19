#include <strstream>
#include <iostream>
 
int main()
{
    {
        std::ostrstream s; // dynamic buffer 
        s << 1.23;
        std::cout << s.str() << '\n';
        s.freeze(false);
    } // destructor called, buffer deallocated 
 
    {
        std::ostrstream s;
        s << 1.23;
        std::cout << s.str() << '\n';
//        buf.freeze(false);
    } // destructor called, memory leaked
}