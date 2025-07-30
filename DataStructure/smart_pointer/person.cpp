#include <string>
#include <iostream>
class Person
{
    std::string name;
    int age;
public:
    friend std::ostream& operator<<(std::ostream& o, Person &obj)
    {
        o <<"[" << obj.get_name()<<
        " ," << obj.get_age() <<
        "]" << std::endl;
        return o;
    }
    Person(std::string name ="", int age=0)
    :name(name) ,age(age){}
    std::string const& get_name() const   
    { return name; }
    int const& get_age() const
    { return age;}
};