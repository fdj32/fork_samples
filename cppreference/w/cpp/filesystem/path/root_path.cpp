#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
 
int main()
{
    std::cout << "Current root path is: " << fs::current_path().root_path() << '\n';
}