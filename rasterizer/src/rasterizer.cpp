#include <rasterizer/rasterizer.h>

using namespace Rasterizer;
using namespace WMath;

void Rasterizer2D::DrawTriangle(const Vector2d& a, const Vector2d& b, const Vector2d& c, color_t color) {
	int top = a.y;
	int bottom = a.y;
	int left = a.x;
	int right = a.x;

	if (b.y > top) {
		top = b.y;
	}
	if (b.y < bottom) {
		bottom = b.y;
	}

	if (c.y > top) {
		top = c.y;
	}
	if (c.y < bottom) {
		bottom = c.y;
	}

	if (b.x < left) {
		left = b.x;
	}
	if (b.x > right) {
		right = b.x;
	}

	if (c.x < left) {
		left = c.x;
	}
	if (c.x > right) {
		right = c.x;
	}

	for (int y = bottom; y <= top; y++) {
		for (int x = left; x <= right; x++) {
			Vector2d p(x, y);
			Vector2d v0 = b - a;
			Vector2d v1 = c - b;
			Vector2d v2 = a - c;
			Vector2d v3 = p - a;
			Vector2d v4 = p - b;
			Vector2d v5 = p - c;

			double cross0 = Vector2d::Cross(v3, v0);
			double cross1 = Vector2d::Cross(v4, v1);
			double cross2 = Vector2d::Cross(v5, v2);

			if (cross0 >= 0 && cross1 >= 0 && cross2 >= 0) {
				putpixel(x, y, color);
			}
		}
	}
}
