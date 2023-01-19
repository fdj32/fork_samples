#include <iostream>
#include <fstream>
#include <locale>
 
template<typename CharT>
int get_encoding(const std::basic_istream<CharT>& stream)
{
    using Facet = std::codecvt<CharT, char, std::mbstate_t>;
    return std::use_facet<Facet>(stream.getloc()).encoding();
}
 
int main()
{
    // prepare a 10-byte file holding 4 characters ("zß水𝄋") in UTF-8
    std::ofstream("text.txt") << "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9d\x84\x8b";
 
    // open using a non-converting encoding
    std::ifstream f1("text.txt");
    std::cout << "f1's locale's encoding() returns "
              << get_encoding(f1) << '\n'
              << "pubseekoff(3, beg) returns "
              << f1.rdbuf()->pubseekoff(3, std::ios_base::beg) << '\n'
              << "pubseekoff(0, end) returns "
              << f1.rdbuf()->pubseekoff(0, std::ios_base::end) << '\n';
 
    // open using UTF-8
    std::wifstream f2("text.txt");
    f2.imbue(std::locale("en_US.UTF-8"));
    std::cout << "f2's locale's encoding() returns "
              << get_encoding(f2) << '\n'
              << "pubseekoff(3, beg) returns "
              << f2.rdbuf()->pubseekoff(3, std::ios_base::beg) << '\n'
              << "pubseekoff(0, end) returns "
              << f2.rdbuf()->pubseekoff(0, std::ios_base::end) << '\n';
}