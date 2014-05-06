/**
 * @file Vector2.cpp
 *
 * DevMath Mathematics Library for C++
 * Copyright 2012-2013 Eetu 'Devenec' Oinasmaa
 *
 * DevMath is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <devmath/Vector2.h>

#include <cassert>
#include <cmath>

#include <devmath/Matrix3.h>
#include <devmath/Matrix4.h>
#include <devmath/Quaternion.h>
#include <devmath/Utils.h>
#include <devmath/Vector3.h>
#include <devmath/Vector4.h>

using namespace devmath;
using namespace std;

Vector2::Vector2() { }

Vector2::Vector2(const float value)
	: x(value),
	  y(value) { }

Vector2::Vector2(const float x, const float y)
	: x(x),
	  y(y) { }

Vector2::Vector2(const Vector2& vector)
	: x(vector.x),
	  y(vector.y) { }

Vector2::~Vector2() { }


// Public

float Vector2::length() const
{
	const float _x = x * x;
	const float _y = y * y;

	return sqrt(_x + _y);
}

bool Vector2::isUnitVector() const
{
	return equals(length(), 1.0f);
}

float Vector2::distance(const Vector2& vector) const
{
	return (*this - vector).length();
}

float Vector2::dot(const Vector2& vector) const
{
	const float _x = x * vector.x;
	const float _y = y * vector.y;

	return _x + _y;
}

Vector2 Vector2::maximum(const Vector2& vector) const
{
	const float _x = devmath::maximum(x, vector.x);
	const float _y = devmath::maximum(y, vector.y);

	return Vector2(_x, _y);
}

Vector2 Vector2::minimum(const Vector2& vector) const
{
	const float _x = devmath::minimum(x, vector.x);
	const float _y = devmath::minimum(y, vector.y);
	
	return Vector2(_x, _y);
}

Vector2 Vector2::normal() const
{
	return *this / length();
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

// Static

Vector2 Vector2::zero()
{
	return Vector2(0.0f);
}

Vector2 Vector2::lerp(const Vector2& vectorA, const Vector2& vectorB, const float weight)
{
	assert(weight >= 0.0f && weight <= 1.0f);
	return (vectorB - vectorA) * weight + vectorA;
}

// Operators

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

namespace devmath
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
		vector = vector * scalar;
		return vector;
	}

	ostream& operator <<(ostream& output, const Vector2& vector)
	{
		output << "[X: " << vector.x << ", Y: " << vector.y << "]";
		return output;
	}
}