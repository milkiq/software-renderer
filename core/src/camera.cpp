#include <node/camera.h>

Core::Camera3D::Camera3D(WMath::Vector3f position, WMath::Vector3f rotation, float fov, float nearDistance, float farDistance, float aspectRatio, float width, float height) {
    this->position = WMath::Vector3f(position);
    this->rotation = WMath::Vector3f(rotation);
    this->fov = fov;
    this->nearDistance = nearDistance;
    this->farDistance = farDistance;
    this->aspectRatio = aspectRatio;
    this->width = width;
    this->height = height;
}