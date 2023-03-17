
 #include <deque>
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    std::deque<std::string> letters;

    letters.push_front("abc");
    std::string s{"def"};
    letters.push_front(std::move(s));

    std::cout << "std::deque `letters` holds: ";
    for (auto&& e : letters) std::cout << std::quoted(e) << ' ';

    std::cout << "\nMoved-from string `s` holds: " << std::quoted(s) << '\n';
}
