#include <cstdio>
#include <graphics.h>
#include <wmath/wmath.h>

int main()
{
	initgraph(640, 480);

	setfont(16, 8, "Courier");	// 设置字体

	setcolor(GREEN);

	wmath::Vector3d a(1, 2, 3);
	wmath::Vector3d b(4, 5, 6);
	double adotb = wmath::Vector3d::dot(a, b);
	double c = wmath::sqrt(2);

	char buffer[256];
	snprintf(buffer, sizeof(buffer), "%f", c);
	outtextxy(320, 240, buffer);
	snprintf(buffer, sizeof(buffer), "%f", adotb);
	outtextxy(320, 260, buffer);

	getch();

	closegraph();

	return 0;
}
