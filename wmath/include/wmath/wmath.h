#ifndef WMATH_H
#define WMATH_H

namespace wmath {
    double sqrt(double x);

    class Vector3d {
        public:
            double x, y, z;
            static double dot(const Vector3d& a, const Vector3d& b);
            
            Vector3d(double x, double y, double z);
            Vector3d Normalized();
    };

    class Matrix3d {
        public:

    };
}

#endif
