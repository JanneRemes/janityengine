/**
 * @file Utils.cpp
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

#include <devmath/Utils.h>

#include <cmath>
#include <cstdlib>
#include <ctime>

namespace devmath
{
	const double TO_RADIANS_FACTOR = PI / 180.0;
	const double TO_DEGREES_FACTOR = 180.0 / PI;

	double clamp(const double value, const double min, const double max)
	{
		if(value < min)
			return min;
		else if(value > max)
			return max;
		else
			return value;
	}

	float clamp(const float value, const float min, const float max)
	{
		if(value < min)
			return min;
		else if(value > max)
			return max;
		else
			return value;
	}

	int clamp(const int value, const int min, const int max)
	{
		if(value < min)
			return min;
		else if(value > max)
			return max;
		else
			return value;
	}

	Matrix4 createOrthographicProjection(const float left, const float right, const float top, const float bottom, const float nearZ, const float farZ)
	{
		const float width = right - left;
		const float height = bottom - top;
		const float depth = farZ - nearZ;

		return Matrix4
		(
			 2.0f / width,			  0.0f,						 0.0f,					 0.0f,
			 0.0f,					  2.0f / -height,			 0.0f,					 0.0f,
			 0.0f,					  0.0f,						-2.0f / depth,			 0.0f,
			-(left + right) / width, -(top + bottom) / -height, -(nearZ + farZ) / depth, 1.0f
		);
	}

	Matrix4 createOrthographicProjection(const Rectangle& viewport, const float nearZ, const float farZ)
	{
		const float left = (float)viewport.left();
		const float right = (float)viewport.right();
		const float top = (float)viewport.top();
		const float bottom = (float)viewport.bottom();

		return createOrthographicProjection(left, right, top, bottom, nearZ, farZ);
	}

	Matrix4 createPerspectiveProjection(const float left, const float right, const float top, const float bottom, const float nearZ, const float farZ)
	{
		const float width = right - left;
		const float height = bottom - top;
		const float depth = farZ - nearZ;

		return Matrix4
		(
			2.0f * nearZ / width,	0.0f,					   0.0f,						 0.0f,
			0.0f,					2.0f * nearZ / -height,	   0.0f,						 0.0f,
			(left + right) / width, (top + bottom) / -height, -(nearZ + farZ) / depth,		-1.0f,
			0.0f,					0.0f,					  -2.0f * nearZ * farZ / depth,	 0.0f
		);
	}

	Matrix4 createPerspectiveProjection(const float aspectRatio, const float fieldOfViewY, const float nearZ, const float farZ)
	{
		const float top = nearZ * tanf(fieldOfViewY / 2.0f);
		const float bottom = -top;
		const float right = aspectRatio * top;
		const float left = -right;

		return createPerspectiveProjection(left, right, top, bottom, nearZ, farZ);
	}

	bool equals(const double valueA, const double valueB, const double threshold)
	{
		return fabs(valueA - valueB) <= threshold;
	}

	bool equals(const float valueA, const float valueB, const float threshold)
	{
		return fabsf(valueA - valueB) <= threshold;
	}

	void initializeRandom(unsigned int seed)
	{
		if(seed == 0)
			seed = (unsigned int)time(NULL);
			
		srand(seed);
	}

	double maximum(const double valueA, const double valueB)
	{
		if(valueA >= valueB)
			return valueA;
		else
			return valueB;
	}

	float maximum(const float valueA, const float valueB)
	{
		if(valueA >= valueB)
			return valueA;
		else
			return valueB;
	}

	int maximum(const int valueA, const int valueB)
	{
		if(valueA >= valueB)
			return valueA;
		else
			return valueB;
	}

	double minimum(const double valueA, const double valueB)
	{
		if(valueA <= valueB)
			return valueA;
		else
			return valueB;
	}

	float minimum(const float valueA, const float valueB)
	{
		if(valueA <= valueB)
			return valueA;
		else
			return valueB;
	}

	int minimum(const int valueA, const int valueB)
	{
		if(valueA <= valueB)
			return valueA;
		else
			return valueB;
	}

	double random()
	{
		return (double)rand() / RAND_MAX;
	}

	double random(const double min, const double max)
	{
		return random() * (max - min) + min;
	}

	int random(const int min, const int max)
	{
		const double randomValue = random() * (max - min) + min;
		return (int)round(randomValue);
	}

	double round(const double value)
	{
		const double floorValue = floor(value);
		
		if(value - floorValue < 0.5)
			return floorValue;
		else
			return ceil(value);
	}

	float round(const float value)
	{
		const float floorValue = floorf(value);
		
		if(value - floorValue < 0.5f)
			return floorValue;
		else
			return ceilf(value);
	}

	int sign(const double value)
	{
		if(equals(value, 0.0))
			return 0;
		else
			return (int)(fabs(value) / value);
	}

	int sign(const float value)
	{
		if(equals(value, 0.0f))
			return 0;
		else
			return (int)(fabsf(value) / value);
	}

	int sign(const int value)
	{
		if(value == 0)
			return 0;
		else
			return abs(value) / value;
	}

	double toDegrees(const double angle)
	{
		return TO_DEGREES_FACTOR * angle;
	}

	float toDegrees(const float angle)
	{
		return (float)TO_DEGREES_FACTOR * angle;
	}

	double toRadians(const double angle)
	{
		return TO_RADIANS_FACTOR * angle;
	}

	float toRadians(const float angle)
	{
		return (float)TO_RADIANS_FACTOR * angle;
	}
}