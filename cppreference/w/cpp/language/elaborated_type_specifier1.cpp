
 class T {
public:
    class U;
private:
    int U;
};

int main()
{
    int T;
    T t; // error: the local variable T is found
    class T t; // OK: finds::T, the local variable T is ignored
    T::U* u; // error: lookup of T::U finds the private data member
    class T::U* u; // OK: the data member is ignored
}
