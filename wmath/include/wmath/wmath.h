#ifndef WMATH_H
#define WMATH_H

namespace WMath {
    double sqrt(double x);

    class Vector3d {
        public:
            double x, y, z;
            static double Dot(const Vector3d& a, const Vector3d& b);
            
            Vector3d(double x, double y, double z);
            Vector3d Normalized();
    };

    class Vector2d {
        public:
            double x, y;
            static double Dot(const Vector2d& a, const Vector2d& b);
            static double Cross(const Vector2d& a, const Vector2d& b);
            
            Vector2d(double x, double y);
            Vector2d Normalized();
            Vector2d operator+(const Vector2d& other) const;
            Vector2d operator-(const Vector2d& other) const;
    };

    class Matrix3d {
        public:

    };
}

#endif
