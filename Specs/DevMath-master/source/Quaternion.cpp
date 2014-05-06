/**
 * @file Quaternion.cpp
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

#include <devmath/Quaternion.h>

#include <cassert>
#include <cfloat>
#include <cmath>

#include <devmath/Matrix3.h>
#include <devmath/Matrix4.h>
#include <devmath/Utils.h>

using namespace devmath;
using namespace std;

Quaternion::Quaternion() { }

Quaternion::Quaternion(const float w, const float x, const float y, const float z)
	: w(w),
	  vector(x, y, z) { }

Quaternion::Quaternion(const float w, const Vector3& vector)
	: w(w),
	  vector(vector) { }

Quaternion::Quaternion(const Matrix4& matrix)
{
	const float trace = matrix[0][0] + matrix[1][1] + matrix[2][2];
	float factor = 0.0f;

	if(trace > 0.0f)
	{
		factor = 0.5f / sqrt(trace + 1.0f);

		w = 0.25f / factor;
		vector.x = factor * (matrix[1][2] - matrix[2][1]);
		vector.y = factor * (matrix[2][0] - matrix[0][2]);
		vector.z = factor * (matrix[0][1] - matrix[1][0]);
	}
	else if(matrix[0][0] > matrix[1][1] && matrix[0][0] > matrix[2][2])
	{
		factor = 2.0f * sqrt(matrix[0][0] - matrix[1][1] - matrix[2][2] + 1.0f);

		w = (matrix[1][2] - matrix[2][1]) / factor;
		vector.x = 0.25f * factor;
		vector.y = (matrix[1][0] + matrix[0][1]) / factor;
		vector.z = (matrix[2][0] + matrix[0][2]) / factor;
	}
	else if(matrix[1][1] > matrix[2][2])
	{
		factor = 2.0f * sqrt(matrix[1][1] - matrix[0][0] - matrix[2][2] + 1.0f);

		w = (matrix[2][0] - matrix[0][2]) / factor;
		vector.x = (matrix[1][0] + matrix[0][1]) / factor;
		vector.y = 0.25f * factor;
		vector.z = (matrix[2][1] + matrix[1][2]) / factor;
	}
	else
	{
		factor = 2.0f * sqrt(matrix[2][2] - matrix[0][0] - matrix[1][1] + 1.0f);

		w = (matrix[0][1] - matrix[1][0]) / factor;
		vector.x = (matrix[2][0] + matrix[0][2]) / factor;
		vector.y = (matrix[2][1] + matrix[1][2]) / factor;
		vector.z = 0.25f * factor;
	}
}

Quaternion::Quaternion(const Quaternion& quaternion)
	: w(quaternion.w),
	  vector(quaternion.vector) { }

Quaternion::~Quaternion() { }


// Public

float Quaternion::length() const
{
	const float vectorDot = vector.dot(vector);
	return sqrt(w * w + vectorDot);
}

bool Quaternion::isUnitQuaternion() const
{
	return equals(length(), 1.0f);
}

Quaternion Quaternion::conjugate() const
{
	return Quaternion(w, -vector);
}

float Quaternion::dot(const Quaternion& quaternion) const
{
	const float _w = w * quaternion.w;
	const float _vector = vector.dot(quaternion.vector);

	return _w + _vector;
}

Quaternion Quaternion::inverse() const
{
	const float len = length();
	return conjugate() / (len * len);
}

Quaternion Quaternion::normal() const
{
	return *this / length();
}

Vector3 Quaternion::rotate(const Vector3& vector) const
{
	const Quaternion result = *this * Quaternion(0.0f, vector) * conjugate();
	return result.vector;
}

// Static

Quaternion Quaternion::identity()
{
	return Quaternion(1.0f, Vector3::zero());
}

Quaternion Quaternion::createRotationX(const float angle)
{
	const Vector3 axis(1.0f, 0.0f, 0.0f);
	return createRotationAxis(axis, angle);
}

Quaternion Quaternion::createRotationY(const float angle)
{
	const Vector3 axis(0.0f, 1.0f, 0.0f);
	return createRotationAxis(axis, angle);
}

Quaternion Quaternion::createRotationZ(const float angle)
{
	const Vector3 axis(0.0f, 0.0f, 1.0f);
	return createRotationAxis(axis, angle);
}

Quaternion Quaternion::createRotationAxis(const Vector3& axis, const float angle)
{
	assert(axis.isUnitVector());

	const float halfAngle = angle / 2.0f;
	const float _w = cos(halfAngle);
	const Vector3 _vector = axis * sin(halfAngle);

	return Quaternion(_w, _vector);
}

Quaternion Quaternion::slerp(const Quaternion& quaternionA, const Quaternion& quaternionB, const float weight)
{
	assert(weight >= 0.0f && weight <= 1.0f);

	const float dot = quaternionA.dot(quaternionB);
	const float angle = acos(clamp(dot, -1.0f, 1.0f));
	const float sinAngle = sin(angle);

	if(sinAngle < FLT_MIN)
		return quaternionA;
	else
	{
		const float a = sin((1.0f - weight) * angle) / sinAngle;
		const float b = sin(weight * angle) / sinAngle;

		return a * quaternionA + b * quaternionB;
	}
}

// Operators

Quaternion Quaternion::operator +(const Quaternion& quaternion) const
{
	const float _w = w + quaternion.w;
	const Vector3 _vector = vector + quaternion.vector;

	return Quaternion(_w, _vector);
}

Quaternion Quaternion::operator -(const Quaternion& quaternion) const
{
	const float _w = w - quaternion.w;
	const Vector3 _vector = vector - quaternion.vector;

	return Quaternion(_w, _vector);
}

Quaternion Quaternion::operator *(const Quaternion& quaternion) const
{
	const float _w = w * quaternion.w - vector.dot(quaternion.vector);
	const Vector3 _vector = w * quaternion.vector + quaternion.w * vector + vector.cross(quaternion.vector);

	return Quaternion(_w, _vector);
}

Quaternion Quaternion::operator =(const Quaternion& quaternion)
{
	if(this != &quaternion)
	{
		w = quaternion.w;
		vector = quaternion.vector;
	}

	return *this;
}

const Quaternion Quaternion::operator +=(const Quaternion& quaternion)
{
	*this = *this + quaternion;
	return *this;
}

const Quaternion Quaternion::operator -=(const Quaternion& quaternion)
{
	*this = *this - quaternion;
	return *this;
}

const Quaternion Quaternion::operator *=(const Quaternion& quaternion)
{
	*this = *this * quaternion;
	return *this;
}

bool Quaternion::operator ==(const Quaternion& quaternion) const
{
	return equals(w, quaternion.w) && vector == quaternion.vector;
}

bool Quaternion::operator !=(const Quaternion& quaternion) const
{
	return !(*this == quaternion);
}

Quaternion Quaternion::operator -()
{
	return Quaternion(-w, -vector);
}

Quaternion Quaternion::operator /(const float scalar) const
{
	assert(!equals(scalar, 0.0f));

	const float _w = w / scalar;
	const Vector3 _vector = vector / scalar;

	return Quaternion(_w, _vector);
}

const Quaternion& Quaternion::operator /=(const float scalar)
{
	*this = *this / scalar;
	return *this;
}

// Friends

namespace devmath
{
	Quaternion operator *(const Quaternion& quaternion, const float scalar)
	{
		const float _w = scalar * quaternion.w;
		const Vector3 _vector = scalar * quaternion.vector;

		return Quaternion(_w, _vector);
	}

	Quaternion operator *(const float scalar, const Quaternion& quaternion)
	{
		return quaternion * scalar;
	}

	const Quaternion& operator *=(Quaternion& quaternion, const float scalar)
	{
		quaternion = quaternion * scalar;
		return quaternion;
	}

	ostream& operator <<(ostream& output, const Quaternion& quaternion)
	{
		const Vector3& vector = quaternion.vector;
		output << "[W: " << quaternion.w << ", X: " << vector.x << ", Y: " << vector.y << ", Z: " << vector.z << "]";
			
		return output;
	}
}