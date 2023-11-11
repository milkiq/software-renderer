#include <wmath/wmath.h>
using namespace WMath;

// Vector3d
Vector3d::Vector3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector3d::Dot(const Vector3d& a, const Vector3d& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3d Vector3d::Normalized() {
    double length = sqrt(x * x + y * y + z * z);
    return Vector3d(x / length, y / length, z / length);
}


// Vector2d
Vector2d::Vector2d(double x, double y) {
    this->x = x;
    this->y = y;
}

double Vector2d::Dot(const Vector2d& a, const Vector2d& b) {
    return a.x * b.x + a.y * b.y;
}

double Vector2d::Cross(const Vector2d& a, const Vector2d& b) {
    return a.x * b.y - b.x * a.y;
}

Vector2d Vector2d::Normalized() {
    double length = sqrt(x * x + y * y);
    return Vector2d(x / length, y / length);
}

Vector2d Vector2d::operator+(const Vector2d& other) const{
    return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator-(const Vector2d& other) const{
    return Vector2d(x - other.x, y - other.y);
}
