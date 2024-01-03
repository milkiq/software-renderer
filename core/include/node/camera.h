#ifndef CORE_CAMERA_H
#define CORE_CAMERA_H

#include <wmath.h>

namespace Core {
    class Camera3D {
        public:
            WMath::Vector3f position;
            WMath::Vector3f rotation;
            float fov;
            float nearDistance;
            float farDistance;
            float aspectRatio;
            float width;
            float height;

            Camera3D(WMath::Vector3f position, WMath::Vector3f rotation, float fov, float nearDistance, float farDistance, float aspectRatio, float width, float height);
    };
}

#endif
