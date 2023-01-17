#include <iostream>
#include <regex>
#include <string>
 
int main()
{
  std::regex re("a(a)*b");
  std::string target("baaaby");
  std::smatch sm;
 
  std::regex_search(target, sm, re);
  std::cout << sm.prefix().str() << '\n';
}