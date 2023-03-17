
 #include <cstdio>
#include <utility>
#include <source_location>

inline void print_function_name(
    const std::source_location& location = std::source_location::current())
{
    std::puts(location.function_name()); // prints the name of the caller
}

void foo(double &&) { print_function_name(); }

namespace bar { void baz() { print_function_name(); } }

template <typename T> auto pub(T) { print_function_name(); return 42; }

struct S {
    S() { print_function_name(); }
    S(int) { print_function_name(); }
    ~S() { print_function_name(); }
    S& operator=(S const&) { print_function_name(); return *this; }
    S& operator=(S&&) { print_function_name(); return *this; }
};

int main(int, char const* const[])
{
    print_function_name();
    foo(3.14);
    bar::baz();
    pub(0xFULL);
    S p;
    S q{42};
    p = q;
    p = std::move(q);
    [] { print_function_name(); }();
}
