#pragma once
#ifndef DEMO_H
#define DEMO_H

#include <Sound.h>
#include <Primitives.h>
#include <Camera.h>
#include <Debug.h>
#include <Scene01.h>


namespace Janity
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

		Sound* bgMusic;
		Sound* soundEffect[2];

		Primitives* _primitives;

		Camera* camera;
	
		bool keyPressed;
	};
}
#endif
