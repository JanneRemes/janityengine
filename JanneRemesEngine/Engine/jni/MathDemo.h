#pragma once
#ifndef MATHDEMO_H
#define MATHDEMO_H

#include <Quad.h>
#include <Shader.h>
#include <JanityMath\JanityMath.h>

using namespace JanityMath;

namespace JanityEngine
{
	class MathDemo
	{
	public:
		MathDemo(float w, float h);
		~MathDemo(void);

		void Update(float dt);
		void Draw();
		void SetProjection();
	
	private:
		MathDemo(const MathDemo&);

		void Initialize();

		Quad* gaia;
		Quad* bg;
		Quad* luna1;

		float sine;
		GLsizei desiredWidth;
		GLsizei desiredHeight;

		Shader* sceneShader;
	};
}
#endif
