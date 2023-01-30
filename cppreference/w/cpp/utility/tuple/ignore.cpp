#include <iostream>
#include <string>
#include <set>
#include <tuple>
 
[[nodiscard]] int dontIgnoreMe()
{
    return 42;
}
 
int main()
{
    std::ignore = dontIgnoreMe();
 
    std::set<std::string> set_of_str;
    bool inserted = false;
    std::tie(std::ignore, inserted) = set_of_str.insert("Test");
    if (inserted) {
        std::cout << "Value was inserted successfully\n";
    }
}