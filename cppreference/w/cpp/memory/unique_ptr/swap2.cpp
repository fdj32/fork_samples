#include <iostream>
#include <memory>
#include <string>
 
struct Foo {
    Foo(int _val) : val(_val) { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
    std::string print() { return std::to_string(val); }
    int val;
};
 
int main()
{
    std::unique_ptr<Foo> p1 = std::make_unique<Foo>(100);
    std::unique_ptr<Foo> p2 = std::make_unique<Foo>(200);
    auto print = [&]() {
        std::cout << " p1=" << (p1 ? p1->print() : "nullptr");
        std::cout << " p2=" << (p2 ? p2->print() : "nullptr") << '\n';  
    };
    print();
 
    std::swap(p1, p2);
    print();
 
    p1.reset();
    print();
 
    std::swap(p1, p2);
    print();   
}