#ifndef JANITYMATH_VECTOR4_H
#define JANITYMATH_VECTOR4_H

#include <iostream>
#include <Vector2.h>
#include <Vector3.h>

namespace JanityMath
{
	class Quaternion;

	class Vector4
	{
	public:
	//	Variables Start
		float x,y,z,w;
		static const uint COMPONENTS = 4;
	//	Variables End

	//	Constructors Start
		Vector4();
		explicit Vector4(const float value);
		Vector4(const float X, const float Y, const float Z, const float W);
		Vector4(const Vector2& vector, const float Z, const float W);
		Vector4(const Vector3& vector, const float W);
		Vector4(const Vector4& vector);
		~Vector4();
	//	Constructors End

	//	Methods Start
		float magnitude() const;

		bool isUnitVector() const;
		Vector2 xy() const;
		Vector3 xyz() const;
		float distance(const Vector4& rhs) const;
		float dot(const Vector4& rhs);
		Vector4 normal();
		Vector4 transform(const Quaternion& quaternion) const;
		static Vector4 zero();
	//	Methods End

	//	Operators Start
		Vector4& operator =(const Vector4& rhs);

		Vector4 operator +(const Vector4& rhs) const;
		Vector4& operator +=(const Vector4& rhs);

		Vector4 operator -(const Vector4& rhs) const;
		Vector4& operator -=(const Vector4& rhs);

		Vector4 operator /(float divisor) const;
		Vector4& operator /=(float divisor);

		Vector4 operator -();

		float& operator [](const uint index);
		const float& operator [](const uint index) const;

		bool operator ==(const Vector4& rhs) const;
		bool operator !=(const Vector4& rhs) const;

		friend Vector4 operator *(const Vector4& vector, const float scalar);
		friend Vector4 operator *(const float scalar, const Vector4& vector);
		friend const Vector4& operator *=(Vector4& vector, const float scalar);
		friend std::ostream& operator <<(std::ostream output, const Vector4& vector);
	//	Operators End
	};
}

#endif