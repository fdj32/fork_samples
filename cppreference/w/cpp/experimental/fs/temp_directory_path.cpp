
 #include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
int main()
{
    std::cout << "Temp directory is " << fs::temp_directory_path() << '\n';
}
