/**
 * @file Vector2.h
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

#ifndef DEVMATH_VECTOR2_H
#define DEVMATH_VECTOR2_H

#include <iostream>

namespace devmath
{
	class Matrix3;
	class Matrix4;
	class Quaternion;
	
	/**
	 * Two component column vector.
	 */
	class Vector2
	{
	public:

		/**
		 * Number of components.
		 */
		static const unsigned int COMPONENTS = 2;

		/**
		 * X component.
		 */
		float x;

		/**
		 * Y component.
		 */
		float y;

		/**
		 * Default constructor.
		 */
		Vector2();

		/**
		 * Overloaded constructor.
		 *
		 * @param value
		 *   Value of all components.
		 */
		explicit Vector2(const float value);

		/**
		 * Overloaded constructor.
		 *
		 * @param x
		 *   X component.
		 * @param y
		 *   Y component.
		 */
		Vector2(const float x, const float y);

		/**
		 * Copy constructor.
		 */
		Vector2(const Vector2& vector);

		/**
		 * Destructor.
		 */
		~Vector2();

		/**
		 * Gets the length.
		 */
		float length() const;

		/**
		 * Indicates whether the vector is unit vector.
		 */
		bool isUnitVector() const;

		/**
		 * Calculates the distance between two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Distance.
		 */
		float distance(const Vector2& vector) const;

		/**
		 * Calculates the dot product of two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Dot product.
		 */
		float dot(const Vector2& vector) const;

		/**
		 * Gets a vector with larger components from two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Vector with larger components.
		 */
		Vector2 maximum(const Vector2& vector) const;

		/**
		 * Gets a vector with smaller components from two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Vector with smaller components.
		 */
		Vector2 minimum(const Vector2& vector) const;

		/**
		 * Calculates the unit vector.
		 *
		 * @return
		 *   Unit vector.
		 */
		Vector2 normal() const;

		/**
		 * Transforms the vector using transform matrix.
		 *
		 * @param transform
		 *   3 x 3 transform matrix.
		 * @return
		 *   Transformed vector.
		 */
		Vector2 transform(const Matrix3& transform) const;

		/**
		 * Transforms the vector using transform matrix.
		 *
		 * @param transform
		 *   4 x 4 transform matrix.
		 * @return
		 *   Transformed vector.
		 */
		Vector2 transform(const Matrix4& transform) const;

		/**
		 * Rotates the vector using rotation quaternion.
		 *
		 * @param quaternion
		 *   Rotation quaternion.
		 * @return
		 *   Rotated vector.
		 */
		Vector2 transform(const Quaternion& quaternion) const;

		/**
		 * Gets a zero vector.
		 */
		static Vector2 zero();

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
		static Vector2 lerp(const Vector2& vectorA, const Vector2& vectorB, const float weight);

		/**
		 * Addition operator overload.
		 */
		Vector2 operator +(const Vector2& vector) const;

		/**
		 * Subtraction operator overload.
		 */
		Vector2 operator -(const Vector2& vector) const;

		/**
		 * Assignment operator overload.
		 */
		Vector2& operator =(const Vector2& vector);

		/**
		 * Assignment addition operator overload.
		 */
		const Vector2& operator +=(const Vector2& vector);
	
		/**
		 * Assignment subtraction operator overload.
		 */
		const Vector2& operator -=(const Vector2& vector);

		/**
		 * Equal operator overload.
		 */
		bool operator ==(const Vector2& vector) const;

		/**
		 * Not equal operator overload.
		 */
		bool operator !=(const Vector2& vector) const;

		/**
		 * Unary negation operator overload.
		 */
		Vector2 operator -() const;

		/**
		 * Scalar division operator overload.
		 */
		Vector2 operator /(const float scalar) const;

		/**
		 * Assignment scalar division operator overload.
		 */
		const Vector2& operator /=(const float scalar);

		/**
		 * Subscript operator overload.
		 */
		float& operator [](const unsigned int index);
		const float& operator [](const unsigned int index) const;

		/**
		 * Scalar multiplication operator overload.
		 */
		friend Vector2 operator *(const Vector2& vector, const float scalar);
		friend Vector2 operator *(const float scalar, const Vector2& vector);

		/**
		 * Assignment scalar multiplication operator overload.
		 */
		friend const Vector2& operator *=(Vector2& vector, const float scalar);

		/**
		 * Ostream output overload.
		 */
		friend std::ostream& operator <<(std::ostream& output, const Vector2& vector);
	};
}

#endif