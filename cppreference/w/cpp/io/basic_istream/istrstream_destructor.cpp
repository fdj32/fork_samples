// https://en.cppreference.com/w/cpp/io/istrstream/~istrstream
#include <strstream>
#include <iostream>
 
int main()
{
    {
        std::istrstream s("1.234");
        double d;
        s >> d;
        std::cout << d << '\n';
    } // destructor called
}