
 #include <iostream>
#include <iterator>
#include <string>

int main()
{
    std::string s;
    // assign(size_type count, CharT ch)
    s.assign(4, '=');
    std::cout << s << '\n'; // "===="

    std::string const c("Exemplary");
    // assign(basic_string const& str)
    s.assign(c);
    std::cout << c << " == " << s <<'\n'; // "Exemplary == Exemplary"

    // assign(basic_string const& str, size_type pos, size_type count)
    s.assign(c, 0, c.length()-1);
    std::cout << s << '\n'; // "Exemplar";

    // assign(basic_string&& str)
    s.assign(std::string("C++ by ") + "example");
    std::cout << s << '\n'; // "C++ by example"

    // assign(CharT const* s, size_type count)
    s.assign("C-style string", 7);
    std::cout << s << '\n'; // "C-style"

    // assign(CharT const* s)
    s.assign("C-style\0string");
    std::cout << s << '\n'; // "C-style"

    char mutable_c_str[] = "C-style string";
    // assign(InputIt first, InputIt last)
    s.assign(std::begin(mutable_c_str), std::end(mutable_c_str)-1);
    std::cout << s << '\n'; // "C-style string"

    // assign(std::initializer_list<CharT> ilist)
    s.assign({ 'C', '-', 's', 't', 'y', 'l', 'e' });
    std::cout << s << '\n'; // "C-style"
}
