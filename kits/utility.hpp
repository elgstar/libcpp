/*
 * some useful tools
*/
#ifndef _SLJ_UTILITY_HPP_
#define _SLJ_UTILITY_HPP_
#include <cmath>

#include <cstddef>

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

#endif
