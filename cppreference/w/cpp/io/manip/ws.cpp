#include <iostream>
#include <iomanip>
#include <istream>
#include <sstream>
#include <string>
 
int main()
{
    for (const char* str: {"     #1 test", "\t #2 test", "#3 test"}) {
        std::string line;
        std::getline(std::istringstream{str}, line);
        std::cout << "getline returns: \t" << quoted(line) << '\n';
        std::istringstream iss{str};
        std::getline(iss >> std::ws, line);
        std::cout << "ws + getline returns: \t" << quoted(line) << '\n';
    }
}