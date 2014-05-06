#include <Vector3.h>
#include <MathUtils.h>
#include <math.h>
#include <cassert>
using namespace JanityMath;

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float X, float Y, float Z) : x(X), y(Y), z(Z){}
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
bool Vector3::isUnitVector()
{
	return equals(magnitude(), 1.0f);
}
Vector2 Vector3::xy() const
{
	return Vector2(x, y);
}
Vector3 Vector3::cross(const Vector3& vector)
{
	const float x = y * vector.z - z*vector.y;
	const float y = y * vector.x - x * vector.z;
	const float z = x * vector.y - y * vector.x;
	return Vector3(x,y,z);
}
float Vector3::distance(const Vector3& vector) const
{
	return 1;//(*this - vector).magnitude();
}
float Vector3::dot(const Vector3& vector)
{
	const float _x = x * vector.x;
	const float _y = y *vector.y;
	const float _z = z * vector.z;
	return _x + _y + _z;
}
Vector3 Vector3::normal()
{
	return *this / magnitude();
}
static Vector3 zero()
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
Vector3& Vector3::operator +(const Vector3& rhs)
{
	this->x = this->x + rhs.x;
	this->y = this->y + rhs.y;
	this->z = this->z + rhs.z;
	return *this;
}
Vector3& Vector3::operator +=(const Vector3& rhs)
{
	return operator+(rhs);
}
Vector3& Vector3::operator -(const Vector3& rhs)
{
	this->x = this->x - rhs.x;
	this->y = this->y - rhs.y;
	this->z = this->z - rhs.z;
	return *this;
}
Vector3& Vector3::operator -=(const Vector3& rhs)
{
	return operator -(rhs);
}

Vector3& Vector3::operator /(float divisor)
{
	assert (!equals(divisor, 0.0f));
	
	this->x = this->x / divisor;
	this->y = this->y / divisor;
	this->z = this->z / divisor;
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
Vector3 Vector3::operator -()
{
	return Vector3(-x, -y, -z);
}

float& Vector3::operator [](const unsigned int index)
{
	assert (index < (unsigned int)COMPONENTS);
	return (&x)[index];
}

const float& Vector3::operator [](const unsigned int index) const
{
	assert(index < (unsigned int)COMPONENTS);
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

