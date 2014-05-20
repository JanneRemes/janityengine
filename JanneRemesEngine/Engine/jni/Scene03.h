#pragma once
#ifndef SCENE03_H
#define SCENE03_H

#include <Quad.h>
#include <Shader.h>
#include <GameObject.h>

namespace JanityEngine
{
	class Scene03
	{
	public:
		Scene03(float w, float h);
		~Scene03(void);

		void Update(float dt);
		void Draw();
		void SetProjection();
	
	private:
		Scene03(const Scene03&);

		void Initialize();

		float desiredWidth;
		float desiredHeight;

		GameObject *go1;
		GameObject *go2;
		Sprite* sprite1;

		Shader* sceneShader;
	};
}
#endif
