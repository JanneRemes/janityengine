#pragma once
#ifndef Primitives_H
#define Primitives_H

#include <vector>
#include <string>

#include <ObjLoader.h>
#include <JanityMath\JanityMath.h>

using namespace JanityMath;

namespace JanityEngine
{
	
	class Primitives
	{
	public:
		struct Model
		{
			std::vector<Vector3> vertices;
			std::vector<Vector2> uvs;
			std::vector<Vector3> normals;
		}; 

		Primitives();
		~Primitives();

		static struct Model Triangle;
		static struct Model Plane;
		static struct Model Cube;
		static struct Model Sphere;
		static struct Model Pyramid;

	private:
		Primitives(const Primitives&);

		void Load(const char* _path);
		void Clear();

		ObjLoader* obj;

		std::vector<Vector3> vertices;
		std::vector<Vector2> uvs;
		std::vector<Vector3> normals;
	};
}
#endif