#pragma once
#ifndef DEMO_H
#define DEMO_H

#include <Sound.h>
#include <Primitives.h>
#include <Camera.h>

#include <Scene01.h>
#include <Scene02.h>
#include <Scene03.h>
#include <Scene04.h>

namespace JanityEngine
{
	class Demo
	{
	public:
		Demo(float w, float h);
		~Demo(void);

		void Update(float dt);
		void Draw();

		static float* sphere;

	private:
		Demo(const Demo&);

		int activeScene;
		float sceneTimer;
		float desiredWidth;
		float desiredHeight;

		void CreateScenes();

		Scene01* scene1;
		Scene02* scene2;
		Scene03* scene3;
		Scene04* scene4;

		Sound* bgMusic;
		Sound* soundEffect[2];

		Primitives* _primitives;

		Camera* camera;
	
		bool keyPressed;
	};
}
#endif
