#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <DeviceManager.h>
#include <ObjLoader.h>

namespace Janity
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
	};
}
#endif