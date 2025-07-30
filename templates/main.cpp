#include <iostream>
#include <cstring>

#include "temp_print.cpp"
 #include "max_temp.hpp"
#include "Person.cpp"
// #include "temp_array.cpp"
// #define getname(a) #a

int main()
{
    // int i{1};
    // print(&i);
    // //fmt::print(" how are you");
    // // std::string a= getname(vector);
    // // std::cout << a<< a[5];
    // // is_Array<int> n;
    // // std::cout<<n.get() ;

    Person a{"ahmed",40};
    Person b{"ali",36};
    std::cout << myMax(a,b);
    return 0;
}