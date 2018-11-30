#include "vec4.h"
namespace mike { namespace maths {



vec4::vec4()
{
    x=0.0f;
    y=0.0f;
    z=0.0f;
    a=0.0f;
}

vec4::vec4(const float& x, const float& y, const float& z, const float& a)
:x(x),y(y),z(z),a(a)
{

}

vec4& vec4::add(const vec4& other)
{
    x+=other.x;
    y+=other.y;
    z+=other.z;
    a+=other.a;
    return *this;
}

vec4& vec4::subtract(const vec4& other)
{
    x-=other.x;
    y-=other.y;
    z-=other.z;
    a-=other.a;
    return *this;
}

vec4& vec4::multiply(const vec4& other)
{
    x*=other.x;
    y*=other.y;
    z*=other.z;
    a*=other.a;
    return *this;
}

vec4& vec4::divide(const vec4& other)
{
    x/=other.x;
    y/=other.y;
    z/=other.z;
    a/=other.a;
    return *this;

}

std::ostream& operator<<(std::ostream& stream, const vec4& vec)
{
    stream << "vec4:("<<vec.x<<","<<vec.y<<","<<vec.z<<","<<vec.a<<")";
    return stream;
}

vec4 operator+(vec4 left, const vec4& right)
{

    return left.add(right);
}

vec4 operator-(vec4 left, const vec4& right)
{

    return left.subtract(right);
}

vec4 operator*(vec4 left, const vec4& right)
{

    return left.multiply(right);
}

vec4 operator/(vec4 left, const vec4& right)
{

    return left.divide(right);
}
vec4& vec4::operator+=(const vec4& other)
{
   return add(other);
}

vec4& vec4::operator-=(const vec4& other)
{
    return subtract(other);
}

vec4& vec4::operator*=(const vec4& other)
{
    return multiply(other);
}

vec4& vec4::operator/=(const vec4& other)
{
    return divide(other);
}

bool vec4::operator==(const vec4 &other)
{
    return (x==other.x && y==other.y && z==other.z && a==other.a);
}


bool vec4::operator!=(const vec4 &other)
{
    return !(*this==other);
}




}
}
