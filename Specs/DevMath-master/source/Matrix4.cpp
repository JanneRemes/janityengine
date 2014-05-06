/**
 * @file Matrix4.cpp
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

#include <devmath/Matrix4.h>

#include <cassert>
#include <cmath>

#include <devmath/Utils.h>

using namespace devmath;
using namespace std;

Matrix4::Matrix4() { }

Matrix4::Matrix4(const float m11, const float m12, const float m13, const float m14, const float m21, const float m22, const float m23, const float m24, const float m31, const float m32, const float m33, const float m34, const float m41, const float m42, const float m43, const float m44)
{
	_columns[0] = Vector4(m11, m12, m13, m14);
	_columns[1] = Vector4(m21, m22, m23, m24);
	_columns[2] = Vector4(m31, m32, m33, m34);
	_columns[3] = Vector4(m41, m42, m43, m44);
}

Matrix4::Matrix4(const Vector4& column1, const Vector4& column2, const Vector4& column3, const Vector4& column4)
{
	_columns[0] = column1;
	_columns[1] = column2;
	_columns[2] = column3;
	_columns[3] = column4;
}

Matrix4::Matrix4(const Matrix3& matrix)
{
	_columns[0] = Vector4(matrix[0], 0.0f);
	_columns[1] = Vector4(matrix[1], 0.0f);
	_columns[2] = Vector4(matrix[2], 0.0f);
	_columns[3] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4::Matrix4(const Quaternion& quaternion)
{
	assert(quaternion.isUnitQuaternion());

	const float w = quaternion.w;
	const float x = quaternion.vector.x;
	const float y = quaternion.vector.y;
	const float z = quaternion.vector.z;

	const float m11 = 1.0f - 2.0f * y * y - 2.0f * z * z;
	const float m12 = 2.0f * x * y + 2.0f * w * z;
	const float m13 = 2.0f * x * z - 2.0f * w * y;
	const float m21 = 2.0f * x * y - 2.0f * w * z;
	const float m22 = 1.0f - 2.0f * x * x - 2.0f * z * z;
	const float m23 = 2.0f * y * z + 2.0f * w * x;
	const float m31 = 2.0f * x * z + 2.0f * w * y;
	const float m32 = 2.0f * y * z - 2.0f * w * x;
	const float m33 = 1.0f - 2.0f * x * x - 2.0f * y * y;

	_columns[0] = Vector4(m11, m12, m13, 0.0f);
	_columns[1] = Vector4(m21, m22, m23, 0.0f);
	_columns[2] = Vector4(m31, m32, m33, 0.0f);
	_columns[3] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4::Matrix4(const Matrix4& matrix)
{
	_columns[0] = matrix._columns[0];
	_columns[1] = matrix._columns[1];
	_columns[2] = matrix._columns[2];
	_columns[3] = matrix._columns[3];
}

Matrix4::~Matrix4() { }


// Public

const float* Matrix4::elements() const
{
	return &_columns[0][0];
}

float Matrix4::determinant() const
{
	const float m12 = _columns[0][1];
	const float m13 = _columns[0][2];
	const float m14 = _columns[0][3];
	const float m22 = _columns[1][1];
	const float m23 = _columns[1][2];
	const float m24 = _columns[1][3];
	const float m32 = _columns[2][1];
	const float m33 = _columns[2][2];
	const float m34 = _columns[2][3];
	const float m42 = _columns[3][1];
	const float m43 = _columns[3][2];
	const float m44 = _columns[3][3];

	const float detA = m22 * (m33 * m44 - m43 * m34) - m32 * (m23 * m44 - m43 * m24) + m42 * (m23 * m34 - m33 * m24);
	const float detB = m12 * (m33 * m44 - m43 * m34) - m32 * (m13 * m44 - m43 * m14) + m42 * (m13 * m34 - m33 * m14);
	const float detC = m12 * (m23 * m44 - m43 * m24) - m22 * (m13 * m44 - m43 * m14) + m42 * (m13 * m24 - m23 * m14);
	const float detD = m12 * (m23 * m34 - m33 * m24) - m22 * (m13 * m34 - m33 * m14) + m32 * (m13 * m24 - m23 * m14);

	return _columns[0][0] * detA - _columns[1][0] * detB + _columns[2][0] * detC - _columns[3][0] * detD;
}

Matrix4 Matrix4::inverse() const
{
	Matrix4 result = identity();
	const float det = determinant();

	if(!equals(det, 0.0f))
		result = 1.0f / det * adjugate();
		
	return result;
}

Matrix4 Matrix4::transpose() const
{
	Matrix4 result;

	for(unsigned int c = 0; c < COLUMNS; ++c)
	{
		for(unsigned int r = 0; r < ROWS; ++r)
			result[c][r] = _columns[r][c];
	}

	return result;
}

Vector3 Matrix4::extractPosition() const
{
	return _columns[3].xyz();
}

Matrix4 Matrix4::extractRotation() const
{
	const Vector3 scaling = extractScaling();
	return extractRotation(scaling);
}

Matrix4 Matrix4::extractRotation(const Vector3& scaling) const
{
	Matrix4 result(*this);
	result[0] /= scaling.x;
	result[1] /= scaling.y;
	result[2] /= scaling.z;
	result[3] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);

	return result;
}

Vector3 Matrix4::extractScaling() const
{
	const float x = _columns[0].xyz().length();
	const float y = _columns[1].xyz().length();
	const float z = _columns[2].xyz().length();
	
	return Vector3(x, y, z);
}

// Static

Matrix4 Matrix4::identity()
{
	return Matrix4
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix4 Matrix4::createRotationX(const float angle)
{
	return Matrix4
	(
		1.0f,  0.0f,	   0.0f,	   0.0f,
		0.0f,  cos(angle), sin(angle), 0.0f,
		0.0f, -sin(angle), cos(angle), 0.0f,
		0.0f,  0.0f,	   0.0f,	   1.0f
	);
}

Matrix4 Matrix4::createRotationY(const float angle)
{
	return Matrix4
	(
		cos(angle),	0.0f, -sin(angle), 0.0f,
		0.0f,		1.0f,  0.0f,	   0.0f,
		sin(angle), 0.0f,  cos(angle), 0.0f,
		0.0f,		0.0f,  0.0f,	   1.0f
	);
}

Matrix4 Matrix4::createRotationZ(const float angle)
{
	return Matrix4
	(
		 cos(angle), sin(angle), 0.0f, 0.0f,
		-sin(angle), cos(angle), 0.0f, 0.0f,
		 0.0f,		 0.0f,		 1.0f, 0.0f,
		 0.0f,		 0.0f,		 0.0f, 1.0f
	);
}

Matrix4 Matrix4::createRotationAxis(const Vector3& axis, const float angle)
{
	assert(axis.isUnitVector());

	const float x = axis.x;
	const float y = axis.y;
	const float z = axis.z;

	const float angleSin = sin(angle);
	const float angleCos = cos(angle);

	return Matrix4
	(
		x * x * (1 - angleCos) + angleCos,
		x * y * (1 - angleCos) + z * angleSin,
		x * z * (1 - angleCos) - y * angleSin, 0.0f,
		x * y * (1 - angleCos) - z * angleSin,
		y * y * (1 - angleCos) + angleCos,
		y * z * (1 - angleCos) + x * angleSin, 0.0f,
		x * z * (1 - angleCos) + y * angleSin,
		y * z * (1 - angleCos) - x * angleSin,
		z * z * (1 - angleCos) + angleCos,	   0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix4 Matrix4::createScaling(const float x, const float y, const float z)
{
	return Matrix4
	(
		x,    0.0f, 0.0f, 0.0f,
		0.0f, y,    0.0f, 0.0f,
		0.0f, 0.0f, z,    0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix4 Matrix4::createScaling(const Vector3& scaling)
{
	return createScaling(scaling.x, scaling.y, scaling.z);
}

Matrix4 Matrix4::createScalingAxis(const Vector3& axis, const float scale)
{
	assert(axis.isUnitVector());

	const float x = axis.x;
	const float y = axis.y;
	const float z = axis.z;

	return Matrix4
	(
		x * x * (scale - 1) + 1,
		x * y * (scale - 1),
		x * z * (scale - 1),	 0.0f,
		x * y * (scale - 1),
		y * y * (scale - 1) + 1,
		y * z * (scale - 1),	 0.0f,
		x * z * (scale - 1),
		y * z * (scale - 1),
		z * z * (scale - 1) + 1, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix4 Matrix4::createTranslation(const float x, const float y, const float z)
{
	return Matrix4
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		x,	  y,	z,	  1.0f
	);
}

Matrix4 Matrix4::createTranslation(const Vector3& translation)
{
	return createTranslation(translation.x, translation.y, translation.z);
}

// Operators

Matrix4 Matrix4::operator +(const Matrix4& matrix) const
{
	Matrix4 result;

	for(unsigned int c = 0; c < COLUMNS; ++c)
	{
		for(unsigned int r = 0; r < ROWS; ++r)
			result[c][r] = _columns[c][r] + matrix._columns[c][r];
	}

	return result;
}

Matrix4 Matrix4::operator -(const Matrix4& matrix) const
{
	Matrix4 result;
	
	for(unsigned int c = 0; c < COLUMNS; ++c)
	{
		for(unsigned int r = 0; r < ROWS; ++r)
			result[c][r] = _columns[c][r] - matrix._columns[c][r];
	}

	return result;
}

Matrix4 Matrix4::operator *(const Matrix4& matrix) const
{
	const float mA11 = _columns[0][0];
	const float mA12 = _columns[0][1];
	const float mA13 = _columns[0][2];
	const float mA14 = _columns[0][3];
	const float mA21 = _columns[1][0];
	const float mA22 = _columns[1][1];
	const float mA23 = _columns[1][2];
	const float mA24 = _columns[1][3];
	const float mA31 = _columns[2][0];
	const float mA32 = _columns[2][1];
	const float mA33 = _columns[2][2];
	const float mA34 = _columns[2][3];
	const float mA41 = _columns[3][0];
	const float mA42 = _columns[3][1];
	const float mA43 = _columns[3][2];
	const float mA44 = _columns[3][3];

	const float mB11 = matrix._columns[0][0];
	const float mB12 = matrix._columns[0][1];
	const float mB13 = matrix._columns[0][2];
	const float mB14 = matrix._columns[0][3];
	const float mB21 = matrix._columns[1][0];
	const float mB22 = matrix._columns[1][1];
	const float mB23 = matrix._columns[1][2];
	const float mB24 = matrix._columns[1][3];
	const float mB31 = matrix._columns[2][0];
	const float mB32 = matrix._columns[2][1];
	const float mB33 = matrix._columns[2][2];
	const float mB34 = matrix._columns[2][3];
	const float mB41 = matrix._columns[3][0];
	const float mB42 = matrix._columns[3][1];
	const float mB43 = matrix._columns[3][2];
	const float mB44 = matrix._columns[3][3];

	return Matrix4
	(
		mA11 * mB11 + mA21 * mB12 + mA31 * mB13 + mA41 * mB14,
		mA12 * mB11 + mA22 * mB12 + mA32 * mB13 + mA42 * mB14,
		mA13 * mB11 + mA23 * mB12 + mA33 * mB13 + mA43 * mB14,
		mA14 * mB11 + mA24 * mB12 + mA34 * mB13 + mA44 * mB14,
		mA11 * mB21 + mA21 * mB22 + mA31 * mB23 + mA41 * mB24,
		mA12 * mB21 + mA22 * mB22 + mA32 * mB23 + mA42 * mB24,
		mA13 * mB21 + mA23 * mB22 + mA33 * mB23 + mA43 * mB24,
		mA14 * mB21 + mA24 * mB22 + mA34 * mB23 + mA44 * mB24,
		mA11 * mB31 + mA21 * mB32 + mA31 * mB33 + mA41 * mB34,
		mA12 * mB31 + mA22 * mB32 + mA32 * mB33 + mA42 * mB34,
		mA13 * mB31 + mA23 * mB32 + mA33 * mB33 + mA43 * mB34,
		mA14 * mB31 + mA24 * mB32 + mA34 * mB33 + mA44 * mB34,
		mA11 * mB41 + mA21 * mB42 + mA31 * mB43 + mA41 * mB44,
		mA12 * mB41 + mA22 * mB42 + mA32 * mB43 + mA42 * mB44,
		mA13 * mB41 + mA23 * mB42 + mA33 * mB43 + mA43 * mB44,
		mA14 * mB41 + mA24 * mB42 + mA34 * mB43 + mA44 * mB44
	);
}

Matrix4& Matrix4::operator =(const Matrix4& matrix)
{
	if(this != &matrix)
	{
		_columns[0] = matrix._columns[0];
		_columns[1] = matrix._columns[1];
		_columns[2] = matrix._columns[2];
		_columns[3] = matrix._columns[3];
	}
	
	return *this;
}

const Matrix4& Matrix4::operator +=(const Matrix4& matrix)
{
	*this = *this + matrix;
	return *this;
}

const Matrix4& Matrix4::operator -=(const Matrix4& matrix)
{
	*this = *this - matrix;
	return *this;
}

const Matrix4& Matrix4::operator *=(const Matrix4& matrix)
{
	*this = *this * matrix;
	return *this;
}

bool Matrix4::operator ==(const Matrix4& matrix) const
{
	for(unsigned int c = 0; c < COLUMNS; ++c)
	{
		if(_columns[c] != matrix._columns[c])
			return false;
	}

	return true;
}

bool Matrix4::operator !=(const Matrix4& matrix) const
{
	return !(*this == matrix);
}

Matrix4 Matrix4::operator /(const float scalar)
{
	assert(!equals(scalar, 0.0f));
	Matrix4 result;

	for(unsigned int c = 0; c < COLUMNS; ++c)
		result[c] = _columns[c] / scalar;
			
	return result;
}

const Matrix4& Matrix4::operator /=(const float scalar)
{
	*this = *this / scalar;
	return *this;
}

Vector4 Matrix4::operator *(const Vector4& vector) const
{
	const float m11 = _columns[0][0];
	const float m12 = _columns[0][1];
	const float m13 = _columns[0][2];
	const float m14 = _columns[0][3];
	const float m21 = _columns[1][0];
	const float m22 = _columns[1][1];
	const float m23 = _columns[1][2];
	const float m24 = _columns[1][3];
	const float m31 = _columns[2][0];
	const float m32 = _columns[2][1];
	const float m33 = _columns[2][2];
	const float m34 = _columns[2][3];
	const float m41 = _columns[3][0];
	const float m42 = _columns[3][1];
	const float m43 = _columns[3][2];
	const float m44 = _columns[3][3];

	return Vector4
	(
		m11 * vector.x + m21 * vector.y + m31 * vector.z + m41 * vector.w,
		m12 * vector.x + m22 * vector.y + m32 * vector.z + m42 * vector.w,
		m13 * vector.x + m23 * vector.y + m33 * vector.z + m43 * vector.w,
		m14 * vector.x + m24 * vector.y + m34 * vector.z + m44 * vector.w
	);
}

Vector4& Matrix4::operator [](const unsigned int index)
{
	assert(index < (unsigned int)COLUMNS);
	return _columns[index];
}

const Vector4& Matrix4::operator [](const unsigned int index) const
{
	assert(index < (unsigned int)COLUMNS);
	return _columns[index];
}

// Friends

namespace devmath
{
	Matrix4 operator *(const Matrix4& matrix, const float scalar)
	{
		Matrix4 result;

		for(unsigned int c = 0; c < Matrix4::COLUMNS; ++c)
			result[c] = scalar * matrix._columns[c];
		
		return result;
	}

	Matrix4 operator *(const float scalar, const Matrix4& matrix)
	{
		return matrix * scalar;
	}

	const Matrix4& operator *=(Matrix4& matrix, const float scalar)
	{
		matrix = matrix * scalar;
		return matrix;
	}

	ostream& operator <<(ostream& output, const Matrix4& matrix)
	{
		for(unsigned int r = 0; r < Matrix4::ROWS; ++r)
		{
			for(unsigned int c = 0; c < Matrix4::COLUMNS; ++c)
			{
				output << matrix._columns[c][r];

				if(c < Matrix4::COLUMNS - 1)
					output << ", ";
			}

			output << "\n";
		}

		return output;
	}
}


// Private

Matrix4 Matrix4::adjugate() const
{
	const float m11 = _columns[0][0];
	const float m12 = _columns[0][1];
	const float m13 = _columns[0][2];
	const float m14 = _columns[0][3];
	const float m21 = _columns[1][0];
	const float m22 = _columns[1][1];
	const float m23 = _columns[1][2];
	const float m24 = _columns[1][3];
	const float m31 = _columns[2][0];
	const float m32 = _columns[2][1];
	const float m33 = _columns[2][2];
	const float m34 = _columns[2][3];
	const float m41 = _columns[3][0];
	const float m42 = _columns[3][1];
	const float m43 = _columns[3][2];
	const float m44 = _columns[3][3];

	return Matrix4
	(
		 m22 * (m33 * m44 - m43 * m34) - m32 * (m23 * m44 - m43 * m24) + m42 * (m23 * m34 - m33 * m24),
		-(m12 * (m33 * m44 - m43 * m34) - m32 * (m13 * m44 - m43 * m14) + m42 * (m13 * m34 - m33 * m14)),
		 m12 * (m23 * m44 - m43 * m24) - m22 * (m13 * m44 - m43 * m14) + m42 * (m13 * m24 - m23 * m14),
		-(m12 * (m23 * m34 - m33 * m24) - m22 * (m13 * m34 - m33 * m14) + m32 * (m13 * m24 - m23 * m14)),
		-(m21 * (m33 * m44 - m43 * m34) - m31 * (m23 * m44 - m43 * m24) + m41 * (m23 * m34 - m33 * m24)),
		 m11 * (m33 * m44 - m43 * m34) - m31 * (m13 * m44 - m43 * m14) + m41 * (m13 * m34 - m33 * m14),
		-(m11 * (m23 * m44 - m43 * m24) - m21 * (m13 * m44 - m43 * m14) + m41 * (m13 * m24 - m23 * m14)),
		 m11 * (m23 * m34 - m33 * m24) - m21 * (m13 * m34 - m33 * m14) + m31 * (m13 * m24 - m23 * m14),
		 m21 * (m32 * m44 - m42 * m34) - m31 * (m22 * m44 - m42 * m24) + m41 * (m22 * m34 - m32 * m24),
		-(m11 * (m32 * m44 - m42 * m34) - m31 * (m12 * m44 - m42 * m14) + m41 * (m12 * m34 - m32 * m14)),
		 m11 * (m22 * m44 - m42 * m24) - m21 * (m12 * m44 - m42 * m14) + m41 * (m12 * m24 - m22 * m14),
		-(m11 * (m22 * m34 - m32 * m24) - m21 * (m12 * m34 - m32 * m14) + m31 * (m12 * m24 - m22 * m14)),
		-(m21 * (m32 * m43 - m42 * m33) - m31 * (m22 * m43 - m42 * m23) + m41 * (m22 * m33 - m32 * m23)),
		 m11 * (m32 * m43 - m42 * m33) - m31 * (m12 * m43 - m42 * m13) + m41 * (m12 * m33 - m32 * m13),
		-(m11 * (m22 * m43 - m42 * m23) - m21 * (m12 * m43 - m42 * m13) + m41 * (m12 * m23 - m22 * m13)),
		 m11 * (m22 * m33 - m32 * m23) - m21 * (m12 * m33 - m32 * m13) + m31 * (m12 * m23 - m22 * m13)
	);
}