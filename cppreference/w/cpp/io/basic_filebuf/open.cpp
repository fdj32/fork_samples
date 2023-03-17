
 #include <fstream>
#include <iostream>

int main()
{
    std::string filename = "Test.b";
    std::filebuf fb;

    // prepare a file to read
    double d = 3.14;
    if (!fb.open(filename, std::ios::binary | std::ios::out))
    {
        std::cout << "Open file " << filename << " for write failed\n";
        return 1;
    } 
    fb.sputn(reinterpret_cast<char*>(&d), sizeof d);
    fb.close();

    // open file for reading
    double d2 = 0.0;
    if (!fb.open(filename, std::ios::binary | std::ios::in))
    {
        std::cout << "Open file " << filename << " for read failed\n";
        return 1;
    }

    auto got = fb.sgetn(reinterpret_cast<char*>(&d2), sizeof d2);
    if (sizeof(d2) != got)
        std::cout << "Read of " << filename << " failed\n";
    else
        std::cout << "Read back from file: " << d2 << '\n';
}
