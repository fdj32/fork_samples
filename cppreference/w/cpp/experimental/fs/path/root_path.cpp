
 #include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main()
{
    std::cout << "Current root path is: " << fs::current_path().root_path() << '\n';
}
