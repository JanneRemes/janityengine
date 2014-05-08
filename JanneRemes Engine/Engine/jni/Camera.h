#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <glm\glm.hpp>
#include <glm\ext.hpp>
//#include <glm\gtc\matrix_transform.hpp>

namespace KaMo
{
	class Camera
	{
		static glm::mat4 _view;
		static glm::mat4 _projection;
		static glm::vec3 _axis;


		Camera(const Camera&);
		Camera& operator = (const Camera&);
	public:
		static glm::vec3 _position;
		static glm::vec3 _lookAt;

		Camera();
		Camera(glm::vec3 Position, glm::vec3 Origin, glm::vec3 Axis);
		~Camera();

		static Camera* CreateCamera(glm::vec3 Position, glm::vec3 Origin, glm::vec3 Axis);
		
		static void SetAxis(glm::vec3 Axis);
		static void LookAt(glm::vec3 Origin);
		static void Move(glm::vec3 Position);
		static void Move(glm::vec3 Position, glm::vec3 Origin, glm::vec3 Axis);

		static glm::mat4 GetViewMat();
		static glm::mat4 GetProjMat(float fov, float _aspectRatio, float _near, float _far);
	};
}
#endif