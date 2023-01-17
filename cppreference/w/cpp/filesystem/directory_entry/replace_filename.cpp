#include <iostream>
#include <filesystem>
 
int main()
{
    namespace fs = std::filesystem;
    {
        fs::directory_entry entry{ "omega" };
        std::cout << entry << '\n';
        entry.replace_filename("alpha");
        std::cout << entry << '\n';
    }{
        fs::directory_entry entry{ "/omega/" };
        std::cout << entry << '\n';
        entry.replace_filename("alpha");
        std::cout << entry << '\n';
    }
}