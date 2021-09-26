#ifndef MATH_MATH
#define MATH_MATH

#include <functional>
#include <bitset>
#include <string>
#include <sstream>

class Math {
public:
    //
};

template<typename T>
class Vec2 {
public:
    T x = 0;
    T y = 0;

    Vec2(T x = 0, T y = 0){
        this->x = x;
        this->y = y;
    };
};

template<typename T>
class Vec3 : public Vec2<T> {
public:
    T z = 0;

    Vec3(T x = 0, T y = 0, T z = 0){
        this->x = x;
        this->y = y;
        this->z = z;
    };
};

template<typename T>
class AABB {
public:
    Vec3<T> vecA = Vec3<T>(0, 0, 0);
    Vec3<T> vecB = Vec3<T>(0, 0, 0);

    AABB(Vec3<T> vecA = Vec3<T>(0, 0, 0), Vec3<T> vecB = Vec3<T>(0, 0, 0)){
        this->vecA = vecA;
        this->vecB = vecB;
    };
};

#endif /* MATH_MATH */