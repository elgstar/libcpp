/*
 * describe three-dimensional fields
*/
#ifndef _SLJ_FIELD_HPP_
#define _SLJ_FIELD_HPP_
#include "exception.hpp"
#include "utility.hpp"
#include <cstddef>
#include <functional>

namespace slj {
/*
 * @brief: the class to describe the coordinates of a grid point in 3-D space
 * @info: written by Liangjin Song on 20220425 at Nanchang University
 * @value: i, j, k -- the index in three direction
*/
class ITripolar {
public:
    size_t i, j, k;
public:
    ITripolar(const size_t &ii = 0, const size_t &jj = 0, const size_t &kk = 0): i(ii), j(jj), k(kk) {}
    ~ITripolar() = default;
};


/*
 * @brief: the class to describe the value of a Vector at a point in 3-D space
 * @info: written by Liangjin Song on 20220425 at Nanchang University
 * @type: R -- the real number type, e.g. float, double
 * @value: x, y, z -- the value of the Vector at a point
*/
template <typename R>
class Tripolar {
public:
    R x, y, z;
public:
    Tripolar(const R &xx = 0, const R &yy=0, const R &zz = 0): x(xx), y(yy), z(zz) {}
    ~Tripolar() = default;
public:
    /*
     * @brief: calculate the dot product
     * @param: rhs -- right operand of dot product
     * @return: the resulat of lhs dot rhs
    */
    R dot(const Tripolar &rhs) {
        return x* rhs.x + y* rhs.y + z*rhs.z;
    }
    /*
     * @brief: calculate the cross product
     * @param: rhs -- right operand of cross product
     * @return: the resulat of lhs cross rhs
    */
    Tripolar cross(const Tripolar &rhs) {
        return {y* rhs.z - z*rhs.y, z* rhs.x - x*rhs.z, x* rhs.y - y*rhs.x};
    }
public:
    /*
     * @brief: calculate the arithmetic
     * @param: rhs -- right operand
     * @return: the resulat of arithmetic
    */
    Tripolar operator+(const Tripolar &rhs) {
        return {x+rhs.x, y+rhs.y, z+rhs.z};
    }
    Tripolar operator-(const Tripolar &rhs) {
        return {x-rhs.x, y-rhs.y, z-rhs.z};
    }
    Tripolar operator*(const Tripolar &rhs) {
        return {x*rhs.x, y*rhs.y, z*rhs.z};
    }
    Tripolar operator/(const Tripolar &rhs) {
        #if  defined(SLJ_DIVIDE_BY_ZERO_EXCEPTION)
        {
            if(isEqual<R>(rhs.x, 0) || isEqual<R>(rhs.y, 0) || isEqual<R>(rhs.z, 0)) {
                throw ERROROUTFLOW("divided by zero");
            }
            else {
                return {x/rhs.x, y/rhs.y, z/rhs.z};
            }
        }
        #elif   defined(SLJ_DIVIDE_BY_ZERO_TO_ZERO)
        {
            R xx, yy, zz;
            isEqual<R>(rhs.x, 0)?(xx = 0):(xx = x/rhs.x);
            isEqual<R>(rhs.y, 0)?(yy = 0):(yy = y/rhs.y);
            isEqual<R>(rhs.z, 0)?(zz = 0):(zz = z/rhs.z);
            return{xx, yy, zz};
        }
        #else
        {
            return {x/rhs.x, y/rhs.y, z/rhs.z};
        }
        #endif
    }
    Tripolar &operator+=(const Tripolar &rhs) {
        (*this) = (*this)+rhs;
        return *this;
    }
    Tripolar &operator-=(const Tripolar &rhs) {
        (*this) = (*this)-rhs;
        return *this;
    }
    Tripolar &operator*=(const Tripolar &rhs) {
        (*this) = (*this)*rhs;
        return *this;
    }
    Tripolar &operator/=(const Tripolar &rhs) {
        (*this) = (*this)/rhs;
        return *this;
    }
public:
    /*
     * @brief: calculate the arithmetic with a value
     * @param: rhs -- right operand
     * @return: the resulat of arithmetic
    */
    Tripolar operator+(const R &rhs) {
        return {x+rhs, y+rhs, z+rhs};
    }
    Tripolar operator-(const R &rhs) {
        return {x-rhs, y-rhs, z-rhs};
    }
    Tripolar operator*(const R &rhs) {
        return {x*rhs, y*rhs, z*rhs};
    }
    Tripolar operator/(const R &rhs) {
        #if  defined(SLJ_DIVIDE_BY_ZERO_EXCEPTION)
        {
            if(isEqual<R>(rhs, 0)) {
                throw ERROROUTFLOW("divided by zero");
            }
            else {
                return {x/rhs, y/rhs, z/rhs};
            }
        }
        #elif   defined(SLJ_DIVIDE_BY_ZERO_TO_ZERO)
        {
            R xx, yy, zz;
            isEqual<R>(rhs, 0)?(xx = yy = zz = 0):(xx = x/rhs, yy = y/rhs, zz = z/rhs);
            return {xx, yy, zz};
        }
        #else
        {
            return {x/rhs, y/rhs, z/rhs};
        }
        #endif
    }
    Tripolar &operator+=(const R &rhs) {
        (*this) = (*this)+rhs;
        return *this;
    }
    Tripolar &operator-=(const R &rhs) {
        (*this) = (*this)-rhs;
        return *this;
    }
    Tripolar &operator*=(const R &rhs) {
        (*this) = (*this)*rhs;
        return *this;
    }
    Tripolar &operator/=(const R &rhs) {
        (*this) = (*this)/rhs;
        return *this;
    }
};


/*
 * @brief: the class to describe the value of a Tensor at a point in 3-D space
 * @info: written by Liangjin Song on 20220425 at Nanchang University
 * @type: R -- the real number type, e.g. float, double
 * @value: xx, xy, xz, yy, yz, zz -- the value of the Tensor at a point
*/
template <typename R>
class Sexpolar {
public:
    R xx, xy, xz, yy, yz, zz;
public:
    Sexpolar(const R &aa = 0, const R &ab = 0, const R &ac = 0, const R &bb = 0, const R &bc = 0, const R &cc = 0) : xx(aa), xy(ab), xz(ac), yy(bb), yz(bc), zz(cc) {}
    ~Sexpolar() = default;
public:
    /*
     * @brief: calculate the arithmetic
     * @param: rhs -- right operand
     * @return: the resulat of arithmetic
    */
    Sexpolar operator+(const R &rhs) {
        return {xx+rhs, xy+rhs, xz+rhs, yy+rhs, yz+rhs, zz+rhs};
    }
    Sexpolar operator-(const R &rhs) {
        return {xx-rhs, xy-rhs, xz-rhs, yy-rhs, yz-rhs, zz-rhs};
    }
    Sexpolar operator*(const R &rhs) {
        return {xx*rhs, xy*rhs, xz*rhs, yy*rhs, yz*rhs, zz*rhs};
    }
    Sexpolar &operator+=(const R &rhs) {
        (*this) = (*this) + rhs;
        return *this;
    }
    Sexpolar &operator-=(const R &rhs) {
        (*this) = (*this) - rhs;
        return *this;
    }
    Sexpolar &operator*=(const R &rhs) {
        (*this) = (*this) * rhs;
        return *this;
    }
};
}


namespace slj {
/*
 * @brief: describe the scalar field
 * @info: written by Liangjin Song on 20220426 at Nanchang University
 * @value: val -- pointer to the data, use 1D arrays to represent 3D data
 * @value: nx, ny, nz -- the number of grids in three direction
*/
template <typename R>
class Scalar {
private:
    std::unique_ptr<R[]> val;
    size_t nx, ny, nz;
private:
    void foreach(const std::function<void(R &)> &f) {
        for(size_t i =0; i<length(); ++i) {
            f(val[i]);
        }
    }
    void foreach(const std::function<void (const size_t &)> &f) {
        for(size_t i = 0; i< length(); ++i) {
            f(i);
        }
    }
public:
    Scalar(const size_t &i = 0, const size_t &j = 0, const size_t &k = 0) {
        reset(i, j, k);
    }
    Scalar(const ITripolar &sz) {
        reset(sz);
    }
    ~Scalar() = default;
    Scalar(const Scalar &r) {
        (*this) = r;
    }
    Scalar(Scalar &&r) {
        (*this) = std::move(r);
    }
    Scalar &operator=(const Scalar &r) {
        reset(r.size());
        auto f = [&](const size_t &i) {
            val[i] = r[i];
        };
        foreach(f);
        return *this;
    }
    Scalar &operator=(Scalar &&r) {
        nx = r.nx;
        ny = r.ny;
        nz = r.nz;
        val = std::move(r.val);
        return *this;
    }
public:
    ITripolar size() const {
        return {nx, ny, nz};
    }
    size_t length() const {
        return nx*ny*nz;
    }
public:
    void reset(const size_t &i = 0, const size_t &j = 0, const size_t &k = 0) {
        nx = i;
        ny = j;
        nz = k;
        (i*j*k == 0)? val.reset() : (val=slj::make_unique<R[]>(i*j*k));
    }
    void reset(const ITripolar &sz) {
        this->reset(sz.i, sz.j, sz.k);
    }
    friend void swap(Scalar &a, Scalar &b) {
        std::swap(a.nx, b.nx);
        std::swap(a.ny, b.ny);
        std::swap(a.nz, b.nz);
        std::swap(a.val, b.val);
    }
};
}

#endif
