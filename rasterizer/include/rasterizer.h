#ifndef RASTERIZER_H
#define RASTERIZER_H
#include <graphics.h>
#include <wmath.h>
#define WRGB(r, g, b) ((r << 16) | (g << 8) | b)

using namespace WMath;

namespace Rasterizer {
    class Rasterizer2D {
        public:
            static void DrawTriangle(const Vector2i& a, const Vector2i& b, const Vector2i& c, color_t color);
    };
}

#endif
