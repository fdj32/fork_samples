
 #include <array>
#include <iostream>

int main()
{
    std::array<char, 6> letters {'a', 'b', 'c', 'd', 'e', 'f'};

    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
    }  
}
