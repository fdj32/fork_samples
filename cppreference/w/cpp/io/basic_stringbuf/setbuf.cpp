#include <iostream>
#include <sstream>
 
int main()
{
    std::ostringstream ss;
    char c[1024] = {};
    ss.rdbuf()->pubsetbuf(c, 1024);
    ss << 3.14 << '\n';
    std::cout << c << '\n';
}