/*
 * some useful tools
*/
#ifndef _SLJ_UTILITY_HPP_
#define _SLJ_UTILITY_HPP_
#include <cmath>
#include <memory>

namespace slj {
/*
 * @brief: the number definition
 * @info: written by Liangjin Song on 20220426 an Nanchang University
 * @type: n_nat -- the natural number
 * @type: n_real -- the real number
*/
typedef size_t n_nat;
#if defined(SLJ_REAL_FLOAT)
    typedef float n_real;
#elif defined(SLJ_REAL_DOUBLE)
    typedef double n_real;
#elif defined(SLJ_REAL_LONG_DOUBLE)
    typedef long double n_real;
#else
    typedef double n_real;
#endif
}


namespace slj {
/*
 * @brief: compare two numbers for equality
 * @info: written by Liangjin Song on 20220425 at Nanchang University
 * @type: R -- the real number type, e.g. float, double
 * @param: a, b -- two numbers to be compared
 * @return: a is equal to b or not
 * @note: two numbers are considered equal if the distance between them is less than the given value
*/
template <typename R>
bool isEqual(const R &a, const R &b)
{
    constexpr R c = 0.000001;
    return std::abs(a - b) <= c;
}
}


namespace slj {
/*
 * @brief: creat the unique pointer, make_unique<T>
*/

// 单一元素类模板定义
template <typename T>
using Ele = typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type;


// 变长数组类模板定义
template <typename T>
using Slice = typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0, std::unique_ptr<T>>::type;


// 定长数组类模板定义
template <typename T>
using Arr = typename std::enable_if<std::extent<T>::value != 0, void>::type;


// 支持普通指针
template <typename T, typename ... Args> inline
Ele<T> make_unique(Args &&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


// 支持动态数组
template <typename T> inline
Slice<T> make_unique(size_t size)
{
    using U = typename std::remove_extent<T>::type;
    return std::unique_ptr<T>(new U[size]);
}


// 过滤定长数组
template <typename T, typename ... Args>
Arr<T> make_unique(Args &...) = delete;
}


#endif
