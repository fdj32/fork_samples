
 void f(int) {}
void f(double) {}

struct A { int i; };
struct B { void f(); };

int main()
{
    int n = 1;
    int* pn = &n;    // pointer
    int* pn2 = &*pn; // pn2 == pn

    int A::* mp = &A::i;      // pointer to data member
    void (B::*mpf)() = &B::f; // pointer to member function

    void (*pf)(int) = &f; // overload resolution due to initialization context
//  auto pf2 = &f; // error: ambiguous overloaded function type
    auto pf2 = static_cast<void (*)(int)>(&f); // overload resolution due to cast
}
