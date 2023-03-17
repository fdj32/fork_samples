
 #include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

std::string get_stem(const fs::path &p) { return p.stem().string(); }
void create_file(const fs::path &p) { std::ofstream o{p}; }

int main()
{
        const fs::path dir{"tmp_dir"};
        fs::create_directory(dir);
        create_file(dir / "one");
        create_file(dir / "two");
        create_file(dir / "three");

        for (const auto &file : fs::directory_iterator(dir)) {
                // Explicit conversion
                std::cout << get_stem(file.path()) << '\n';

                // Implicit conversion
                std::cout << get_stem(file) << '\n';
        }

        fs::remove_all(dir);
}
