
 #include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    // prepare file
    std::ofstream("test.txt") << 1 << ' ' << 2 << '\n';
    std::FILE* f = std::fopen("test.txt", "r");

    std::vector<char> buf(4); // char is trivially copyable
    const std::size_t n = std::fread(&buf[0], sizeof buf[0], buf.size(), f);

    std::cout << "read " << n << " object" << (n > 1 ? "s" : "" ) << ": "
              << std::hex << std::showbase; 
    for (char n : buf)
        std::cout << static_cast<int>(n) << ' ';

    std::vector<std::string> buf2; // string is not trivially copyable
//  This would result in undefined behavior:
//  std::fread(&buf2[0], sizeof buf2[0], buf2.size(), f);
}
