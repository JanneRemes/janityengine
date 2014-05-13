#include <JanityMath\Rectangle.h>
#include <JanityMath\MathUtils.h>

using namespace JanityMath;

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
	return !(left() > rectangle.right() ||
			 right() < rectangle.left() ||
			 top() > rectangle.bottom() ||
			 bottom() < rectangle.top());
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
	return x == rectangle.x &&
		   y == rectangle.y &&
		   width == rectangle.width &&
		   height == rectangle.height;
}

bool Rectangle::operator !=(const Rectangle& rectangle) const
{
	return !(*this == rectangle);
}

namespace JanityMath
{
	std::ostream& operator <<(std::ostream& output, const Rectangle& rectangle)
	{
		output << "[X: " << rectangle.x << ", Y: " << rectangle.y
			<< ", W: " << rectangle.width << ", H: " << rectangle.height << "]";
			
		return output;
	}
}