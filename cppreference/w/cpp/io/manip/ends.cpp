#include <cstdio>
#include <strstream>
int main()
{
    std::ostrstream oss;
    oss << "Sample text: " << 42 << std::ends;
    std::printf("%s\n", oss.str());
    oss.freeze(false); // enable memory deallocation
}