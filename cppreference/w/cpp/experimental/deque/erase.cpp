
 #include <experimental/deque>
#include <iostream>

auto show = [](const auto& container)
{
    for (auto e : container)
        std::cout << e;
    std::cout << '\n';
};

int main()
{
    std::deque<int> data{1,1,1,4,1,1,1,2,1,1,1};
    show(data);
    std::experimental::erase(data, 1);
    show(data);
}
