#pragma once
#ifndef SCENE01_H
#define SCENE01_H


//#include <Shader.h>
//#include <Quad.h>
//#include <Camera.h>


namespace Janity
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

		float desiredWidth;
		float desiredHeight;

		//Shader* sceneShader;

		bool keyPressed;
	};
}
#endif
