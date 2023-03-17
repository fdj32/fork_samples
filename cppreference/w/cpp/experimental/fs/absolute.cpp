
 #include <iostream>
#include <filesystem>
namespace fs = std::experimental::filesystem;
int main()
{
    fs::path p = "C:cl.exe";
    std::cout << "Current path is " << fs::current_path() << '\n'
              << "Absolute path for " << p << " is " << fs::absolute(p) << '\n'
	      << "System complete path for " << p << " is " << fs::system_complete(p) << '\n';
}
