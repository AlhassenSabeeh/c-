

#ifndef SMARTPOINTERINTERFACE_H
#define SMARTPOINTERINTERFACE_H

template <typename T>
class SmartPointerInterface
{
    T* ptr;
public:
    SmartPointerInterface() noexcept ;
    explicit SmartPointerInterface(T* p) noexcept;
    SmartPointerInterface(SmartPointerInterface const&) noexcept;
    SmartPointerInterface& operator=(SmartPointerInterface const&) noexcept;
    SmartPointerInterface(SmartPointerInterface&&) noexcept;
    SmartPointerInterface& operator=(SmartPointerInterface&&) noexcept;
    T& operator*() const   ;
    T* operator->() const noexcept;
    T* release() noexcept;
    void reset(T* = nullptr) noexcept;
    T* get() const noexcept;
    ~SmartPointerInterface() noexcept;
};

// template<typename T>
//     class SmartPointerInterface<T[]>{
//         T ptr;
//     public:
//         SmartPointerInterface() noexcept ;
//         T& operator*() const   ;
//     };
//     T ptr;
// public:
//     SmartPointerInterface() noexcept ;
//     explicit SmartPointerInterface(T* ) noexcept;
//     SmartPointerInterface(SmartPointerInterface const&) noexcept;
//     SmartPointerInterface& operator=(SmartPointerInterface const&) noexcept;
//     SmartPointerInterface(SmartPointerInterface&&) noexcept;
//     SmartPointerInterface& operator=(SmartPointerInterface&&) noexcept;
//     T& operator*() const   ;
//     T* operator->() const noexcept;
//     T* release() noexcept;
//     void reset(T* = nullptr) noexcept;
//     T* get() const noexcept;
//     ~SmartPointerInterface() noexcept;
    
// };

#endif