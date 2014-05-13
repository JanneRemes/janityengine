#pragma once
#ifndef SCENE02_H
#define SCENE02_H


#include <Shader.h>
#include <Mesh.h>
#include <Quad.h>
#include <Camera.h>
#include <Primitives.h>

namespace JanityEngine
{
	class Scene02
	{
	public:
		Scene02(float w, float h);
		~Scene02(void);

		void Update(float dt);
		void Draw();
		void SetProjection();

	private:
		Scene02(const Scene02&);

		void Initialize();

		float desiredWidth;
		float desiredHeight;

		Shader* sceneShader;

		Mesh* gaia;
		Mesh* gaia_cloud;
		Mesh* luna1;
		Mesh* luna2;
		Mesh* luna3;
		Mesh* luna4;
		Mesh* luna5;
	

		float sine;
		bool keyPressed;
	};
}
#endif
