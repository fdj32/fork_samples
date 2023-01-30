#include <cassert>
#include <iostream>
#include <string>
#include <variant>
#include <vector>
 
using vector_t = std::vector<int>;
 
auto& operator<<(auto& out, const vector_t& v)
{
    out << "{ ";
    for (int e: v)
        out << e << ' ';
    return out << "}";
}
 
int main()
{
    // value-initializes first alternative
    std::variant<int, std::string> var0;
    assert(std::holds_alternative<int>(var0) and
           var0.index() == 0 and
           std::get<int>(var0) == 0);
 
    // initializes first alternative with std::string{"STR"};
    std::variant<std::string, int> var1{"STR"};
    assert(var1.index() == 0);
    std::cout << "1) " << std::get<std::string>(var1) << '\n';
 
    // initializes second alternative with int == 42;
    std::variant<std::string, int> var2{42};
    assert(std::holds_alternative<int>(var2));
    std::cout << "2) " << std::get<int>(var2) << '\n';
 
    // initializes first alternative with std::string{4, 'A'};
    std::variant<std::string, vector_t, float> var3
    {
        std::in_place_type<std::string>, 4, 'A'
    };
    assert(var3.index() == 0);
    std::cout << "3) " << std::get<std::string>(var3) << '\n';
 
    // initializes second alternative with std::vector{1,2,3,4,5};
    std::variant<std::string, vector_t, char> var4
    {
        std::in_place_type<vector_t>, {1,2,3,4,5}
    };
    assert(var4.index() == 1);
    std::cout << "4) " << std::get<vector_t>(var4) << '\n';
 
    // initializes first alternative with std::string{"ABCDE", 3};
    std::variant<std::string, vector_t, bool> var5 {std::in_place_index<0>, "ABCDE", 3};
    assert(var5.index() == 0);
    std::cout << "5) " << std::get<std::string>(var5) << '\n';
 
    // initializes second alternative with std::vector(4, 42);
    std::variant<std::string, vector_t, char> var6 {std::in_place_index<1>, 4, 42};
    assert(std::holds_alternative<vector_t>(var6));
    std::cout << "6) " << std::get<vector_t>(var6) << '\n';
}