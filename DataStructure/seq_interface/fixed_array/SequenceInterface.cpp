#include "SequenceInterface.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
SequenceInterface<T>::SequenceInterface(
    const SequenceInterface & seqToCopy)
    : length(seqToCopy.get_length()),
    seq(new T[seqToCopy.get_length()+1])
    {
        for ( size_t i = 0; i <= seqToCopy.get_length(); ++i )
            seq[ i ] = seqToCopy.seq[ i ];
    }

template<typename T>
SequenceInterface<T>::SequenceInterface( size_t len)
: length(len >= 0 ? len-1:
throw invalid_argument( "Array size must be greater than 0" )),
seq(len >0 ? new T[len] : nullptr){
    if(get_seq())
    for(size_t i =0; i<= get_length(); i++)
        seq[i] = T();
}

template<typename T>
SequenceInterface<T>::~SequenceInterface(){
    if(get_seq())
        {
        delete []get_seq();
        std::cout << " delete memory "<< std::endl;
        }
}

template<typename T>
T* SequenceInterface<T>::get_seq() const {
    return seq;
}

template<typename T>
void SequenceInterface<T>::set_seq(  T* new_adrs){
    if(seq){
        delete []seq;
        seq = nullptr;
    }
    seq = new_adrs;
}

template<typename T>
size_t SequenceInterface<T>::get_length() const {
    if(length >= 0)
        return length;
    else return -1;
}

template<typename T>
void SequenceInterface<T>::set_length(  size_t len){
    if(len>=0)
        length = len;
}
template<typename T>
T &SequenceInterface<T>::operator[](int subscript){
    if (subscript < 0 || subscript > get_length())
    {
        string error = "The range must be 0-"+to_string(get_length());
        throw invalid_argument(error);
    } 
    return seq[subscript];
}

template<typename T>
T SequenceInterface<T>::operator[](int subscript) const{
    if (subscript <0 || subscript > get_length())
    {
        string error = "The range must be 0-"+to_string(get_length());
        throw invalid_argument(error);
    } 
    return seq[subscript];
}
template<typename T>
bool SequenceInterface<T>::operator==(
    const SequenceInterface  &right) const{
        if (length != right.length)
            return false;
        for(size_t i=0; i<= get_length(); i++ )
            if (get_at(i) != right.get_at(i))
                return false;
        return true;
    }
template<typename T>
bool SequenceInterface<T>::operator!=(
    const SequenceInterface &right) const{
        return !(*this == right);
    }
