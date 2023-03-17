
 #include <exception>

int main()
{
    try
    {
        throw gcnew System::Exception("Managed exception");
    }
    catch (...)
    {
        std::exception_ptr ex = std::current_exception();
        try
        {
            std::rethrow_exception(ex);
        }
        catch (std::bad_exception const &)
        {
            // This will be printed.
            std::cout << "Bad exception" << std::endl;
        }
    }
}
