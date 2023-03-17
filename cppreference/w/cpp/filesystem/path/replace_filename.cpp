
 #include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    std::cout << fs::path("/foo").replace_filename("bar") << '\n'
              << fs::path("/").replace_filename("bar") << '\n'
              << fs::path("").replace_filename("pub") << '\n';
}
