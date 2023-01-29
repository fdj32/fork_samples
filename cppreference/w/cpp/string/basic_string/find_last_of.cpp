#include <string>
#include <iostream>
 
int main()
{
    const std::string path = "/root/config";
    auto const pos = path.find_last_of('/');
    const auto leaf = path.substr(pos + 1);
 
    std::cout << leaf << '\n';
}