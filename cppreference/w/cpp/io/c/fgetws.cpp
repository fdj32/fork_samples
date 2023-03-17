
 #include <array>
#include <clocale>
#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <iostream>

int main()
{
    // Create temp file that contains wide characters
    std::setlocale(LC_ALL, "en_US.utf8");
    std::FILE* tmpf = std::tmpfile();

    for (const wchar_t* text :{
        L"Tétraèdre"    L"\n",
        L"Cube"         L"\n",
        L"Octaèdre"     L"\n",
        L"Icosaèdre"    L"\n",
        L"Dodécaèdre"   L"\n",
        })
        if (int rc = std::fputws(text, tmpf); rc == EOF) {
            std::perror("fputws()"); // POSIX requires that errno is set
            return EXIT_FAILURE;
        }

    std::rewind(tmpf);

    std::array<wchar_t, 16> buf;
    while (std::fgetws(buf.data(), buf.size(), tmpf) != nullptr)
        std::wcout << L'"' << buf.data() << L'"' << L'\n';

    return EXIT_SUCCESS;
}
