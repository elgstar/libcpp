#include <iostream>
#include <memory>
#include "../kits/utility.hpp"

struct Class {
    int m;
    Class(const int &i = 0): m(i) {
        std::cout<<"construct: "<<i<<std::endl;
    }
    ~Class() {
        std::cout<<"destruct: " <<m<<std::endl;
    }
};

int main()
{
    std::unique_ptr<Class> p1=slj::make_unique<Class>(10);
    std::cout<<" ====== \n" ;
    p1 = slj::make_unique<Class>(1000);
    std::cout<<" ====== \n" ;
    std::unique_ptr<Class[]> p2=slj::make_unique<Class[]>(10);
    for(int i=0; i<10; ++i) {
        p2[i].m = i+11;
    }
    std::cout<<" ====== \n" ;
    p2 = slj::make_unique<Class[]>(5);
    for(int i=0; i<5; ++i) {
        p2[i].m=i+101;
    }
    std::cout<<" ====== \n" ;
    std::unique_ptr<Class> p3;
    p3 = slj::make_unique<Class>();
    p3->m = 500;
    p3.reset();
    std::cout<<" ====== \n" ;
    std::unique_ptr<Class> p4 = slj::make_unique<Class>();
    p4->m  = 300;
    std::unique_ptr<Class> p5 = slj::make_unique<Class>();
    p5->m  = 200;
    std::swap(p4, p5);
    std::cout<<p4->m <<"   "<<p5->m<<std::endl;
}
