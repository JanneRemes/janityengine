#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <Texture.h>
#include <Sprite.h>
#include <Object.h>
#include <Mesh.h>
#include <JanityMath\JanityMath.h>

using namespace JanityMath;

namespace JanityEngine
{
	struct pos
	{
		float x,y,z;
	};
    struct Transform
	{
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;
	}; 

	extern struct Transform;

	extern enum Components;
	enum Components
	{
		AnimationTrackComponent, CameraComponent,LightComponent, MaterialComponent, MeshComponent,SpriteComponent
	};

	class Sprite;
	class GameObject : Object
	{
	//public:
		GameObject(); //empty gameObject
		//Mesh
		GameObject(Mesh* Mesh);
		GameObject(Mesh* Mesh, Vector3 Position);
		GameObject(Mesh* Mesh, Vector3 Position, float Angle, Vector3 Axis);
		GameObject(Mesh* Mesh, Vector3 Position, float Angle, Vector3 Axis, Vector3 Scalar);
		GameObject(Mesh* Mesh, Transform Transform);

		//Sprite
		GameObject(Texture* _texture);

		GameObject(Texture* _texture, Vector2 _position);
		GameObject(Texture* _texture, Vector2 _position, float _rotation);
		GameObject(Texture* _texture, Vector2 _position, float _rotation, float Scalar);
		GameObject(Texture* _texture, Vector2 _position, float _rotation, Vector2 Scale);

		GameObject(Texture* _texture, Vector3 Position);
		GameObject(Texture* _texture, Vector3 Position, float Rotation);
		GameObject(Texture* _texture, Vector3 Position, float Rotation, float Scalar);
		GameObject(Texture* _texture, Vector3 Position, float Rotation, Vector3 Scale);
		GameObject(Texture* _texture, Transform Transform);

		~GameObject();

		GameObject(const GameObject& gameObject);
		GameObject Instantiate(const GameObject &prefab);
		GameObject Instantiate(const GameObject &prefab, Vector2 Position);
		GameObject Instantiate(const GameObject &prefab, Vector3 Position);

		void Destroy();
		void PrintInfo();
		void ResetTransform();
		void Draw();	

		Mesh* mesh;
		Sprite* sprite;
		Transform transform;
		std::string tag;
		
		void SetProjection(float desiredWidth, float desiredHeight);
		void SetProgram(GLuint program);
		void SetTexture(const char* texturePath);
		void SetTexture(Texture* Texture);
		void AddComponent(Components);
		void AddComponent(Components, Texture*);
		bool HasComponent(Components);
		void* GetComponent(Components);
		void RemoveComponent(Components);
		void Translate(const Vector2 vector2);
		void Translate(const Vector3 vector3);
		void Translate(float X, float Y = 0, float Z = 0);
		void Scale(Vector3 Scalar);
		void Scale(Vector2 Scalar);
		void Scale(float X, float Y = 0, float Z = 0);

		void Rotate(float Z);
		void Rotate(Vector3 Axis);
		void Rotate(float Angle, Vector3 Axis);
		void Rotate(float r, float X, float Y, float Z);
		void UpdateTransform();
	
	private:
	

	};
}
	  

#endif