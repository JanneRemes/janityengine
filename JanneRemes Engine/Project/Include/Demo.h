#pragma once
#ifndef DEMO_H
#define DEMO_H

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

		

		//Camera* camera;
	
		bool keyPressed;
	};
}
#endif
