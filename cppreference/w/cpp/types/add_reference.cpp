#include <iostream>
#include <type_traits>
 
int main()
{
   using nonref = int;
   using lref = typename std::add_lvalue_reference<nonref>::type;
   using rref = typename std::add_rvalue_reference<nonref>::type;
   using voidref = std::add_lvalue_reference_t<void>;
 
   std::cout << std::boolalpha
             << std::is_lvalue_reference<nonref>::value << '\n'
             << std::is_lvalue_reference<lref>::value << '\n'
             << std::is_rvalue_reference<rref>::value << '\n'
             << std::is_reference_v<voidref> << '\n';
}