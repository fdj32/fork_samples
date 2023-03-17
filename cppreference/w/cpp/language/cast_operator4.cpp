
 struct B {};

struct X : B
{
    operator B&() { return *this; };
};

int main()
{
    X x;
    B& b1 = x;                  // does not call X::operatorB&()
    B& b2 = static_cast<B&>(x); // does not call X::operatorB&
    B& b3 = x.operator B&();    // calls X::operatorB&
}
