
 class Foo;  // forward declaration of a class

class Bar { // definition of a class
  public:
    Bar(int i) : m_i(i) {}
  private:
    int m_i;
};

template <class T> // template argument
void qux() {
    T t;
}

enum class Pub { // scoped enum, since C++11
    b, d, p, q
};

int main()
{
    Bar Bar(1);
    class Bar Bar2(2); // elaborated type
}
