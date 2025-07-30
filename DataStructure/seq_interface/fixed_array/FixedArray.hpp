#ifndef FIXEDARRAY_H
#define FIXEDARRAY_H
#include <cstddef>
#include <iostream>

//#include "SequenceInterface.hpp"
#include "SequenceInterface.cpp"
using namespace std;

template<typename T> 
class FixedArray ;


template<typename T> 
std::ostream& operator << (std::ostream& , const FixedArray<T>&);


template < typename T >
class FixedArray : public SequenceInterface<T> {
    friend std::ostream& operator<< <> (std::ostream &, const FixedArray<T> &) ;

public:

    // build operation supported in roughly O(n) time (costructor)
    //FixedArray(T*  );
    FixedArray(size_t =0  );
    FixedArray(const FixedArray &);
    // destructor operation to delete dynamic memory O(1) time
    ~FixedArray();

    // overriden of printalble interface
    void print() const override;
    // set_at operation supported ilsn O    (1) time
    void set_at(const T  ,const size_t  ) override;
    //get_at operation supported in O(1) time 
    T& get_at(  const  size_t  ) const override ;
    // insert_first operation supported in O(n) time
    void insert_first(const T   ) override ;
    // insert_ last operation supported in O(n time)
    void insert_last(const T) override  ;
    // delete_firet operation suppoted in O(n) time
    T delete_first() override ;
    //insert at operation supported in O(n) time 
    void insert_at(const T , const size_t ) override ;
    // validate insert at supported in O(1) time
    // delete_last operation supported in O(n) time 
    T delete_last() override;
    // insert_at operation supported in O(n) time 
    //delete_at operation supported in O(n) time 
    T delete_at(size_t ) override ;
    // getters and setters of class attributes  supported on O(1) time
    //T* get_seq() const;
    //size_t get_length() const ;
    const size_t get_size() const;

    // itorator declatraion
    T* begin();
    T* end();
    bool is_empty()const;
private:
    // build operation supported in O(n) time 
    void build( T*);
    // rebuild operation supported in O(n) time 
    void rebuild_up(size_t );
    // shift_right operation supported in O(n) time 
    void shift_right(const size_t );
    // getters and setters of class attributes  supported on O(1) time
    //void set_seq(  T*  );
    //void set_length(  size_t );
    // build_init operation supported in O(n) time 
    void build_init(T* , size_t); 
    // reinsert operation supported in O(n) time 
    void reinsert(T* first,T* last, const size_t);
    // rebuild down operation supported in O(n) time 
    void redelete(T* ,T* , size_t );
    // 
    void rebuild_down(size_t index);
    //
    
    // 
    //void set_size(size_t );

}; 


#endif