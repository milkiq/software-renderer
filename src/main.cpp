#include <cstdio>
#include <vector>
#include <graphics.h>
#include <wmath.h>
#include <rasterizer.h>
#include <node/camera.h>
#include <node/mesh.h>

using namespace WMath;
using namespace Rasterizer;

Node::Mesh mesh;

void drawScene(int width, int height, Node::Camera3D camera) {
	std::vector<Node::Triangle*>* triangles = mesh.getTriangles();
	for (int i = 0; i < triangles->size(); i++) {
		Node::Triangle* triangle = triangles->at(i);
		// FIXME: Fix camera forward vector
		Vector3f cameraForward = Vector3f(0, 0, 0) - camera.position;
		if(triangle->normal.Dot(cameraForward) > 0) continue;

		Vector3f a = triangle->a;
		Vector3f b = triangle->b;
		Vector3f c = triangle->c;
		color_t color = triangle->color;
		Vector4f aProjected = camera.Project(a);
		Vector4f bProjected = camera.Project(b);
		Vector4f cProjected = camera.Project(c);
		Vector2f a2D = camera.ViewportTrans(aProjected, width, height);
		Vector2f b2D = camera.ViewportTrans(bProjected, width, height);
		Vector2f c2D = camera.ViewportTrans(cProjected, width, height);
		Rasterizer2D::DrawTriangle(a2D, b2D, c2D, color);
	}
}

int main()
{
	initgraph(640, 480);

	mesh.addTriangle(
		Vector3f(-1, 1, 1),
		Vector3f(1, 1, 1),
		Vector3f(-1, -1, 1),
		WRGB(255, 0, 0)
	);
	mesh.addTriangle(
		Vector3f(1, 1, 1),
		Vector3f(1, -1, 1),
		Vector3f(-1, -1, 1),
		WRGB(255, 0, 0)
	);
	mesh.addTriangle(
		Vector3f(1, 1, 1),
		Vector3f(1, 1, -1),
		Vector3f(1, -1, 1),
		WRGB(0, 255, 0)
	);
	mesh.addTriangle(
		Vector3f(1, 1, -1),
		Vector3f(1, -1, -1),
		Vector3f(1, -1, 1),
		WRGB(0, 255, 0)
	);
	mesh.addTriangle(
		Vector3f(1, 1, -1),
		Vector3f(-1, 1, -1),
		Vector3f(1, -1, -1),
		WRGB(0, 0, 255)
	);
	mesh.addTriangle(
		Vector3f(-1, 1, -1),
		Vector3f(-1, -1, -1),
		Vector3f(1, -1, -1),
		WRGB(0, 0, 255)
	);
	mesh.addTriangle(
		Vector3f(-1, 1, -1),
		Vector3f(-1, 1, 1),
		Vector3f(-1, -1, -1),
		WRGB(255, 255, 0)
	);
	mesh.addTriangle(
		Vector3f(-1, 1, 1),
		Vector3f(-1, -1, 1),
		Vector3f(-1, -1, -1),
		WRGB(255, 255, 0)
	);
	mesh.addTriangle(
		Vector3f(-1, 1, 1),
		Vector3f(-1, 1, -1),
		Vector3f(1, 1, 1),
		WRGB(0, 255, 255)
	);
	mesh.addTriangle(
		Vector3f(-1, 1, -1),
		Vector3f(1, 1, -1),
		Vector3f(1, 1, 1),
		WRGB(0, 255, 255)
	);
	mesh.addTriangle(
		Vector3f(-1, -1, 1),
		Vector3f(1, -1, 1),
		Vector3f(-1, -1, -1),
		WRGB(255, 0, 255)
	);
	mesh.addTriangle(
		Vector3f(1, -1, 1),
		Vector3f(1, -1, -1),
		Vector3f(-1, -1, -1),
		WRGB(255, 0, 255)
	);

	Node::Camera3D camera(
		Vector3f(0,0,3),
		Vector3f(0,0,0),
		PI*0.6666,
		1.0,
		1000.0,
		1.3333
	);

	float radius = 0;
	for ( ; is_run() && kbmsg() == 0; delay_fps(60) )
	{
		camera.position = Vector3f(cos(radius) * 3, 0, sin(radius) * 3);
		// FIXME: fix camera lookat
		camera.LookAt(Vector3f(0, 0, 0));
		cleardevice();
		drawScene(640, 480, camera);
		radius += 0.01;
		if(radius > 2 * PI) radius = 0;
	}

	closegraph();
	return 0;
}
