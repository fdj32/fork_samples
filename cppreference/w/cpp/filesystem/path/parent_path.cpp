
 #include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    for(fs::path p : {"/var/tmp/example.txt", "/", "/var/tmp/."})
        std::cout << "The parent path of " << p
                  << " is " << p.parent_path() << '\n';
}
