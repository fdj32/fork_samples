#include <string>
#include <iostream>
 
int main()
{
  std::string foo("quuuux");
  // brace-initialization initializes all characters to 0, providing a null-terminator
  char bar[7]{};
  foo.copy(bar, sizeof bar - 1); // don't use the last char to guarantee null-termination
  std::cout << bar << '\n';      // requires bar to be null-terminated
}