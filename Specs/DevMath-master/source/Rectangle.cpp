/**
 * @file Rectangle.cpp
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

#include <devmath/Rectangle.h>
#include <devmath/Utils.h>

using namespace devmath;
using namespace std;

Rectangle::Rectangle() { }

Rectangle::Rectangle(const int x, const int y, const int width, const int height)
	: x(x),
	  y(y),
	  width(width),
	  height(height) { }

Rectangle::Rectangle(const Point& position, const Point& dimensions)
	: x(position.x),
	  y(position.y),
	  width(dimensions.x),
	  height(dimensions.y) { }

Rectangle::Rectangle(const Rectangle& rectangle)
	: x(rectangle.x),
	  y(rectangle.y),
	  width(rectangle.width),
	  height(rectangle.height) { }

Rectangle::~Rectangle() { }


// Public

int Rectangle::left() const
{
	return x;
}

int Rectangle::right() const
{
	return x + width;
}

int Rectangle::top() const
{
	return y;
}

int Rectangle::bottom() const
{
	return y + height;
}

Point Rectangle::topLeft() const
{
	return Point(left(), top());
}

Point Rectangle::bottomRight() const
{
	return Point(right(), bottom());
}

bool Rectangle::isEmpty() const
{
	return *this == empty();
}

Rectangle Rectangle::combine(const Rectangle& rectangle) const
{
	const Point position = topLeft().minimum(rectangle.topLeft());
	const Point rightBottom = bottomRight().maximum(rectangle.bottomRight());

	const int _width = rightBottom.x - position.x;
	const int _height = rightBottom.y - position.y;

	return Rectangle(position.x, position.y, _width, _height);
}

bool Rectangle::contains(const int x, const int y) const
{
	return x >= left() && x <= right() && y >= top() && y <= bottom();
}

bool Rectangle::contains(const Point& point) const
{
	return contains(point.x, point.y);
}

void Rectangle::inflate(const int amountX, const int amountY)
{
	width += amountX;
	height += amountY;
}

void Rectangle::inflate(const Point& amount)
{
	return inflate(amount.x, amount.y);
}

bool Rectangle::intersects(const Rectangle& rectangle) const
{
	return !(left() > rectangle.right() || right() < rectangle.left() ||
		top() > rectangle.bottom() || bottom() < rectangle.top());
}

void Rectangle::offset(const int amountX, const int amountY)
{
	x += amountX;
	y += amountY;
}

void Rectangle::offset(const Point& amount)
{
	return offset(amount.x, amount.y);
}

// Static

Rectangle Rectangle::empty()
{
	return Rectangle(0, 0, 0, 0);
}

// Operators

Rectangle& Rectangle::operator =(const Rectangle& rectangle)
{
	if(this != &rectangle)
	{
		x = rectangle.x;
		y = rectangle.y;
		width = rectangle.width;
		height = rectangle.height;
	}

	return *this;
}

bool Rectangle::operator ==(const Rectangle& rectangle) const
{
	return x == rectangle.x && y == rectangle.y && width == rectangle.width && height == rectangle.height;
}

bool Rectangle::operator !=(const Rectangle& rectangle) const
{
	return !(*this == rectangle);
}

namespace devmath
{
	ostream& operator <<(ostream& output, const Rectangle& rectangle)
	{
		output << "[X: " << rectangle.x << ", Y: " << rectangle.y
			<< ", W: " << rectangle.width << ", H: " << rectangle.height << "]";
			
		return output;
	}
}