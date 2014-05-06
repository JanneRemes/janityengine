/**
 * @file Vector3.cpp
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

#include <devmath/Vector3.h>

#include <cassert>
#include <cmath>

#include <devmath/Matrix4.h>
#include <devmath/Quaternion.h>
#include <devmath/Utils.h>
#include <devmath/Vector4.h>

using namespace devmath;
using namespace std;

Vector3::Vector3() { }

Vector3::Vector3(const float value)
	: x(value),
	  y(value),
	  z(value) { }

Vector3::Vector3(const float x, const float y, const float z)
	: x(x),
	  y(y),
	  z(z) { }

Vector3::Vector3(const Vector2& vector, const float z)
	: x(vector.x),
	  y(vector.y),
	  z(z) { }

Vector3::Vector3(const Vector3& vector)
	: x(vector.x),
	  y(vector.y),
	  z(vector.z) { }

Vector3::~Vector3() { }


// Public

float Vector3::length() const
{
	const float _x = x * x;
	const float _y = y * y;
	const float _z = z * z;

	return sqrt(_x + _y + _z);
}

Vector2 Vector3::xy() const
{
	return Vector2(x, y);
}

bool Vector3::isUnitVector() const
{
	return equals(length(), 1.0f);
}

Vector3 Vector3::cross(const Vector3& vector) const
{
	const float _x = y * vector.z - z * vector.y;
	const float _y = z * vector.x - x * vector.z;
	const float _z = x * vector.y - y * vector.x;

	return Vector3(_x, _y, _z);
}

float Vector3::distance(const Vector3& vector) const
{
	return (*this - vector).length();
}

float Vector3::dot(const Vector3& vector) const
{
	const float _x = x * vector.x;
	const float _y = y * vector.y;
	const float _z = z * vector.z;

	return _x + _y + _z;
}

Vector3 Vector3::maximum(const Vector3& vector) const
{
	const float _x = devmath::maximum(x, vector.x);
	const float _y = devmath::maximum(y, vector.y);
	const float _z = devmath::maximum(z, vector.z);
	
	return Vector3(_x, _y, _z);
}

Vector3 Vector3::minimum(const Vector3& vector) const
{
	const float _x = devmath::minimum(x, vector.x);
	const float _y = devmath::minimum(y, vector.y);
	const float _z = devmath::minimum(z, vector.z);
	
	return Vector3(_x, _y, _z);
}

Vector3 Vector3::normal() const
{
	return *this / length();
}

Vector3 Vector3::transform(const Matrix4& transform) const
{
	const Vector4 vector = transform * Vector4(*this, 1.0f);
	return vector.xyz();
}

Vector3 Vector3::transform(const Quaternion& quaternion) const
{
	return quaternion.rotate(*this);
}

// Static

Vector3 Vector3::zero()
{
	return Vector3(0.0f);
}

Vector3 Vector3::lerp(const Vector3& vectA, const Vector3& vectB, const float weight)
{
	assert(weight >= 0.0f && weight <= 1.0f);
	return (vectB - vectA) * weight + vectA;
}

// Operators

Vector3 Vector3::operator +(const Vector3& vector) const
{
	const float _x = x + vector.x;
	const float _y = y + vector.y;
	const float _z = z + vector.z;

	return Vector3(_x, _y, _z);
}

Vector3 Vector3::operator -(const Vector3& vector) const
{
	const float _x = x - vector.x;
	const float _y = y - vector.y;
	const float _z = z - vector.z;

	return Vector3(_x, _y, _z);
}

Vector3& Vector3::operator =(const Vector3& vector)
{
	if(this != &vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}

	return *this;
}

const Vector3& Vector3::operator +=(const Vector3& vector)
{
	*this = *this + vector;
	return *this;
}

const Vector3& Vector3::operator -=(const Vector3& vector)
{
	*this = *this - vector;
	return *this;
}

bool Vector3::operator ==(const Vector3& vector) const
{
	return equals(x, vector.x) && equals(y, vector.y) && equals(z, vector.z);
}

bool Vector3::operator !=(const Vector3& vector) const
{
	return !(*this == vector);
}

Vector3 Vector3::operator -() const
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator /(const float scalar) const
{
	assert(!equals(scalar, 0.0f));

	const float _x = x / scalar;
	const float _y = y / scalar;
	const float _z = z / scalar;

	return Vector3(_x, _y, _z);
}

const Vector3& Vector3::operator /=(const float scalar)
{
	*this = *this / scalar;
	return *this;
}

float& Vector3::operator [](const unsigned int index)
{
	assert(index < (unsigned int)COMPONENTS);
	return (&x)[index];
}

const float& Vector3::operator [](const unsigned int index) const
{
	assert(index < (unsigned int)COMPONENTS);
	return (&x)[index];
}

// Friends

namespace devmath
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
		vector = vector * scalar;
		return vector;
	}

	ostream& operator <<(ostream& output, const Vector3& vector)
	{
		output << "[X: " << vector.x << ", Y: " << vector.y << ", Z: " << vector.z << "]";
		return output;
	}
}