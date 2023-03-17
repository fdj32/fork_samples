
 #include <functional>
#include <iostream>

struct S
{
    int get_data() const { return data; }
    void no_args() const { std::cout << "void S::no_args() const\n"; }
    void one_arg(int) { std::cout << "void S::one_arg()\n"; }
    void two_args(int, int) { std::cout << "void S::two_args(int, int)\n"; }
    int data{42};
};

int main() {
    S s;

    auto p = std::mem_fun(&S::get_data);
    std::cout << "s.get_data(): " << p(&s) << '\n';

    auto p0 = std::mem_fun(&S::no_args);
    p0(&s);
    auto p1 = std::mem_fun(&S::one_arg);
    p1(&s, 1);

//  auto p2 = std::mem_fun(&S::two_args); // Error: mem_fun supports only member functions
                                          // without parameters or with only one parameter.
                                          // Thus, std::mem_fn is a better alternative:
    auto p2 = std::mem_fn(&S::two_args);
    p2(s, 1, 2);

//  auto pd = std::mem_fun(&S::data); // Error: pointers to data members are not supported.
                                      // Use std::mem_fn instead:
    auto pd = std::mem_fn(&S::data);
    std::cout << "s.data = " << pd(s) << '\n';
}
