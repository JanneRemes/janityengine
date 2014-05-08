#ifndef JANITYMATH_QUATERNION_H
#define JANITYMATH_QUATERNION_H

#include <iostream>
#include <Vector3.h>

namespace JanityMath
{
	class Matrix3;
	class Matrix4;
	
	class Quaternion
	{
	public:
	//Variables
		float w;
		Vector3 vector;
	//Variables End

	//Constructors Start
		Quaternion();
		Quaternion(const float w, const float x, const float y, const float z);
		Quaternion(const float w, const Vector3& vector);
		explicit Quaternion(const Matrix4& matrix);
		Quaternion(const Quaternion& quaternion);
		~Quaternion();
	//Constructors End

	//Methods Start
		float magnitude() const;
		bool isUnitQuaternion() const;
		Quaternion conjugate() const;
		float dot(const Quaternion& quaternion) const;
		Quaternion inverse() const;
		Quaternion normal() const;
		Vector3 rotate(const Vector3& vector) const;

		static Quaternion identity();
		static Quaternion createRotationX(const float angle);
		static Quaternion createRotationY(const float angle);
		static Quaternion createRotationZ(const float angle);
		static Quaternion createRotationAxis(const Vector3& axis, const float angle);
	//Methods end

	//Operators Start
		Quaternion operator =(const Quaternion& quaternion);

		Quaternion operator +(const Quaternion& quaternion) const;
		const Quaternion operator +=(const Quaternion& quaternion);

		Quaternion operator -(const Quaternion& quaternion) const;
		const Quaternion operator -=(const Quaternion& quaternion);

		Quaternion operator *(const Quaternion& quaternion) const;
		const Quaternion operator *=(const Quaternion& quaternion);

		Quaternion operator /(const float scalar) const;
		const Quaternion& operator /=(const float scalar);
	
		bool operator ==(const Quaternion& quaternion) const;
		bool operator !=(const Quaternion& quaternion) const;
		
		Quaternion operator -();

		friend Quaternion operator *(const Quaternion& quaternion, const float scalar);
		friend Quaternion operator *(const float scalar, const Quaternion& quaternion);
		friend const Quaternion& operator *=(Quaternion& quaternion, const float scalar);

		friend std::ostream& operator <<(std::ostream& output, const Quaternion& quaternion);
	//Operators End
	};
}
#endif