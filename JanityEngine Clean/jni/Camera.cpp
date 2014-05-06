#include <Camera.h>
#include <Debug.h>

using namespace Janity;

glm::mat4 Camera::_view        =	glm::mat4(0);
glm::mat4 Camera::_projection  =	glm::mat4(0);

glm::vec3 Camera::_position	 = glm::vec3(0);
glm::vec3 Camera::_lookAt    = glm::vec3(0);
glm::vec3 Camera::_axis		 = glm::vec3(0);

Camera::Camera()
{	
		_position =		glm::vec3(0,10,30);
		_lookAt =		glm::vec3(0,0,0);
		_axis =			glm::vec3(0,1,0);// Head is up (set to 0,-1,0 to look upside down);
}
Camera::Camera(glm::vec3 Position, glm::vec3 Origin, glm::vec3 Axis)
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
Camera* Camera::CreateCamera(glm::vec3 Position, glm::vec3 Origin, glm::vec3 Axis)
{
	return new Camera(Position, Origin, Axis);
}
void Camera::SetAxis(glm::vec3 Axis)
{
	_axis = Axis;
}
void Camera::LookAt(glm::vec3 Origin)
{
	_lookAt = Origin;
}
void Camera::Move(glm::vec3 Position)
{
	if(Position.x == _lookAt.x && Position.z == _lookAt.z)
		_position = glm::vec3(Position.x+0.1f,Position.y,Position.z);
	else
		_position = Position;
}
void Camera::Move(glm::vec3 Position, glm::vec3 Origin, glm::vec3 Axis)
{
	if(Position.x == Origin.x && Position.z == Origin.z)
	{
		Position.x += 1;
	}
	_position = Position;
	_lookAt = Origin;
	_axis = Axis;
}

glm::mat4 Camera::GetProjMat(float _fov, float _aspectRatio, float _near, float _far)
{
	_projection = glm::perspective(_fov, _aspectRatio, _near, _far);
	return _projection;
}
glm::mat4 Camera::GetViewMat()
{
	_view = glm::lookAt(_position, _lookAt, _axis);
	return _view;
}