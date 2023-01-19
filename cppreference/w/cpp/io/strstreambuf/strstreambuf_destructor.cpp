#include <strstream>
#include <iostream>
 
void* my_alloc(size_t n)
{
    std::cout << "my_alloc(" << n << ") called\n";
    return new char[n];
}
 
void my_free(void* p)
{
    std::cout << "my_free() called\n";
    delete[] (char*)p;
}
 
int main()
{
    {
        std::strstreambuf buf(my_alloc, my_free);
        std::ostream s(&buf);
        s << 1.23 << std::ends;
        std::cout << buf.str() << '\n';
        buf.freeze(false);
    } // destructor called here, buffer deallocated
 
    {
        std::strstreambuf buf(my_alloc, my_free);
        std::ostream s(&buf);
        s << 1.23 << std::ends;
        std::cout << buf.str() << '\n';
//        buf.freeze(false);
    } // destructor called here, memory leak!
}