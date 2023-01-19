#include <string>
#include <fstream>
#include <iostream>
//this file is called main.cpp
 
bool file_exists(const std::string& str)
{
   std::ifstream fs(str);
   return fs.is_open();
}
 
int main()
{
  std::boolalpha(std::cout);
  std::cout << file_exists("main.cpp")  << '\n'
            << file_exists("strange_file") << '\n';
}