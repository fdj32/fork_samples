
 #include <list>
#include <iostream>

int main()
{
    std::list<char> chars{'A', 'B', 'C', 'D'};

    for (; !chars.empty(); chars.pop_front())
    {
        std::cout << "chars.front(): '" << chars.front() << "'\n";
    }
}
