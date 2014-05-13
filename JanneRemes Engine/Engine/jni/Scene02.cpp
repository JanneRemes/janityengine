#include <Scene02.h>
#include <cmath>
#include <Debug.h>

using namespace JanityEngine;
using namespace glm;

Scene02::Scene02(float w, float h)
{
	desiredWidth = w;
	desiredHeight = h;
	Initialize();
	SetProjection();
}

Scene02::~Scene02(void)
{
	delete gaia;
	delete gaia_cloud;
	delete luna1;
	delete luna2;
	delete luna3;
	delete luna4;
	delete luna5;

}

// PUBLIC
void Scene02::Update(float dt)
{
	sine+=0.01f;
	
	gaia->Rotate(sine*30, 0,1,0);
	gaia_cloud->Rotate(-sine*30, 0,1,0);
	
	
	luna1->Rotate(sine*20, 1,1,0);
	luna1->Move(0 + sin(sine)*2.5f, 0 + cos(sine)*4.5f, 0 + sin(sine)*4.5f);
	luna2->Rotate(-sine*20, 0,1,1);
	luna2->Move(0 + sin(sine+3.14f)*2.5f, 0 + cos(sine+3.14f)*4.5f, 0 + sin(sine+3.14f)*4.5f);
	
	luna3->Rotate(sine*40, 1,0,1);
	luna3->Move(0 + sin(-sine)*10.0f, 0 + cos(-sine)*8.0f, 0 + sin(sine)*13.0f);
	luna4->Rotate(-sine*50, 0,1,0);
	luna4->Move(0 + sin(-sine+2.07f)*10.0f, 0 + cos(-sine+2.07f)*8.0f, 0 + sin(sine-2.07f)*13.0f);
	luna5->Rotate(sine*40, 1,0,1);
	luna5->Move(0 + sin(-sine+4.14f)*10.0f, 0 + cos(-sine+4.14f)*8.0f, 0 + sin(sine-4.14f)*13.0f);
	
	Camera::Move(glm::vec3(0+sin(sine)*60.0f,30,0+cos(sine)*60.0f));

	//if(GetAsyncKeyState(VK_UP) && !keyPressed)
	//	gaia->Move(gaia->x,gaia->y,gaia->z-0.3f);
	//
	//if(GetAsyncKeyState(VK_DOWN) && !keyPressed)
	//	gaia->Move(gaia->x,gaia->y,gaia->z+0.3f);
	//
	//if(GetAsyncKeyState(VK_LEFT) && !keyPressed)
	//	gaia->Move(gaia->x-0.3f,gaia->y,gaia->z);
	//
	//if(GetAsyncKeyState(VK_RIGHT) && !keyPressed)
	//	gaia->Move(gaia->x+0.3f,gaia->y,gaia->z);
	//
	//if(GetAsyncKeyState(VK_CONTROL) && !keyPressed)
	//	gaia->Move(gaia->x,gaia->y+0.3f,gaia->z);
	//
	//if(GetAsyncKeyState(VK_MENU) && !keyPressed)
	//	gaia->Move(gaia->x,gaia->y-0.3f,gaia->z);
	//
	//Debug::WriteLog("Planet x: %d\n", gaia->x);
	//Debug::WriteLog("Planet y: %d\n", gaia->y);
	//Debug::WriteLog("Planet z: %d\n", gaia->z);


	//keyPressed = GetAsyncKeyState(VK_UP) | GetAsyncKeyState(VK_DOWN) 
	//	| GetAsyncKeyState(VK_RIGHT) | GetAsyncKeyState(VK_LEFT)
	//	| GetAsyncKeyState(VK_CONTROL) | GetAsyncKeyState(VK_MENU);
}

void Scene02::Draw()
{	


	gaia->Draw();
	luna1->Draw();
	luna2->Draw();
	luna3->Draw();
	
	luna4->Draw();
	luna5->Draw();
	
	gaia_cloud->Draw();
}

void Scene02::SetProjection()
{
	

	gaia->SetProjection(desiredWidth, desiredHeight);
	gaia_cloud	->SetProjection(desiredWidth, desiredHeight);
	luna1			->SetProjection(desiredWidth, desiredHeight);
	luna2			->SetProjection(desiredWidth, desiredHeight);
	luna3			->SetProjection(desiredWidth, desiredHeight);
	luna4			->SetProjection(desiredWidth, desiredHeight);
	luna5			->SetProjection(desiredWidth, desiredHeight);
}

// PRIVATE

void Scene02::Initialize()
{
	// Create shader
	sceneShader = new Shader();
	GLuint Program = sceneShader->CreateShader("Scene02/scene02.frag","Scene02/scene02.vert");
	delete sceneShader;

	//gaia_cloud =		new Mesh(0, 0, 0, 0.11f,"Scene02/planet.obj");
	//luna1 =			new Mesh(0, 0, 0, 0.1f, "Scene02/planet.obj");
	//luna2 =			new Mesh(0, 0, 0, 0.1f, "Scene02/planet.obj");
	//luna3 =			new Mesh(0, 0, 0, 0.1f, "Scene02/planet.obj");
	//luna4 =			new Mesh(0, 0, 0, 0.1f, "Scene02/planet.obj");
	//luna5 =			new Mesh(0, 0, 0, 0.1f, "Scene02/planet.obj");

	gaia =			new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);
	gaia_cloud =	new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);
	luna1 =			new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);
	luna2 =			new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);
	luna3 =			new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);
	luna4 =			new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);
	luna5 =			new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);

	gaia		->Resize(0.1f, 0.1f, 0.1f);
	gaia_cloud	->Resize(0.11f,0.11f,0.11f);
	luna1		->Resize(0.1f, 0.1f, 0.1f);
	luna2		->Resize(0.1f, 0.1f, 0.1f);
	luna3		->Resize(0.1f, 0.1f, 0.1f);
	luna4		->Resize(0.1f, 0.1f, 0.1f);
	luna5		->Resize(0.1f, 0.1f, 0.1f);

	gaia			->SetProgram(Program);
	gaia_cloud		->SetProgram(Program);
	luna1			->SetProgram(Program);
	luna2			->SetProgram(Program);
	luna3			->SetProgram(Program);
	luna4			->SetProgram(Program);
	luna5			->SetProgram(Program);
	
	gaia			->SetTexture("Scene02/planet.tga");
	gaia_cloud		->SetTexture("Scene02/planet_clouds.tga");
	luna1			->SetTexture("Scene02/planet.tga");
	luna2			->SetTexture("Scene02/planet.tga");
	luna3			->SetTexture("Scene02/planet.tga");
	luna4			->SetTexture("Scene02/planet.tga");
	luna5			->SetTexture("Scene02/planet.tga");




	sine = 0;
	keyPressed = false;
	//camera = Camera::CreateCamera(glm::vec3(0,10,30), glm::vec3(0,0,0), glm::vec3(0,1,0));

}