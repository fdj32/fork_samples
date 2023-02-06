#include <iostream>
#include <memory>
 
int main()
{
    std::cout << "Pointer safety: ";
#ifdef __clang__
    switch (std::get_pointer_safety()) {
        case std::pointer_safety::strict:    std::cout << "strict\n"; break;
        case std::pointer_safety::preferred: std::cout << "preferred\n"; break;
        case std::pointer_safety::relaxed:   std::cout << "relaxed\n"; break;
    }
#endif
}