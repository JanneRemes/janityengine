/**
 * @file Vector4.h
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

#ifndef DEVMATH_VECTOR4_H
#define DEVMATH_VECTOR4_H

#include <iostream>

#include <devmath/Vector2.h>
#include <devmath/Vector3.h>

namespace devmath
{
	class Quaternion;

	/**
	 * Four component column vector.
	 */
	class Vector4
	{
	public:

		/**
		 * Number of components.
		 */
		static const unsigned int COMPONENTS = 4;

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
		 * W component.
		 */
		float w;

		/**
		 * Default constructor.
		 */
		Vector4();

		/**
		 * Overloaded constructor.
		 *
		 * @param value
		 *   Value of all components.
		 */
		explicit Vector4(const float value);

		/**
		 * Overloaded constructor.
		 *
		 * @param x
		 *   X component.
		 * @param y
		 *   Y component.
		 * @param z
		 *   Z component.
		 * @param w
		 *   W component.
		 */
		Vector4(const float x, const float y, const float z, const float w);

		/**
		 * Overloaded constructor.
		 *
		 * @param vector
		 *   Two component vector.
		 * @param z
		 *   Z component.
		 * @param w
		 *   W component.
		 */
		Vector4(const Vector2& vector, const float z, const float w);

		/**
		 * Overloaded constructor.
		 *
		 * @param vector
		 *   Three component vector.
		 * @param w
		 *   W component.
		 */
		Vector4(const Vector3& vector, const float w);

		/**
		 * Copy constructor.
		 */
		Vector4(const Vector4& vector);

		/**
		 * Destructor.
		 */
		~Vector4();

		/**
		 * Gets the length.
		 */
		float length() const;

		/**
		 * Gets a two component vector representing X and Y components.
		 */
		Vector2 xy() const;

		/**
		 * Gets a three component vector representing X, Y and Z components.
		 */
		Vector3 xyz() const;

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
		float distance(const Vector4& vector) const;

		/**
		 * Calculates the dot product of two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Dot product.
		 */
		float dot(const Vector4& vector) const;

		/**
		 * Calculates a vector with larger values from two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Vector with larger values.
		 */
		Vector4 maximum(const Vector4& vector) const;

		/**
		 * Calculates a vector with smaller values from two vectors.
		 *
		 * @param vector
		 *   Other vector.
		 * @return
		 *   Vector with smaller values.
		 */
		Vector4 minimum(const Vector4& vector) const;

		/**
		 * Calculates the unit vector.
		 *
		 * @return
		 *   Unit vector.
		 */
		Vector4 normal() const;

		/**
		 * Rotates the vector using rotation quaternion.
		 *
		 * @param quaternion
		 *   Rotation quaternion.
		 * @return
		 *   Rotated vector.
		 */
		Vector4 transform(const Quaternion& quaternion) const;

		/**
		 * Gets a zero vector.
		 */
		static Vector4 zero();

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
		static Vector4 lerp(const Vector4& vectorA, const Vector4& vectorB, const float weight);

		/**
		 * Addition operator overload.
		 */
		Vector4 operator +(const Vector4& vector) const;

		/**
		 * Subtraction operator overload.
		 */
		Vector4 operator -(const Vector4& vector) const;

		/**
		 * Assignment operator overload.
		 */
		Vector4& operator =(const Vector4& vector);

		/**
		 * Assignment addition operator overload.
		 */
		const Vector4& operator +=(const Vector4& vector);
	
		/**
		 * Assignment subtraction operator overload.
		 */
		const Vector4& operator -=(const Vector4& vector);

		/**
		 * Equal operator overload.
		 */
		bool operator ==(const Vector4& vector) const;

		/**
		 * Not equal operator overload.
		 */
		bool operator !=(const Vector4& vector) const;

		/**
		 * Unary negation operator overload.
		 */
		Vector4 operator -() const;

		/**
		 * Scalar division operator overload.
		 */
		Vector4 operator /(const float scalar) const;

		/**
		 * Assignment scalar division operator overload.
		 */
		const Vector4& operator /=(const float scalar);

		/**
		 * Subscript operator overload.
		 */
		float& operator [](const unsigned int index);
		const float& operator [](const unsigned int index) const;

		/**
		 * Scalar multiplication operator overload.
		 */
		friend Vector4 operator *(const Vector4& vector, const float scalar);
		friend Vector4 operator *(const float scalar, const Vector4& vector);

		/**
		 * Assignment scalar multiplication operator overload.
		 */
		friend const Vector4& operator *=(Vector4& vector, const float scalar);

		/**
		 * Ostream output overload.
		 */
		friend std::ostream& operator <<(std::ostream& output, const Vector4& vector);
	};
}

#endif