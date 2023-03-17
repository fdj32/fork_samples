
 #include <stdexcept>
#include <iostream>

struct X
{
    X() { throw std::runtime_error(""); }

    // custom placement new
    static void* operator new(std::size_t count, bool b)
    {
        std::cout << "custom placement new called, b = " << b << '\n';
        return ::operator new(count);
    }

    // custom placement delete
    static void operator delete(void* ptr, bool b)
    {
        std::cout << "custom placement delete called, b = " << b << '\n';
        ::operator delete(ptr);
    }
};

int main()
{
    try
    {
        [[maybe_unused]] X* p1 = new (true) X;
    }
    catch(const std::exception&)
    {}
}
