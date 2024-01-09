#ifndef CORE_MESH_H
#define CORE_MESH_H
#include <wmath.h>
#include <vector>
#include <graphics.h>
using namespace WMath;

namespace Node {
    struct Triangle
    {
        Vector3f a;
        Vector3f b;
        Vector3f c;
        Vector3f aNormal;
        Vector3f bNormal;
        Vector3f cNormal;
        Vector3f normal;
        color_t color;

        Triangle(Vector3f& a, Vector3f& b, Vector3f& c);
        Triangle(Vector3f& a, Vector3f& b, Vector3f& c, Vector3f& normal);
        Triangle(Vector3f& a, Vector3f& b, Vector3f& c, color_t color);
        Vector3f CalcPlaneNormal();
    };
    
    class Mesh {
        private:
            std::vector<Triangle*> *triangles;
        public:
            Mesh();
            ~Mesh();
            void addTriangle(Triangle* t);
            void addTriangle(Vector3f a, Vector3f b, Vector3f c);
            void addTriangle(Vector3f a, Vector3f b, Vector3f c, Vector3f normal);
            void addTriangle(Vector3f a, Vector3f b, Vector3f c, color_t color);
            std::vector<Triangle*>* getTriangles();
    };
}

#endif
