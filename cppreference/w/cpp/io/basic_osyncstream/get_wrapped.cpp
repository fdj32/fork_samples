#ifndef __clang__
#include <syncstream>
#endif
#include <iostream>
int main()
{
#ifndef __clang__
  std::osyncstream bout1(std::cout);
  bout1 << "Hello, ";
  {
    std::osyncstream(bout1.get_wrapped()) << "Goodbye, "
                                          << "Planet!" << '\n';
  } // emits the contents of the temporary buffer
  bout1 << "World!" << '\n';
#endif
} // emits the contents of bout1