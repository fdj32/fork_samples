
 #include <iostream>
#include <sstream>

int main()
{
    std::ostringstream s;
    s.rdbuf()->sputc('a');
    std::cout << s.str() << '\n';
}
