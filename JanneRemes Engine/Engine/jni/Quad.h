#pragma once
#ifndef QUAD_H
#define QUAD_H

#include <Win32toAndroid.h>
#include <Shader.h>
#include <Texture.h>
#include <glm\glm.hpp>
namespace KaMo
{
	class Quad
	{
	public:
		
		Quad(int X, int Y, float Z, int W, int H);
		~Quad();

		void Move(glm::vec3 Vector3);
		void Move(int X, int Y, float Z);
		void Resize(int W, int H);
		void Rotate(float);
		void SetTexture(Texture* Texture);
		void SetTexture(const char* Texture);
		void SetProgram(GLuint Program);
		void SetProjection(int desiredWidth, int desiredHeight);

		void Draw();

		static float* projection;
		
	private:
		Quad(const Quad&);
		
		void GenBuffer();
		
		int x,y,z,h,w;
		float* translation;
		float* rotation;
		float* scale;

		GLuint position, uv;
		GLint loc, loc2, loc3, loc4, loc5;

	
		Texture* texture;
		GLuint program, vbo;
	};
}
#endif