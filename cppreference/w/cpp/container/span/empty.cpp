
 #include <span>
#include <iostream>
#include <iomanip>

int main()
{
    std::span<const char> span{ "ABCDEF" };

    while (!span.empty()) {
        std::cout << std::quoted(span.data()) << '\n';
        span = span.last(span.size() - 1);
    }
}
