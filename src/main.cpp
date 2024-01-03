#include <cstdio>
#include <graphics.h>
#include <wmath.h>
#include <rasterizer.h>
#include <node/camera.h>

using namespace WMath;
using namespace Rasterizer;

void drawScene(int width, int height, Core::Camera3D camera) {}

int main()
{
	initgraph(640, 480);

	Vector2i a(300, 300);
	Vector2i b(400, 400);
	Vector2i c(500, 200);

	Rasterizer2D::DrawTriangle(a, b, c, WRGB(255, 0, 0));

	getch();

	closegraph();
	return 0;
}
