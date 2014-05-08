#include <Primitives.h>

using namespace KaMo;

Primitives::Model Primitives::Cube;
Primitives::Model Primitives::Plane;
Primitives::Model Primitives::Sphere;
Primitives::Model Primitives::Moon;

Primitives::Primitives()
{
	Load("!cube.obj");
	Cube.vertices = vertices;
	Cube.uvs = uvs;
	Cube.normals = normals;
	Clear();

	Load("Plane.obj");
	Plane.vertices = vertices;
	Plane.uvs = uvs;
	Plane.normals = normals;
	Clear();

	Load("Scene02/planet.obj");
	Sphere.vertices = vertices;
	Sphere.uvs = uvs;
	Sphere.normals = normals;
	Clear();
}

Primitives::~Primitives()
{
	Clear();
	delete &vertices;
	delete &uvs;
	delete &normals;

	delete &Cube;
	delete &Plane;
	delete &Sphere;
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