#include "SmartPointerInterface.cpp"
#include "Uniqe_Ptr.cpp"
#include <iostream>
#include "Person.cpp"
#include <utility>

int main()
{
     Uniqe_Ptr<int> a(new int());
     Uniqe_Ptr<int> b(std::move(a));
     std::cout <<*b;
     b = std::move(a);
    SmartPointerInterface<int[]> n;
     Uniqe_Ptr<Person> r {std::move(Make_Uniqe<Person>("ali",16))};
    SmartPointerInterface<Person[]> m;
    // SmartPointerInterface<Person> s{m};
    //Uniqe_Ptr<Person> b {std::move(a)};
    //Uniqe_Ptr<int> b(std::move(a));
    // b = std::move(a);a   

     std::cout << *m;
     //std::cout << *b;
    // int* p = new int[5];
    // std::cout << sizeof(p);

    
}
