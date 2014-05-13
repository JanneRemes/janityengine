#pragma once
#ifndef MESH_H
#define MESH_H

#include <Win32toAndroid.h>
#include <Shader.h>
#include <Texture.h>
#include <ObjLoader.h>

#include <vector>
#include <JanityMath\JanityMath.h>
using namespace JanityMath;

namespace JanityEngine
{
	class Mesh
	{
	public:
		Mesh(int X, int Y, int Z, float scale, const char* _objPath);
		Mesh(int Size, float* _data);
		Mesh(std::vector<Vector3> _vertices, std::vector<Vector2> _uvs, std::vector<Vector3> _normals);
		~Mesh();
		
		void Move(float X, float Y, float Z);
		void Move(Vector3 vector3);
		void Resize(float W, float H, float D);
		void Rotate(float, int X, int Y, int Z);
		void SetTexture(const char* Texture);
		void SetProgram(GLuint program);
		void SetProjection(int desiredWidth, int desiredHeight);

		void Draw();
		float x,y,z;

		float* Data;
		int _size;
	private:
		Mesh(const Mesh& mesh);
		Mesh& operator = (const Mesh&);


		void LoadObj(const char* _objPath);
		void HandleData();
		void GenBuffer();
		

		GLuint position, uv;
		GLint loc, loc2, loc3, loc4, loc5;
		GLint loc6, loc7;

		GLuint program, vbo;
		Texture* texture;
		ObjLoader* obj;
		
		std::vector<Vector3> vertices;
		std::vector<Vector2> uvs;
		std::vector<Vector3> normals;

		Matrix4 translation;
		Matrix4 rotation;
		Matrix4 scale;
		Matrix4 projection;
		Matrix4 view;
		Matrix4 model;
	};
}
#endif