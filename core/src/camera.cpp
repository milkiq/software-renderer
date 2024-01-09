#include <node/camera.h>

using namespace WMath;

Node::Camera3D::Camera3D(Vector3f position, Vector3f rotation, float fov, float nearDistance, float farDistance, float aspectRatio): position(position), rotation(rotation), fov(fov), nearDistance(nearDistance), farDistance(farDistance), aspectRatio(aspectRatio) { }

Vector4f Node::Camera3D::Project(Vector3f point) {
    Matrix4f moveMatrix = Matrix4f({
        {1, 0, 0, -position.x},
        {0, 1, 0, -position.y},
        {0, 0, 1, -position.z},
        {0, 0, 0, 1}
    });
    Matrix4f rotateMatrix = Matrix4f({
        {1, 0, 0, 0},
        {0, cos(rotation.x), -sin(rotation.x), 0},
        {0, sin(rotation.x), cos(rotation.x), 0},
        {0, 0, 0, 1}
    }) * Matrix4f({
        {cos(rotation.y), 0, sin(rotation.y), 0},
        {0, 1, 0, 0},
        {-sin(rotation.y), 0, cos(rotation.y), 0},
        {0, 0, 0, 1}
    }) * Matrix4f({
        {cos(rotation.z), -sin(rotation.z), 0, 0},
        {sin(rotation.z), cos(rotation.z), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    });
    Matrix4f cameraMatrix = rotateMatrix * moveMatrix;

    float n = nearDistance;
    float f = farDistance;
    float t = tan(fov / 2) * n;
    float b = -t;
    float r = t * aspectRatio;
    float l = -r;
    Matrix4f perspMatrix = Matrix4f({
        { n, 0, 0, 0 },
        { 0, n, 0, 0 },
        { 0, 0, n + f, -n * f },
        { 0, 0, 1, 0 }
    });
    Matrix4f orthoMatrix = Matrix4f({
        { 2 / (r - l), 0, 0, 0 },
        { 0, 2 / (t - b), 0, 0 },
        { 0, 0, 2 / (n - f), 0 },
        { 0, 0, 0, 1 }
    }) * Matrix4f({
        { 1, 0, 0, -(r + l) / 2 },
        { 0, 1, 0, -(t + b) / 2 },
        { 0, 0, 1, -(n + f) / 2 },
        { 0, 0, 0, 1 }
    });

    Matrix4f finalMatrix = orthoMatrix * perspMatrix * cameraMatrix;

    Vector4f point4 = Vector4f(point.x, point.y, point.z, 1);
    auto movere = moveMatrix * point4;

    auto result = finalMatrix * point4;
    float w = result.get(3, 0);

    return Vector4f(result.get(0, 0) / w, result.get(1, 0) / w, result.get(2, 0) / w, 1);
}

void Node::Camera3D::LookAt(Vector3f point) {
    Vector3f up(0, 1, 0);
    Vector3f z = (position - point).Normalized();
    Vector3f x = up.Cross(z).Normalized();
    Vector3f y = z.Cross(x);

    float yaw = atan2(x.z, x.x);
    float pitch = atan2(-z.y, sqrt(z.x * z.x + z.z * z.z));
    float roll = atan2(y.z, y.y);

    rotation = Vector3f(pitch, yaw, roll);
}

Vector3f Node::Camera3D::GetForward() {
    return Vector3f(
        cos(rotation.y) * cos(rotation.x),
        sin(rotation.x),
        sin(rotation.y) * cos(rotation.x)
    );
}

Vector2f Node::Camera3D::ViewportTrans(Vector4f point, float screenWidth, float screenHeight) {
    Matrix4f viewportMatrix = Matrix4f({
        { screenWidth / 2, 0, 0, screenWidth / 2 },
        { 0, screenHeight / 2, 0, screenHeight / 2 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 1 }
    });
    auto result = viewportMatrix * point;
    return Vector2f(result.get(0, 0), result.get(1, 0));
}
