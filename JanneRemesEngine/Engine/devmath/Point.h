/**
 * @file Point.h
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

#ifndef DEVMATH_POINT_H
#define DEVMATH_POINT_H

#include <iostream>

namespace devmath
{
	/**
	 * 2D point.
	 *
	 * Used with Rectangle.
	 */
	class Point
	{
	public:

		/**
		 * X component.
		 */
		int x;

		/**
		 * Y component.
		 */
		int y;

		/**
		 * Default constructor.
		 */
		Point();

		/**
		 * Overloaded constructor.
		 *
		 * @param value
		 *   Value for both components.
		 */
		explicit Point(const int value);

		/**
		 * Overloaded constructor.
		 *
		 * @param x
		 *   X component.
		 * @param y
		 *   Y component.
		 */
		Point(const int x, const int y);

		/**
		 * Copy constructor.
		 */
		Point(const Point& point);

		/**
		 * Destructor.
		 */
		~Point();

		/**
		 * Gets a point with larger components from two points.
		 *
		 * @param point
		 *   Other point.
		 * @return
		 *   Point with larger components.
		 */
		Point maximum(const Point& point) const;

		/**
		 * Gets a point with smaller components from two points.
		 *
		 * @param point
		 *   Other point.
		 * @return
		 *   Point with smaller components.
		 */
		Point minimum(const Point& point) const;

		/**
		 * Gets a zero point.
		 */
		static Point zero();

		/**
		 * Assignment operator overload.
		 */
		Point& operator =(const Point& point);

		/**
		 * Equal operator overload.
		 */
		bool operator ==(const Point& point) const;

		/**
		 * Not equal operator overload.
		 */
		bool operator !=(const Point& point) const;

		/**
		 * Ostream output overload.
		 */
		friend std::ostream& operator <<(std::ostream& output, const Point& point);
	};
}

#endif