
 #include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main()
{
    fs::path p = "/foo/bar.jpeg";
    std::cout << "Was: " << p << '\n';
    p.replace_extension(".jpg");
    std::cout << "Now: " << p << '\n';
}
