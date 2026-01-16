#pragma once
#include <cstddef>

namespace tiny{

template <typename T>
//if type doesnt match anything else, itll go here
//genereralizing to T, so it can fit any type
constexpr const char* type_name(){
    return "unknown";
}

template<>
//returns a pointer to immutable chars, and CAN
//be evalutated at compile time(does not HAVE to be)
constexpr const char* type_name<int>(){
    return "int";
}

template<>
//not
constexpr const char* type_name<double>(){
    return "double";
}

/*
 * this is a template for creating arrays
 * N must be known at compile time because the compiler needs to know
 * the exact mem layout and size of array!
 * arrays are contiguous memory and have fixed size
 * Layout: T is the tpye of array(int, double, etc), N is the size
 */

template <typename T, std::size_t N>//size_t for N, since it is for the size
class FixedArray{
    
public:

    constexpr std::size_t size() const{
        return N;
    }

    T& operator[]( std::size_t index ){
        return data[index];
    }
    const T& operator[]( std::size_t index ) const{
        return data[index];
    }


private:
    T data[N];
};

}//end of ns tiny
