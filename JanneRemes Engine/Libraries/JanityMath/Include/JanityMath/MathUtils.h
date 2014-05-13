#ifndef JANITYMATH_MATHUTILS_H
#define JANITYMATH_MATHUTILS_H

#include <JanityMath\Matrix4.h>
#include <JanityMath\Rectangle.h>
namespace JanityMath
{
//Variables Start
		const double PI =3.1415926535897932;
	
//Variables End

//Functions Start
		double clamp(const double value, const double min, const double max);
		float clamp(const float value, const float min, const float max);
		int clamp(const int value, const int min, const int max);

		Matrix4 createOrthographicProjection(const float left, const float right, const float top, const float bottom, const float nearZ, const float farZ);
		Matrix4 createOrthographicProjection(const Rectangle& viewport, const float nearZ, const float farZ);
		Matrix4 createPerspectiveProjection(const float left, const float right, const float top, const float bottom, const float nearZ, const float farZ);
		Matrix4 createPerspectiveProjection(const float aspectRatio, const float fieldOfViewY, const float nearZ, const float farZ);
		Matrix4 lookAt(const Vector3& fromPosition, const Vector3& toPosition, const Vector3& upDirection);
		Matrix4 FPSview(Vector3 cameraPosition, float pitch, float yaw);
	
		

		double minimum(double A, double B);
		float minimum(float A, float B);
		int minimum(int A, int B);

		double maximum(double A, double B);
		float maximum(float A, float B);
		int maximum(int A, int B);

		bool equals(const double valueA, const double valueB, const double threshold = 0.001);
		bool equals(const float valueA, const float valueB, const float threshold = 0.001f);

		void initializeRandom(unsigned int seed = 0);
		double random();
		double random(const double min, const double max);
		int random(const int min, const int max);
		
		double round(const double value);
		float round(const float value);

		int sign(const double value);
		int sign(const float value);
		int sign(const int value);

		double toDegrees(const double angle);
		float toDegrees(const float angle);

		double toRadians(const double angle);
		float toRadians(const float angle);
//Functions End
}

#endif