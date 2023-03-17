
 #include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
int main()
{
    // on a typical Linux system, /lib/libc.so.6 is a symlink
    fs::path p = "/lib/libc.so.6";
    if(exists(p) && is_symlink(p))
        std::cout << p << " -> " << read_symlink(p) << '\n';
    else
        std::cout << p << " does not exist or is not a symlink\n";
}
