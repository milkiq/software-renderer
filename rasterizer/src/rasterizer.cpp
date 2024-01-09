#include <rasterizer.h>

using namespace Rasterizer;
using namespace WMath;

void Rasterizer2D::DrawTriangle(const Vector2f& a, const Vector2f& b, const Vector2f& c, color_t color) {
	float top = a.y;
	float bottom = a.y;
	float left = a.x;
	float right = a.x;

	// calculate the bounding box of the triangle
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

	left = floor(left);
	right = ceil(right);
	bottom = floor(bottom);
	top = ceil(top);

	// use cross product to judge whether a pixel is in the triangle
	// the right hand rule of cross product can judge whether a point is on the left or right of a line
	// if all three points are on the same side of the line, the result of cross product is all positive or negative
	// but cross product can be optimized, because the result of cross product is a linear change in the loop
	// so we can calculate the cross0 and then add a constant in each loop
	// cross0 = P0.x * (B.y - A.y) + P0.y * (A.x - B.x) + B.x * A.y - A.x * B.y
	// crossn = cross0 + (Pn.x - P0.x) * (B.y - A.y) + (Pn.y - P0.y) * (A.x - B.x)
	// so we only need to calculate cross0 once and then add a constant in each loop
	/** deprecated code
	for (int y = bottom; y <= top; y++) {
		for (int x = left; x <= right; x++) {
			Vector2f p(x, y);
			Vector2f v0 = b - a;
			Vector2f v1 = c - b;
			Vector2f v2 = a - c;
			Vector2f v3 = p - a;
			Vector2f v4 = p - b;
			Vector2f v5 = p - c;

			float cross0 = Vector2f::Cross(v3, v0);
			float cross1 = Vector2f::Cross(v4, v1);
			float cross2 = Vector2f::Cross(v5, v2);

			if (cross0 >= 0 && cross1 >= 0 && cross2 >= 0) {
				putpixel(x, y, color);

			}
		}
	}
	**/

	// optimized code
	float l0 = b.y - a.y;
	float l1 = c.y - b.y;
	float l2 = a.y - c.y;
	float b0 = a.x - b.x;
	float b1 = b.x - c.x;
	float b2 = c.x - a.x;
	float crossY0 = left * l0 + bottom * b0 + b.x * a.y - a.x * b.y;
	float crossY1 = left * l1 + bottom * b1 + c.x * b.y - b.x * c.y;
	float crossY2 = left * l2 + bottom * b2 + a.x * c.y - c.x * a.y;

	for (int y = bottom; y <= top; y++) {
		float crossX0 = crossY0, crossX1 = crossY1, crossX2 = crossY2;
		for (int x = left; x <= right; x++) {
			if (signbit(crossX0) == signbit(crossX1) && signbit(crossX1) == signbit(crossX2)) {
				putpixel(x, y, color);
			}
			crossX0 += l0; crossX1 += l1; crossX2 += l2;
		}
		crossY0 += b0; crossY1 += b1; crossY2 += b2;
	}
}
