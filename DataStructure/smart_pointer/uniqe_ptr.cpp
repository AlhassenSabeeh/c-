#ifndef UNIQE_PTR_H
#define UNIQE_PTR_H

template <typename T>

class Uniqe_Ptr : public SmartPointerInterface<T>
{

public:
    Uniqe_Ptr() noexcept
    : SmartPointerInterface<T>::SmartPointerInterface() {}
    Uniqe_Ptr(T* p) noexcept
    : SmartPointerInterface<T>::SmartPointerInterface(p) {}
    Uniqe_Ptr(Uniqe_Ptr&& rhs) noexcept
    : SmartPointerInterface<T>::SmartPointerInterface(std::move(rhs))
    { std::cout<<"move constructor"<<std::endl; }
    Uniqe_Ptr(Uniqe_Ptr const& ) = delete;
    Uniqe_Ptr<T>& operator=(Uniqe_Ptr&& rhs) noexcept
    {
        if(this != &rhs)
        SmartPointerInterface<T>::operator=(std::move(rhs));
        std::cout << "move assin" << std::endl;
        return *this;
    }
    ~Uniqe_Ptr() noexcept 
    { std::cout <<"destructive of uniqe "<<std::endl;}
    

};

template <typename T, typename... args>
Uniqe_Ptr<T> Make_Uniqe(args&&... arg){
    return std::move(Uniqe_Ptr<T>(new T(arg...)));
}
#endif