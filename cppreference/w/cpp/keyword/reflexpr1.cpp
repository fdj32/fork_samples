
 #include <string>
#include <vector>

struct S {
    int b;
    std::string s;
    std::vector<std::string> v;
};

// Reflection TS
#include <experimental/reflect>
using meta_S = reflexpr(S);
using mem = std::reflect::get_data_members_t<meta_S>;
using meta = std::reflect::get_data_members_t<mem>;
static_assert(std::reflect::is_public_v<meta>); // successful

int main() {}
