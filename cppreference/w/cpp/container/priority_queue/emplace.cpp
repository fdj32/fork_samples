
 #include <iostream>
#include <queue>

struct S
{
    int id;

    S(int i, double d, std::string s) : id{i}
    {
        std::cout << "S::S(" << i << ", " << d << ", \"" << s << "\");\n";
    }

    friend bool operator< (S const& x, S const& y) { return x.id < y.id; }
};

int main()
{
    std::priority_queue<S> adaptor;

    adaptor.emplace(42, 3.14, "C++");

    std::cout << "id: " << adaptor.top().id << '\n';
}
