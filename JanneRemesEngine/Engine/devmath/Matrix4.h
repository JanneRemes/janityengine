/**
 * @file Matrix4.h
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

#ifndef DEVMATH_MATRIX4_H
#define DEVMATH_MATRIX4_H

#include <iostream>

#include <devmath/Quaternion.h>
#include <devmath/Matrix3.h>
#include <devmath/Vector3.h>
#include <devmath/Vector4.h>

namespace devmath
{
	/**
	 * 4 x 4 column major order matrix for 3D transformations.
	 */
	class Matrix4
	{
	public:

		static const unsigned int COLUMNS = 4;
		static const unsigned int ROWS = 4;

		/**
		 * Default constructor.
		 */
		Matrix4();

		/**
		 * Overloaded constructor.
		 *
		 * @param m11
		 *   First element of the first column.
		 * @param m12
		 *   Second element of the first column.
		 * @param m13
		 *   Third element of the first column.
		 * @param m14
		 *   Fourth element of the first column.
		 * @param m21
		 *   First element of the second column.
		 * @param m22
		 *   Second element of the second column.
		 * @param m23
		 *   Third element of the second column.
		 * @param m24
		 *   Fourth element of the second column.
		 * @param m31
		 *   First element of the third column.
		 * @param m32
		 *   Second element of the third column.
		 * @param m33
		 *   Third element of the third column.
		 * @param m34
		 *   Fourth element of the third column.
		 * @param m41
		 *   First element of the fourth column.
		 * @param m42
		 *   Second element of the fourth column.
		 * @param m43
		 *   Third element of the fourth column.
		 * @param m44
		 *   Fourth element of the fourth column.
		 */
		Matrix4(const float m11, const float m12, const float m13, const float m14, const float m21, const float m22, const float m23, const float m24, const float m31, const float m32, const float m33, const float m34, const float m41, const float m42, const float m43, const float m44);

		/**
		 * Overloaded constructor.
		 *
		 * @param column1
		 *   First column.
		 * @param column2
		 *   Second column.
		 * @param column3
		 *   Third column.
		 * @param column4
		 *   Fourth column.
		 */
		Matrix4(const Vector4& column1, const Vector4& column2, const Vector4& column3, const Vector4& column4);

		/**
		 * Overloaded constructor.
		 *
		 * @param matrix
		 *   3 x 3 matrix.
		 */
		explicit Matrix4(const Matrix3& matrix);

		/**
		 * Overloaded constructor.
		 *
		 * @param quaternion
		 *   Unit quaternion.
		 */
		explicit Matrix4(const Quaternion& quaternion);

		/**
		 * Copy constructor.
		 */
		Matrix4(const Matrix4& matrix);

		/**
		 * Destructor.
		 */
		~Matrix4();

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
		Matrix4 inverse() const;

		/**
		 * Calculates the transpose matrix.
		 *
		 * @return
		 *   Transpose matrix.
		 */
		Matrix4 transpose() const;

		/**
		 * Extracts the position information.
		 *
		 * @return
		 *   Position information.
		 */
		Vector3 extractPosition() const;

		/**
		 * Extracts the rotation matrix.
		 *
		 * Also extracts scaling information in order to extract the rotation matrix.
		 *
		 * @return
		 *   Rotation matrix.
		 */
		Matrix4 extractRotation() const;

		/**
		 * Extracts the rotation matrix.
		 *
		 * @param scaling
		 *   Scaling amount.
		 * @return
		 *   Rotation matrix.
		 */
		Matrix4 extractRotation(const Vector3& scaling) const;

		/**
		 * Extracts the scaling information.
		 *
		 * @return
		 *   Scaling amount.
		 */
		Vector3 extractScaling() const;

		/**
		 * Gets an identity matrix.
		 */
		static Matrix4 identity();

		/**
		 * Creates a rotation matrix for the x axis.
		 *
		 * @param angle
		 *   Angle in radians.
		 * @return
		 *   Rotation matrix.
		 */
		static Matrix4 createRotationX(const float angle);

		/**
		 * Creates a rotation matrix for the y axis.
		 *
		 * @param angle
		 *   Angle in radians.
		 * @return
		 *   Rotation matrix.
		 */
		static Matrix4 createRotationY(const float angle);

		/**
		 * Creates a rotation matrix for the z axis.
		 *
		 * @param angle
		 *   Angle in radians.
		 * @return
		 *   Rotation matrix.
		 */
		static Matrix4 createRotationZ(const float angle);

		/**
		 * Creates a rotation matrix for specified axis.
		 *
		 * @param axis
		 *   Unit vector representing the rotational axis.
		 * @param angle
		 *   Angle in radians.
		 * @return
		 *   Rotation matrix.
		 */
		static Matrix4 createRotationAxis(const Vector3& axis, const float angle);

		/**
		 * Creates a scaling matrix.
		 *
		 * @param x
		 *   Scaling along x axis.
		 * @param y
		 *   Scaling along y axis.
		 * @param z
		 *   Scaling along z axis.
		 * @return
		 *   Scaling matrix.
		 */
		static Matrix4 createScaling(const float x = 1.0f, const float y = 1.0f, const float z = 1.0f);

		/**
		 * Creates a scaling matrix.
		 *
		 * @param scaling
		 *   Scaling amount.
		 * @return
		 *   Scaling matrix.
		 */
		static Matrix4 createScaling(const Vector3& scaling);

		/**
		 * Creates a scaling matrix for specified axis.
		 *
		 * @param axis
		 *   Unit vector representing the scaling axis.
		 * @param scale
		 *   Scale.
		 * @return
		 *   Scaling matrix.
		 */
		static Matrix4 createScalingAxis(const Vector3& axis, const float scale);

		/**
		 * Creates a translation matrix.
		 *
		 * @param x
		 *   Translation along x axis.
		 * @param y
		 *   Translation along y axis.
		 * @param z
		 *   Translation along z axis.
		 * @return
		 *   Translation matrix.
		 */
		static Matrix4 createTranslation(const float x, const float y, const float z);

		/**
		 * Creates a translation matrix.
		 *
		 * @param translation
		 *   Translation amount.
		 * @return
		 *   Translation matrix.
		 */
		static Matrix4 createTranslation(const Vector3& translation);

		/**
		 * Addition operator overload.
		 */
		Matrix4 operator +(const Matrix4& matrix) const;

		/**
		 * Subtraction operator overload.
		 */
		Matrix4 operator -(const Matrix4& matrix) const;

		/**
		 * Multiplication operator overload.
		 */
		Matrix4 operator *(const Matrix4& matrix) const;

		/**
		 * Assignment operator overload.
		 */
		Matrix4& operator =(const Matrix4& matrix);

		/**
		 * Assignment addition operator overload.
		 */
		const Matrix4& operator +=(const Matrix4& matrix);

		/**
		 * Assignment subtraction operator overload.
		 */
		const Matrix4& operator -=(const Matrix4& matrix);

		/**
		 * Assignment multiplication operator overload.
		 */
		const Matrix4& operator *=(const Matrix4& matrix);

		/**
		 * Equal operator overload.
		 */
		bool operator ==(const Matrix4& matrix) const;

		/**
		 * Not equal operator overload.
		 */
		bool operator !=(const Matrix4& matrix) const;

		/**
		 * Scalar division operator overload.
		 */
		Matrix4 operator /(const float scalar);

		/**
		 * Assignment scalar division operator overload.
		 */
		const Matrix4& operator /=(const float scalar);

		/**
		 * Vector multiplication operator overload.
		 */
		Vector4 operator *(const Vector4& vector) const;

		/**
		 * Subscript operator overload.
		 */
		Vector4& operator [](const unsigned int index);
		const Vector4& operator [](const unsigned int index) const;

		/**
		 * Scalar multiplication operator overload.
		 */
		friend Matrix4 operator *(const Matrix4& matrix, const float scalar);
		friend Matrix4 operator *(const float scalar, const Matrix4& matrix);

		/**
		 * Assignment scalar multiplication operator overload.
		 */
		friend const Matrix4& operator *=(Matrix4& matrix, const float scalar);

		/**
		 * Ostream output overload.
		 */
		friend std::ostream& operator <<(std::ostream& output, const Matrix4& matrix);

	private:

		Vector4 _columns[4];
		
		Matrix4 adjugate() const;
	};
}

#endif