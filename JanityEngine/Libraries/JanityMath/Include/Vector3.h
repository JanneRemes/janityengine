#ifndef JANITYMATH_VECTOR3_H
#define JANITYMATH_VECTOR3_H
#include <iostream>
#include <Vector2.h>


//http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
namespace JanityMath
{
	class Matrix4;
	class Quaternion;

	class Vector3
	{
	public:
	//	Variables Start
		float x,y,z;
		static const uint COMPONENTS = 3;
	//	Variables End
	
	//	Constructors Start
		Vector3();
		explicit Vector3(float value);
		Vector3(float X, float Y, float Z);
		Vector3(const Vector2& vector, const float z);
		Vector3(const Vector3& other);
		~Vector3();
	//	Constructors End

	//	Methods Start
		float magnitude() const;

	    bool isUnitVector() const;
		Vector2 xy() const;
		Vector3 cross(const Vector3& rhs) const;
		float distance(const Vector3& rhs) const;
		float dot(const Vector3& rhs) const;
		Vector3 normal();
		Vector3 transform(const Matrix4& transform) const;
		Vector3 transform(const Quaternion& quaternion) const;
		static Vector3 zero();
	//	Methods End

	//	Operators Start
		Vector3& operator =(const Vector3& rhs);

		Vector3 operator +(const Vector3& rhs) const;
		Vector3& operator +=(const Vector3& rhs);

		Vector3 operator -(const Vector3& rhs) const;
		Vector3& operator -=(const Vector3& rhs);
	
		Vector3 operator /(float divisor) const;
		Vector3& operator /=(float divisor);
		
		Vector3 operator -() const;

		float& operator [](const uint index);
		const float& operator [](const uint index) const;

		bool operator ==(const Vector3& rhs) const;
		bool operator !=(const Vector3& rhs) const;

		friend Vector3 operator *(const Vector3& vector, const float scalar);
		friend Vector3 operator *(const float scalar, const Vector3& vector);

		friend const Vector3& operator *=(Vector3& vector, const float scalar);
		friend std::ostream& operator <<(std::ostream& output, const Vector3& vector);
	//	Operators End

	};
}
#endif