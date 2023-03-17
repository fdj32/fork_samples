
 #include <filesystem>
#include <iostream>

int main()
{
    for (auto const str:
    {
        "/usr/bin/cat",
        "/usr/bin/mouse",
        "/usr/bin/bison",
        "/usr/bin/c++",
    })
    {
        std::filesystem::directory_entry entry{str};

        std::cout << "directory entry " << entry
                  << (entry.exists() ? " exists" : " does not exist")
                  << '\n';
    }
}
