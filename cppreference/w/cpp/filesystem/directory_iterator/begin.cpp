#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    fs::create_directories("sandbox/a/b");
    std::ofstream("sandbox/file1.txt");
    std::ofstream("sandbox/file2.txt");
#ifndef __clang__
    for (auto &p : fs::directory_iterator("sandbox"))
        std::cout << p << '\n';
#endif
    fs::remove_all("sandbox");
}