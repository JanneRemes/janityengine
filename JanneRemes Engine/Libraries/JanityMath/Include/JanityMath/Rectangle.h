#ifndef JANITYMATH_RECTANGLE_H
#define JANITYMATH_RECTANGLE_H

#include <iostream>
#include <JanityMath\Point.h>

namespace JanityMath
{
	class Rectangle
	{
	public:
	//	Variables Start
		int x, y, width, height;
	//	Variables End

	//	Constructors Start
		Rectangle();
		Rectangle(const int x, const int y, const int width, const int height);
		Rectangle(const Point& position, const Point& dimensions);
		Rectangle(const Rectangle& rectangle);
		~Rectangle();
	//	Constructors End

	//	Methods Start
		int left() const;
		int right() const;
		int top() const;
		int bottom() const;

		Point topLeft() const;
		Point bottomRight() const;

		bool isEmpty() const;

		Rectangle combine(const Rectangle& rectangle) const;

		bool contains(const int x, const int y) const;
		bool contains(const Point& point) const;

		void inflate(const int amountX, const int amountY);
		void inflate(const Point& amount);

		bool intersects(const Rectangle& rectangle) const;

		void offset(const int amountX, const int amountY);
		void offset(const Point& amount);

		static Rectangle empty();
	//	Methods End
		
	//	Operators Start
		Rectangle& operator =(const Rectangle& rectangle);
		bool operator ==(const Rectangle& rectangle) const;
		bool operator !=(const Rectangle& rectangle) const;

		friend std::ostream& operator <<(std::ostream& output, const Rectangle& rectangle);
	//	Operators End
	};
}
#endif