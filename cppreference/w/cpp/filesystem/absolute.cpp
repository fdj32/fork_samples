#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
 
int main()
{
    std::filesystem::path p = "foo.c";
    std::cout << "Current path is " << std::filesystem::current_path() << '\n';
    std::cout << "Absolute path for " << p << " is " << fs::absolute(p) << '\n';
}