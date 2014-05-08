#include <Demo.h>
//#include <Camera.h>

using namespace Janity;

Demo::Demo(float w, float h)
{
	desiredWidth = w;
	desiredHeight = h;
	CreateScenes();

	activeScene = 1;
	sceneTimer = 0.0f;

	keyPressed = false;
}

Demo::~Demo(void)
{
	delete scene1;
}

// PUBLIC
void Demo::Update(float dt)
{
	//sceneTimer += dt;

	if(sceneTimer > 0.005f)
	{
		sceneTimer = 0.0f;
		if(activeScene < 4)
			activeScene++;
		else
			activeScene = 1;
	}


	switch(activeScene)
	{
	case 1:
		scene1->SetProjection();
		scene1->Update(dt);
		break;
	}
}

void Demo::Draw()
{
	switch(activeScene)
	{
	case 1:
		scene1->Draw();
		break;
	}
}


// PRIVATE

void Demo::CreateScenes()
{
	//camera = Camera::CreateCamera(glm::vec3(0,10,30), glm::vec3(0,0,0), glm::vec3(0,1,0));
	
	scene1 = new Scene01(desiredWidth, desiredHeight);
}