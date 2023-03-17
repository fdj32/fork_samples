
 struct D;

struct B
{
    virtual operator D() = 0;
};

struct D : B
{
    operator D() override { return D(); }
};

int main()
{
    D obj;
    D obj2 = obj; // does not call D::operator D()
    B& br = obj;
    D obj3 = br;  // calls D::operator D() through virtual dispatch
}
