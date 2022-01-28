#pragma once

#include "Stuffwaffe.hpp"

namespace sw {
    template<typename T>
    struct Vec2 {
    public:
        static_assert(std::is_arithmetic_v<T>, "Stuffwaffe Vec2 Must Be Arithmetic!");
        Vec2() : m_x(0), m_y(0) { }
        Vec2(T x, T y) : m_x(x), m_y(y) { }

        template<typename U>
        Vec2(U x, U y) : m_x(static_cast<U>(x)), m_y(static_cast<U>(y)) { }

        T& GetX() {
            return m_x;
        }

        T& GetY() {
            return m_y;
        }

    private:
        T m_x;
        T m_y;

    };

    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;
    using Vec2u = Vec2<unsigned int>;
    using Vec2l = Vec2<long>;
    using Vec2d = Vec2<double>;

    template<typename T>
    struct Vec3 {
    public:
        static_assert(std::is_arithmetic_v<T>, "Stuffwaffe Vec3 Must Be Arithmetic!");
        Vec3() : m_x(0), m_y(0), m_z(0) { }
        Vec3(T x, T y, T z) : m_x(x), m_y(y), m_z(z) { }

        template<typename U>
        Vec3(U x, U y, U z) : m_x(static_cast<U>(x)), m_y(static_cast<U>(y)), m_z(static_cast<U>(z)) { }

        T& GetX() {
            return m_x;
        }

        T& GetY() {
            return m_y;
        }

        T& GetZ() {
            return m_z;
        }

    private:
        T m_x;
        T m_y;
        T m_z;

    };

    using Vec3f = Vec3<float>;
    using Vec3i = Vec3<int>;
    using Vec3u = Vec3<unsigned int>;
    using Vec3l = Vec3<long>;
    using Vec3d = Vec3<double>;

    template<typename T>
    struct Vec4 {
    public:
        static_assert(std::is_arithmetic_v<T>, "Stuffwaffe Vec4 Must Be Arithmetic!");
        Vec4() : m_x(0), m_y(0), m_z(0), m_w(0) { }
        Vec4(T x, T y, T z, T w) : m_x(x), m_y(y), m_z(z), m_w(w) { }

        template<typename U>
        Vec4(U x, U y, U z, U w) : m_x(static_cast<U>(x)), m_y(static_cast<U>(y)), m_z(static_cast<U>(z)), m_w(static_cast<U>(w)) { }

        T& GetX() {
            return m_x;
        }

        T& GetY() {
            return m_y;
        }

        T& GetZ() {
            return m_z;
        }

        T& GetW() {
            return m_w;
        }

    private:
        T m_x;
        T m_y;
        T m_z;
        T m_w;

    };

    using Vec4f = Vec4<float>;
    using Vec4i = Vec4<int>;
    using Vec4u = Vec4<unsigned int>;
    using Vec4l = Vec4<long>;
    using Vec4d = Vec4<double>;
};