/*
 * some useful tools
*/
#ifndef _SLJ_UTILITY_HPP_
#define _SLJ_UTILITY_HPP_



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
    constexpr R &c = 0.000001;
    return (a - b <= c) ? true : false;
}
}

#endif
