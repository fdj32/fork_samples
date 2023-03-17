
 #include <iomanip>
#include <iostream>
#include <string>
#include <system_error>

int main()
{
    for (int const code : {EDOM, 10001})
    {
        const std::error_condition econd =
            std::system_category().default_error_condition(code);

        std::cout << "Category: " << econd.category().name() << '\n'
                  << "Value:    " << econd.value() << '\n'
                  << "Message:  " << econd.message() << "\n\n";
    }
}
