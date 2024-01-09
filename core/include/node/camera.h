#ifndef CORE_CAMERA_H
#define CORE_CAMERA_H

#include <wmath.h>

namespace Node {
    class Camera3D {
        public:
            WMath::Vector3f position;
            WMath::Vector3f rotation;
            float fov;
            float nearDistance;
            float farDistance;
            float aspectRatio;

            Camera3D(WMath::Vector3f position, WMath::Vector3f rotation, float fov, float nearDistance, float farDistance, float aspectRatio);
            WMath::Vector4f Project(WMath::Vector3f point);
            void LookAt(WMath::Vector3f point);
            WMath::Vector3f GetForward();

            static WMath::Vector2f ViewportTrans(WMath::Vector4f point, float screenWidth, float screenHeight);
    };
}

#endif
