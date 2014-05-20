#include <MathDemo.h>
#include <cmath>
#include <iostream>
#include <Camera.h>
using namespace JanityEngine;

MathDemo::MathDemo(float w, float h)
{
	desiredWidth = (GLsizei)w;
	desiredHeight = (GLsizei)h;
	Initialize();
	SetProjection();
}

MathDemo::~MathDemo(void)
{
}

// PUBLIC

void MathDemo::Update(float dt)
{	
	sine+=0.01f;
	std::sin(-sine*3.5f);

	gaia->Rotate(sine/3);
	
	Vector3 moveVector = Vector3(desiredWidth + std::sin(-sine*1.5f+3.14f)*250, desiredHeight + std::cos(-sine*1.5f+3.14f)*350, 0.3f);
	luna1->Move(moveVector);
	
	Vector2 size((int)(128+std::sin(sine*1.5f)*64), (int)(128+std::sin(sine*1.5f)*64));
	luna1->Resize(size);
	luna1->Rotate(-sine/1.5f);
}

void MathDemo::Draw()
{
	bg->Draw();
	gaia->Draw();
	luna1->Draw();
}

void MathDemo::SetProjection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,desiredWidth, desiredHeight);
	glFrustum(0,desiredWidth,0,desiredHeight,-1,1);
	bg->SetProjection(desiredWidth, desiredHeight);
	luna1->SetProjection(desiredWidth, desiredHeight);
}

// PRIVATE

void MathDemo::Initialize()
{
	sine = 0;

	sceneShader = new Shader();
	GLuint Program = sceneShader->CreateShader("MathDemo/scene01.frag","MathDemo/scene01.vert");
	delete sceneShader;

	// Space-background
	bg = new Quad(Vector4(desiredWidth, desiredHeight, 0.6f, desiredWidth), desiredHeight);
	bg->SetProgram(Program);
	bg->SetTexture("MathDemo/Scene01_space.tga");
	bg->Resize(desiredWidth*2, desiredHeight*2);

	// Terra
	gaia = new Quad(Vector4(desiredWidth,desiredHeight, 0.4f, 256), 256);
	gaia->SetProgram(Program);
	gaia->SetTexture("MathDemo/Scene01_gaia.tga");

	luna1 = new Quad(Vector4(desiredWidth+250,desiredHeight, 0.3f, 128), 128);
	luna1->SetProgram(Program);
	luna1->SetTexture("MathDemo/Scene01_luna1.tga");

	Camera* camera = Camera::MainCamera();
	camera->Move(Vector3::up() * 10, Vector3::zero(), Vector3::up());
}