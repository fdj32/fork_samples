#include <chrono>
 
int main()
{
    constexpr std::chrono::month_weekday_last mwdl1 {
                  std::chrono::March/std::chrono::Friday[std::chrono::last]
              };
    constexpr std::chrono::month_weekday_last mwdl2 {
                  std::chrono::March,
                  std::chrono::Friday[std::chrono::last]
              };
    static_assert(mwdl1 == mwdl2);
}