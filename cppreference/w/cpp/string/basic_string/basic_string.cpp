#include <cassert>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
 
int main()
{
    std::cout << "1) string(); ";
    std::string s1;
    assert(s1.empty() && (s1.length() == 0) && (s1.size() == 0));
    std::cout << "s1.capacity(): " << s1.capacity() << '\n'; // unspecified
 
    std::cout << "2) string(size_type count, CharT ch): ";
    std::string s2(4, '=');
    std::cout << std::quoted(s2) << '\n'; // "===="
 
    std::cout << "3) string(const string& other, size_type pos, size_type count): ";
    std::string const other3("Exemplary");
    std::string s3(other3, 0, other3.length()-1);
    std::cout << quoted(s3) << '\n'; // "Exemplar"
 
    std::cout << "4) string(const string& other, size_type pos): ";
    std::string const other4("Mutatis Mutandis");
    std::string s4(other4, 8);
    std::cout << quoted(s4) << '\n'; // "Mutandis", i.e. [8, 16)
 
    std::cout << "5) string(CharT const* s, size_type count): ";
    std::string s5("C-style string", 7);
    std::cout << quoted(s5) << '\n'; // "C-style", i.e. [0, 7)
 
    std::cout << "6) string(CharT const* s): ";
    std::string s6("C-style\0string");
    std::cout << quoted(s6) << '\n'; // "C-style"
 
    std::cout << "7) string(InputIt first, InputIt last): ";
    char mutable_c_str[] = "another C-style string";
    std::string s7(std::begin(mutable_c_str) + 8, std::end(mutable_c_str) - 1);
    std::cout << quoted(s7) << '\n'; // "C-style string"
 
    std::cout << "8) string(string&): ";
    std::string const other8("Exemplar");
    std::string s8(other8);
    std::cout << quoted(s8) << '\n'; // "Exemplar"
 
    std::cout << "9) string(string&&): ";
    std::string s9(std::string("C++ by ") + std::string("example"));
    std::cout << quoted(s9) << '\n'; // "C++ by example"
 
    std::cout << "a) string(std::initializer_list<CharT>): ";
    std::string sa({'C', '-', 's', 't', 'y', 'l', 'e'});
    std::cout << quoted(sa) << '\n'; // "C-style"
 
    // before C++11, overload resolution selects string(InputIt first, InputIt last)
    // [with InputIt = int] which behaves *as if* string(size_type count, CharT ch)
    // after C++11 the InputIt constructor is disabled for integral types and calls:
    std::cout << "b) string(size_type count, CharT ch) is called: ";
    std::string sb(3, std::toupper('a'));
    std::cout << quoted(sb) << '\n'; // "AAA"
 
    [[maybe_unused]]
    auto zero = [] { /* ... */ return nullptr; };
//  std::string sc{zero()}; // Before C++23: throws std::logic_error
                            // Since C++23: won't compile, see overload (12)
}