
 #include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main()
{
    std::cout << fs::path("/foo/bar.txt").stem() << '\n'
              << fs::path("/foo/.bar").stem() << '\n';

    for (fs::path p = "foo.bar.baz.tar"; !p.extension().empty(); p = p.stem())
        std::cout << p.extension() << '\n';
}
