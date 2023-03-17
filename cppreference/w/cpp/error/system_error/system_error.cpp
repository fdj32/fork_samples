
 #include <iostream>
#include <system_error>

int main()
{
    try
    {
        throw std::system_error(EDOM, std::generic_category(), "hello world");
    }
    catch (const std::system_error& ex)
    {
        std::cout << ex.code() << '\n';
        std::cout << ex.code().message() << '\n';
        std::cout << ex.what() << '\n';
    }
}
