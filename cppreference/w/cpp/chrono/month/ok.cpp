
 #include <iostream>
#include <chrono>

int main()
{
    for (const unsigned mm : {6u, 0u, 16U}) {
        std::cout << mm << ": ";
        const std::chrono::month m{mm};
        m.ok() ? std::cout << "month is valid\n"
               : std::cout << "month is invalid\n";
    }
}
