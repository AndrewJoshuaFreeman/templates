#include "../include/tiny/type_name.hpp"
#include <iostream>
#include <string>

int main(){

    std::cout << tiny::type_name<int>() << '\n';
    std::cout << tiny::type_name<double>() << '\n';
    std::cout << tiny::type_name<std::string>() << '\n';

    std::cout << tiny::size(tiny::FixedArray<int, 6>) << '\n';

return 0;
}
