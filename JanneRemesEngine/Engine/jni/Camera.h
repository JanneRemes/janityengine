#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <JanityMath\JanityMath.h>

using namespace JanityMath;


namespace JanityEngine
{
	class Camera
	{
	
	public:
		static Camera* _mainCamera;
		static Camera* MainCamera();

		Vector3 _position;
		Vector3 _lookAt;

		Camera();
		Camera(Vector3 Position, Vector3 Origin, Vector3 Axis);
		~Camera();
		
		void SetAxis(Vector3 Axis);
		void LookAt(Vector3 Origin);
		void Move(Vector3 Position);
		void Move(Vector3 Position, Vector3 Origin, Vector3 Axis);

		Matrix4 GetViewMat();
		Matrix4 GetProjMat(float fov, float _aspectRatio, float _near, float _far);

	private:
		Matrix4 _view;
		Matrix4 _projection;
		Vector3 _axis;


		Camera(const Camera&);
		Camera& operator = (const Camera&);
	};
}
#endif