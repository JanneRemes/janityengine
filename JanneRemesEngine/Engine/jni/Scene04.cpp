#include <Scene04.h>

#include <JanityMath\JanityMath.h>

using namespace JanityMath;
using namespace JanityEngine;

Scene04::Scene04(float w, float h)
{
	desiredWidth = w;
	desiredHeight = h;
	Initialize();
	SetProjection();
}

Scene04::~Scene04()
{
	delete planet;
	delete moon;
	delete probe;
}

// PUBLIC
float rKey = 0.0f;
void Scene04::Update(float dt)
{
	sine+=0.01f;

	planet->Move(0,0,0);
	planet->Rotate(sine*30,0,1,0);

	moon->Move(0 + sin(sine)*2.5f, 0 + cos(sine)*4.5f, 0 + sin(sine)*4.5f);
	probe->Move(sin(sine)*2.5f - cos(sine)*2.5f, cos(sine)*4.5f - sin(sine)*2.5f, sin(sine)*4.5f);

	//Camera::Move(glm::vec3(0+sin(sine)*60.0f,30,0+cos(sine)*60.0f));
	Camera* mainCamera = Camera::MainCamera();

	Vector3 temp = mainCamera->_position - mainCamera->_lookAt;
	float distance = std::sqrt((temp.x)*(temp.x)+(temp.z)*(temp.z));

	if(GetAsyncKeyState(VK_UP) && !keyPressed)
	{	rKey+=0.1f;
		mainCamera->Move(Vector3(0+sin(rKey)*distance,mainCamera->_position.y,mainCamera->_position.z-1));
		//Camera::Move(glm::vec3(Camera::_position.x,Camera::_position.y,Camera::_position.z-1));
	}
	if(GetAsyncKeyState(VK_DOWN) && !keyPressed)
	{	rKey+=0.1f;
		mainCamera->Move(Vector3(0+sin(rKey)*distance,mainCamera->_position.y,0+cos(rKey)*distance));
		//Camera::Move(glm::vec3(Camera::_position.x,Camera::_position.y,Camera::_position.z+1));
	}
	if(GetAsyncKeyState(VK_LEFT) && !keyPressed)
	{	rKey+=0.1f;
		mainCamera->Move(Vector3(0+sin(rKey)*distance,mainCamera->_position.y,0+cos(rKey)*distance));
		//Camera::Move(glm::vec3(Camera::_position.x-1,Camera::_position.y,Camera::_position.z));
	}
	if(GetAsyncKeyState(VK_RIGHT) && !keyPressed)
	{	rKey-=0.1f;
		mainCamera->Move(Vector3(0+sin(rKey)*distance,mainCamera->_position.y,0+cos(rKey)*distance));
		//Camera::Move(glm::vec3(Camera::_position.x+1,Camera::_position.y,Camera::_position.z));
	}
	if(GetAsyncKeyState(VK_CONTROL) && !keyPressed)
	{
		mainCamera->Move(Vector3(mainCamera->_position.x,mainCamera->_position.y-1,mainCamera->_position.z));
	}
	if(GetAsyncKeyState(VK_MENU) && !keyPressed)
	{
		mainCamera->Move(Vector3(mainCamera->_position.x,mainCamera->_position.y+1,mainCamera->_position.z));
	}

	Debug::WriteLog("Camera x: %f\n", temp.x);
	Debug::WriteLog("Camera y: %f\n", temp.y);
	Debug::WriteLog("Camera z: %f\n", temp.z);
	Debug::WriteLog("Camera x-z: %f\n", distance);

	//keyPressed = GetAsyncKeyState(VK_UP) | GetAsyncKeyState(VK_DOWN) 
	//	| GetAsyncKeyState(VK_RIGHT) | GetAsyncKeyState(VK_LEFT)
	//	| GetAsyncKeyState(VK_CONTROL) | GetAsyncKeyState(VK_MENU);
}

void Scene04::Draw()
{
	planet->Draw();
	moon->Draw();
	probe->Draw();
}

void Scene04::SetProjection()
{
	planet->SetProjection(desiredWidth, desiredHeight);
	moon->SetProjection(desiredWidth, desiredHeight);
	probe->SetProjection(desiredWidth, desiredHeight);
}

// PRIVATE 
void Scene04::Initialize()
{
	sceneShader = new Shader();
	GLuint Program = sceneShader->CreateShader("Scene04/scene04.frag","Scene04/scene04.vert");
	delete sceneShader;

	planet	= new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);
	moon	= new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);
	probe	= new Mesh(Primitives::Sphere.vertices, Primitives::Sphere.uvs, Primitives::Sphere.normals);

	planet	->Resize(0.1f, 0.1f, 0.1f);
	moon	->Resize(0.1f, 0.1f, 0.1f);
	probe	->Resize(0.05f, 0.05f, 0.05f);

	planet	->SetProgram(Program);
	moon	->SetProgram(Program);
	probe	->SetProgram(Program);

	planet	->SetTexture("Scene04/planet.tga");
	moon	->SetTexture("Scene04/planet.tga");
	probe	->SetTexture("Scene04/planet.tga");

	sine = 0.0f;
	keyPressed = false;
}