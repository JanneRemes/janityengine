/**
 * @file Point.cpp
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

#include <devmath/Point.h>
#include <devmath/Utils.h>

using namespace devmath;
using namespace std;

Point::Point() { }

Point::Point(const int value)
	: x(value),
	  y(value) { }

Point::Point(const int x, const int y)
	: x(x),
	  y(y) { }

Point::Point(const Point& point)
	: x(point.x),
	  y(point.y) { }

Point::~Point() { }


// Public

Point Point::maximum(const Point& point) const
{
	const int _x = devmath::maximum(x, point.x);
	const int _y = devmath::maximum(y, point.y);

	return Point(_x, _y);
}

Point Point::minimum(const Point& point) const
{
	const int _x = devmath::minimum(x, point.x);
	const int _y = devmath::minimum(y, point.y);
	
	return Point(_x, _y);
}

// Static

Point Point::zero()
{
	return Point(0, 0);
}

// Operators

Point& Point::operator =(const Point& point)
{
	if(this != &point)
	{
		x = point.x;
		y = point.y;
	}

	return *this;
}

bool Point::operator ==(const Point& point) const
{
	return x == point.x && y == point.y;
}

bool Point::operator !=(const Point& point) const
{
	return !(*this == point);
}

// Friends

namespace devmath
{
	ostream& operator <<(ostream& output, const Point& point)
	{
		output << "[X: " << point.x << ", Y: " << point.y << "]";
		return output;
	}
}