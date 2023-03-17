
 extern "C"
{
    int open(const char *pathname, int flags); // C function declaration
}

int main()
{
    int fd = open("test.txt", 0); // calls a C function from a C++ program
}

// This C++ function can be called from C code
extern "C" void handler(int)
{
    std::cout << "Callback invoked\n"; // It can use C++
}
