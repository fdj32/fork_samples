int main(void) // the main function definition
{
    int sum(int, int); // function declaration (may appear at any scope)
    int x = 1;  // local variable in main
    sum(1, 2); // function call
 
//    int sum(int a, int b) // error: no nested functions
//    {
//        return  a + b; 
//    }
}
int sum(int a, int b) // function definition
{
//    return x + a + b; //  error: main's x is not accessible within sum
    return a + b;
}