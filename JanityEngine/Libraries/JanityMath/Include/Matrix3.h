#ifndef JANITYMATH_MATRIX3
#define JANITYMATH_MATRIX3

#include <iostream>
#include <Vector2.h>
#include <Vector3.h>

//http://euclideanspace.com/
namespace JanityMath
{
	class Matrix3
	{
	public:
	//  Variables Start
		static const uint COLUMNS = 3;
		static const uint ROWS = 3;
	//  Variables End

	//  Constructors Start
		Matrix3();
		Matrix3(const float m11,
				const float m12,
				const float m13,
				const float m21,
				const float m22,
				const float m23,
				const float m31,
				const float m32,
				const float m33);

		Matrix3(const Vector3& column1, const Vector3& column2, const Vector3& column3);

		Matrix3(const Matrix3& matrix);
		~Matrix3();
	//  Constructors End

	//  Methods Start
		const float* elements() const;
		float determinant() const;
		Matrix3 inverse() const;
		Matrix3 transpose() const;

		Vector2 extractPosition() const;
		Matrix3 extractRotation() const;
		Matrix3 extractRotation(const Vector2& scaling) const;
		Vector2 extractScaling() const;

		static Matrix3 identity();

		static Matrix3 createRotation(const float angle);

		static Matrix3 createScaling(const float x = 1.0f, const float y = 1.0f);
		static Matrix3 createScaling(const Vector2& scaling);

		static Matrix3 createTranslation(const float x, const float y);
		static Matrix3 createTranslation(const Vector2& translation);
	//	Methods End

	//	Operators Start
		Matrix3& operator =(const Matrix3& rhs);

		Matrix3 operator +(const Matrix3& rhs) const;
		const Matrix3& operator +=(const Matrix3& rhs);

		Matrix3 operator -(const Matrix3& rhs) const;
		const Matrix3& operator -=(const Matrix3& rhs);

		Matrix3 operator *(const Matrix3& rhs) const;
		const Matrix3& operator *=(const Matrix3& rhs);
		Vector3 operator *(const Vector3& vector) const;

		bool operator ==(const Matrix3& rhs) const;
		bool operator !=(const Matrix3& rhs) const;

		Matrix3 operator /(const float divisor);
		const Matrix3& operator /=(const float divisor);

		Vector3& operator [](const uint index);
		const Vector3& operator [](const uint index) const;


		friend Matrix3 operator *(const Matrix3& matrix, const float scalar);
		friend Matrix3 operator *(const float scalar, const Matrix3& matrix);
		friend const Matrix3& operator *=(Matrix3& matrix, const float scalar);
		friend std::ostream& operator <<(std::ostream& output, const Matrix3& matrix);

	//	Operators End

	//	Variables Start
	private:
		Vector3 _columns[3];
		Matrix3 adjugate() const;
	};
	//	Variables End
}


#endif