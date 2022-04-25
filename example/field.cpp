/*
 * test the field
*/
#define SLJ_DIVIDE_BY_ZERO_EXCEPTION
// #define SLJ_DIVIDE_BY_ZERO_TO_ZERO

#include "../kits/field.hpp"


template <typename R>
void printPolar(const slj::Tripolar<R> &t)
{
    std::cout<<"x = "<<t.x <<"   y = "<<t.y<<"   z = "<<t.z<<std::endl;
}

void trepolar()
{
    slj::Tripolar<float> a{1.2, 3.4, 5.6}, b{7.8, 9.1, 10.11}, c;
    printPolar<float>(a+b);
    printPolar<float>(a-b);
    printPolar<float>(a*b);
    printPolar<float>(a/b);
    printPolar<float>(a.cross(b));
    std::cout<<a.dot(b)<<std::endl<<std::endl;
    c=a;
    c+=b;
    printPolar<float>(c);
    c=a;
    c-=b;
    printPolar<float>(c);
    c=a;
    c*=b;
    printPolar<float>(c);
    c=a;
    c/=b;
    printPolar<float>(c);
    c=a;
    c=c.cross(b);
    printPolar<float>(c);
    c=a;
    std::cout<<c.dot(b)<<std::endl<<std::endl;
    // b.y = - 0;
    // c=a;
    // c/=b;
    // printPolar<float>(c);
    std::cout<<std::endl<<std::endl;
    float r = 10;
    printPolar<float>(a+r);
    printPolar<float>(a-r);
    printPolar<float>(a*r);
    printPolar<float>(a/r);
    std::cout<<std::endl<<std::endl;
    c=a;
    c+=r;
    printPolar<float>(c);
    c=a;
    c-=r;
    printPolar<float>(c);
    c=a;
    c*=r;
    printPolar<float>(c);
    c=a;
    c/=r;
    printPolar<float>(c);
    std::cout<<std::endl<<std::endl;
    r=0;
    c/=r;
    printPolar<float>(c);
}

int main()
{
    try {
        trepolar();
    }
    catch(slj::Exception &e) {
        e.view();
    }
    catch(std::exception &e) {
        std::cerr << e.what() <<std::endl;
    }
    return 0;
}
