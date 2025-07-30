template<typename T>
class is_Array{
    bool array ;
public:
    is_Array()
    {
        if constexpr (isArray<T>)
        { array = 1;}
        else 
        { array = 0;}
        }
        bool get(){
            return array;
    }
};