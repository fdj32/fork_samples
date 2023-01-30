#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
 
class S {
    inline static int n{1};
    int m{};
    void pre() const { std::cout << "#" << m << std::string(m, ' '); }
public:
    S(int x) : m{n++} { pre(); std::cout << "S::S(" << x << ");\n"; }
    ~S() { pre(); std::cout << "S::~S();\n"; }
    void id() const { pre(); std::cout << "S::id();\n"; }
};
 
int main() {
    constexpr std::size_t n{4};
    std::allocator<S> allocator;
    try {
        S* s = allocator.allocate(n); // may throw
        for (std::size_t i{}; i != n; ++i) {
        //  allocator.construct(&s[i], i+42); // removed in C++20
            std::construct_at(&s[i], i+42); // since C++20
        }
        std::for_each_n(s, n, [](const auto& e) { e.id(); });
        std::destroy_n(s, n);
        allocator.deallocate(s, n);
    }
    catch(std::bad_array_new_length const& ex) { std::cout << ex.what() << '\n'; }
    catch(std::bad_alloc const& ex) { std::cout << ex.what() << '\n'; }
}