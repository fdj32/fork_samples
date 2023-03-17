
 #include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
int main()
{
    for(fs::path p : {"/var/tmp/example.txt", "/", "/var/tmp/."})
        std::cout << "The parent path of " << p
                  << " is " << p.parent_path() << '\n';
}
