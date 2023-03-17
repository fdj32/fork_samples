
 #include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    fs::current_path(fs::temp_directory_path());
    fs::create_directories("sandbox/a/b/c");
    fs::create_directories("sandbox/a/b/d/e");
    std::ofstream("sandbox/a/b/file1.txt");
    fs::create_symlink("a", "sandbox/syma");
    for(auto i = fs::recursive_directory_iterator("sandbox");
             i != fs::recursive_directory_iterator();
           ++i ) {
        std::cout << std::string(i.depth(), ' ') << *i;
        if(fs::is_symlink(i->symlink_status()))
            std::cout << " -> " << fs::read_symlink(*i);
        std::cout << '\n';
    }
    fs::remove_all("sandbox");
}
