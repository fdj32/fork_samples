#include <iomanip>
#include <iostream>
#include <string>
 
void print(int id, std::string::size_type n, std::string const& s);
 
int main()
{
    std::string::size_type n;
    std::string const s = "This is a string";  /*
                             ^  ^  ^
                             1  2  3           */
 
    // search from beginning of string
    n = s.find("is");
    print(1, n, s);
 
    // search from position 5
    n = s.find("is", 5);
    print(2, n, s);
 
    // find a single character
    n = s.find('a');
    print(3, n, s);
 
    // find a single character
    n = s.find('q');
    print(4, n, s);
}
 
void print(int id, std::string::size_type n, std::string const& s)
{
    std::cout << id << ") ";
    if (std::string::npos == n)
        std::cout << "not found! n == npos\n";
    else
        std::cout << "found @ n = " << n << ", substr(" << n << ") = "
                  << std::quoted(s.substr(n)) << "\n";
}