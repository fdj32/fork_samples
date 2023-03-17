
 #include <iostream>
#include <stack>

struct S
{
    int id;

    S(int i, double d, std::string s) : id{i}
    {
        std::cout << "S::S(" << i << ", " << d << ", \"" << s << "\");\n";
    }
};

int main()
{
    std::stack<S> adaptor;

    const S& s = adaptor.emplace(42, 3.14, "C++"); // for return value C++17 required

    std::cout << "id = " << s.id << '\n';
}
