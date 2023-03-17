
 #include <experimental/simd>
#include <iostreams>

int main() 
{
    namespace stdx = std::experimental;
    std::cout << stdx::is_abi_tag_v<stdx::simd_abi::scalar> << '\n';
    std::cout << stdx::is_abi_tag_v<int> << '\n';
}
