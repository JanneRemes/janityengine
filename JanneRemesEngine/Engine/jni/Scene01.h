#pragma once
#ifndef SCENE01_H
#define SCENE01_H

#include <Quad.h>
#include <Shader.h>
#include <JanityMath\JanityMath.h>

using namespace JanityMath;

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
		
		int amountOfCollisions;
		const int MAX_COLLISIONS;
	
		float collisionVelocityPenalty;
		float collisionHeight;
		float radius;
		Vector2 dir;
		float speed;
		const float GRAVITY;
		Vector2 velocity;
		Vector3 position;
		bool CollisionCheck(float newY);
		void Move(float dt);


		GLsizei desiredWidth;
		GLsizei desiredHeight;

		Shader* sceneShader;
	};
}
#endif
