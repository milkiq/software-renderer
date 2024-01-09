#include <node/mesh.h>

namespace Node {
    Triangle::Triangle(Vector3f& a, Vector3f& b, Vector3f& c) : a(a), b(b), c(c) {
        normal = CalcPlaneNormal();
    }

    Triangle::Triangle(Vector3f& a, Vector3f& b, Vector3f& c, Vector3f& normal) : a(a), b(b), c(c), normal(normal) {}

    Triangle::Triangle(Vector3f& a, Vector3f& b, Vector3f& c, color_t color) : a(a), b(b), c(c), color(color) {
        normal = CalcPlaneNormal();
    }

    Vector3f Triangle::CalcPlaneNormal() {
        Vector3f v1 = a - b;
        Vector3f v2 = c - b;

        return v1.Cross(v2).Normalized();
    }

    Mesh::Mesh() {
        triangles = new std::vector<Triangle*>();
    }

    Mesh::~Mesh() {
        for (int i = 0; i < triangles->size(); i++) {
            delete triangles->at(i);
        }
        delete &triangles;
    }

    void Mesh::addTriangle(Triangle* t) {
        triangles->push_back(t);
    }

    void Mesh::addTriangle(Vector3f a, Vector3f b, Vector3f c) {
        Triangle* t = new Triangle(a, b, c);
        triangles->push_back(t);
    }

    void Mesh::addTriangle(Vector3f a, Vector3f b, Vector3f c, color_t color) {
        Triangle* t = new Triangle(a, b, c, color);
        triangles->push_back(t);
    }

    void Mesh::addTriangle(Vector3f a, Vector3f b, Vector3f c, Vector3f normal) {
        Triangle* t = new Triangle(a, b, c, normal);
        triangles->push_back(t);
    }

    std::vector<Triangle*>* Mesh::getTriangles() {
        return triangles;
    }
}
