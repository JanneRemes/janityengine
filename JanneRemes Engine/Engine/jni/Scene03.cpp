#include <Scene03.h>
#include <cmath>
#include <Texture.h> // test can delete later
using namespace KaMo;

Scene03::Scene03(float w, float h)
{
	desiredWidth = w;
	desiredHeight = h;
	Initialize();
}

Scene03::~Scene03(void)
{
}

// PUBLIC
float sine = 0;
float X = 0;
void Scene03::Update(float dt)
{
	sine+=0.01f;
	std::sin(-sine*3.5f);

	go2->Rotate(-sine*3.5f);
	X += 10;
	go1->Translate(10, 0, 0);
}

void Scene03::Draw()
{
	go1->sprite->Draw();
	go2->sprite->Draw();
}

void Scene03::SetProjection()
{
	go1->SetProjection(desiredWidth, desiredHeight);
	go2->SetProjection(desiredWidth, desiredHeight);
}

// PRIVATE

void Scene03::Initialize()
{
	scene03Shader = new Shader();
	GLuint Program = scene03Shader->CreateShader("Scene03/scene03.frag","Scene03/scene03.vert");
	delete scene03Shader;

	//GameObject that gets sprite component
	go1 = new GameObject();
	go1->AddComponent(Components::SpriteComponent);
	go1->SetProgram(Program);
	go1->SetTexture("Scene03/Scene03_luna1.tga");
	go1->Translate(300,300,0);
	go1->Scale(200, 200);

	//GameObject that creates sprite component automagically
	Texture* luna1Texture = Texture::Load("Scene03/Scene03_luna1.tga");
	go2 = new GameObject(luna1Texture);
	go2->SetProgram(Program);
	go2->Translate(100, 100);
	go2->Scale(100, 100);
}