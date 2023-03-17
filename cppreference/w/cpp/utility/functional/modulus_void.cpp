
 #include <functional>
#include <iostream>

struct M
{
    M(int x) { std::cout << "M(" << x << ");\n"; }
    M() {}
};

auto operator% (M, M) { std::cout << "operator% (M, M);\n"; return M{}; }
auto operator% (M, int) { std::cout << "operator% (M, int);\n"; return M{}; }
auto operator% (int, M) { std::cout << "operator% (int, M);\n"; return M{}; }

int main()
{
    M m1, m2;

    m1 % m2;
    m1 % 42;
    42 % m1;

    std::modulus<M>{}(m1, 42); // 42 is converted into a temporary M{42}
    std::modulus<> {}(m1, 42); // no temp. object, calls operator% (M, int)
    std::modulus<> {}(42, m1); // no temp. object, calls operator% (int, M)
}
