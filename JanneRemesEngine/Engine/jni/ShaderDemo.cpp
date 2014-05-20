#include <ShaderDemo.h>
#include <cmath>
#include <iostream>
#include <Camera.h>
using namespace JanityEngine;

ShaderDemo::ShaderDemo(float w, float h)
{
	desiredWidth = w;
	desiredHeight = h;
	Initialize();
	SetProjection();
}

ShaderDemo::~ShaderDemo(void)
{
}

// PUBLIC

void ShaderDemo::Update(float dt)
{
	totalTime += dt;
}

void ShaderDemo::Draw()
{
	glUseProgram(Program);

	/*glUniform1f(time, totalTime);
	glUniform1f(mouseX,mousePositionX);
	glUniform1f(mouseY,mousePositionY);
	glUniform1f(resolutionX, screenResolutionX);
	glUniform1f(resolutionY, screenResolutionY);*/	
}

void ShaderDemo::SetProjection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,desiredWidth, desiredHeight);
	glFrustum(0,desiredWidth,0,desiredHeight,-1,1);

	/*time = glGetAttribLocation(Program, "time");
	mouseX = glGetAttribLocation(Program, "mouseX");
	mouseY = glGetAttribLocation(Program, "mouseY");

	resolutionX = glGetAttribLocation(Program, "resolutionX");
	resolutionY = glGetAttribLocation(Program, "resolutionY");*/
}

// PRIVATE

void ShaderDemo::Initialize()
{
	totalTime = 0.0f;
	
	screenResolutionX = desiredWidth;
	screenResolutionY = desiredHeight;
	mousePositionX =0;
	mousePositionY =0;

	sceneShader = new Shader();
	//Program = sceneShader->CreateShader("ShaderDemo/test.frag","ShaderDemo/test.vert");
	delete sceneShader;

	Camera* camera = Camera::MainCamera();
	camera->Move(Vector3::up() * 10, Vector3::zero(), Vector3::up());
}