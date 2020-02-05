template <bool condition, typename Type>
struct EnableIf;
 
template <typename Type>
struct EnableIf<true, Type>
{
    using type = Type;
};

template <typename T, typename U>
struct IsSame
{
    static constexpr bool value = false;
};
 
template <typename T>
struct IsSame<T, T>
{
    static constexpr bool value = true;
};
