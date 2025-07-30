#include "SmartPointerInterface.h"
#include <utility>
#include <iostream>
template <typename T>
SmartPointerInterface<T>::SmartPointerInterface() noexcept
:ptr(nullptr) { std::cout << " giniric ";}


template <typename T>
SmartPointerInterface<T*>::SmartPointerInterface()  
:ptr(nullptr) {std::cout << " partial ";}

template <typename T>
SmartPointerInterface<T>::SmartPointerInterface(T* p) noexcept
:ptr(p){}

// template<typename T>
// SmartPointerInterface<T[]>::SmartPointerInterface(T* p)  
// :ptr(p){}

// template <typename T>
// SmartPointerInterface<T[]>::SmartPointerInterface
// (unsigned int items ) noexcept
// :items(items)

// template<>
// SmartPointerInterface<T[]>::SmartPointerInterface
// (unsigned int n) noexcept : ptr(p[n]) {}

template <typename T>
SmartPointerInterface<T>::SmartPointerInterface
(SmartPointerInterface const &rhs) noexcept
:ptr(){}

template <typename T>
SmartPointerInterface<T>::SmartPointerInterface
(SmartPointerInterface &&rhs) noexcept
:ptr(std::exchange(rhs.ptr,nullptr))
{ std::cout<<"move constructor of base"<<std::endl;}

template <typename T>
SmartPointerInterface<T>::~SmartPointerInterface() noexcept
{ 
    delete[] ptr;
    std::cout <<"destructive of smart"<<std::endl;
}

template <typename T>
SmartPointerInterface<T>& SmartPointerInterface<T>::operator=
(SmartPointerInterface const &rhs) noexcept
{
    if(this != &rhs){
        delete ptr;
        ptr = nullptr;
        ptr = rhs.ptr;
    }
    std::cout<<"assign constructor of base"<<std::endl;
    return *this; 
}

template <typename T>
SmartPointerInterface<T>& SmartPointerInterface<T>::operator=
(SmartPointerInterface &&rhs) noexcept
{
    if(this != &rhs){
        delete ptr;
        ptr = nullptr;
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
    }
    return *this;
}

template <typename T>
T& SmartPointerInterface<T>::operator*() const 
{
    //if(ptr)
        return *ptr;
    //return  T();
    
    // try{
    //     if(!ptr) 
    //     throw 0;
    //     return *ptr;
    // }catch(...){
    //     std::cout<<" You try to derefrence null pointer! ";
    // }
}

template <typename T>
T* SmartPointerInterface<T>::operator->() const noexcept
{ return ptr; }

template <typename T>
T* SmartPointerInterface<T>::release() noexcept
{
    T* old = ptr;
    ptr = nullptr;
    return old;
}

template <typename T>
void SmartPointerInterface<T>::reset(T* p) noexcept
{
    delete ptr;
    ptr = p;
}

template <typename T>
T* SmartPointerInterface<T>::get() const noexcept
{ return ptr; }



// // specialization template





// template <typename T>
// SmartPointerInterface<T[]>::SmartPointerInterface() noexcept
// :ptr(nullptr){}

// template <typename T>
// SmartPointerInterface<T[]>::SmartPointerInterface(T* p) noexcept
// :ptr(p){}

// template <typename T>
// SmartPointerInterface<T[]>::SmartPointerInterface
// (SmartPointerInterface const &rhs) noexcept
// :ptr(rhs.ptr){}

// template <typename T>
// SmartPointerInterface<T[]>::SmartPointerInterface
// (SmartPointerInterface &&rhs) noexcept
// :ptr(std::exchange(rhs.ptr,nullptr))
// { std::cout<<"move constructor of base"<<std::endl;}

// template <typename T>
// SmartPointerInterface<T[]>::~SmartPointerInterface() noexcept
// { 
//     delete ptr;
//     std::cout <<"destructive of smart"<<std::endl;
// }