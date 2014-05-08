#include <Vector4.h>

#include <cassert>
#include <cmath>

#include <Quaternion.h>
#include <MathUtils.h>
using namespace JanityMath;

Vector4::Vector4() : x(0), y(0), z(0), w(0) { }

Vector4::Vector4(const float value) : x(value), y(value), z(value), w(value){}

Vector4::Vector4(const float X, const float Y, const float Z, const float W)
	: x(X),
	  y(Y),
	  z(Z),
	  w(W) { }

Vector4::Vector4(const Vector2& vector, const float Z, const float W) 
	: x(vector.x), 
	  y(vector.y),
	  z(Z),
	  w(W) { }

Vector4::Vector4(const Vector3& vector, const float W)
	: x(vector.x),
	  y(vector.y),
	  z(vector.z),
	  w(W) { }

Vector4::Vector4(const Vector4& vector) 
	: x(vector.x),
	  y(vector.y),
	  z(vector.z),
	  w(vector.w) { }

Vector4::~Vector4(){}

float Vector4::magnitude() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

bool Vector4::isUnitVector() const
{
	return equals(magnitude(), 1.0f);
}

Vector2 Vector4::xy() const
{
	return Vector2(x, y);
}
Vector3 Vector4::xyz() const
{
	return Vector3(x, y, z);
}
float Vector4::distance(const Vector4& rhs) const
{
	return(*this - rhs).magnitude();
}

float Vector4::dot(const Vector4& rhs)
{
	const float _x = x * rhs.x;
	const float _y = y * rhs.y;
	const float _z = z * rhs.w;
	const float _w = w * rhs.w;

	return _x + _y + _z + _w;
}

Vector4 Vector4::normal()
{
	return *this / magnitude();
}

Vector4 Vector4::transform(const Quaternion& quaternion) const
{
	const Vector3 result = quaternion.rotate(xyz());
	return Vector4(result, w);
}

// static
Vector4 Vector4::zero()
{
	return Vector4(0,0,0,0);
}

Vector4& Vector4::operator =(const Vector4& rhs)
{
	if(this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
	}
	return *this;
}
Vector4 Vector4::operator +(const Vector4& rhs) const
{
	const float _x = this->x + rhs.x;
	const float _y = this->x + rhs.y;
	const float _z = this->x + rhs.z;
	const float _w = this->x + rhs.w;
	return Vector4(_x, _y, _z, _w);
}

Vector4& Vector4::operator +=(const Vector4& rhs)
{
	return operator+(rhs);
}

Vector4 Vector4::operator -(const Vector4& rhs) const
{
	const float _x = this->x - rhs.x;
	const float _y = this->x - rhs.y;
	const float _z = this->x - rhs.z;
	const float _w = this->x - rhs.w;
	return Vector4(_x, _y, _z, _w);
}
Vector4& Vector4::operator -=(const Vector4& rhs)
{
	return operator-(rhs);
}

Vector4 Vector4::operator /(float divisor) const
{
	assert(!equals(divisor, 0.0f));

	const float _x = this->x / divisor;
	const float _y = this->x / divisor;
	const float _z = this->x / divisor;
	const float _w = this->x / divisor;
	return Vector4(_x, _y, _z, _w); 
}
Vector4& Vector4::operator /=(float divisor)
{
	return operator /(divisor);
}

Vector4 Vector4::operator -()
{
	return Vector4(-x,-y,-z,-w);
}

float& Vector4::operator [](const uint index)
{
	assert (index < (uint)COMPONENTS);
	return (&x)[index];
}

const float& Vector4::operator [](const uint index) const
{
	assert (index < (uint)COMPONENTS);
	return (&x)[index];
}

bool Vector4::operator ==(const Vector4& rhs) const
{
	if(this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w)
		return true;
	else
		return false;
}
bool Vector4::operator !=(const Vector4& rhs) const
{
	return !(*this == rhs);
}

//Friends
namespace JanityMath
{
	Vector4 operator *(const Vector4& vector, const float scalar)
	{
		const float _x = scalar * vector.x;
		const float _y = scalar * vector.y;
		const float _z = scalar * vector.z;
		const float _w = scalar * vector.w;
		return Vector4(_x, _y, _z, _w);
	}
	Vector4 operator *(const float scalar, const Vector4& vector)
	{
		return vector * scalar;
	}
	const Vector4& operator *=(Vector4& vector, const float scalar)
	{
		Vector4 result;
		result = vector * scalar;
		return result;
	}

	std::ostream& operator <<(std::ostream& output, const Vector4& vector)
	{
		output << "[X: " << vector.x << ", Y: " << vector.y << ", Z: " << vector.z << ", W: " << vector.w <<"]";
		return output;
	}
}