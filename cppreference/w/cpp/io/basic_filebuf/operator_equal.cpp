// https://en.cppreference.com/w/cpp/io/basic_filebuf/operator%3D
#include <fstream>
#include <string>
#include <iostream>
 
int main()
{
 
    std::ifstream fin("test.in"); // read-only
    std::ofstream fout("test.out"); // write-only
 
    std::string s;
    getline(fin, s);
    std::cout << s << '\n'; // output
 
    *fin.rdbuf() = std::move(*fout.rdbuf());
 
    getline(fin, s);
    std::cout << s << '\n'; // empty line
 
    std::cout << std::boolalpha << fout.is_open() << '\n'; // prints "false"
 
}