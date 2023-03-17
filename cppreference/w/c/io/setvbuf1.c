
 int main(void) {
    char buf[BUFSIZ];
    setbuf(stdin, buf);
} // lifetime of buf ends, undefined behavior
