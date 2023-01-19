#include <strstream>
#include <iostream>
 
int main()
{
    char a[100] = {};
    std::strstream str;
    str.rdbuf()->pubsetbuf(a, sizeof a);
    str << "Test string" << std::ends;
    std::cout << "user-provided buffer holds \"" << a << "\"\n";
}