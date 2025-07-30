#include "consepts.hpp"
//#include <concepts>
template<typename T>
requires SupportsLessThan<T> && Copyable<T>
T&  myMax(T a,T b) 
{
    return a < b ? b:a;
}