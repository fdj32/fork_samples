
 #include <iostream>

// class-specific allocation functions
struct X
{
    static void* operator new(std::size_t count)
    {
        std::cout << "custom new for size " << count << '\n';
        return ::operator new(count);
    }

    static void* operator new[](std::size_t count)
    {
        std::cout << "custom new[] for size " << count << '\n';
        return ::operator new[](count);
    }
};

int main()
{
    X* p1 = new X;
    delete p1;
    X* p2 = new X[10];
    delete[] p2;
}
