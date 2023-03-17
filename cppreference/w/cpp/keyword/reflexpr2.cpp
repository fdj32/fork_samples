
 #include <string>
#include <string_view>
#include <iostream>
// Reflection TS
#include <experimental/reflect>
template <typename Tp>
constexpr std::string_view nameof() {
 using TpInfo = reflexpr(Tp);
 using aliased_Info = std::experimental::reflect::get_aliased_t<TpInfo>;
 return std::experimental::reflect::get_name_v<aliased_Info>;
}

int main(){
 std::cout << nameof<std::string>() << '\n';
 static_assert(nameof<std::string>() == "basic_string"); // successful
}
