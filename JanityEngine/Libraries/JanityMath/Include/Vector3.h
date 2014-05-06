#ifndef JANITYMATH_VECTOR3_H
#define JANITYMATH_VECTOR3_H
#include <iostream>
#include <Vector2.h>


//http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
namespace JanityMath
{
	//class Matrix4;
	//class Quaternion;
	class Vector3
	{
	public:
		Vector3();
		Vector3(float value);
		Vector3(float X, float Y, float Z);
		~Vector3();
		Vector3(const Vector3& other);
		static const unsigned int COMPONENTS = 3;

		float x,y,z;
		float magnitude() const;

	    bool isUnitVector();
		Vector2 xy() const;
		Vector3 cross(const Vector3& vector);
		float distance(const Vector3& vector) const;
		float dot(const Vector3& vector);
		Vector3 normal();
		static Vector3 zero();

		Vector3& operator =(const Vector3& rhs);
		Vector3& operator +=(const Vector3& rhs);
		Vector3& operator +(const Vector3& rhs);
		Vector3& operator -=(const Vector3& rhs);
		Vector3& operator -(const Vector3& rhs);
		
		Vector3& operator /=(float divisor);
		Vector3& operator /(float divisor);
		Vector3 operator -();

		float& operator [](const unsigned int index);
		const float& operator [](const unsigned int index) const;

		bool operator== (const Vector3& rhs) const;
		bool operator!= (const Vector3& rhs) const;

		friend Vector3 operator *(const Vector3& vector, const float scalar);
		friend Vector3 operator *(const float scalar, const Vector3& vector);

		friend const Vector3& operator *=(Vector3& vector, const float scalar);
		friend std::ostream& operator <<(std::ostream& output, const Vector3& vector);

	};
}
#endif