#include <cstdio>
#include <graphics.h>
#include <wmath/wmath.h>
#include <rasterizer/rasterizer.h>

using namespace WMath;
using namespace Rasterizer;

int main()
{
	initgraph(640, 480);

	Vector2d a(300, 300);
	Vector2d b(400, 400);
	Vector2d c(500, 200);

	Rasterizer2D::DrawTriangle(a, b, c, WRGB(255, 0, 0));

	getch();

	closegraph();
	return 0;
}
