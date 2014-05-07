#include <Vector2.h>

#include <math.h>
#include <cassert>

#include <MathUtils.h>
#include <Vector3.h>
#include <Vector4.h>
#include <Matrix3.h>
#include <Matrix4.h>
#include <Quaternion.h>

using namespace JanityMath;

Vector2::Vector2() : x(0), y(0){}
Vector2::Vector2(const float X, const float Y) : x(X), y(Y){}
Vector2::Vector2(const float value) : x(value), y(value){}
Vector2::~Vector2(){}

float Vector2::magnitude() const
{
	return sqrt(x * x + y * y);
}

bool Vector2::isUnitVector() const
{
	return equals(magnitude(), 1.0f);
}

Vector3 Vector2::xyz()
{
	return Vector3(x,y,0);
}

float Vector2::distance(const Vector2& vector) const
{
	return (*this - vector).magnitude();
}

float Vector2::dot(const Vector2& vector) const
{
	const float _x = x * vector.x;
	const float _y = y * vector.y;
	return _x + _y;
}

Vector2 Vector2::normal()
{
	float length = magnitude();
	float _x = this->x;
	float _y = this->y;
	return Vector2(_x/magnitude(), _y/magnitude());
}

//static
Vector2 Vector2::zero()
{
	return Vector2(0.0f);
}

//Operators
Vector2& Vector2::operator =(const Vector2& rhs) 
{
	if(this!= &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}
	return *this;
}

Vector2& Vector2::operator +(const Vector2& rhs) const
{
	const float _x = x + rhs.x;
	const float _y = y + rhs.y;
	return Vector2(_x, _y);
}

Vector2& Vector2::operator +=(const Vector2& rhs) const
{
	return operator+(rhs);
}

Vector2& Vector2::operator -(const Vector2& rhs) const
{
	const float _x = x - rhs.x;
	const float _y = y - rhs.y;
	return Vector2(_x, _y);
}

Vector2& Vector2::operator -=(const Vector2& rhs) const
{
	return operator-(rhs);
}

Vector2& Vector2::operator /(const float divisor) const
{
	assert(!equals(divisor, 0.0f));

	const float _x = x / divisor;
	const float _y = y / divisor;

	return Vector2(_x, _y);
}
const Vector2& Vector2::operator /=(const float divisor)
{
	*this = *this / divisor;
	return *this;
}

float& Vector2::operator [](const uint index)
{
	assert(index < (uint)COMPONENTS);
	return (&x)[index];
}

const float& Vector2::operator [](const uint index) const
{
	assert(index < (uint)COMPONENTS);
	return (&x)[index];
}

namespace JanityMath
{
	Vector2 operator *(const Vector2& rhs, const float scalar)
	{
		const float _x = scalar * rhs.x;
		const float _y = scalar * rhs.y;

		return Vector2(_x, _y);
	}

	Vector2 operator *(const float scalar, const Vector2& rhs)
	{
		return rhs * scalar;
	}

	const Vector2& operator *=(Vector2& rhs, const float scalar)
	{
		return rhs * scalar;
	}

	std::ostream& operator <<(std::ostream& output, const Vector2& vector)
	{
		output << "[X: " << vector.x << ", Y: " << vector.y << "]";
		return output;
	}
}