#ifndef POINT_H
#define POINT_H
#include <iostream>

namespace JanityMath
{
	class Point
	{
	public:
	//	Variables Start
		float x;
		float y;
	//	Variables End

	//	Constructors Start
		Point();
		Point(float X, float Y);
		~Point();
		Point(const Point& other);
	//	Constructors End

	//	Methods Start
		Point maximum(const Point& point) const;
		Point minimum(const Point& point) const;
		static Point zero();
	//	Methods End

	//	Operators Start
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
		friend std::ostream& operator << (std::ostream& output, const Point& point);
	// Operators End
	};
}

#endif