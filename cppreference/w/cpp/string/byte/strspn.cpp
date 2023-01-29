#include <cstring>
#include <string>
#include <iostream>
 
const char *low_alpha = "qwertyuiopasdfghjklzxcvbnm";
int main()
{
    std::string s = "abcde312$#@";
 
    std::size_t spnsz = std::strspn(s.c_str(), low_alpha);
    std::cout << "After skipping initial lowercase letters from '" << s
              << "'\nThe remainder is '" << s.substr(spnsz) << "'\n";
}