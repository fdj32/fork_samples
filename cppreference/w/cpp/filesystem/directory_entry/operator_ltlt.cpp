#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    const auto entries = {
        fs::directory_entry{fs::current_path()},
        fs::directory_entry{fs::temp_directory_path()}};
#ifndef __clang__
    for (const fs::directory_entry &de : entries)
    {
        std::cout << de << '\n';
    }
#endif
}