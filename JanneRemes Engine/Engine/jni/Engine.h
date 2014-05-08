#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <Win32toAndroid.h>

//#include <InputManager.h>
#include <ContentManager.h>
#include <DeviceManager.h>
#include <SoundManager.h>
#include <ObjLoader.h>

namespace KaMo
{
	class Engine
	{
	public:

		Engine();
		~Engine(); 
		
	
	
		virtual void LoadContent();	//TODO: points to content manager, 
		virtual void Init();
		virtual void Update(float dt);
		virtual void Draw();
		virtual void OnExit();	//TODO: not implemented
	
		DeviceManager* deviceManager;
	private:
		ContentManager* contentManager;
		SoundManager* soundManager;
		
		//InputManager *inputManager;




	};
}
#endif