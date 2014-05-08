#pragma once
#ifndef GAME_H
#define GAME_H

#include <Engine.h>
#include <Demo.h>

namespace Janity
{


	class Game : Engine
	{
	public:
		Game(float DesiredWidth,float DesiredHeight, float width,float height);
		~Game();
		virtual void Init();
		virtual void LoadContent();		
		virtual void Update(float dt);
		virtual void Draw();
		virtual void OnExit();

		void CreateObjects();
		DeviceManager *deviceManager;
	
	private:
		Game(const Game& game);

		float position;
		float sine;

		//GLfloat* Data;
		Shader* shader;
		

		float desiredWidth;
		float desiredHeight;

		// Demo creates and contains all scenes.
		Demo* demo;
	};

}
#endif