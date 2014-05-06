#include <Engine.h> 
#include <stdlib.h> 
#include <FileReader.h>
#include <cmath>

using namespace Janity;
Engine::Engine() 
{ 
	Init();
} 
  
Engine::~Engine() 
{ 
	OnExit();
} 
  

  

void Engine::Init()
{
	deviceManager = new DeviceManager();
	soundManager = new SoundManager();
}
void Engine::LoadContent()
{
	contentManager = new ContentManager();
}

void Engine::Update(float dt) 
{ 
	
} 



void Engine::Draw() 
{ 

	
}

void Engine::OnExit()
{
	delete deviceManager;
	delete contentManager;
	delete soundManager;
}