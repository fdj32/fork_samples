
 #include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main()
{
    std::cout << "Current root name is: " << fs::current_path().root_name() << '\n';
}
