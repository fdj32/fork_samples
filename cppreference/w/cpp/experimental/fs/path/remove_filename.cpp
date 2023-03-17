
 #include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main()
{

    std::cout << fs::path("/foo").remove_filename() << '\n'
              << fs::path("/").remove_filename() << '\n';
}
