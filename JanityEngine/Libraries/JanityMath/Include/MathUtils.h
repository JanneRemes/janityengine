#ifndef JANITYMATH_MATHUTILS_H
#define JANITYMATH_MATHUTILS_H

namespace JanityMath
{
		const double PI =3.1415926535897932;
		typedef unsigned int uint;

		double clamp(const double value, const double min, const double max);
		float clamp(const float value, const float min, const float max);
		int clamp(const int value, const int min, const int max);

		double minimum(double A, double B);
		float minimum(float A, float B);
		int minimum(int A, int B);

		double maximum(double A, double B);
		float maximum(float A, float B);
		int maximum(int A, int B);

		bool equals(const double valueA, const double valueB, const double threshold = 0.001);
		bool equals(const float valueA, const float valueB, const float threshold = 0.001f);

		void initializeRandom(uint seed = 0);
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
}

#endif