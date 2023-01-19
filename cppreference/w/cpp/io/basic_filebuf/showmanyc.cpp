#include <fstream>
#include <iostream>
 
struct mybuf : std::filebuf
{
     using std::filebuf::showmanyc;
};
 
int main()
{
    mybuf fin;
    fin.open("main.cpp", std::ios_base::in);
    std::cout << "showmanyc() returns " << fin.showmanyc() << '\n';
}