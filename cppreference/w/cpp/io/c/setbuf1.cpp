
 int main() {
    char buf[BUFSIZ];
    std::setbuf(stdin, buf);
} // lifetime of buf ends, undefined behavior
