
 #include <iostream>
#include <map>
#include <string>

int main()
{
    int a[4] = {1, 2, 3, 4};
    int* p = &a[2];
    std::cout << p[1] << p[-1] << 1[p] << (-1)[p] << '\n';

    std::map<std::pair<int, int>, std::string> m;
    m[{1, 2}] = "abc"; // uses the [{...}] version
}
