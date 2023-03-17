
 #include <algorithm>
#include <iostream>
#include <stack>

int main()
{
    std::stack<int> container;

    std::cout << "Initially, container.size(): " << container.size() << '\n';

    for (int i = 0; i < 7; ++i)
        container.push(i);

    std::cout << "After adding elements, container.size(): " << container.size() << '\n';
}
