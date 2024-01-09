#ifndef WMATH_VECTOR_H
#define WMATH_VECTOR_H

#include <stddef.h>

namespace WMath {
    template<typename T, size_t N>
    struct VecDataDefault {
        T data[N];
    };

    template <typename T>
    struct VecData2 {
        union {
            T data[2];
            struct { T x, y; };
        };
    };

    template <typename T>
    struct VecData3 {
        union {
            T data[3];
            struct { T x, y, z; };
        };
    };

    template <typename T>
    struct VecData4 {
        union {
            T data[4];
            struct { T x, y, z, w; };
        };
    };

    template<typename T, size_t N, typename D = VecDataDefault<T, N>, typename current = D>
    class Vec: public D {
        static_assert(N != 0, "N can't be zero");
        static_assert(N <= 4, "N can't over 4");

        current do_add(const Vec<T, N, D, current>& other) const {
           current result;
            for (size_t i = 0; i < N; i++) {
                result[i] = data[i] + other[i];
            }
            return result;
        }

       current do_sub(const Vec<T, N, D, current>& other) const {
            current result;
            for (size_t i = 0; i < N; i++) {
                result[i] = data[i] - other[i];
            }
            return result;
        }

    public:
        using D::data;

        Vec() {
            for (size_t i = 0; i < N; i++) {
                data[i] = 0;
            }
        }

        template<typename U, size_t M, typename C, typename inCurrent>
        Vec(const Vec<U, M, C, inCurrent>& other) {
            static_assert(M >= N, "M must be greater than or equal to N");
            for (size_t i = 0; i < N; i++) {
                data[i] = static_cast<T>(other[i]);
            }
        }

        T operator[](size_t index) const {
            return data[index];
        }

        T& operator[](size_t index) {
            return data[index];
        }

        current operator+(const Vec<T, N, D, current>& other) const {
            return do_add(other);
        }

        current& operator+=(const Vec<T, N, D, current>& other) {
            current result = do_add(other);
            for (size_t i = 0; i < N; i++) {
                data[i] = result[i];
            }
            return *this;
        }

        current operator-(const Vec<T, N, D, current>& other) const {
            return do_sub(other);
        }

        current& operator-=(const Vec<T, N, D, current>& other) {
            current result = do_sub(other);
            for (size_t i = 0; i < N; i++) {
                data[i] = result[i];
            }
            return *this;
        }

        template<typename U, size_t M, typename C, typename inCurrent>
        current& operator=(const Vec<U, M, C, inCurrent>& other) {
            static_assert(M >= N, "M must be greater than or equal to N");

            for (size_t i = 0; i < N; i++) {
                data[i] = static_cast<T>(other[i]);
            }

            return *this;
        }

        void operator=(int a) {
            printf("a");
        }

        bool operator==(const Vec<T, N, D, current>& other) const {
            for (size_t i = 0; i < N; i++) {
                if (data[i] != other[i]) {
                    return false;
                }
            }
            return true;
        }

        T Dot(const Vec<T, N, D, current>& other) const {
            T result = 0;
            for (size_t i = 0; i < N; i++) {
                result += data[i] * other[i];
            }
            return result;
        }

        current Normalized() const {
            T length = 0;
            for (size_t i = 0; i < N; i++) {
                length += data[i] * data[i];
            }
            length = sqrt(length);
            current result;
            for (size_t i = 0; i < N; i++) {
                result[i] = data[i] / length;
            }
            return result;
        }

        current Cross(const Vec<T, N, D, current>& other) const {
            current result;
            for (size_t i = 0; i < N; i++) {
                result[i] = data[(i + 1) % N] * other[(i + 2) % N] - data[(i + 2) % N] * other[(i + 1) % N];
            }
            return result;
        }
    };

    template<typename T>
    class Vector4: public Vec<T, 4, VecData4<T>, Vector4<T>> {
        public:
            using D = VecData4<T>;
            using D::x;
            using D::y;
            using D::z;
            using D::w;
            using Vec<T, 4, VecData4<T>, Vector4<T>>::Vec;
            using Vec<T, 4, VecData4<T>, Vector4<T>>::operator+;
            using Vec<T, 4, VecData4<T>, Vector4<T>>::operator-;
            using Vec<T, 4, VecData4<T>, Vector4<T>>::operator=;
            using Vec<T, 4, VecData4<T>, Vector4<T>>::operator+=;
            using Vec<T, 4, VecData4<T>, Vector4<T>>::operator-=;
            using Vec<T, 4, VecData4<T>, Vector4<T>>::operator==;
            Vector4(T _x, T _y, T _z, T _w);
    };

    template<typename T>
    class Vector3: public Vec<T, 3, VecData3<T>, Vector3<T>> {
        public:
            using D = VecData3<T>;
            using D::x;
            using D::y;
            using D::z;
            using Vec<T, 3, VecData3<T>, Vector3<T>>::Vec;
            using Vec<T, 3, VecData3<T>, Vector3<T>>::operator+;
            using Vec<T, 3, VecData3<T>, Vector3<T>>::operator-;
            using Vec<T, 3, VecData3<T>, Vector3<T>>::operator=;
            using Vec<T, 3, VecData3<T>, Vector3<T>>::operator+=;
            using Vec<T, 3, VecData3<T>, Vector3<T>>::operator-=;
            using Vec<T, 3, VecData3<T>, Vector3<T>>::operator==;
            // Vector3();
            Vector3(T _x, T _y, T _z);
    };

    template<typename T>
    class Vector2: public Vec<T, 2, VecData2<T>, Vector2<T>> {
        public:
            using D = VecData2<T>;
            using D::x;
            using D::y;
            using Vec<T, 2, VecData2<T>, Vector2<T>>::Vec;
            using Vec<T, 2, VecData2<T>, Vector2<T>>::operator+;
            using Vec<T, 2, VecData2<T>, Vector2<T>>::operator-;
            using Vec<T, 2, VecData2<T>, Vector2<T>>::operator=;
            using Vec<T, 2, VecData2<T>, Vector2<T>>::operator+=;
            using Vec<T, 2, VecData2<T>, Vector2<T>>::operator-=;
            using Vec<T, 2, VecData2<T>, Vector2<T>>::operator==;
            Vector2(T _x, T _y);
    };

    template<typename T>
    Vector4<T>::Vector4(T _x, T _y, T _z, T _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    template<typename T>
    Vector3<T>::Vector3(T _x, T _y, T _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    template<typename T>
    Vector2<T>::Vector2(T _x, T _y) {
        x = _x;
        y = _y;
    }

    using Vector4i = WMath::Vector4<int>;
    using Vector4f = WMath::Vector4<float>;

    using Vector3i = WMath::Vector3<int>;
    using Vector3f = WMath::Vector3<float>;

    using Vector2i = WMath::Vector2<int>;
    using Vector2f = WMath::Vector2<float>;

}

#endif
