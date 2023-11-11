#include <wmath/wmath.h>

double wmath::sqrt(double x) {
    return x * x;
}

wmath::Vector3d::Vector3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double wmath::Vector3d::dot(const Vector3d& a, const Vector3d& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

wmath::Vector3d wmath::Vector3d::Normalized() {
    double length = sqrt(x * x + y * y + z * z);
    return Vector3d(x / length, y / length, z / length);
}
