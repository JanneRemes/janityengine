#include <Scene01.h>
#include <cmath>


using namespace Janity;


Scene01::Scene01(float w, float h)
{
	desiredWidth = w;
	desiredHeight = h;
	Initialize();
	SetProjection();
}

Scene01::~Scene01(void)
{

}

// PUBLIC
void Scene01::Update(float dt)
{
	

	//keyPressed = GetAsyncKeyState(VK_UP) | GetAsyncKeyState(VK_DOWN) 
	//	| GetAsyncKeyState(VK_RIGHT) | GetAsyncKeyState(VK_LEFT)
	//	| GetAsyncKeyState(VK_CONTROL) | GetAsyncKeyState(VK_MENU);
}

void Scene01::Draw()
{	
	//bg->Draw();

	
}

void Scene01::SetProjection()
{
	//bg->SetProjection(desiredWidth, desiredHeight);
}

// PRIVATE

void Scene01::Initialize()
{
	// Create shader
	//sceneShader = new Shader();
	//GLuint Program = sceneShader->CreateShader("Scene01/scene01.frag","Scene01/scene01.vert");
	//delete sceneShader;

}