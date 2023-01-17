#include <iostream>
#include <filesystem>
#include <string>
int main() {
    std::filesystem::path p1; // an empty path
    p1 += "var"; // does not insert a separator
    std::cout << R"("" + "var" --> )" << p1 << '\n';
    p1 += "lib"; // does not insert a separator
    std::cout << R"("var" + "lib" --> )" << p1 << '\n';
    auto str = std::string{"1234567"};
    p1.concat(std::begin(str)+3, std::end(str)-1);
    std::cout << "p1.concat --> " << p1 << '\n';
}