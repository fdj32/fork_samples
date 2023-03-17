
 #include <strstream>
int main()
{
    const std::strstream buf;
    std::strstreambuf* ptr = buf.rdbuf();
}
