
 #include <optional>
#include <iostream>

int main()
{
    std::cout << std::boolalpha;

    std::optional<int> opt;
    std::cout << opt.has_value() << '\n';

    opt = 43;
    if (opt)
        std::cout << "value set to " << opt.value() << '\n';
    else
        std::cout << "value not set\n";

    opt.reset();
    if (opt.has_value())
        std::cout << "value still set to " << opt.value() << '\n';
    else
        std::cout << "value no longer set\n";
}
