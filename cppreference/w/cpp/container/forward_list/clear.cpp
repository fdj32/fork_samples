
 #include <algorithm>
#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> container{1, 2, 3};

    auto print = [](const int& n) { std::cout << " " << n; };

    std::cout << "Before clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << '\n';

    std::cout << "Clear\n";
    container.clear();

    std::cout << "After clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << '\n';
}
