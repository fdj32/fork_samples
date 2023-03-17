
 #include <iostream>
#include <cstdlib>
#include <string>
#include <typeinfo>

#include <boost/core/demangle.hpp>

struct Base { virtual ~Base() = default; };
struct Derived : Base {};

int main()
{
    Base b1;
    Derived d1;

    const Base *pb = &b1;
    std::cout << typeid(*pb).name() << '\n';
    pb = &d1;
    std::cout << typeid(*pb).name() << '\n';

    std::string real_name = boost::core::demangle(typeid(pb).name());
    std::cout << typeid(pb).name() << " => " << real_name << '\n';

    std::cout << "c++filt => " << std::flush;
    std::string s = typeid(pb).name();
    std::system(("c++filt -t " + s).data());
}
