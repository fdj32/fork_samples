
 int main()
{
    L"A" "B" "C"_x;  // OK: same as L"ABC"_x
    "P"_x "Q" "R"_y; // error: two different ud-suffixes (_x and _y)
}
