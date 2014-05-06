/**
 * @file Matrix3.cpp
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

#include <devmath/Matrix3.h>

#include <cassert>
#include <cmath>

#include <devmath/Utils.h>

using namespace devmath;
using namespace std;

Matrix3::Matrix3() { }

Matrix3::Matrix3(const float m11, const float m12, const float m13, const float m21, const float m22, const float m23, const float m31, const float m32, const float m33)
{
	_columns[0] = Vector3(m11, m12, m13);
	_columns[1] = Vector3(m21, m22, m23);
	_columns[2] = Vector3(m31, m32, m33);
}

Matrix3::Matrix3(const Vector3& column1, const Vector3& column2, const Vector3& column3)
{
	_columns[0] = column1;
	_columns[1] = column2;
	_columns[2] = column3;
}

Matrix3::Matrix3(const Matrix3& matrix)
{
	_columns[0] = matrix._columns[0];
	_columns[1] = matrix._columns[1];
	_columns[2] = matrix._columns[2];
}

Matrix3::~Matrix3() { }


// Public

const float* Matrix3::elements() const
{
	return &_columns[0][0];
}

float Matrix3::determinant() const
{
	const float m12 = _columns[0][1];
	const float m13 = _columns[0][2];
	const float m22 = _columns[1][1];
	const float m23 = _columns[1][2];
	const float m32 = _columns[2][1];
	const float m33 = _columns[2][2];

	const float detA =  m22 * m33 - m32 * m23;
	const float detB =  m12 * m33 - m32 * m13;
	const float detC =  m12 * m23 - m22 * m13;

	return _columns[0][0] * detA - _columns[1][0] * detB + _columns[2][0] * detC;
}

Matrix3 Matrix3::inverse() const
{
	Matrix3 result = identity();
	const float det = determinant();

	if(!equals(det, 0.0f))
		result = 1.0f / det * adjugate();
		
	return result;
}

Matrix3 Matrix3::transpose() const
{
	Matrix3 result;

	for(unsigned int c = 0; c < COLUMNS; ++c)
	{
		for(unsigned int r = 0; r < ROWS; ++r)
			result._columns[c][r] = _columns[r][c];
	}

	return result;
}

Vector2 Matrix3::extractPosition() const
{
	return _columns[2].xy();
}

Matrix3 Matrix3::extractRotation() const
{
	const Vector2 scaling = extractScaling();
	return extractRotation(scaling);
}

Matrix3 Matrix3::extractRotation(const Vector2& scaling) const
{
	Matrix3 result(*this);
	result[0] /= scaling.x;
	result[1] /= scaling.y;
	result[2] = Vector3(0.0f, 0.0f, 1.0f);

	return result;
}

Vector2 Matrix3::extractScaling() const
{
	const float x = _columns[0].xy().length();
	const float y = _columns[1].xy().length();

	return Vector2(x, y);
}

// Static

Matrix3 Matrix3::identity()
{
	return Matrix3
	(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	);
}

Matrix3 Matrix3::createRotation(const float angle)
{
	return Matrix3
	(
		 cos(angle), sin(angle), 0.0f,
		-sin(angle), cos(angle), 0.0f,
		 0.0f,		 0.0f,		 1.0f
	);
}

Matrix3 Matrix3::createScaling(const float x, const float y)
{
	return Matrix3
	(
		x,    0.0f, 0.0f,
		0.0f, y,    0.0f,
		0.0f, 0.0f, 1.0f
	);
}

Matrix3 Matrix3::createScaling(const Vector2& scaling)
{
	return createScaling(scaling.x, scaling.y);
}

Matrix3 Matrix3::createTranslation(const float x, const float y)
{
	return Matrix3
	(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		x,	  y,	1.0f
	);
}

Matrix3 Matrix3::createTranslation(const Vector2& translation)
{
	return createTranslation(translation.x, translation.y);
}

// Operators

Matrix3 Matrix3::operator +(const Matrix3& matrix) const
{
	Matrix3 result;

	for(unsigned int c = 0; c < COLUMNS; ++c)
	{
		for(unsigned int r = 0; r < ROWS; ++r)
			result._columns[c][r] = _columns[c][r] + matrix._columns[c][r];
	}

	return result;
}

Matrix3 Matrix3::operator -(const Matrix3& matrix) const
{
	Matrix3 result;
	
	for(unsigned int c = 0; c < COLUMNS; ++c)
	{
		for(unsigned int r = 0; r < ROWS; ++r)
			result._columns[c][r] = _columns[c][r] - matrix._columns[c][r];
	}

	return result;
}

Matrix3 Matrix3::operator *(const Matrix3& matrix) const
{
	const float mA11 = _columns[0][0];
	const float mA12 = _columns[0][1];
	const float mA13 = _columns[0][2];
	const float mA21 = _columns[1][0];
	const float mA22 = _columns[1][1];
	const float mA23 = _columns[1][2];
	const float mA31 = _columns[2][0];
	const float mA32 = _columns[2][1];
	const float mA33 = _columns[2][2];

	const float mB11 = matrix._columns[0][0];
	const float mB12 = matrix._columns[0][1];
	const float mB13 = matrix._columns[0][2];
	const float mB21 = matrix._columns[1][0];
	const float mB22 = matrix._columns[1][1];
	const float mB23 = matrix._columns[1][2];
	const float mB31 = matrix._columns[2][0];
	const float mB32 = matrix._columns[2][1];
	const float mB33 = matrix._columns[2][2];

	return Matrix3
	(
		mA11 * mB11 + mA21 * mB12 + mA31 * mB13,
		mA12 * mB11 + mA22 * mB12 + mA32 * mB13,
		mA13 * mB11 + mA23 * mB12 + mA33 * mB13,
		mA11 * mB21 + mA21 * mB22 + mA31 * mB23,
		mA12 * mB21 + mA22 * mB22 + mA32 * mB23,
		mA13 * mB21 + mA23 * mB22 + mA33 * mB23,
		mA11 * mB31 + mA21 * mB32 + mA31 * mB33,
		mA12 * mB31 + mA22 * mB32 + mA32 * mB33,
		mA13 * mB31 + mA23 * mB32 + mA33 * mB33
	);
}

Matrix3& Matrix3::operator =(const Matrix3& matrix)
{
	if(this != &matrix)
	{
		_columns[0] = matrix._columns[0];
		_columns[1] = matrix._columns[1];
		_columns[2] = matrix._columns[2];
	}
	
	return *this;
}

const Matrix3& Matrix3::operator +=(const Matrix3& matrix)
{
	*this = *this + matrix;
	return *this;
}

const Matrix3& Matrix3::operator -=(const Matrix3& matrix)
{
	*this = *this - matrix;
	return *this;
}

const Matrix3& Matrix3::operator *=(const Matrix3& matrix)
{
	*this = *this * matrix;
	return *this;
}

bool Matrix3::operator ==(const Matrix3& matrix) const
{
	for(unsigned int c = 0; c < COLUMNS; ++c)
	{
		if(_columns[c] != matrix._columns[c])
			return false;
	}

	return true;
}

bool Matrix3::operator !=(const Matrix3& matrix) const
{
	return !(*this == matrix);
}

Matrix3 Matrix3::operator /(const float scalar)
{
	assert(!equals(scalar, 0.0f));
	Matrix3 result;

	for(unsigned int c = 0; c < COLUMNS; ++c)
		result[c] = _columns[c] / scalar;
			
	return result;
}

const Matrix3& Matrix3::operator /=(const float scalar)
{
	*this = *this / scalar;
	return *this;
}

Vector3 Matrix3::operator *(const Vector3& vector) const
{
	const float m11 = _columns[0][0];
	const float m12 = _columns[0][1];
	const float m13 = _columns[0][2];
	const float m21 = _columns[1][0];
	const float m22 = _columns[1][1];
	const float m23 = _columns[1][2];
	const float m31 = _columns[2][0];
	const float m32 = _columns[2][1];
	const float m33 = _columns[2][2];

	return Vector3
	(
		m11 * vector.x + m21 * vector.y + m31 * vector.z,
		m12 * vector.x + m22 * vector.y + m32 * vector.z,
		m13 * vector.x + m23 * vector.y + m33 * vector.z
	);
}

Vector3& Matrix3::operator [](const unsigned int index)
{
	assert(index < (unsigned int)COLUMNS);
	return _columns[index];
}

const Vector3& Matrix3::operator [](const unsigned int index) const
{
	assert(index < (unsigned int)COLUMNS);
	return _columns[index];
}

// Friends

namespace devmath
{
	Matrix3 operator *(const Matrix3& matrix, const float scalar)
	{
		Matrix3 result;

		for(unsigned int c = 0; c < Matrix3::COLUMNS; ++c)
			result[c] = scalar * matrix._columns[c];
		
		return result;
	}

	Matrix3 operator *(const float scalar, const Matrix3& matrix)
	{
		return matrix * scalar;
	}

	const Matrix3& operator *=(Matrix3& matrix, const float scalar)
	{
		matrix = matrix * scalar;
		return matrix;
	}

	ostream& operator <<(ostream& output, const Matrix3& matrix)
	{
		for(unsigned int r = 0; r < Matrix3::ROWS; ++r)
		{
			for(unsigned int c = 0; c < Matrix3::COLUMNS; ++c)
			{
				output << matrix._columns[c][r];

				if(c < Matrix3::COLUMNS - 1)
					output << ", ";
			}

			output << "\n";
		}

		return output;
	}
}


// Private

Matrix3 Matrix3::adjugate() const
{
	const float m11 = _columns[0][0];
	const float m12 = _columns[0][1];
	const float m13 = _columns[0][2];
	const float m21 = _columns[1][0];
	const float m22 = _columns[1][1];
	const float m23 = _columns[1][2];
	const float m31 = _columns[2][0];
	const float m32 = _columns[2][1];
	const float m33 = _columns[2][2];

	return Matrix3
	(
		m22 * m33 - m32 * m23,
		m32 * m13 - m12 * m33,
		m12 * m23 - m22 * m13,
		m31 * m23 - m21 * m33,
		m11 * m33 - m31 * m13,
		m13 * m21 - m11 * m23,
		m21 * m32 - m31 * m22,
		m31 * m12 - m11 * m32,
		m11 * m22 - m21 * m12
	);
}