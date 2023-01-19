#include <strstream>
int main()
{
    const std::ostrstream buf;
    std::strstreambuf* ptr = buf.rdbuf();
}