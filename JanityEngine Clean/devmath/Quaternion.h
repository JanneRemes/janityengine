/**
 * @file Quaternion.h
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

#ifndef DEVMATH_QUATERNION_H
#define DEVMATH_QUATERNION_H

#include <iostream>
#include <devmath/Vector3.h>

namespace devmath
{
	class Matrix3;
	class Matrix4;

	/**
	 * Quaternion for 3D rotations.
	 */
	class Quaternion
	{
	public:

		/**
		 * Constant.
		 */
		float w;

		/**
		 * Vector part.
		 */
		Vector3 vector;

		/**
		 * Default constructor.
		 */
		Quaternion();

		/**
		 * Overloaded constructor.
		 *
		 * @param w
		 *   Constant.
		 * @param x
		 *   X component of the vector part.
		 * @param y
		 *   Y component of the vector part.
		 * @param z
		 *   Z component of the vector part.
		 */
		Quaternion(const float w, const float x, const float y, const float z);

		/**
		 * Overloaded constructor.
		 *
		 * @param w
		 *   Constant.
		 * @param vector
		 *   Vector part.
		 */
		Quaternion(const float w, const Vector3& vector);

		/**
		 * Overloaded constructor.
		 *
		 * @param matrix
		 *   4 x 4 rotation matrix.
		 */
		explicit Quaternion(const Matrix4& matrix);

		/**
		 * Copy constructor.
		 */
		Quaternion(const Quaternion& quaternion);

		/**
		 * Destructor.
		 */
		~Quaternion();

		/**
		 * Gets the length.
		 */
		float length() const;

		/**
		 * Indicates whether the quaternion is unit quaternion.
		 */
		bool isUnitQuaternion() const;

		/**
		 * Calculates the conjugate quaternion.
		 *
		 * @return
		 *   Conjugate quaternion.
		 */
		Quaternion conjugate() const;

		/**
		 * Calculates the dot product of two quaternions.
		 *
		 * @param quaternion
		 *   Other quaternion.
		 * @return
		 *   Dot product.
		 */
		float dot(const Quaternion& quaternion) const;

		/**
		 * Calculates the inverse quaternion.
		 *
		 * @return
		 *   Inverse quaternion.
		 */
		Quaternion inverse() const;

		/**
		 * Calculates the unit quaternion.
		 *
		 * @return
		 *   Unit quaternion.
		 */
		Quaternion normal() const;

		/**
		 * Rotates a vector.
		 *
		 * @param vector
		 *   Vector to rotate.
		 * @return
		 *   Rotated vector.
		 */
		Vector3 rotate(const Vector3& vector) const;

		/**
		 * Gets a quaternion representing zero degree rotation.
		 */
		static Quaternion identity();

		/**
		 * Creates a rotation quaternion for the x axis.
		 *
		 * @param angle
		 *   Angle in radians.
		 * @return
		 *   Rotation quaternion.
		 */
		static Quaternion createRotationX(const float angle);
		
		/**
		 * Creates a rotation quaternion for the y axis.
		 *
		 * @param angle
		 *   Angle in radians.
		 * @return
		 *   Rotation quaternion.
		 */
		static Quaternion createRotationY(const float angle);

		/**
		 * Creates a rotation quaternion for the z axis.
		 *
		 * @param angle
		 *   Angle in radians.
		 * @return
		 *   Rotation quaternion.
		 */
		static Quaternion createRotationZ(const float angle);

		/**
		 * Creates a rotation quaternion for specified axis.
		 *
		 * @param axis
		 *   Unit vector representing rotational axis.
		 * @param angle
		 *   Angle in radians.
		 * @return
		 *   Rotation quaternion.
		 */
		static Quaternion createRotationAxis(const Vector3& axis, const float angle);

		/**
		 * Calculates an interpolated quaternion between two quaternions using spherical linear interpolation.
		 *
		 * @param quaternionA
		 *   Quaternion A.
		 * @param quaternionB
		 *   Quaternion B.
		 * @param weight
		 *   Weighting factor. Must be in range of 0.0f to 1.0f.
		 * @return
		 *   Interpolated quaternion.
		 */
		static Quaternion slerp(const Quaternion& quaternionA, const Quaternion& quaternionB, const float weight);

		/**
		 * Addition operator overload.
		 */
		Quaternion operator +(const Quaternion& quaternion) const;

		/**
		 * Subtraction operator overload.
		 */
		Quaternion operator -(const Quaternion& quaternion) const;

		/**
		 * Multiplication operator overload.
		 */
		Quaternion operator *(const Quaternion& quaternion) const;

		/**
		 * Assignment operator overload.
		 */
		Quaternion operator =(const Quaternion& quaternion);

		/**
		 * Assignment addition operator overload.
		 */
		const Quaternion operator +=(const Quaternion& quaternion);

		/**
		 * Assignment subtraction operator overload.
		 */
		const Quaternion operator -=(const Quaternion& quaternion);

		/**
		 * Assignment multiplication operator overload;
		 */
		const Quaternion operator *=(const Quaternion& quaternion);

		/**
		 * Equal operator overload.
		 */
		bool operator ==(const Quaternion& quaternion) const;

		/**
		 * Not equal operator overload.
		 */
		bool operator !=(const Quaternion& quaternion) const;

		/**
		 * Unary negation operator overload.
		 */
		Quaternion operator -();

		/**
		 * Scalar division operator overload.
		 */
		Quaternion operator /(const float scalar) const;

		/**
		 * Assignment scalar division operator overload.
		 */
		const Quaternion& operator /=(const float scalar);

		/**
		 * Scalar multiplication operator overload.
		 */
		friend Quaternion operator *(const Quaternion& quaternion, const float scalar);
		friend Quaternion operator *(const float scalar, const Quaternion& quaternion);

		/**
		 * Assignment scalar multiplication operator overload.
		 */
		friend const Quaternion& operator *=(Quaternion& quaternion, const float scalar);

		/**
		 * Ostream output overload.
		 */
		friend std::ostream& operator <<(std::ostream& output, const Quaternion& quaternion);
	};
}

#endif