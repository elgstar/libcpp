/*
 * the exception test
*/
#include "../lib/exception.hpp"

#include <exception>

int main()
{
    std::string msg{"test!"};
    try{
        throw EXCEPTION(msg);
        // throw ERRORLOGIC(msg);
        // throw ERROREXPECTION(msg);
        // throw ERROROUTFLOW(msg);
    }
    catch (slj::Exception & e){
        e.view();
    }
    catch(std::exception & e){
        std::cerr << e.what() <<std::endl;
    }
}
