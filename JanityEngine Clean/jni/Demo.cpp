#include <Demo.h>
#include <Util.h>
#include <Camera.h>

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
	delete _primitives;

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
	_primitives = new Primitives();
	camera = Camera::CreateCamera(glm::vec3(0,10,30), glm::vec3(0,0,0), glm::vec3(0,1,0));

	//bgMusic = Sound::Load(Util::resourcePath + "media/kajak.ogg");
	//bgMusic->Loop(AL_TRUE);
	//soundEffect[0] = Sound::Load(Util::resourcePath + "media/hit.ogg");
	//soundEffect[0]->Loop(AL_FALSE);
	//soundEffect[1] = Sound::Load(Util::resourcePath + "media/ruby.ogg");
	//soundEffect[1]->Loop(AL_FALSE);
	
	scene1 = new Scene01(desiredWidth, desiredHeight);


	//bgMusic->Play(40);
}