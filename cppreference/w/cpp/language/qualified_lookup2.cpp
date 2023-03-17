
 struct A
{
    static int n;
};

int main()
{
    int A;
    A::n = 42; // OK: unqualified lookup of A to the left of:: ignores the variable
    A b;       // Error: unqualified lookup of A finds the variable A
}

template<int>
struct B : A {};

namespace N
{
    template<int>
    void B();

    int f()
    {
        return B<0>::n; // error: N::B<0> is not a type
    }
}
