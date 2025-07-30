#include <cstddef>
#include <exception>
#include "FixedArray.hpp"
#include <string>

const string emptyError = "The fixed array is impty ii";
const string outOfRangeEr = "The index must be 0-";
// implemetation of PrintableInterface
template< typename T>
void FixedArray<T>::print() const {
    std::cout<< *this <<std::endl;
}



template< typename T>
std::ostream& operator<<(std::ostream &os, const FixedArray<T> &in){
    os <<"[";
    size_t i{0};
    for(i; i<in.get_size()-1 ;i++)
        os << in.get_at(i)  << ",";
        os << in.get_at(i);
    os <<"]";
    return os;
}

/*
template<typename T>
FixedArray<T>::FixedArray(T* sequnce)
: FixedArray<T>::SequenceInterface(/*sequnce,){
    build(sequnce);
}
*/


template< typename T>
FixedArray<T>::FixedArray(size_t len  )
: FixedArray<T>::SequenceInterface(len){} // length(N-1) ,seq(nullptr) {}
template<typename T>
FixedArray<T>::FixedArray(const FixedArray & FixArrToCopy)
: FixedArray<T>::SequenceInterface(FixArrToCopy)
{}
template< typename T>
T& FixedArray<T>::get_at(  size_t index) const {
    return  *(this->get_seq()+index);
}


template<typename T>
void FixedArray<T>::set_at(const T item,const size_t index){
    *(this->get_seq()+index) = item;
}
template< typename T>
void FixedArray<T>::insert_first(const T item )  {

    rebuild_up(0);
    set_at(item,0);

}
template< typename T>
void FixedArray<T>::rebuild_up(size_t index){
    this->set_length(this->get_length()+1);
    T* last{nullptr};
    last = new T[this->get_length()+1];
    if(this->get_seq())
        reinsert(this->get_seq(),last,index);
    this->set_seq(last);
    last = nullptr; 
    //delete []last;
}

template< typename T> 
void FixedArray<T>::build( T* sequnce){
    size_t index = 0;
    build_init(sequnce,index);

}

// template<typename T> 
// void FixedArray<T>::shift_right(const size_t index){
//     this->set_seq()
//     T* temp = this->get_seq();
//     if ((this->get_seq()+index) < (this->get_seq()+length))
//         *((temp--)+length+1)=  *((temp--)+length);
// }

template< typename T>
void FixedArray<T>::build_init(T* sequnce,size_t index){
    *(this->get_seq()+index) = *sequnce;
    if(this->get_seq()+index <= this->get_seq()+this->get_length() )  
        build_init(++sequnce,++index);
}

template<typename T>
void FixedArray<T>::reinsert(T* first,T* last, size_t index){
    if(first<= this->get_seq()+this->get_length()-1){
        if (this->get_seq()+index == first){
            ++last;
            *last = *first;
            reinsert(++first,++last, index);
        }
        else{
            *last = *first;
            reinsert(++first,++last, index);
        }
    }
}
    
template<typename T>
void FixedArray<T>::insert_at( const T item , const size_t index){
    if (!(index <= this->get_length()+1)){
        string error = outOfRangeEr
        +std::to_string(this->get_length())+"\n";
    throw invalid_argument( error );    
    }
    rebuild_up(index);
    set_at(item,index);
}
template<typename T>
void FixedArray<T>::insert_last(T item){
    rebuild_up(this->get_length()+1);
    set_at(item,this->get_length());
}
template<typename T>
FixedArray<T>::~FixedArray(){
    
}

template< typename T>
void FixedArray<T>::rebuild_down(size_t index){
    this->set_length(this->get_length()-1);
    if(!is_empty()){
        T* last = new T[this->get_length()+1];
        redelete(this->get_seq(),last,index);
        this->set_seq(last);
        last = nullptr; 
        delete []last;
    }
    else this->set_seq(nullptr);
}

template<typename T>
void FixedArray<T>::redelete(T* first,T* last, size_t index){
    if(first<= this->get_seq()+this->get_length()+1){
        if (this->get_seq()+index == first){
            ++first;
            *last = *first;
            redelete(++first,++last, index);
        }
        else{
            *last = *first;
            redelete(++first,++last, index);
        }
    }
}
template<typename T>
T FixedArray<T>::delete_at(   size_t index){
    if (is_empty()){
       throw out_of_range(emptyError);
       
    }
    else if(index > this->get_length()){
        string error = outOfRangeEr
        +std::to_string(this->get_length())+"\n";
        throw invalid_argument(error);
    }
    T temp = get_at(index);
    rebuild_down(index);
    return temp;
}
template<typename T>
T FixedArray<T>::delete_first(){
    if (is_empty()){
        throw out_of_range(emptyError);
    }
    T  temp = get_at(0);
    rebuild_down(0);
    return temp;
    
}

template< typename T>
T FixedArray<T>::delete_last(){
    if (is_empty()){
        throw out_of_range(emptyError);
    }
    T temp = get_at(this->get_length());
    rebuild_down(this->get_length());
    return temp;
}


template< typename T>
bool FixedArray<T>::is_empty() const{
    return !(this->get_length() +1);
}

template< typename T>
const size_t FixedArray<T>::get_size() const{
 
   return this->get_length()+1;
}


// implementation of itorator

template< typename T>
T* FixedArray<T>::begin(){
    return this->get_seq();
}

template< typename T>
T* FixedArray<T>::end(){
    return (this->get_seq()+get_size());
}