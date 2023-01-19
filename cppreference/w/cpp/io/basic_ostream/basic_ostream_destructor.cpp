// https://en.cppreference.com/w/cpp/io/basic_ostream/~basic_ostream
#include <sstream>
#include <iostream>
void add_words(std::streambuf* p)
{
    std::ostream buf(p); // buf shares the buffer with s
    buf << " is the answer";
} // calls the destructor of buf. p remains unaffected
int main()
{
    std::ostringstream s;
    s << 42;
    add_words(s.rdbuf());
    s << ".";
    std::cout << s.str() << '\n';
}