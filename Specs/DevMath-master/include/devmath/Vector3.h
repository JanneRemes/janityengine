/**
 * @file Vector3.h
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

#ifndef DEVMATH_VECTOR3_H
#define DEVMATH_VECTOR3_H

#include <iostream>
#include <devmath/Vector2.h>

namespace devmath
{
	class Matrix4;
	class Quaternion;

	/**
	 * Three component column vector.
	 */
	class Vector3
	{
	public:

		/**
		 * Number of components.
		 */
		static const unsigned int COMPONENTS = 3;

		/**
		 * X component.
		 */
		float x;
		
		/**
		 * Y component.
		 */
		float y;
		
		/**
		 * Z component.
		 */
		float z;

		/**
		 * Default constructor.
		 */
		Vector3();

		/**
		 * Overloaded constructor.
		 *
		 * @param value
		 *   Value of all components.
		 */
		explicit Vector3(const float value);

		/**
		 * Overloaded constructor.
		 *
		 * @param x
		 *   X component.
		 * @param y
		 *   Y component.
		 * @param z
		 *   Z component.
		 */
		Vector3(const float x, const float y, const float z);

		/**
		 * Overloaded constructor.
		 *
		 * @param vector
		 *   Two component vector.
		 * @param z
		 *   Z component.
		 */
		Vector3(const Vector2& vector, const float z);

		/**
		 * Copy constructor.
		 */
		Vector3(const Vector3& vector);

		/**
		 * Destructor.
		 */
		~Vector3();

		/**
		 * Gets the length.
		 */
		float length() const;

		/**
		 * Gets a two component vector representing X and Y components.
		 */
		Vector2 xy() const;

		/**
		 * Indicates whether the vector is unit vector.
		 */
		bool isUnitVector() const;

		/**
		 * Calculates the cross product of two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Cross product.
		 */
		Vector3 cross(const Vector3& vector) const;
		
		/**
		 * Calculates the distance between two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Distance.
		 */
		float distance(const Vector3& vector) const;

		/**
		 * Calculates the dot product of two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Dot product.
		 */
		float dot(const Vector3& vector) const;

		/**
		 * Gets a vector with larger components from two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Vector with larger components.
		 */
		Vector3 maximum(const Vector3& vector) const;

		/**
		 * Gets a vector with smaller components from two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Vector with smaller components.
		 */
		Vector3 minimum(const Vector3& vector) const;

		/**
		 * Calculates the unit vector.
		 *
		 * @return
		 *   Unit vector.
		 */
		Vector3 normal() const;

		/**
		 * Transforms the vector using transform matrix.
		 *
		 * @param transform
		 *   4 x 4 transform matrix.
		 * @return
		 *   Transformed vector.
		 */
		Vector3 transform(const Matrix4& transform) const;

		/**
		 * Rotates the vector using rotation quaternion.
		 *
		 * @param quaternion
		 *   Rotation quaternion.
		 * @return
		 *   Rotated vector.
		 */
		Vector3 transform(const Quaternion& quaternion) const;

		/**
		 * Gets a zero vector.
		 */
		static Vector3 zero();

		/**
		 * Calculates an interpolated vector between two vectors using linear interpolation.
		 *
		 * @param vectorA
		 *   Vector A.
		 * @param vectorB
		 *   Vector B.
		 * @param weight
		 *   Weighting factor. Must be in range of 0.0f to 1.0f.
		 * @return
		 *   Interpolated vector.
		 */
		static Vector3 lerp(const Vector3& vectorA, const Vector3& vectorB, const float weight);

		/**
		 * Addition operator overload.
		 */
		Vector3 operator +(const Vector3& vector) const;

		/**
		 * Subtraction operator overload.
		 */
		Vector3 operator -(const Vector3& vector) const;

		/**
		 * Assignment operator overload.
		 */
		Vector3& operator =(const Vector3& vector);

		/**
		 * Assignment addition operator overload.
		 */
		const Vector3& operator +=(const Vector3& vector);
	
		/**
		 * Assignment subtraction operator overload.
		 */
		const Vector3& operator -=(const Vector3& vector);

		/**
		 * Equal operator overload.
		 */
		bool operator ==(const Vector3& vector) const;

		/**
		 * Not equal operator overload.
		 */
		bool operator !=(const Vector3& vector) const;

		/**
		 * Unary negation operator overload.
		 */
		Vector3 operator -() const;

		/**
		 * Scalar division operator overload.
		 */
		Vector3 operator /(const float scalar) const;

		/**
		 * Assignment scalar division operator overload.
		 */
		const Vector3& operator /=(const float scalar);

		/**
		 * Subscript operator overload.
		 */
		float& operator [](const unsigned int index);
		const float& operator [](const unsigned int index) const;

		/**
		 * Scalar multiplication operator overload.
		 */
		friend Vector3 operator *(const Vector3& vector, const float scalar);
		friend Vector3 operator *(const float scalar, const Vector3& vector);

		/**
		 * Assignment scalar multiplication operator overload.
		 */
		friend const Vector3& operator *=(Vector3& vector, const float scalar);

		/**
		 * Ostream output overload.
		 */
		friend std::ostream& operator <<(std::ostream& output, const Vector3& vector);
	};
}

#endif