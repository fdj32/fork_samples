
 #include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<char> letters {'a', 'b', 'c', 'd', 'e', 'f'};

    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
    }  
}
