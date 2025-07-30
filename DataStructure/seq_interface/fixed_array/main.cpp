//#include "PrintableInterface.hpp"
//#include "SequenceInterface.hpp"
//#include  "SequenceInterface.cpp"
//#include "FixedArray.hpp"
#include "FixedArray.cpp"
#include "../../../book_examples/date_class/Date.cpp"
//#include "print.hpp"

using namespace std;
int main(){
    /*
    int b[5] = {7,8,9,10,11};
    FixedArray<int> a;
    a.print();
    a.insert_first(60);  a.print();
    a.insert_first(900); a.print();
    a.insert_last(500);  a.print();
    a.insert_first(22);  a.print();
    a.insert_at(4,0);    a.print();
    cout <<"****************delte checks*****************"<<endl;
    cout << a.delete_first() << "  ";    a.print();
    cout << a.delete_first ()<< "  ";   a.print();
    cout <<  a.delete_first()<< "  ";    a.print();
    cout << a.delete_at(5)<< "   ";      a.print();
    cout << a.delete_at(2)<<"   ";      a.print();
    cout << a.delete_last()<<"   ";     a.print();
    a.insert_first(40);  a.print();
    //printf(a);
    //
     FixedArray<int> c(a);
     c.print();
    a.insert_first(48);    a.print();
    cout << a.delete_at(3) <<"   ";       a.print();
    cout <<a.delete_at(12)<<"   ";      a.print();
    std::cout << a;
    for(const auto& elem :a)
        cout<<elem << " ";
    */  
        
        Date b[3];
        FixedArray<Date> a(8);
        FixedArray<Date> c(8);
        cout << (a==c) << endl;
        cout << a.is_empty() << endl;
        a[3]++;
        a.insert_first(Date(5));
        a.print();
        try{
             cout <<a.delete_at(10);
        }catch(invalid_argument &e){
            cout << e.what() << endl;
        }
        
        cout << a.delete_first();
        a.delete_first();
        a.delete_first();
        
       // cout << a.get_length();
              
}