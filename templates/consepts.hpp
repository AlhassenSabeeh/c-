// #include <string>
// #include <cstring>

// bool CHICK(std::string type)
// {
//     unsigned int size = type.size()-1;
//     return (type[size] == ']');
// }
// #define getTypeName(a) #a

// template<typename T>
// concept  isArray = requires
// { CHICK(getTypeName(T)); };


template<typename T>
concept SupportsLessThan = requires (T x) 
{
     x.operator<(x);
};

template<typename T>
concept Copyable = requires (T x)
{ 
    x.x( x );
};




