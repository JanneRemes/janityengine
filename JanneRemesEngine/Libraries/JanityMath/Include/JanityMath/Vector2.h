#ifndef JANITYMATH_VECTOR2_H
#define JANITYMATH_VECTOR2_H

#include <iostream>
namespace JanityMath
{
	class Matrix3;
	class Matrix4;
	class Vector3;
	class Quaternion;

	class Vector2
	{
	public:
	//	Variables Start
		float x, y;
		static const unsigned int COMPONENTS = 2;
	//	Variables End

	//	Constructors Start
		Vector2();
		Vector2(const float X, const float Y);
	    explicit Vector2(const float value);
		Vector2(const Vector2& other);
		~Vector2();
	//	Constructors End
		
	//	Methods Start
		float magnitude() const;
		bool isUnitVector() const;
		Vector3 xyz();
		float distance(const Vector2& vector) const; 
		float dot(const Vector2& vector) const;
		Vector2 normal();
		Vector2 transform(const Matrix3& transform) const;
		Vector2 transform(const Matrix4& transform) const;
		Vector2 transform(const Quaternion& quaternion) const;
		static Vector2 zero();
		static Vector2 up();
		static Vector2 down();
		static Vector2 left();
		static Vector2 right();
	//	Methods End

	//	Operators Start
		Vector2 operator +(const Vector2& vector) const;
		Vector2 operator -(const Vector2& vector) const;
		Vector2& operator =(const Vector2& vector);

		const Vector2& operator +=(const Vector2& vector);
		const Vector2& operator -=(const Vector2& vector);

		bool operator ==(const Vector2& vector) const;
		bool operator !=(const Vector2& vector) const;

		Vector2 operator -() const;
		Vector2 operator /(const float scalar) const;
		const Vector2& operator /=(const float scalar);

		float& operator [](const unsigned int index);
		const float& operator [](const unsigned int index) const;

		friend Vector2 operator *(const Vector2& vector, const float scalar);
		friend Vector2 operator *(const float scalar, const Vector2& vector);

		friend const Vector2& operator *=(Vector2& vector, const float scalar);
		friend std::ostream& operator <<(std::ostream& output, const Vector2& vector);
	//	Operators End
	};
}
#endif