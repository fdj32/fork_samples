#include <iostream>
#include <filesystem>
int main()
{
    std::cout << std::filesystem::current_path() << '\n';
    std::cout << std::filesystem::temp_directory_path() << '\n';
}