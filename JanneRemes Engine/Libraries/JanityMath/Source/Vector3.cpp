#include <JanityMath\Vector3.h>
#include <math.h>
#include <cassert>

#include <JanityMath\Matrix4.h>
#include <JanityMath\Quaternion.h>
#include <JanityMath\MathUtils.h>
#include <JanityMath\Vector4.h>
using namespace JanityMath;

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float value) : x(value), y(value), z(value){}
Vector3::Vector3(float X, float Y, float Z) : x(X), y(Y), z(Z){}
Vector3::Vector3(const Vector2& vector, const float z)
	: x(vector.x),
	  y(vector.y),
	  z(z) { }
Vector3::Vector3(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}
Vector3::~Vector3(){}

float Vector3::magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}
bool Vector3::isUnitVector() const
{
	return equals(magnitude(), 1.0f);
}
Vector2 Vector3::xy() const
{
	return Vector2(x, y);
}
Vector3 Vector3::cross(const Vector3& rhs) const
{
	const float _x = y * rhs.z - z*rhs.y;
	const float _y = y * rhs.x - x * rhs.z;
	const float _z = x * rhs.y - y * rhs.x;
	return Vector3(_x,_y,_z);
}
float Vector3::distance(const Vector3& rhs) const
{
	return 1;//(*this - vector).magnitude();
}
float Vector3::dot(const Vector3& rhs) const
{
	const float _x = x * rhs.x;
	const float _y = y *rhs.y;
	const float _z = z * rhs.z;
	return _x + _y + _z;
}
Vector3 Vector3::normal()
{
	return *this / magnitude();
}

Vector3 Vector3::transform(const Matrix4& transform) const
{
	const Vector4 vector = transform * Vector4(*this, 1.0f);
	return vector.xyz();
}

Vector3  Vector3::transform(const Quaternion& quaternion) const
{
	return quaternion.rotate(*this);
}

Vector3 Vector3::zero()
{
	return Vector3(0,0,0);
}

Vector3& Vector3::operator =(const Vector3& rhs)
{
	if(this == &rhs)
	{
		return *this;
	}
	else
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		return *this;
	}
}
Vector3 Vector3::operator +(const Vector3& rhs) const
{
	const float _x = this->x + rhs.x;
	const float _y = this->y + rhs.y;
	const float _z = this->z + rhs.z;
	return Vector3(_x, _y, _z);
}
Vector3& Vector3::operator +=(const Vector3& rhs)
{
	return operator+(rhs);
}
Vector3 Vector3::operator -(const Vector3& rhs) const
{
	const float _x = this->x - rhs.x;
	const float _y = this->y - rhs.y;
	const float _z = this->z - rhs.z;
	return *this;
}
Vector3& Vector3::operator -=(const Vector3& rhs)
{
	return operator -(rhs);
}

Vector3 Vector3::operator /(float divisor) const
{
	assert (!equals(divisor, 0.0f));
	
	const float _x = this->x / divisor;
	const float _y = this->y / divisor;
	const float _z = this->z / divisor;
	return *this;
}
Vector3& Vector3::operator /=(float divisor)
{
	return operator /(divisor);
}

bool Vector3::operator ==(const Vector3& rhs) const
{
	if(this->x == rhs.x && this->y == rhs.y && this->z == rhs.z)
		return true;
	else
		return false;
}
bool Vector3::operator !=(const Vector3& rhs) const
{
	return !(*this == rhs);
}
Vector3 Vector3::operator -() const
{
	return Vector3(-x, -y, -z);
}

float& Vector3::operator [](const uint index)
{
	assert (index < (uint)COMPONENTS);
	return (&x)[index];
}

const float& Vector3::operator [](const uint index) const
{
	assert(index < (uint)COMPONENTS);
	return (&x)[index];
}

// Friends
namespace JanityMath
{
	Vector3 operator *(const Vector3& vector, const float scalar)
	{
		const float _x = scalar * vector.x;
		const float _y = scalar * vector.y;
		const float _z = scalar * vector.z;

		return Vector3(_x, _y, _z);
	}

	Vector3 operator *(const float scalar, const Vector3& vector)
	{
		return vector * scalar;
	}

	const Vector3& operator *=(Vector3& vector, const float scalar)
	{
		Vector3 result;
		result = vector * scalar;
		return result;
	}

	std::ostream& operator <<(std::ostream& output, const Vector3& vector)
	{
		output << "[X: " << vector.x << ", Y: " << vector.y << ", Z: " << vector.z << "]";
		return output;
	}
	
	
}

