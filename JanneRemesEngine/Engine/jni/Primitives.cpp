#include <Primitives.h>

using namespace JanityEngine;

Primitives::Model Primitives::Triangle;
Primitives::Model Primitives::Plane;
Primitives::Model Primitives::Cube;
Primitives::Model Primitives::Sphere;
Primitives::Model Primitives::Pyramid;

Primitives::Primitives()
{
	Load("Primitives/triangle.obj");
	Triangle.vertices = vertices;
	Triangle.uvs = uvs;
	Triangle.normals = normals;
	Clear();
	
	Load("Primitives/plane.obj");
	Plane.vertices = vertices;
	Plane.uvs = uvs;
	Plane.normals = normals;
	Clear();

	Load("Primitives/cube.obj");
	Cube.vertices = vertices;
	Cube.uvs = uvs;
	Cube.normals = normals;
	Clear();

	Load("Primitives/sphere.obj");
	Sphere.vertices = vertices;
	Sphere.uvs = uvs;
	Sphere.normals = normals;
	Clear();

	Load("Primitives/pyramid.obj");
	Pyramid.vertices = vertices;
	Pyramid.uvs = uvs;
	Pyramid.normals = normals;
	Clear();

	
	
}

Primitives::~Primitives()
{
	Clear();
	delete &vertices;
	delete &uvs;
	delete &normals;

	delete &Triangle;
	delete &Plane;
	delete &Cube;
	delete &Sphere;
	delete &Pyramid;
}

//PUBLIC




//PRIVATE
void Primitives::Load(const char* _path)
{
	obj = new ObjLoader();
	obj->LoadOBJ(_path, vertices, uvs, normals);
	delete obj;
}

void Primitives::Clear()
{
	vertices.clear();
	uvs.clear();
	normals.clear();
}