
 #include <cassert>
#include <iostream>
#include <set>

// Example module 97 key compare function
struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};

int main()
{
    std::set<int, ModCmp> cont{1, 2, 3, 4, 5};

    auto comp_func = cont.key_comp();

    for (int key : cont) {
        bool before = comp_func(key, 100);
        bool after = comp_func(100, key);
        if (!before && !after)
            std::cout << key << " equivalent to key 100\n";
        else if (before)
            std::cout << key << " goes before key 100\n";
        else if (after)
            std::cout << key << " goes after key 100\n";
        else
            assert(0); // Cannot happen
    }
}
