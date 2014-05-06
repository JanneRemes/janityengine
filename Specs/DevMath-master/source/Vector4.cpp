/**
 * @file Vector4.cpp
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

#include <devmath/Vector4.h>

#include <cassert>
#include <cmath>

#include <devmath/Quaternion.h>
#include <devmath/Utils.h>

using namespace devmath;
using namespace std;

Vector4::Vector4() { }

Vector4::Vector4(const float value)
	: x(value),
	  y(value),
	  z(value),
	  w(value) { }

Vector4::Vector4(const float x, const float y, const float z, const float w)
	: x(x),
	  y(y),
	  z(z),
	  w(w) { }

Vector4::Vector4(const Vector2& vector, const float z, const float w)
	: x(vector.x),
	  y(vector.y),
	  z(z),
	  w(w) { }

Vector4::Vector4(const Vector3& vector, const float w)
	: x(vector.x),
	  y(vector.y),
	  z(vector.z),
	  w(w) { }

Vector4::Vector4(const Vector4& vector)
	: x(vector.x),
	  y(vector.y),
	  z(vector.z),
	  w(vector.w) { }

Vector4::~Vector4() { }


// Public

float Vector4::length() const
{
	const float _x = x * x;
	const float _y = y * y;
	const float _z = z * z;
	const float _w = w * w;

	return sqrt(_x + _y + _z + _w);
}

Vector2 Vector4::xy() const
{
	return Vector2(x, y);
}

Vector3 Vector4::xyz() const
{
	return Vector3(x, y, z);
}

bool Vector4::isUnitVector() const
{
	return equals(length(), 1.0f);
}

float Vector4::distance(const Vector4& vector) const
{
	return (*this - vector).length();
}

float Vector4::dot(const Vector4& vector) const
{
	const float _x = x * vector.x;
	const float _y = y * vector.y;
	const float _z = z * vector.z;
	const float _w = w * vector.w;

	return _x + _y + _z + _w;
}

Vector4 Vector4::maximum(const Vector4& vector) const
{
	const float _x = devmath::maximum(x, vector.x);
	const float _y = devmath::maximum(y, vector.y);
	const float _z = devmath::maximum(z, vector.z);
	const float _w = devmath::maximum(w, vector.w);

	return Vector4(_x, _y, _z, _w);
}

Vector4 Vector4::minimum(const Vector4& vector) const
{
	const float _x = devmath::minimum(x, vector.x);
	const float _y = devmath::minimum(y, vector.y);
	const float _z = devmath::minimum(z, vector.z);
	const float _w = devmath::minimum(w, vector.w);

	return Vector4(_x, _y, _z, _w);
}

Vector4 Vector4::normal() const
{
	return *this / length();
}

Vector4 Vector4::transform(const Quaternion& quaternion) const
{
	const Vector3 result = quaternion.rotate(xyz());
	return Vector4(result, w);
}

// Static

Vector4 Vector4::zero()
{
	return Vector4(0.0f);
}

Vector4 Vector4::lerp(const Vector4& vectorA, const Vector4& vectorB, const float weight)
{
	assert(weight >= 0.0f && weight <= 1.0f);
	return (vectorB - vectorA) * weight + vectorA;
}

// Operators

Vector4 Vector4::operator +(const Vector4& vector) const
{
	const float _x = x + vector.x;
	const float _y = y + vector.y;
	const float _z = z + vector.z;
	const float _w = w + vector.w;

	return Vector4(_x, _y, _z, _w);
}

Vector4 Vector4::operator -(const Vector4& vector) const
{
	const float _x = x - vector.x;
	const float _y = y - vector.y;
	const float _z = z - vector.z;
	const float _w = w - vector.w;

	return Vector4(_x, _y, _z, _w);
}

Vector4& Vector4::operator =(const Vector4& vector)
{
	if(this != &vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
	}

	return *this;
}

const Vector4& Vector4::operator +=(const Vector4& vector)
{
	*this = *this + vector;
	return *this;
}

const Vector4& Vector4::operator -=(const Vector4& vector)
{
	*this = *this - vector;
	return *this;
}

bool Vector4::operator ==(const Vector4& vector) const
{
	return equals(x, vector.x) && equals(y, vector.y) && equals(z, vector.z) && equals(w, vector.w);
}

bool Vector4::operator !=(const Vector4& vector) const
{
	return !(*this == vector);
}

Vector4 Vector4::operator -() const
{
	return Vector4(-x, -y, -z, -w);
}

Vector4 Vector4::operator /(const float scalar) const
{
	assert(!equals(scalar, 0.0f));

	const float _x = x / scalar;
	const float _y = y / scalar;
	const float _z = z / scalar;
	const float _w = w / scalar;

	return Vector4(_x, _y, _z, _w);
}

const Vector4& Vector4::operator /=(const float scalar)
{
	*this = *this / scalar;
	return *this;
}

float& Vector4::operator [](const unsigned int index)
{
	assert(index < (unsigned int)COMPONENTS);
	return (&x)[index];
}

const float& Vector4::operator [](const unsigned int index) const
{
	assert(index < (unsigned int)COMPONENTS);
	return (&x)[index];
}

// Friends

namespace devmath
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
		vector = vector * scalar;
		return vector;
	}

	ostream& operator <<(ostream& output, const Vector4& vector)
	{
		output << "[X: " << vector.x << ", Y: " << vector.y << ", Z: " << vector.z << ", W: " << vector.w << "]";
		return output;
	}
}