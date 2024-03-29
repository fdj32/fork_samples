
 #include <cassert>
#include <string>
#include <iomanip>
#include <iostream>

int main()
{
    std::string str("Short string!");
    std::cout << "before=" << std::quoted(str) << '\n';
    assert(str.size() == 13);

    str.pop_back();
    std::cout << " after=" << std::quoted(str) << '\n';
    assert(str.size() == 12);

    str.clear();
//  str.pop_back(); // undefined behavior
}
