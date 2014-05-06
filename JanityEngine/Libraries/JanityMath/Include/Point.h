#ifndef POINT_H
#define POINT_H
#include <iostream>
namespace JanityMath
{
	class Point
	{
	public:
		Point();
		Point(float X, float Y);
		~Point();
		Point(const Point& other);

		float x;
		float y;
		inline Point& operator= (const Point& rhs);
		inline Point& operator+= (const Point& rhs);
		inline Point& operator+ (const Point& rhs);
		inline Point& operator+= (int value);
		inline Point& operator+ (int value);
		inline Point& operator-= (int value);
		inline Point& operator- (int value);
		inline Point& operator*= (int scalar);
		inline Point& operator* (int scalar);
		inline Point& operator/= (int divisor);
		inline Point& operator/ (int divisor);

		friend bool operator== (const Point& lhs, const Point& rhs);
		friend bool operator!= (const Point& lhs, const Point& rhs);

	private:
		friend std::ostream& operator << (std::ostream& output, const Point& point);
	};
}

#endif