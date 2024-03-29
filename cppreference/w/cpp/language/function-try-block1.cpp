
 #include <iostream>
#include <string>

struct S
{
    std::string m;

    S(const std::string& str, int idx)
    try : m(str, idx)
    {
        std::cout << "S(" << str << ", " << idx << ") constructed, m = " << m << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << "S(" << str << ", " << idx << ") failed: " << e.what() << '\n';
    } // implicit "throw;" here for constructor
};

int main()
{
    S s1{"ABC", 1}; // does not throw (index is in bounds)

    try
    {
        S s2{"ABC", 4}; // throws (out of bounds)
    }
    catch (std::exception& e)
    {
        std::cout << "S s2... raised an exception: " << e.what() << '\n';
    }
}
