#include <GameObject.h>
using namespace JanityEngine;

GameObject::GameObject()
: sprite(NULL),
  mesh(NULL)//empty gameObject
{
	ResetTransform();
}

//constructor mesh
GameObject::GameObject(Mesh* Mesh)
	: sprite(NULL)
{
	ResetTransform();
	mesh = Mesh;
}
GameObject::GameObject(Mesh* Mesh, glm::vec3 Position)
	: sprite(NULL)
{
	mesh = Mesh;
	ResetTransform();
	Translate(Position);
}
GameObject::GameObject(Mesh* Mesh, glm::vec3 Position, float Angle, glm::vec3 Axis)
	: sprite(NULL)
{
	mesh = Mesh;	
	ResetTransform();
	Translate(Position);
	Rotate(Angle, Axis);
}
GameObject::GameObject(Mesh* Mesh, glm::vec3 Position, float Angle, glm::vec3 Axis, glm::vec3 Scale)
	: sprite(NULL)
{
	mesh = Mesh;	
	ResetTransform();
	Rotate(Angle, Axis);
}

GameObject::GameObject(Mesh* Mesh, Transform Transform)
{
	ResetTransform();
	mesh = Mesh;
	Translate(Transform.position.x, Transform.position.y, Transform.position.z);
	Rotate(Transform.rotation);
	Scale(Transform.scale.x, Transform.scale.y, Transform.scale.z);
}

//constructor sprite
GameObject::GameObject(Texture* Texture)
	: mesh(NULL)
{
	sprite = new Sprite(Texture);
	ResetTransform();
}

//vec2
GameObject::GameObject(Texture* Texture, glm::vec2 Position) 
	: mesh(NULL)
{
	sprite = new Sprite(Texture);
	ResetTransform();
	Translate(Position.x, Position.y);
}

GameObject::GameObject(Texture* Texture, glm::vec2 Position, float Rotation)
	: mesh(NULL)
{
	sprite = new Sprite(Texture);
	ResetTransform();
	Translate(Position.x, Position.y);
	Rotate(Rotation);
}
GameObject::GameObject(Texture* Texture, glm::vec2 Position, float Rotation, float Scalar) 
	: mesh(NULL)
{
	sprite = new Sprite(Texture);
	ResetTransform();
	Translate(Position);
	Rotate(Rotation);
	Scale(Scalar);
}
GameObject::GameObject(Texture* Texture, glm::vec2 Position, float Rotation, glm::vec2 Scalar)
	: mesh(NULL)
{
	sprite = new Sprite(Texture);
	ResetTransform();
	Translate(Position);
	Rotate(Rotation);
	Scale(Scalar);
}


//vec3
GameObject::GameObject(Texture* Texture, glm::vec3 Position)
	: mesh(NULL)
{
	sprite = new Sprite(Texture);
	ResetTransform();
	transform.position = Position;
}
GameObject::GameObject(Texture* Texture, glm::vec3 Position, float Rotation, float Scalar)
	: mesh(NULL)
{
	sprite = new Sprite(Texture);
	ResetTransform();
	Translate(Position);
	Rotate(Rotation);
	Scale(Scalar);
}
GameObject::GameObject(Texture* Texture, glm::vec3 Position, float Rotation, glm::vec3 Scalar)
	: mesh(NULL)
{
	sprite = new Sprite(Texture);
	ResetTransform();
	Translate(Position);
	Rotate(Rotation);
	Scale(Scalar);
}

GameObject::GameObject(Texture* Texture, Transform Transform)
	: mesh(NULL)
{
	sprite = new Sprite(Texture);
	ResetTransform();
	Translate(Transform.position);
	Rotate(Transform.rotation.z);
	Scale(Transform.scale);
}


GameObject::~GameObject()
{
}
GameObject::GameObject(const GameObject& gameObject)
{
}
GameObject GameObject::Instantiate(const GameObject& prefab)
{
	return GameObject(prefab);
}

GameObject GameObject::Instantiate(const GameObject& Prefab, glm::vec2 Position)
{
	GameObject go = GameObject(Prefab);
	go.transform.position.x = Position.x;
	go.transform.position.y = Position.y;
	return go;
}
GameObject GameObject::Instantiate(const GameObject& Prefab, glm::vec3 Position)
{
	GameObject go = GameObject(Prefab);
	go.transform.position = Position;
	return go;
}


void GameObject::Destroy()
{
	Object::~Object();
}
void GameObject::PrintInfo()
{
}

void GameObject::ResetTransform()
{
	transform.position.x = 0;
	transform.position.y = 0;
	transform.position.z = 0;
	transform.rotation.null;
	transform.scale.x = 1;
	transform.scale.y = 1;
	transform.scale.z = 1;
}

void GameObject::Draw()
{
	if(sprite != NULL)
	{
		sprite->Draw();
	}
	if(mesh != NULL)
	{
		mesh->Draw();
	}
}

void GameObject::SetProjection(float desiredWidth, float desiredHeight)
{
	if (sprite != NULL)
	{
		sprite->SetProjection(desiredWidth, desiredHeight);
	}
	if(mesh !=NULL)
	{
		mesh->SetProjection(desiredWidth, desiredHeight);
	}
}
void GameObject::SetProgram(GLuint program)
{
	if (sprite != NULL)
	{
		sprite->SetProgram(program);
	}
	if(mesh != NULL)
	{
		mesh->SetProgram(program);
	}
}
void GameObject::SetTexture(const char* texturePath)
{
	if (sprite != NULL)
	{
		sprite->SetTexture(texturePath);
	}
}
void GameObject::SetTexture(Texture* Texture)
{
	if (sprite != NULL)
	{
		sprite->SetTexture(Texture);
	}
}

void GameObject::AddComponent(Components component)
{
	switch(component)
	{
		case Components::AnimationTrackComponent:
			break;
		case Components::CameraComponent:
			break;
		case Components::LightComponent: 
			break;
		case Components::MaterialComponent:
			break;
		case Components::MeshComponent:
			
			break;
		case Components::SpriteComponent:
			if (sprite == nullptr)
			{
				sprite = new Sprite();
			}
			else
			{
				RemoveComponent(Components::SpriteComponent);
				sprite = new Sprite();
			}
			break;
	}
}

void GameObject::AddComponent(Components Component, Texture* Texture)
{
	switch(Component)
	{
		case Components::SpriteComponent:
			sprite = new Sprite(Texture);
			UpdateTransform();
			break;
	}
}

bool GameObject::HasComponent(Components Component)
{
	switch(Component)
	{
	case Components::SpriteComponent:
		return (sprite) ? true:false;
		break;
	}
}

void* GameObject::GetComponent(Components Component)
{
	switch(Component)
	{
	case Components::SpriteComponent:
		return sprite;
		break;
	}
}

void GameObject::RemoveComponent(Components Component)
{
	switch(Component)
	{
	case Components::SpriteComponent:
		if(sprite)
			delete(sprite);
		break;
	}
}

void GameObject::Translate(glm::vec2 Vector2)
{
	Translate(Vector2.x, Vector2.y, 0);
}
void GameObject::Translate(glm::vec3 Vector3)
{
	Translate(Vector3.x, Vector3.y, Vector3.z);
}
void GameObject::Translate(float X, float Y, float Z)
{
	transform.position.x += X;
	transform.position.y += Y;
	transform.position.z += Z;
	UpdateTransform();
}

void GameObject::Scale(glm::vec2 Scalar)
{
	Scale(Scalar.x, Scalar.y, 0);
}
void GameObject::Scale(glm::vec3 Scalar)
{
	Scale(Scalar.x, Scalar.y, Scalar.z);
}
void GameObject::Scale(float X, float Y, float Z)
{
	transform.scale.x += X;
	transform.scale.y += Y;
	transform.scale.z += Z;

	if (sprite != NULL)
	{
		sprite->Resize(transform.scale.x, transform.scale.y);
	}
	if(mesh != NULL)
	{
		mesh->Resize(transform.scale.x, transform.scale.y, transform.scale.z);
	}
}

//rotates sprite
void GameObject::Rotate(float Z)
{
	if (sprite != NULL)
	{
		sprite->Rotate(Z);
	}
}
void GameObject::Rotate(glm::vec3 Axis)
{
	Rotate(Axis.x,1,0,0);
	Rotate(Axis.y,0,1,0);
	Rotate(Axis.z,0,0,1);
}
void GameObject::Rotate(float Angle, glm::vec3 Axis)
{
	Rotate(Angle, Axis.x, Axis.y, Axis.z);
}
void GameObject::Rotate(float R, float X, float Y, float Z)
{
	if(mesh != NULL)
	{
		mesh->Rotate(R, X, Y, Z);
	}
}
void GameObject::UpdateTransform()
{		
	glm::vec3 moveVector(transform.position.x, transform.position.y, transform.position.z);
	if (sprite != NULL)
	{
		sprite->Move(moveVector);
	}

	if(mesh != NULL)
	{
		mesh->Move(moveVector);
	}
}
