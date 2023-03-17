
 #include <variant>
#include <iostream>

int main()
{
    auto check_value = [](const std::variant<int, float>& v)
    {
        if(const int* pval = std::get_if<int>(&v))
          std::cout << "variant value: " << *pval << '\n'; 
        else 
          std::cout << "failed to get value!" << '\n'; 
    };

    std::variant<int, float> v{12}, w{3.f};
    check_value(v);
    check_value(w);
}
