#include <iostream>
#include <exception>
#include <stdexcept>
 
void my_unexp() { throw; }
 
void test() throw(std::bad_exception)
{
    throw std::runtime_error("test");
}
 
int main()
{
    std::set_unexpected(my_unexp);
    try {
         test();
    } catch(const std::bad_exception& e)
    {
        std::cerr << "Caught " << e.what() << '\n';
    }
}