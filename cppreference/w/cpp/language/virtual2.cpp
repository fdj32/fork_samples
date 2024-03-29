
 class B
{
    virtual void do_f(); // private member
public:
    void f() { do_f(); } // public interface
};

struct D : public B
{
    void do_f() override; // overrides B::do_f
};

int main()
{
    D d;
    B* bp = &d;
    bp->f(); // internally calls D::do_f();
}
