
 #include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v = {"once", "upon", "a", "time"};
    std::transform(v.cbegin(), v.cend(),
                   std::ostream_iterator<std::size_t>(std::cout, " "),
                   std::mem_fun_ref(&std::string::size));
}
