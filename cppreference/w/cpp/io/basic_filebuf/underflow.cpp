#include <fstream>
#include <iostream>
 
struct mybuf : std::filebuf
{
    int underflow() {
         std::cout << "Before underflow(): size of the get area is "
                   << egptr()-eback() << " with "
                   << egptr()-gptr() << " read positions available\n";
         int rc = std::filebuf::underflow();
         std::cout << "underflow() returns " << rc << ".\nAfter the call, "
                   << "size of the get area is "
                   << egptr()-eback() << " with "
                   << egptr()-gptr() << " read positions available\n";
        return rc;
    }
};
 
int main()
{
    mybuf buf;
    buf.open("test.txt", std::ios_base::in);
    std::istream stream(&buf);
    while(stream.get()) ;
}