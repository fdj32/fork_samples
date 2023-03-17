
 #include <algorithm>
#include <iostream>
#include <queue>

int main()
{
    std::queue<int> container;

    std::cout << "Initially, container.size(): " << container.size() << '\n';

    for (int i = 0; i < 7; ++i)
        container.push(i);

    std::cout << "After adding elements, container.size(): " << container.size() << '\n';
}
