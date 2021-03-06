#include <JanityMath\Vector2.h>

#include <math.h>
#include <cassert>

#include <JanityMath\MathUtils.h>
#include <JanityMath\Vector3.h>
#include <JanityMath\Vector4.h>
#include <JanityMath\Matrix3.h>
#include <JanityMath\Matrix4.h>
#include <JanityMath\Quaternion.h>

using namespace JanityMath;

Vector2::Vector2() : x(0), y(0){}
Vector2::Vector2(const float X, const float Y) : x(X), y(Y){}
Vector2::Vector2(const float value) : x(value), y(value){}
Vector2::Vector2(const Vector2& other)
{
	x = other.x;
	y = other.y;
}
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

Vector2 Vector2::transform(const Matrix3& transform) const
{
	const Vector3 result = transform * Vector3(*this, 1.0f);
	return result.xy();
}

Vector2 Vector2::transform(const Matrix4& transform) const
{
	const Vector4 result = transform * Vector4(*this, 0.0f, 1.0f);
	return result.xy();
}

Vector2 Vector2::transform(const Quaternion& quaternion) const
{
	const Vector3 vector(*this, 0.0f);
	const Vector3 result = quaternion.rotate(vector);

	return result.xy();
}

//static
Vector2 Vector2::zero()
{
	return Vector2(0.0f);
}


Vector2 Vector2::up()
{
	return Vector2(0,1);
}
Vector2 Vector2::down()
{
	return Vector2(0,-1);
}
Vector2 Vector2::left()
{
	return Vector2(-1,0);
}
Vector2 Vector2::right()
{
	return Vector2(1,0);
}

//Operators
Vector2 Vector2::operator +(const Vector2& vector) const
{
	const float _x = x + vector.x;
	const float _y = y + vector.y;

	return Vector2(_x, _y);
}

Vector2 Vector2::operator -(const Vector2& vector) const
{
	const float _x = x - vector.x;
	const float _y = y - vector.y;

	return Vector2(_x, _y);
}

Vector2& Vector2::operator =(const Vector2& vector)
{
	if(this != &vector)
	{
		x = vector.x;
		y = vector.y;
	}

	return *this;
}

const Vector2& Vector2::operator +=(const Vector2& vector)
{
	*this = *this + vector;
	return *this;
}

const Vector2& Vector2::operator -=(const Vector2& vector)
{
	*this = *this - vector;
	return *this;
}

bool Vector2::operator ==(const Vector2& vector) const
{
	return equals(x, vector.x) && equals(y, vector.y);
}

bool Vector2::operator !=(const Vector2& vector) const
{
	return !(*this == vector);
}

Vector2 Vector2::operator -() const
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator /(const float scalar) const
{
	assert(!equals(scalar, 0.0f));

	const float _x = x / scalar;
	const float _y = y / scalar;

	return Vector2(_x, _y);
}

const Vector2& Vector2::operator /=(const float scalar)
{
	*this = *this / scalar;
	return *this;
}

float& Vector2::operator [](const unsigned int index)
{
	assert(index < (unsigned int)COMPONENTS);
	return (&x)[index];
}

const float& Vector2::operator [](const unsigned int index) const
{
	assert(index < (unsigned int)COMPONENTS);
	return (&x)[index];
}

// Friends

namespace JanityMath
{
	Vector2 operator *(const Vector2& vector, const float scalar)
	{
		const float _x = scalar * vector.x;
		const float _y = scalar * vector.y;
		

		return Vector2(_x, _y);
	}

	Vector2 operator *(const float scalar, const Vector2& vector)
	{
		return vector * scalar;
	}

	const Vector2& operator *=(Vector2& vector, const float scalar)
	{
		Vector2 result;
		result = vector * scalar;
		return result;
	}
	std::ostream& operator <<(std::ostream& output, const Vector2& vector)
	{
		output << "[X: " << vector.x << ", Y: " << vector.y << "]";
		return output;
	}
}