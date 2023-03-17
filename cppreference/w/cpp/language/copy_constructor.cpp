
 struct A
{
    int n;
    A(int n = 1) : n(n) {}
    A(const A& a) : n(a.n) {} // user-defined copy constructor
};

struct B : A
{
    // implicit default constructor B::B()
    // implicit copy constructor B::B(const B&)
};

struct C : B
{
    C() : B() {}
private:
    C(const C&); // non-copyable, C++98 style
};

int main()
{
    A a1(7);
    A a2(a1); // calls the copy constructor

    B b;
    B b2 = b;
    A a3 = b; // conversion to A& and copy constructor

    volatile A va(10);
    // A a4 = va; // compile error

    C c;
    // C c2 = c; // compile error
}
