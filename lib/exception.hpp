/*
 * exception classes
*/
#ifndef _SLJ_EXCEPTION_H_
#define _SLJ_EXCEPTION_H_
#include <exception>
#include <string>
#include <iostream>

namespace slj {
/*
 * @brief: the basic exception class
 * @info: written by Liangjin Song on 20220425 at Nanchang University
 * @value: filename -- the file that throws the exception
 * @value: function -- the function name that throws the exception
 * @value: linenumber -- the line number that throws the exception
 * @value: msg -- Supplementary notes on exception
 */
class Exception : public std::exception {
protected:
    std::string filename;
    std::string function;
    int linenumber;
    std::string msg;
public:
    Exception(const std::string &file, const std::string &func, const int &line, const std::string &info) : filename(file), function(func), linenumber(line), msg(info) {}
    virtual ~Exception() = default;
protected:
    virtual void head() {
        std::cerr << "Error! " << std::endl;
        std::cerr << "CPP version: " << __cplusplus << std::endl;
        std::cerr << "Filename: " << filename << std::endl;
        std::cerr << "Function: " << function << std::endl;
        std::cerr << "Line: " << linenumber << std::endl;
    }
    virtual void type() {
        std::cerr << "Type: basic exception" << std::endl;
    }
    virtual void tail() {
        std::cerr << "Supplement: " << msg <<std::endl;
    }
public:
    virtual void view() {
        head();
        type();
        tail();
    }
};
}


namespace slj {
/*
 * @brief: the logic error class, exceptions that can be detected by the code
 * @info: written by Liangjin Song on 20220425 at Nanchang University
*/
class ErrorLogic : public Exception {
public:
    ErrorLogic(const std::string &file, const std::string &func, const int &line, const std::string &info): Exception(file, func, line, info) {}
    virtual ~ErrorLogic() = default;
protected:
    virtual void type() {
        std::cerr << "Type: logic error" << std::endl;
    }
};
}


namespace slj {
/*
 * @brief: the outflow error class, e.g. array out of bounds, divide by 0
 * @info: written by Liangjin Song on 20220425 at Nanchang University
*/
class ErrorOutflow : public Exception {
public:
    ErrorOutflow(const std::string &file, const std::string &func, const int &line, const std::string &info): Exception(file, func, line, info) {}
    virtual ~ErrorOutflow() = default;
protected:
    virtual void type() {
        std::cerr << "Type: outflow error" << std::endl;
    }
};
}


namespace slj {
/*
 * @brief: the expection error class, e.g. can't open the file
 * @info: written by Liangjin Song on 20220425 at Nanchang University
*/
class ErrorExpection : public Exception {
public:
    ErrorExpection(const std::string &file, const std::string &func, const int &line, const std::string &info): Exception(file, func, line, info) {}
    virtual ~ErrorExpection() = default;
protected:
    virtual void type() {
        std::cerr << "Type: expection error" << std::endl;
    }
};
}
#endif
