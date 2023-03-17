
 #include <iostream>
#include <sstream>

int main()
{
    int n;

    std::istringstream in;  // could also use in("1 2")
    in.rdbuf()->str("1 2"); // set the get area
    in >> n;
    std::cout << "after reading the first int from \"1 2\", the int is " 
              << n << ", str() = \"" << in.rdbuf()->str() << "\"\n"; // or in.str()

    std::ostringstream out("1 2");
    out << 3;
    std::cout << "after writing the int '3' to output stream \"1 2\""
              << ", str() = \"" << out.str() << "\"\n";

    std::ostringstream ate("1 2", std::ios_base::ate); // C++11
    ate << 3;
    std::cout << "after writing the int '3' to append stream \"1 2\""
              << ", str() = \"" << ate.str() << "\"\n";
}
