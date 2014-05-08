#include <Point.h>
#include <MathUtils.h>
using namespace JanityMath;

Point::Point() : x(0), y(0){}
Point::Point(float X, float Y) : x(X), y(Y){}
Point::~Point(){}
Point::Point(const Point& other) : x(other.x), y(other.y){}

// Public

Point Point::maximum(const Point& point) const
{
	const int _x = JanityMath::maximum(x, point.x);
	const int _y = JanityMath::maximum(y, point.y);

	return Point(_x, _y);
}

Point Point::minimum(const Point& point) const
{
	const int _x = JanityMath::minimum(x, point.x);
	const int _y = JanityMath::minimum(y, point.y);

	return Point(_x, _y);
}

// Static
Point Point::zero()
{
	return Point(0, 0);
}
// Operators
Point& Point::operator= (const Point& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
}
Point& Point::operator+= (const Point& rhs)
{
	this->x = this->x + rhs.x;
	this->y = this->y + rhs.y;
}
Point& Point::operator+ (const Point& rhs)
{
	return operator+=(rhs);
}
Point& Point::operator+= (int value)
{
	this->x = this->x + value;
	this->y = this->y + value;
}
Point& Point::operator+ (int value)
{
	return operator+(value);
}
Point& Point::operator-= (int value)
{
	this->x = this->x- value;
	this->y = this->y - value;
}
Point& Point::operator- (int value)
{
	return operator-=(value);
}
Point& Point::operator*= (int scalar)
{
	this->x = this->x * scalar;
	this->y = this->y * scalar;
}
Point& Point::operator* (int scalar)
{
	return operator*=(scalar);
}
Point& Point::operator/= (int divisor)
{
	if(divisor!=0)
	{
		this->x = this->x / divisor;
		this->y = this->y / divisor;
	}
	else
	{
		std::printf("Error: Point/= 0");
	}
}
Point& Point::operator/ (int divisor)
{
	return operator/=(divisor);
}

bool operator== (const Point& lhs, const Point& rhs)
{
	float x = lhs.x;

	if(lhs.x == rhs.x && lhs.y == rhs.y)
		return true;
	else
		return false;
}
bool operator!= (const Point& lhs, const Point& rhs)
{
	if(lhs.x == rhs.x && lhs.y == rhs.y)
		return false;
	else
		return true;
}

std::ostream& operator<< (std::ostream& output, const Point& point)
{
	return output << "[" << point.x << "," << point.y << "]";
}
