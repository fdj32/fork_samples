
 #include <iostream>
#include <unordered_set>

// print out a container
template <class Os, class K>
Os& operator<<(Os& os, const std::unordered_multiset<K>& v) {
    os << '[' << v.size() << "] {";
    bool o{};
    for (const auto& e : v)
        os << (o ? ", " : (o = 1, " ")) << e;
    return os << " }\n";
}

int main()
{
    std::unordered_multiset<char>
        p{ 'C', 'B', 'B', 'A' }, 
        q{ 'E', 'D', 'E', 'C' };

    std::cout << "p: " << p << "q: " << q;

    p.merge(q);

    std::cout << "p.merge(q);\n" << "p: " << p << "q: " << q;
}
