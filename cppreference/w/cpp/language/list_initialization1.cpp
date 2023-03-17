
 struct X {}; // aggregate

struct Q     // non-aggregate
{
    Q() = default;
    Q(Q const&) = default;
    Q(std::initializer_list<Q>) {}
};

int main()
{
    X x;
    X x2 = X{x}; // copy-constructor (not aggregate initialization)

    Q q;
    Q q2 = Q{q}; // initializer-list constructor (not copy constructor)
}
