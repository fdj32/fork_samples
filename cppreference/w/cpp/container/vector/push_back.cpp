
 #include <vector>
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    std::vector<std::string> letters;

    letters.push_back("abc");
    std::string s{"def"};
    letters.push_back(std::move(s));

    std::cout << "std::vector `letters` holds: ";
    for (auto&& e : letters) std::cout << std::quoted(e) << ' ';

    std::cout << "\nMoved-from string `s` holds: " << std::quoted(s) << '\n';
}
