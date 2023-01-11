#include <wchar.h>
#include <stdio.h>
#include <locale.h>
 
int main(void)
{
    wchar_t *src = L"犬 means dog";
//  src[0] = L'狗' ; // this would be undefined behavior
    wchar_t dst[wcslen(src) + 1]; // +1 to accommodate for the null terminator
    wcscpy(dst, src);
    dst[0] = L'狗'; // OK
 
    setlocale(LC_ALL, "en_US.utf8");
    printf("src = %ls\ndst = %ls\n", src, dst);
}