#pragma once
#ifndef SCENE01_H
#define SCENE01_H

#include <Quad.h>
#include <Shader.h>

namespace JanityEngine
{
	class Scene01
	{
	public:
		Scene01(float w, float h);
		~Scene01(void);

		void Update(float dt);
		void Draw();
		void SetProjection();
	
	private:
		Scene01(const Scene01&);

		void Initialize();

		Quad* gaia;
		Quad* luna1;
		Quad* luna2;
		Quad* luna3;
		Quad* luna4;
		Quad* luna5;
		Quad* bg;

		float sine;
		float desiredWidth;
		float desiredHeight;

		Shader* sceneShader;
	};
}
#endif
