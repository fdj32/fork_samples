
 struct V
{
    V& operator=(V&& other)
    {
        // this may be called once or twice
        // if called twice, 'other' is the just-moved-from V subobject
        return *this;
    }
};

struct A : virtual V {}; // operator= calls V::operator=
struct B : virtual V {}; // operator= calls V::operator=
struct C : B, A {};      // operator= calls B::operator=, then A::operator=
                         // but they may only call V::operator= once

int main()
{
    C c1, c2;
    c2 = std::move(c1);
}
