#include <Camera.h>
#include <Debug.h>

using namespace JanityEngine;

Camera* Camera::_mainCamera;
/*Matrix4 Camera::_view;       //= Matrix4::identity();
Matrix4 Camera::_projection; //= Matrix4::identity();

Vector3 Camera::_position;   //= Vector3::zero();
Vector3 Camera::_lookAt;     //= Vector3::zero();
Vector3 Camera::_axis;		 //= Vector3::zero();*/

Camera::Camera()
{	
		_position =		Vector3(0,10,30);
		_lookAt =		Vector3(0,0,0);
		_axis =			Vector3(0,1,0);// Head is up (set to 0,-1,0 to look upside down);
}
Camera::Camera(Vector3 Position, Vector3 Origin, Vector3 Axis)
{
	_position = Position;
	_lookAt = Origin;
	_axis = Axis;
}
Camera::~Camera()
{
	delete &_view;
	delete &_projection;
	delete &_position;
	delete &_lookAt;
	delete &_axis;
}

// PUBLIC
Camera* Camera::MainCamera()
{
	if(_mainCamera == NULL)
		_mainCamera = new Camera();

	return _mainCamera;
}
void Camera::SetAxis(Vector3 Axis)
{
	_axis = Axis;
}
void Camera::LookAt(Vector3 Origin)
{
	_lookAt = Origin;
}
void Camera::Move(Vector3 Position)
{
	if(Position.x == _lookAt.x && Position.z == _lookAt.z)
		_position = Vector3(Position.x+0.1f,Position.y,Position.z);
	else
		_position = Position;
}
void Camera::Move(Vector3 Position, Vector3 Origin, Vector3 Axis)
{
	if(Position.x == Origin.x && Position.z == Origin.z)
	{
		Position.x += 1;
	}
	_position = Position;
	_lookAt = Origin;
	_axis = Axis;
}

Matrix4 Camera::GetProjMat(float _fov, float _aspectRatio, float _near, float _far)
{
	_projection = createPerspectiveProjection(_fov, _aspectRatio, _near, _far);
	return _projection;
}
Matrix4 Camera::GetViewMat()
{
	_view = lookAt(_position, _lookAt, _axis);
	return _view;
}