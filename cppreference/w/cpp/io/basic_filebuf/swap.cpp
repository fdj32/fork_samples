
 #include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::ifstream fin("test.in"); // read-only
    std::ofstream fout("test.out"); // write-only

    std::string s;
    getline(fin, s);
    std::cout << s << '\n'; // outputs the first line of test.in

    fin.rdbuf()->swap(*fout.rdbuf()); //swap the underlying buffers

    getline(fin, s); // fails: cannot read from a write-only filebuf
    std::cout << s << '\n'; // prints empty line
}
