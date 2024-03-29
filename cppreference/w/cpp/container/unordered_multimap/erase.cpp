
 #include <unordered_map>
#include <iostream>

int main()
{
    std::unordered_multimap<int, std::string> c =
    {
        {1, "one" }, {2, "two" }, {3, "three"},
        {4, "four"}, {5, "five"}, {6, "six"  }
    };

    // erase all odd numbers from c
    for (auto it = c.begin(); it != c.end();)
    {
        if (it->first % 2 != 0)
            it = c.erase(it);
        else
            ++it;
    }

    for (auto& p : c)
        std::cout << p.second << ' ';
}
