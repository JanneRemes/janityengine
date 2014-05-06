/**
 * @file Rectangle.h
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

#ifndef DEVMATH_RECTANGLE_H
#define DEVMATH_RECTANGLE_H

#include <iostream>
#include <devmath/Point.h>

namespace devmath
{
	/**
	 * 2D rectangle.
	 */
	class Rectangle
	{
	public:

		/**
		 * X coordinate.
		 */
		int x;
		
		/**
		 * Y coordinate.
		 */
		int y;
		
		/**
		 * Width.
		 */
		int width;

		/**
		 * Height.
		 */
		int height;

		/**
		 * Default constructor.
		 */
		Rectangle();

		/**
		 * Overloaded constructor.
		 *
		 * @param x
		 *   X coordinate.
		 * @param y
		 *   Y coordinate.
		 * @param width
		 *   Width.
		 * @param height
		 *   Height.
		 */
		Rectangle(const int x, const int y, const int width, const int height);

		/**
		 * Overloaded constructor.
		 *
		 * @param position
		 *   Position.
		 * @param dimensions
		 *   Dimensions.
		 */
		Rectangle(const Point& position, const Point& dimensions);

		/**
		 * Copy constructor.
		 */
		Rectangle(const Rectangle& rectangle);

		/**
		 * Destructor.
		 */
		~Rectangle();
	
		/**
		 * Gets the left bound.
		 */
		int left() const;
	
		/**
		 * Gets the right bound.
		 */
		int right() const;
	
		/**
		 * Gets the top bound.
		 */
		int top() const;
	
		/**
		 * Gets the bottom bound.
		 */
		int bottom() const;

		/**
		 * Gets the top left corner.
		 */
		Point topLeft() const;

		/**
		 * Gets the bottom right corner.
		 */
		Point bottomRight() const;

		/**
		 * Indicates whether the rectangle is empty.
		 */
		bool isEmpty() const;

		/**
		 * Creates a rectangle containing two rectangles.
		 *
		 * @param rectangle
		 *   Other rectangle.
		 * @return
		 *   Combined rectangle.
		 */
		Rectangle combine(const Rectangle& rectangle) const;

		/**
		 * Checks whether the rectangle contains a point.
		 *
		 * @param x
		 *   X coordinate of the point.
		 * @param y
		 *   Y coordinate of the point.
		 * @return
		 *   Indicates whether the point is inside the rectangle.
		 */
		bool contains(const int x, const int y) const;

		/**
		 * Checks whether the rectangle contains a point.
		 *
		 * @param point
		 *   Point.
		 * @return
		 *   Indicates whether the point is inside the rectangle.
		 */
		bool contains(const Point& point) const;

		/**
		 * Adjusts the size of the rectangle by specified amount.
		 *
		 * @param x
		 *   Amount in X direction.
		 * @param y
		 *   Amount in Y direction. 
		 */
		void inflate(const int amountX, const int amountY);

		/**
		 * Adjusts the size of the rectangle by specified amount.
		 *
		 * @param amount
		 *   Amount.
		 */
		void inflate(const Point& amount);

		/**
		 * Checks whether two rectangles intersect each other.
		 *
		 * @param rectangle
		 *   Other rectangle.
		 * @return bool
		 *   Indicates whether the rectangles intersect.
		 */
		bool intersects(const Rectangle& rectangle) const;

		/**
		 * Adjusts the location of the rectangle by specified amount.
		 *
		 * @param x
		 *   Amount in X direction.
		 * @param y
		 *   Amount in Y direction.
		 */
		void offset(const int amountX, const int amountY);
		
		/**
		 * Adjusts the location of the rectangle by specified amount.
		 *
		 * @param amount
		 *   Amount.
		 */
		void offset(const Point& amount);

		/**
		 * Gets an empty rectangle.
		 */
		static Rectangle empty();

		/**
		 * Assignment operator overload.
		 */
		Rectangle& operator =(const Rectangle& rectangle);

		/**
		 * Equal operator overload.
		 */
		bool operator ==(const Rectangle& rectangle) const;

		/**
		 * Not equal operator overload.
		 */
		bool operator !=(const Rectangle& rectangle) const;

		/**
		 * Ostream output overload.
		 */
		friend std::ostream& operator <<(std::ostream& output, const Rectangle& rectangle);
	};
}

#endif