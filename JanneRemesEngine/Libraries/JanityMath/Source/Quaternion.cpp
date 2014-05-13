#include <JanityMath\Quaternion.h>

#include <cassert>
#include <cfloat>
#include <cmath>

#include <JanityMath\MathUtils.h>
#include <JanityMath\Matrix3.h>
#include <JanityMath\Matrix4.h>

using namespace JanityMath;

Quaternion::Quaternion() { }

Quaternion::Quaternion(const float w,
					   const float x,
					   const float y,
					   const float z)
	: w(w),
	vector(x,y,z) { }

Quaternion::Quaternion(const float w, const Vector3& vector)
	: w(w),
	vector(vector) { }

Quaternion::Quaternion(const Matrix4& matrix)
{
	const float trace = matrix[0][0] + matrix[1][1] + matrix[2][2];
	float factor = 0.0f;

	if(trace > 0.0f)
	{
		factor = 0.5f / sqrt(trace + 1.0f);

		w = 0.25f / factor;
		vector.x = factor * (matrix[1][2] - matrix[2][1]);
		vector.y = factor * (matrix[2][0] - matrix[0][2]);
		vector.z = factor * (matrix[0][1] - matrix[1][0]);
	}
	else if(matrix[0][0] > matrix[1][1] && matrix[1][1] > matrix[2][2])
	{
		factor = 2.0f * sqrt(matrix[0][0] - matrix[1][1] - matrix[2][2] + 1.0f);

		w = (matrix[1][2] - matrix[2][1] / factor);
		vector.x = 0.25f * factor;
		vector.y = (matrix[1][0] + matrix[0][1]) / factor;
		vector.z = (matrix[2][0] + matrix[0][2]) / factor;
	}
	else if(matrix[1][1] > matrix [2][2])
	{
		factor = 2.0f * sqrt(matrix[1][1] - matrix[0][0] - matrix[2][2] +1.0f);

		w = (matrix[2][0] - matrix[0][2]) / factor;
		vector.x = (matrix[1][0] + matrix[0][1]) / factor;
		vector.y = 0.25f * factor;
		vector.z = (matrix[2][1] + matrix[1][2] / factor);
	}
	else
	{
		factor = 2.0f * sqrt(matrix[2][2] - matrix[0][0] - matrix[1][1] + 1.0f);

		w = (matrix[0][1] - matrix[1][0] / factor);
		vector.x = (matrix[2][0] + matrix[0][2]) / factor;
		vector.y = (matrix[2][1] + matrix[1][2]) / factor;
		vector.z = 0.25f * factor;
	}
}
Quaternion::Quaternion(const Quaternion& quaternion)
	: w(quaternion.w),
	vector(quaternion.vector) { }

Quaternion::~Quaternion() { }

//Public

float Quaternion::magnitude() const
{
	const float vectorDot = vector.dot(vector);
	return sqrt(w * w + vectorDot);
}

bool Quaternion::isUnitQuaternion() const
{
	return equals(magnitude(), 1.0f);
}

Quaternion Quaternion::conjugate() const
{
	return Quaternion(w, -vector);
}

float Quaternion::dot(const Quaternion& quaternion) const
{
	const float _w = w * quaternion.w;
	const float _vectorDot = vector.dot(quaternion.vector);

	return _w + _vectorDot;
}

Quaternion Quaternion::inverse() const
{
	const float lenght = magnitude();
	return conjugate() / (lenght * lenght);
}

Quaternion Quaternion::normal() const
{
	return *this / magnitude();
}

Vector3 Quaternion::rotate(const Vector3& vector) const
{
	const Quaternion result = *this * Quaternion(0.0f, vector) * conjugate();
	return result.vector;
}

// Static

Quaternion Quaternion::identity()
{
	return Quaternion(1.0f, Vector3::zero());
}

Quaternion Quaternion::createRotationX(const float angle)
{
	const Vector3 axis(1.0f, 0.0f, 0.0f);
	return createRotationAxis(axis, angle);
}

Quaternion Quaternion::createRotationY(const float angle)
{
	const Vector3 axis(0.0f, 1.0f, 0.0f);
	return createRotationAxis(axis, angle);
}

Quaternion Quaternion::createRotationZ(const float angle)
{
	const Vector3 axis(0.0f, 0.0f, 1.0f);
	return createRotationAxis(axis, angle);
}

Quaternion Quaternion::createRotationAxis(const Vector3& axis, const float angle)
{
	assert(axis.isUnitVector());

	const float halfAngle = angle / 2.0f;
	const float _w = cos(halfAngle);
	const Vector3 _vector = axis * sin(halfAngle);

	return Quaternion (_w, _vector);
}

// Operators
Quaternion Quaternion::operator =(const Quaternion& quaternion)
{
	if(this != &quaternion)
	{
		w = quaternion.w;
		vector = quaternion.vector;
	}
	return *this;
}

Quaternion Quaternion::operator +(const Quaternion& quaternion) const
{
	const float _w = w + quaternion.w;
	const Vector3 _vector = vector + quaternion.vector;

	return Quaternion(_w, _vector);
}

const Quaternion Quaternion::operator +=(const Quaternion& quaternion)
{
	*this = *this + quaternion;
	return *this;
}

Quaternion Quaternion::operator -(const Quaternion& quaternion) const
{
	const float _w = w - quaternion.w;
	const Vector3 _vector = vector - quaternion.vector;

	return Quaternion(_w, _vector);
}

const Quaternion Quaternion::operator -=(const Quaternion& quaternion)
{
	*this = *this - quaternion;
	return *this;
}

Quaternion Quaternion::operator *(const Quaternion& quaternion) const
{
	const float _w = w * quaternion.w - vector.dot(quaternion.vector);
	const Vector3 _vector = w * quaternion.vector + quaternion.w * vector + vector.cross(quaternion.vector);

	return Quaternion(_w, _vector);
}

const Quaternion Quaternion::operator *=(const Quaternion& quaternion)
{
	*this = *this * quaternion;
	return *this;
}

Quaternion Quaternion::operator /(const float scalar) const
{
	assert (!equals(scalar, 0.0f));
	const float _w = w / scalar;
	const Vector3 _vector = vector / scalar;

	return Quaternion(_w, _vector);
}

const Quaternion& Quaternion::operator /=(const float scalar)
{
	*this = *this / scalar;
	return *this;
}

bool Quaternion::operator ==(const Quaternion& quaternion) const
{
	return equals(w, quaternion.w) && vector == quaternion.vector;
}

bool Quaternion::operator !=(const Quaternion& quaternion) const
{
	return !(*this == quaternion);
}

Quaternion Quaternion::operator -()
{
	return Quaternion(-w, -vector);
}

// Friends

namespace JanityMath
{
	Quaternion operator *(const Quaternion& quaternion, const float scalar)
	{
		const float _w = scalar * quaternion.w;
		const Vector3 _vector = scalar * quaternion.vector;

		return Quaternion(_w, _vector);
	}

	Quaternion operator *(const float scalar, const Quaternion& quaternion)
	{
		return quaternion * scalar;
	}

	const Quaternion& operator *=(Quaternion& quaternion, const float scalar)
	{
		quaternion = quaternion * scalar;
		return quaternion;
	}

	std::ostream& operator <<(std::ostream& output, const Quaternion& quaternion)
	{
		const Vector3& vector = quaternion.vector;
		output << "[W: " << 
			quaternion.w << 
			", X: "		 << 
			vector.x	 << 
			", Y: "		 << 
			vector.y	 << 
			", Z: "		 << 
			vector.z	 << 
			"]";
			
		return output;
	}
}