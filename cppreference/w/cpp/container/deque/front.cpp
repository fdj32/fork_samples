
 #include <deque>
#include <iostream>

int main()
{
    std::deque<char> letters {'a', 'b', 'c', 'd', 'e', 'f'};

    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
    }  
}
