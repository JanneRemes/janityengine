/**
 * @file Matrix3.h
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

#ifndef DEVMATH_MATRIX3_H
#define DEVMATH_MATRIX3_H

#include <iostream>

#include <devmath/Vector2.h>
#include <devmath/Vector3.h>

namespace devmath
{
	/**
	 * 3 x 3 column major order matrix for 2D transformations.
	 */
	class Matrix3
	{
	public:

		static const unsigned int COLUMNS = 3;
		static const unsigned int ROWS = 3;

		/**
		 * Default constructor.
		 */
		Matrix3();

		/**
		 * Overloaded constructor.
		 *
		 * @param m11
		 *   First element of the first column.
		 * @param m12
		 *   Second element of the first column.
		 * @param m13
		 *   Third element of the first column.
		 * @param m21
		 *   First element of the second column.
		 * @param m22
		 *   Second element of the second column.
		 * @param m23
		 *   Third element of the second column.
		 * @param m31
		 *   First element of the third column.
		 * @param m32
		 *   Second element of the third column.
		 * @param m33
		 *   Third element of the third column.
		 */
		Matrix3(const float m11, const float m12, const float m13, const float m21, const float m22, const float m23, const float m31, const float m32, const float m33);

		/**
		 * Overloaded constructor.
		 *
		 * @param column1
		 *   First column.
		 * @param column2
		 *   Second column.
		 * @param column3
		 *   Third column.
		 */
		Matrix3(const Vector3& column1, const Vector3& column2, const Vector3& column3);

		/**
		 * Copy constructor.
		 */
		Matrix3(const Matrix3& matrix);

		/**
		 * Destructor.
		 */
		~Matrix3();

		/**
		 * Gets the elements.
		 */
		const float* elements() const;

		/**
		 * Calculates the determinant.
		 *
		 * @return
		 *   Determinant.
		 */
		float determinant() const;

		/**
		 * Calculates the inverse matrix.
		 *
		 * @return
		 *   Inverse matrix or identity matrix if the matrix is not invertible.
		 */
		Matrix3 inverse() const;

		/**
		 * Calculates the transpose matrix.
		 *
		 * @return
		 *   Transpose matrix.
		 */
		Matrix3 transpose() const;

		/**
		 * Extracts the position information.
		 *
		 * @return
		 *   Position information.
		 */
		Vector2 extractPosition() const;

		/**
		 * Extracts the rotation matrix.
		 *
		 * Also extracts scaling information in order to extract the rotation matrix.
		 *
		 * @return
		 *   Rotation matrix.
		 */
		Matrix3 extractRotation() const;

		/**
		 * Extracts the rotation matrix.
		 *
		 * @param scaling
		 *   Scaling amount.
		 * @return
		 *   Rotation matrix.
		 */
		Matrix3 extractRotation(const Vector2& scaling) const;

		/**
		 * Extracts the scaling information.
		 *
		 * @return
		 *   Scaling amount.
		 */
		Vector2 extractScaling() const;

		/**
		 * Gets an identity matrix.
		 */
		static Matrix3 identity();

		/**
		 * Creates a rotation matrix for the z axis.
		 *
		 * @param angle
		 *   Angle in radians.
		 * @return
		 *   Rotation matrix.
		 */
		static Matrix3 createRotation(const float angle);

		/**
		 * Creates a scaling matrix.
		 *
		 * @param x
		 *   Scaling along x axis.
		 * @param y
		 *   Scaling along y axis.
		 * @return
		 *   Scaling matrix.
		 */
		static Matrix3 createScaling(const float x = 1.0f, const float y = 1.0f);

		/**
		 * Creates a scaling matrix.
		 *
		 * @param scaling
		 *   Scaling amount.
		 * @return
		 *   Scaling matrix.
		 */
		static Matrix3 createScaling(const Vector2& scaling);

		/**
		 * Creates a translation matrix.
		 *
		 * @param x
		 *   Translation along x axis.
		 * @param y
		 *   Translation along y axis.
		 * @return
		 *   Translation matrix.
		 */
		static Matrix3 createTranslation(const float x, const float y);

		/**
		 * Creates a translation matrix.
		 *
		 * @param translation
		 *   Translation amount.
		 * @return
		 *   Translation matrix.
		 */
		static Matrix3 createTranslation(const Vector2& translation);

		/**
		 * Addition operator overload.
		 */
		Matrix3 operator +(const Matrix3& matrix) const;

		/**
		 * Subtraction operator overload.
		 */
		Matrix3 operator -(const Matrix3& matrix) const;

		/**
		 * Multiplication operator overload.
		 */
		Matrix3 operator *(const Matrix3& matrix) const;

		/**
		 * Assignment operator overload.
		 */
		Matrix3& operator =(const Matrix3& matrix);

		/**
		 * Assignment addition operator overload.
		 */
		const Matrix3& operator +=(const Matrix3& matrix);

		/**
		 * Assignment subtraction operator overload.
		 */
		const Matrix3& operator -=(const Matrix3& matrix);

		/**
		 * Assignment multiplication operator overload.
		 */
		const Matrix3& operator *=(const Matrix3& matrix);

		/**
		 * Equal operator overload.
		 */
		bool operator ==(const Matrix3& matrix) const;

		/**
		 * Not equal operator overload.
		 */
		bool operator !=(const Matrix3& matrix) const;

		/**
		 * Scalar division operator overload.
		 */
		Matrix3 operator /(const float scalar);

		/**
		 * Assignment scalar division operator overload.
		 */
		const Matrix3& operator /=(const float scalar);

		/**
		 * Vector multiplication operator overload.
		 */
		Vector3 operator *(const Vector3& vector) const;

		/**
		 * Subscript operator overload.
		 */
		Vector3& operator [](const unsigned int index);
		const Vector3& operator [](const unsigned int index) const;

		/**
		 * Scalar multiplication operator overload.
		 */
		friend Matrix3 operator *(const Matrix3& matrix, const float scalar);
		friend Matrix3 operator *(const float scalar, const Matrix3& matrix);

		/**
		 * Assignment scalar multiplication operator overload.
		 */
		friend const Matrix3& operator *=(Matrix3& matrix, const float scalar);

		/**
		 * Ostream output overload.
		 */
		friend std::ostream& operator <<(std::ostream& output, const Matrix3& matrix);

	private:

		Vector3 _columns[3];
		
		Matrix3 adjugate() const;
	};
}

#endif