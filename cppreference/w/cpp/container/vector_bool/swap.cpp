
 #include <vector>
#include <iostream>

int main()
{
    std::vector<bool> vb1{ 1,0 };

    for (auto e : vb1) { std::cout << e << " "; }
    std::cout << '\n';

    vb1.swap(vb1[0], vb1[1]);

    for (auto e : vb1) { std::cout << e << " "; }
}
