#ifndef JANITYMATH_VECTOR2_H
#define JANITYMATH_VECTOR2_H

#include <iostream>
namespace JanityMath
{
	class Matrix3;
	class Vector3;
	//class Matrix4;
	//class Quaternion;
	class Vector2
	{
	public:
		Vector2();
		Vector2(const float X, const float Y);
	    Vector2(const float value);
		~Vector2();
		Vector2(const Vector2& other);
		static const unsigned int COMPONENTS = 2;
		
		float x, y;
		float magnitude() const;
		bool isUnitVector();
		Vector3 xyz();
		float distance(const Vector2& vector) const; 
		float dot(const Vector2& vector) const;
		Vector2 normal();
		static Vector2 zero();

		Vector2& operator =(const Vector2& rhs);
		Vector2& operator +(const Vector2& rhs) const;
		Vector2& operator +=(const Vector2& rhs) const;
		Vector2& operator -(const Vector2& rhs) const;
		Vector2& operator -=(const Vector2& rhs) const;

		Vector2& operator /(const float divisor) const;
		const Vector2& operator /=(const float divisor);

		Vector2 operator -() const;

		bool operator== (const Vector2& rhs) const;
		bool operator!= (const Vector2& rhs) const;

		float& operator [](const unsigned int index);
		const float& operator [](const unsigned int index) const;

		friend Vector2 operator *(const Vector2& vector, const float scalar);
		friend Vector2 operator *(const float scalar, const Vector2& vector);

		friend const Vector2& operator *=(Vector2& vector, const float scalar);
		friend std::ostream& operator <<(std::ostream& output, const Vector2& vector);
	};
}
#endif