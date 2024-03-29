// https://en.cppreference.com/w/cpp/io/basic_streambuf/~basic_streambuf
#include <iostream>
#include <fstream>
 
int main()
{
    std::filebuf* fbp = new std::filebuf;
    fbp->open("test.txt", std::ios_base::out);
    fbp->sputn("Hello\n", 6);
 
    std::streambuf* sbp = fbp;
    delete sbp; // the file is closed, output flushed and written
 
    std::ifstream f("test.txt");
    std::cout << f.rdbuf(); // proof
}