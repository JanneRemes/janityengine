#include <Scene01.h>
#include <cmath>
#include <iostream>
#include <Camera.h>
using namespace JanityEngine;

Scene01::Scene01(float w, float h) : MAX_COLLISIONS(3), GRAVITY(-9810000)
{

	desiredWidth = (GLsizei)w;
	desiredHeight = (GLsizei)h;
	Initialize();
	SetProjection();

	radius=20;
	amountOfCollisions=0;
	collisionVelocityPenalty=0.3f;

	position = Vector3(desiredWidth, desiredHeight+ 250, 0);
	collisionHeight = 0;
	speed = 200000;
	dir = Vector2(0.1f, -1);
	velocity = dir * speed;
}

Scene01::~Scene01(void)
{
}

// PUBLIC

void Scene01::Update(float dt)
{	

	position.x += velocity.x*dt;
	velocity.y -= GRAVITY*dt;
	position.y += velocity.y*dt;

	CollisionCheck(position.y);
	
	//y = position.y;
	velocity.y -= GRAVITY*dt;
	position.y += velocity.y*dt;
	std::cout << position << std::endl;

	gaia->Move(position);
}

void Scene01::Draw()
{
	gaia->Draw();
}

bool Scene01::CollisionCheck(float newY)
{
	if(newY > collisionHeight)
	{
		amountOfCollisions++;
		if(amountOfCollisions >= MAX_COLLISIONS)
		{
			velocity.y= 0;
			velocity.x = 0;
		}
		else
		{
			velocity.y *= -1;
			
			velocity.y -= velocity.y* collisionVelocityPenalty;
			position = Vector3(position.x, collisionHeight, position.z);
		}
		return true;
	}
	return false;
}


void Scene01::SetProjection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,desiredWidth, desiredHeight);
	glFrustum(0,desiredWidth,0,desiredHeight,-1,1);
	gaia->SetProjection(desiredWidth, desiredHeight);
}

// PRIVATE

void Scene01::Initialize()
{
	sceneShader = new Shader();
	GLuint Program = sceneShader->CreateShader("MathDemo/scene01.frag","MathDemo/scene01.vert");
	delete sceneShader;

	// Terra
	gaia = new Quad(Vector4(desiredWidth,desiredHeight, 0.4f, 256), 256);
	gaia->SetProgram(Program);
	gaia->SetTexture("MathDemo/Scene01_gaia.tga");

	position = Vector3(desiredWidth, desiredHeight+ 250, 0);
	gaia->Move(position);

	Camera* camera = Camera::MainCamera();
	camera->Move(Vector3::up() * 10, Vector3::zero(), Vector3::up());
}