#include <iostream>
#include "FixedArray.cpp"

// template<typename T>
// void print(const T& call)
// {
//     for(const auto& elemnt: call)
//     {
//         std::cout << elemnt << "\n";
//     }
// }
void printf( FixedArray<int,5>  call) 
{
    std::cout << call;
}