#include <Scene01.h>
#include <cmath>

using namespace JanityEngine;

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
	
	sine+=0.01f;
	std::sin(-sine*3.5f);

	// Terra
	gaia->Rotate(sine/3);

	// binary moons
	luna1->Move(desiredWidth + std::sin(-sine*1.5f+3.14f)*250, desiredHeight + std::cos(-sine*1.5f+3.14f)*350, 0.3f);
	luna1->Resize(128+std::sin(sine*1.5f)*64,128+std::sin(sine*1.5f)*64);
	luna1->Rotate(-sine/1.5f);

	luna2->Move(desiredWidth + std::sin(-sine*1.5f)*250, desiredHeight + std::cos(-sine*1.5f)*350, 0.3f);
	luna2->Resize(128+std::sin(sine*1.5f+3.14f)*64,128+std::sin(sine*1.5f+3.14f)*64);
	luna2->Rotate(sine/3);

	// trinary moons
	luna3->Move(desiredWidth + std::sin(sine*0.5f-2)*1200, desiredHeight + std::cos(sine*0.5f-2)*600, 0.5f);
	luna3->Resize(200+std::sin(-sine*0.5f)*128, 200+std::sin(-sine*0.5f)*128);
	luna3->Rotate(-sine/5);

	luna4->Move(desiredWidth + std::sin(sine*0.5f+2)*1200, desiredHeight + std::cos(sine*0.5f+2)*600, 0.5f);
	luna4->Resize(200+std::sin(sine*0.5f)*128, 200+std::sin(sine*0.5f)*128);
	luna4->Rotate(sine/5);

	luna5->Move(desiredWidth + std::sin(sine*0.5f)*1200, desiredHeight + std::cos(sine*0.5f)*600, 0.5f);
	luna5->Resize(200+std::sin(sine*0.5f-2)*128, 200+std::sin(sine*0.5f-2)*128);
	luna5->Rotate(-sine/5);
	
	bg->Resize(desiredWidth*2, desiredHeight*2);
}

void Scene01::Draw()
{
	bg->Draw();

	luna3->Draw();
	luna4->Draw();
	luna5->Draw();

	gaia->Draw();

	luna1->Draw();
	luna2->Draw();
}

void Scene01::SetProjection()
{
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glViewport(0,0,desiredWidth, desiredHeight);
	//glFrustum(0,desiredWidth,0,desiredHeight,-1,1);
	bg->SetProjection(desiredWidth, desiredHeight);
}

// PRIVATE

void Scene01::Initialize()
{
	sine = 0;

	sceneShader = new Shader();
	GLuint Program = sceneShader->CreateShader("Scene01/scene01.frag","Scene01/scene01.vert");
	delete sceneShader;

	// Space-background
	bg = new Quad(desiredWidth, desiredHeight, 0.6f, desiredWidth, desiredHeight);
	bg->SetProgram(Program);
	bg->SetTexture("Scene01/Scene01_space.tga");

	// Terra
	gaia = new Quad(desiredWidth,desiredHeight, 0.4f, 256, 256);
	gaia->SetProgram(Program);
	gaia->SetTexture("Scene01/Scene01_gaia.tga");
	// 1st moon
	luna1 = new Quad(desiredWidth+250,desiredHeight, 0.3f, 128, 128);
	luna1->SetProgram(Program);
	luna1->SetTexture("Scene01/Scene01_luna1.tga");
	// 2nd moon
	luna2 = new Quad(desiredWidth-450,desiredHeight, 0.3f, 128, 128);
	luna2->SetProgram(Program);
	luna2->SetTexture("Scene01/Scene01_luna3.tga");
	// 3rd moon
	luna3 = new Quad(200,200, 0.5f, 128, 128);
	luna3->SetProgram(Program);
	luna3->SetTexture("Scene01/Scene01_luna2.tga");
	// 4th moon
	luna4 = new Quad(desiredWidth*2 - 200,200, 0.5f, 128, 128);
	luna4->SetProgram(Program);
	luna4->SetTexture("Scene01/Scene01_luna4.tga");
	// 5th moon
	luna5 = new Quad(desiredWidth,desiredHeight*2-200, 0.5f, 128, 128);
	luna5->SetProgram(Program);
	luna5->SetTexture("Scene01/Scene01_luna5.tga");
}