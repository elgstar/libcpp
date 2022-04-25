#include "../lib/utility.hpp"
#include <iostream>

template <typename R>
void print(const R &a, const R &b)
{
    if(slj::isEqual<R>(a, b)) {
        std::cout<<"True"<<std::endl;
    }
    else {
        std::cout<<"False"<<std::endl;
    }
}

int main()
{
    print<float>(0, 0.00000000001);
    print<float>(0.0000000001, 0);
    print<float>(0.000001, 0);
    print<float>(0.00001, 0);
}
