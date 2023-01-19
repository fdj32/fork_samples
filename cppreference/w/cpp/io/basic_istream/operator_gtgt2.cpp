#include <iostream>
#include <iomanip>
#include <sstream>
 
int main()
{
    std::string input = "n greetings";
    std::istringstream stream(input);
 
    char c;
    const int MAX = 6;
    char cstr[MAX];
 
    stream >> c >> std::setw(MAX) >> cstr;
    std::cout << "c = " << c << '\n'
              << "cstr = " << cstr << '\n';
 
    double f;
    std::istringstream("1.23") >> f; // rvalue stream extraction
    std::cout << "f = " << f << '\n';
}