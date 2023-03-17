
 #include <iostream>
#include <fstream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
int main()
{
    fs::path p = fs::current_path() / "example.bin";
    std::ofstream(p).put('a'); // create file of size 1
    std::cout << "File size = " << fs::file_size(p) << '\n';
    fs::remove(p);

    try {
        fs::file_size("/dev"); // attempt to get size of a directory
    } catch(fs::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }        
}
