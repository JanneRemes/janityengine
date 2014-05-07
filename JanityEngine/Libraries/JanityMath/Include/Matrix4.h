#ifndef JANITYMATH_MATRIX4_H
#define JANITYMATH_MATRIX4_H

#include <iostream>

#include <Matrix3.h>
#include <Vector3.h>
#include <Vector4.h>

namespace JanityMath
{
	class Matrix4
	{
	public:
	//	Variables Start
		static const uint COLUMNS = 4;
		static const uint ROWS = 4;
	//	Variables End

	//	Constructors Start
		Matrix4();

		Matrix4(const float m11, const float m12, const float m13, const float m14,
				const float m21, const float m22, const float m23, const float m24,
				const float m31, const float m32, const float m33, const float m34,
			    const float m41, const float m42, const float m43, const float m44);
		
		Matrix4(const Vector4& column1, 
			    const Vector4& column2,
				const Vector4& column3,
				const Vector4& column4);

		explicit Matrix4(const Matrix3& matrix);

		Matrix4(const Matrix4& matrix);

		~Matrix4();
	//	Constructors End

	//	Methods Start
		const float* elements() const;
		float determinant() const;
		Matrix4 inverse() const;
		Matrix4 transpose() const;

		Vector3 extractPosition() const;
		Matrix4 extractRotation() const;
		Matrix4 extractRotation(const Vector3& scaling) const;
		Vector3 extractScaling() const;

		static Matrix4 identity();

		static Matrix4 createRotationX(const float angle);
		static Matrix4 createRotationY(const float angle);
		static Matrix4 createRotationZ(const float angle);
		static Matrix4 createRotationAxis(const Vector3& axis, const float angle);

		static Matrix4 createScaling(const float x = 1.0f, const float y = 1.0f, const float z = 1.0f);
		static Matrix4 createScaling(const Vector3& scaling);
		static Matrix4 createScalingAxis(const Vector3& axis, const float scale);

		static Matrix4 createTranslation(const float x, const float y, const float z);
		static Matrix4 createTranslation(const Vector3& translation);
	//	Methods End

		Matrix4& operator =(const Matrix4& rhs);
		
		Matrix4 operator +(const Matrix4& rhs) const;
		const Matrix4& operator +=(const Matrix4& rhs);

		Matrix4 operator -(const Matrix4& rhs) const;
		const Matrix4& operator -=(const Matrix4& rhs);

		Matrix4 operator *(const Matrix4& rhs) const;
		const Matrix4& operator *=(const Matrix4& rhs);

		Matrix4 operator /(const float divisor) const;
		const Matrix4& operator /=(const float divisor);
		
		bool operator ==(const Matrix4& rhs) const;
		bool operator !=(const Matrix4& rhs) const;

		Vector4 operator *(const Vector4& vector) const;

		Vector4 operator [](const uint index);
		const Vector4& operator [](const uint index) const;

		friend Matrix4 operator *(const Matrix4& matrix, const float scalar);
		friend Matrix4 operator *(const float scalar, const Matrix4& matrix);
		friend const Matrix4& operator *=(Matrix4& matrix, const float scalar);

		friend std::ostream& operator <<(std::ostream& output, const Matrix4& matrix);

	private:
		Vector4 _columns[4];
		Matrix4 adjugate() const;
	};
}

#endif