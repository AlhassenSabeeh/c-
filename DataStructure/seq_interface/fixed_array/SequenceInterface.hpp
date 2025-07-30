#ifndef SEQUENCEINTERFACE_H
#define SEQUENCEINTERFACE_H
#include <cstddef>
#include "PrintableInterface.hpp"

template<typename T>
class SequenceInterface : public PrintableInterface<T> {
    private:
        T* seq;
        size_t length;
    public:
        
        explicit SequenceInterface( size_t  );
        SequenceInterface(const SequenceInterface &);
        ~SequenceInterface();
        virtual void  set_at(const T  ,const size_t )  = 0 ;
        virtual T& get_at( const size_t ) const = 0 ;
        virtual void insert_first(T) = 0 ;
        virtual void insert_at( const T, const size_t )  = 0 ;
        virtual void insert_last(T) = 0 ;
        virtual T delete_first() = 0 ;
        virtual T delete_at(size_t) = 0 ;
        virtual T delete_last() = 0 ;
        //operator char*() const;

        void set_seq(T*);
        T* get_seq() const;
        size_t get_length() const ;
        void set_length(  size_t );

        T &operator[](int);
        T operator[](int) const;
        bool operator==(const SequenceInterface &)const;
        bool operator!=(const SequenceInterface &) const;
};

#endif