#include <strstream>
int main()
{
    const std::istrstream buf("example");
    std::strstreambuf* ptr = buf.rdbuf();
}