
 struct To
{
    To() = default;
    To(const struct From&) {} // converting constructor
};

struct From
{
    operator To() const {return To();} // conversion function
};

int main()
{
    From f;
    To t1(f);  // direct-initialization: calls the constructor
    // Note: if converting constructor is not available, implicit copy constructor
    // will be selected, and conversion function will be called to prepare its argument

//  To t2 = f; // copy-initialization: ambiguous
    // Note: if conversion function is from a non-const type, e.g.
    // From::operator To();, it will be selected instead of the ctor in this case

    To t3 = static_cast<To>(f); // direct-initialization: calls the constructor
    const To& r = f;            // reference-initialization: ambiguous
}
