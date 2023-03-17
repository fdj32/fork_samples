
 #include <generator>
#include <ranges>
#include <iostream>

std::generator<char> letters(char first)
{
    for (;; co_yield first++);
}

int main()
{
    for (const char ch : letters('a') | std::views::take(032))
        std::cout << ch << ' ';
    std::cout << '\n';
}
