#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <Texture.h>
#include <Sprite.h>
#include <Object.h>
#include <glm\glm.hpp>
#include <Mesh.h>

namespace JanityEngine
{
    struct Transform
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
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
	public:
		GameObject(); //empty gameObject
		//Mesh
		GameObject(Mesh* Mesh);
		GameObject(Mesh* Mesh, glm::vec3 Position);
		GameObject(Mesh* Mesh, glm::vec3 Position, float Angle, glm::vec3 Axis);
		GameObject(Mesh* Mesh, glm::vec3 Position, float Angle, glm::vec3 Axis, glm::vec3 Scalar);
		GameObject(Mesh* Mesh, Transform Transform);

		//Sprite
		GameObject(Texture* _texture);
		GameObject(Texture* _texture, glm::vec2 _position);
		GameObject(Texture* _texture, glm::vec2 _position, float _rotation);
		GameObject(Texture* _texture, glm::vec2 _position, float _rotation, float Scalar);
		GameObject(Texture* _texture, glm::vec2 _position, float _rotation, glm::vec2 Scale);

		GameObject(Texture* _texture, glm::vec3 Position);
		GameObject(Texture* _texture, glm::vec3 Position, float Rotation, float Scalar);
		GameObject(Texture* _texture, glm::vec3 Position, float Rotation, glm::vec3 Scale);
		GameObject(Texture* _texture, Transform Transform);

		~GameObject();

		GameObject(const GameObject& gameObject);
		GameObject Instantiate(const GameObject &prefab);
		GameObject Instantiate(const GameObject &prefab, glm::vec2 Position);
		GameObject Instantiate(const GameObject &prefab, glm::vec3 Position);

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
		void Translate(glm::vec2 Vector2);
		void Translate(glm::vec3 Vector3);
		void Translate(float X, float Y = 0, float Z = 0);
		void Scale(glm::vec3 Scalar);
		void Scale(glm::vec2 Scalar);
		void Scale(float X, float Y = 0, float Z = 0);

		void Rotate(float Z);
		void Rotate(glm::vec3 Axis);
		void Rotate(float Angle, glm::vec3 Axis);
		void Rotate(float r, float X, float Y, float Z);
		void UpdateTransform();
	
	private:


	};
}
	  

#endif