#ifndef vec4_H_INCLUDED
#define vec4_H_INCLUDED
#include <iostream>

namespace mike { namespace maths {

    struct vec4
    {
        float x,y,z,a;

        vec4();
        vec4(const float& x,const float& y, const float& z, const float& a);

        vec4& add(const vec4& other);
        vec4& subtract(const vec4& other);
        vec4& multiply(const vec4& other);
        vec4& divide(const vec4& other);

        friend std::ostream& operator<<(std::ostream& stream, const vec4& vecotr);
        friend vec4 operator+(vec4 left, const vec4& right);
        friend vec4 operator-(vec4 left, const vec4& right);
        friend vec4 operator/(vec4 left, const vec4& right);
        friend vec4 operator*(vec4 left, const vec4& right);

        vec4& operator+=(const vec4 &other);
        vec4& operator-=(const vec4 &other);
        vec4& operator*=(const vec4 &other);
        vec4& operator/=(const vec4 &other);

        bool operator==(const vec4 &other);
        bool operator!=(const vec4 &other);
    };



}}

#endif // vec4_H_INCLUDED
