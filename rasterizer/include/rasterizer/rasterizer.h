
#ifndef RASTERIZER_H
#define RASTERIZER_H
#include <graphics.h>
#include <wmath/wmath.h>
#define WRGB(r, g, b) ((r << 16) | (g << 8) | b)

using namespace WMath;

namespace Rasterizer {
    class Rasterizer2D {
        public:
            static void DrawTriangle(const Vector2d& a, const Vector2d& b, const Vector2d& c, color_t color);
    };
}

#endif
