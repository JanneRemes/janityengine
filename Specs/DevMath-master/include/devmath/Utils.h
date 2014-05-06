/**
 * @file Utils.h
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

#ifndef UTILS_H
#define UTILS_H

#include <devmath/Matrix4.h>
#include <devmath/Rectangle.h>

namespace devmath
{
	/**
	 * Approximation of pi to 16 decimals.
	 */
	const double PI = 3.1415926535897932;

	/**
	 * Clamps a value between minimum and maximum.
	 *
	 * @param value
	 *   Value to clamp.
	 * @param min
	 *   Minimum value.
	 * @param max
	 *   Maximum value.
	 * @return
	 *   Clamped value.
	 */
	double clamp(const double value, const double min, const double max);
	float clamp(const float value, const float min, const float max);
	int clamp(const int value, const int min, const int max);

	/**
	 * Creates an orthographic projection.
	 *
	 * @param left
	 *   Left coordinate.
	 * @param right
	 *   Right coordinate.
	 * @param top
	 *   Top coordinate.
	 * @param bottom
	 *   Bottom coordinate.
	 * @param nearZ
	 *   Near Z coordinate.
	 * @param farZ
	 *   Far Z coordinate.
	 * @return
	 *   Projection matrix.
	 */
	Matrix4 createOrthographicProjection(const float left, const float right, const float top, const float bottom, const float nearZ, const float farZ);

	/**
	 * Creates an orthographic projection.
	 *
	 * @param viewport
	 *   Rectangle viewport.
	 * @param nearZ
	 *   Near Z coordinate.
	 * @param farZ
	 *   Far Z coordinate.
	 * @return
	 *   Projection matrix.
	 */
	Matrix4 createOrthographicProjection(const Rectangle& viewport, const float nearZ, const float farZ);

	/**
	 * Creates a perspective projection.
	 *
	 * @param left
	 *   Left coordinate.
	 * @param right
	 *   Right coordinate.
	 * @param top
	 *   Top coordinate.
	 * @param bottom
	 *   Bottom coordinate.
	 * @param nearZ
	 *   Near Z coordinate.
	 * @param farZ
	 *   Far Z coordinate.
	 * @return
	 *   Projection matrix.
	 */
	Matrix4 createPerspectiveProjection(const float left, const float right, const float top, const float bottom, const float nearZ, const float farZ);

	/**
	 * Creates a perspective projection.
	 *
	 * @param aspectRatio
	 *   Aspect ratio of the projection.
	 * @param fieldOfViewY
	 *   Vertical field of view angle in radians.
	 * @param nearZ
	 *   Near Z coordinate.
	 * @param farZ
	 *   Far Z coordinate.
	 * @return
	 *   Projection matrix.
	 */
	Matrix4 createPerspectiveProjection(const float aspectRatio, const float fieldOfViewY, const float nearZ, const float farZ);

	/**
	 * Safely compares the equality of two floating point values.
	 *
	 * @param valueA
	 *   First value.
	 * @param valueB
	 *   Second value.
	 * @param threshold
	 *   Comparing threshold.
	 * @return
	 *   Indicates whether the values are (nearly) equal.
	 */
	bool equals(const double valueA, const double valueB, const double threshold = 0.001);
	bool equals(const float valueA, const float valueB, const float threshold = 0.001f);

	/**
	 * Initializes the pseudo-random number generator.
	 *
	 * @param seed
	 *   Seed to use in initialization. If the seed is 0, current time will be used.
	 */
	void initializeRandom(unsigned int seed = 0);

	/**
	 * Gets the larger value of two values.
	 *
	 * @param valueA
	 *   First value.
	 * @param valueB
	 *   Second value.
	 * @return
	 *   Larger value.
	 */
	double maximum(const double valueA, const double valueB);
	float maximum(const float valueA, const float valueB);
	int maximum(const int valueA, const int valueB);

	/**
	 * Gets the smaller value of two values.
	 *
	 * @param valueA
	 *   First value.
	 * @param valueB
	 *   Second value.
	 * @return
	 *   Smaller value.
	 */
	double minimum(const double valueA, const double valueB);
	float minimum(const float valueA, const float valueB);
	int minimum(const int valueA, const int valueB);

	/**
	 * Gets a pseudo random floating point value between 0.0 and 1.0.
	 *
	 * It is recommended to seed the random number generator with initializeRandom before calling this function.
	 *
	 * @return
	 *   Pseudo random value.
	 */
	double random();

	/**
	 * Gets a pseudo random floating point value between minimum and maximum values (inclusive).
	 *
	 * It is recommended to seed the random number generator with initializeRandom before calling this function.
	 *
	 * @param min
	 *   Minimum value.
	 * @param max
	 *   Maximum value.
	 * @return
	 *   Pseudo random value.
	 */
	double random(const double min, const double max);

	/**
	 * Gets a pseudo random integer between minimum and maximum values (inclusive).
	 *
	 * It is recommended to seed the random number generator with initializeRandom before calling this function.
	 *
	 * @param min
	 *   Minimum value.
	 * @param max
	 *   Maximum value.
	 * @return
	 *   Pseudo random value.
	 */
	int random(const int min, const int max);

	/**
	 * Rounds a floating point value.
	 *
	 * @param value
	 *   Value to round.
	 * @return
	 *   Rounded value.
	 */
	double round(const double value);
	float round(const float value);

	/**
	 * Gets the sign of a value.
	 *
	 * @param value
	 *   Value.
	 * @return
	 *   Sign of the value: -1, 0 or 1.
	 */
	int sign(const double value);
	int sign(const float value);
	int sign(const int value);

	/**
	 * Converts radians to degrees.
	 *
	 * @param angle
	 *   Angle in radians.
	 * @return
	 *   Angle in degrees.
	 */
	double toDegrees(const double angle);
	float toDegrees(const float angle);

	/**
	 * Converts degrees to radians.
	 *
	 * @param angle
	 *   Angle in degrees.
	 * @return
	 *   Angle in radians.
	 */
	double toRadians(const double angle);
	float toRadians(const float angle);
}

#endif