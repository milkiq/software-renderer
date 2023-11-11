#include <rasterizer/rasterizer.h>

using namespace Rasterizer;
using namespace WMath;

void Rasterizer2D::DrawTriangle(const Vector2d& a, const Vector2d& b, const Vector2d& c, color_t color) {
	int top = a.y;
	int bottom = a.y;
	int left = a.x;
	int right = a.x;

	// 计算三角形的包围盒
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

	// 使用叉乘进行像素是否在三角形内的判断:
	// 叉乘的右手定则可以判断出点在直线的左边还是右边，如果三个点都在直线的同一侧，那么叉乘的结果都是正数或者都是负数
	// 但是叉乘可以进一步优化，因为叉乘的结果在循环中是一个线性变化
	// 可以通过叉乘的运算方式算得
	// 总之 cross0 = P0.x * (B.y - A.y) + P0.y * (A.x - B.x) + B.x * A.y - A.x * B.y
	// crossn = cross0 + (Pn.x - P0.x) * (B.y - A.y) + (Pn.y - P0.y) * (A.x - B.x)
	// 所以只在开始算一次 cross0，然后每次循环只需要加上一个常数即可
	/** 已弃用的直接叉乘法
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
	**/

	// 优化后的叉乘法
	double l0 = b.y - a.y;
	double l1 = c.y - b.y;
	double l2 = a.y - c.y;
	double b0 = a.x - b.x;
	double b1 = b.x - c.x;
	double b2 = c.x - a.x;
	double crossY0 = left * l0 + bottom * b0 + b.x * a.y - a.x * b.y;
	double crossY1 = left * l1 + bottom * b1 + c.x * b.y - b.x * c.y;
	double crossY2 = left * l2 + bottom * b2 + a.x * c.y - c.x * a.y;

	for (int y = bottom; y <= top; y++) {
		double crossX0 = crossY0, crossX1 = crossY1, crossX2 = crossY2;
		for (int x = left; x <= right; x++) {
			if (crossX0 >= 0 && crossX1 >= 0 && crossX2 >= 0) {
				putpixel(x, y, color);
			}
			crossX0 += l0; crossX1 += l1; crossX2 += l2;
		}
		crossY0 += b0; crossY1 += b1; crossY2 += b2;
	}
}
