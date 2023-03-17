
 #include <fstream>
#include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main()
{
    fs::create_directories("sandbox/a/b");
    std::ofstream{"sandbox/file1.txt"};
    std::ofstream{"sandbox/file2.txt"};
    for(const fs::directory_entry& entry: fs::directory_iterator{"sandbox"})
        std::cout << entry << '\n';
    fs::remove_all("sandbox");
}
