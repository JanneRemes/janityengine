#pragma once
#ifndef SHADERDEMO_H
#define SHADERDEMO_H

#include <Quad.h>
#include <Shader.h>
#include <Shader.h>
namespace JanityEngine
{

	class ShaderDemo
	{
	public:
		ShaderDemo(float w, float h);
		~ShaderDemo(void);

		void Update(float dt);
		void Draw();
		void SetProjection();
	
	private:
		ShaderDemo(const ShaderDemo&);

		void Initialize();

		GLuint Program; 
		GLfloat time;
		GLfloat mouseX, mouseY, resolutionX, resolutionY;
	

		GLfloat totalTime;
		GLfloat mousePositionX, mousePositionY;
		GLfloat screenResolutionX, screenResolutionY;

		float desiredWidth;
		float desiredHeight;

		Shader* sceneShader;
	};
}
#endif
