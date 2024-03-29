
 #include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
int main() {
    fs::path p1 = "C:Users";
    std::cout << "\"C:\" / \"Users\" == " << p1 << '\n';
    fs::path p2 ="batman";
    fs::path p3 = p1 / p2; // inserts fs::path::preferred_separator, '\' on Windows
    std::cout << "\"C:\" / \"Users\" / \"batman\" == " << p3 << '\n';
}
