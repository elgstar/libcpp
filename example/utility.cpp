#include "../kits/utility.hpp"
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
    print<slj::n_real>(0, 0.00000000001);
    print<slj::n_real>(0.0000000001, 0);
    print<float>(0.000001, 0);
    print<float>(0.00001, 0);
    slj::n_real a = 1.5;
    slj::n_nat  b = 10;
    double c = 1.5;
    size_t d = 10;
    std::cout<<typeid(a).name()<<"      "<<sizeof(slj::n_real)<<std::endl;
    std::cout<<typeid(b).name()<<"      "<<sizeof(slj::n_nat)<<std::endl;
    std::cout<<typeid(c).name()<<"      "<<sizeof(double)<<std::endl;
    std::cout<<typeid(d).name()<<"      "<<sizeof(size_t)<<std::endl;
}
