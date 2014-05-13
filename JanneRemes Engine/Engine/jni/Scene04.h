#pragma once
#ifndef SCENE04_H
#define SCENE04_H


#include <Shader.h>
#include <Mesh.h>
#include <Camera.h>
#include <Primitives.h>

namespace JanityEngine
{
	class Scene04
	{
	public:
		Scene04(float w, float h);
		~Scene04(void);

		void Update(float dt);
		void Draw();
		void SetProjection();

	private:
		Scene04(const Scene04&);

		void Initialize();

		float desiredWidth;
		float desiredHeight;

		Mesh* planet;
		Mesh* moon;
		Mesh* probe;

		Shader* sceneShader;

		float sine;
		bool keyPressed;
	};
}
#endif
