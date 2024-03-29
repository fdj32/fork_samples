
 #include <iostream>
#include <memory>

struct Foo {
    void bar() { std::cout << "Foo::bar\n"; }
};

void f(const Foo&) 
{
    std::cout << "f(const Foo&)\n";
}

int main() 
{
    std::unique_ptr<Foo> ptr(new Foo);

    ptr->bar();
    f(*ptr);
}
