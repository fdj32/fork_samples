
 #include <experimental/reflect>

namespace reflect = std::experimental::reflect;

template<reflect::Object M>
struct meta_t {
    template<reflect::Object M1>
    friend constexpr bool operator==(meta_t, meta_t<M1>) noexcept
    {
        return reflect::reflects_same_v<M, M1>;
    }
    template<reflect::Object M1>
    friend constexpr bool operator!=(meta_t, meta_t<M1>) noexcept
    {
        return !reflect::reflects_same_v<M, M1>;
    }
};

template<reflect::Object M>
constexpr meta_t<M> meta{};

int main()
{
    static_assert(meta<reflexpr(int)> == meta<reflexpr(signed int)>, "");
    // meta<int>; // error: int is not a meta-object type
}
