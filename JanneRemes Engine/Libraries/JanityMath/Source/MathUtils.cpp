#include <JanityMath\MathUtils.h>
#include <cmath>
#include <ctime>
#include <cstdlib>

namespace JanityMath
{
	const double TO_RADIANS_FACTOR = PI / 180.0;
	const double TO_DEGREES_FACTOR = 180.0 / PI;

	double clamp(const double value, const double min, const double max)
	{
		if(value >= max)
			return max;
		else if(value <= min)
			return min;
		else
			return value;
	}

	float clamp(const float value, const float min, const float max)
	{
		if(value >= max)
			return max;
		else if(value <= min)
			return min;
		else
			return value;
	}

	int clamp(const int value, const int min, const int max)
	{
		if(value >= max)
			return max;
		else if(value <= min)
			return min;
		else
			return value;
	}

	bool equals(const double valueA, const double valueB, const double threshold)
	{
		return fabs(valueA - valueB) <= threshold;
	}

	bool equals(const float valueA, const float valueB, const float threshold)
	{
		return fabsf(valueA - valueB) <= threshold;
	}

	double minimum(double A, double B)
	{
		if(A < B)
			return A;
		else if (A > B)
			return B;
		else
			return A;
	}

	float minimum(float A, float B)
	{
		if(A < B)
			return A;
		else if (A > B)
			return B;
		else
			return A;
	}

	int minimum(int A, int B)
	{
		if(A < B)
			return A;
		else if (A > B)
			return B;
		else
			return A;
	}


	double maximum(double A, double B)
	{
		if(A > B)
			return A;
		else if(B > A)
			return B;
		else
			return A;
	}

	float maximum(float A, float B)
	{
		if(A > B)
			return A;
		else if(B > A)
			return B;
		else
			return A;
	}

	int maximum(int A, int B)
	{
		if(A > B)
			return A;
		else if(B > A)
			return B;
		else
			return A;
	}

	void initializeRandom(uint seed)
	{
		if(seed == 0)
			seed = (uint)time(NULL);

		srand(seed);
	}
	double random()
	{
		return (double)rand() / RAND_MAX;
	}

	double random(const double min, const double max)
	{
		return random() * (max - min) + min;
	}

	int random(const int min, const int max)
	{
		const double randomValue = random() * (max - min) + min;
		return (int)round(randomValue);
	}


	double round(const double value)
	{
		const double floorValue = floor(value);
		if(value - floorValue < 0.5f)
			return floorValue;
		else
			return ceil(value);
	}

	float round(const float value)
	{
		const float floorValue = floor(value);
		if(value - floorValue < 0.5f)
			return floorValue;
		else
			return ceil(value);
	}

	int sign(const double value)
	{
		if(value == 0.0f)
			return 0;
		else
			return (int)(fabs(value) / value);
	}

	int sign(const float value)
	{
		if(value == 0.0f)
			return 0;
		else
			return (int)(fabsf(value) / value);
	}

	int sign(const int value)
	{
		if(value == 0.0f)
			return 0;
		else
			return (int)(abs(value) / value);
	}


	double toDegrees(const double angle)
	{
		return TO_DEGREES_FACTOR * angle;
	}

	float toDegrees(const float angle)
	{
		return TO_DEGREES_FACTOR * angle;
	}

	double toRadians(const double angle)
	{
		return TO_RADIANS_FACTOR * angle;
	}

	float toRadians(const float angle)
	{
		return TO_RADIANS_FACTOR * angle;
	}
}