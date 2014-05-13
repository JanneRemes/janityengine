#include <MathUtils.h>
#include <cmath>
#include <ctime>
#include <cstdlib>

// https://code.google.com/p/slmath/
// simd

#include <Vector4.h>
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

	Matrix4 createOrthographicProjection(const float left, const float right, const float top, const float bottom, const float nearZ, const float farZ)
	{
		const float width = right - left;
		const float height = bottom - top;
		const float depth = farZ - nearZ;

		return Matrix4
		(
			 2.0f / width,			  0.0f,						 0.0f,					 0.0f,
			 0.0f,					  2.0f / -height,			 0.0f,					 0.0f,
			 0.0f,					  0.0f,						-2.0f / depth,			 0.0f,
			-(left + right) / width, -(top + bottom) / -height, -(nearZ + farZ) / depth, 1.0f
		);
	}

	Matrix4 createOrthographicProjection(const Rectangle& viewport, const float nearZ, const float farZ)
	{
		const float left = (float)viewport.left();
		const float right = (float)viewport.right();
		const float top = (float)viewport.top();
		const float bottom = (float)viewport.bottom();

		return createOrthographicProjection(left, right, top, bottom, nearZ, farZ);
	}

	Matrix4 createPerspectiveProjection(const float left, const float right, const float top, const float bottom, const float nearZ, const float farZ)
	{
		const float width = right - left;
		const float height = bottom - top;
		const float depth = farZ - nearZ;

		return Matrix4
		(
			2.0f * nearZ / width,	0.0f,					   0.0f,						 0.0f,
			0.0f,					2.0f * nearZ / -height,	   0.0f,						 0.0f,
			(left + right) / width, (top + bottom) / -height, -(nearZ + farZ) / depth,		-1.0f,
			0.0f,					0.0f,					  -2.0f * nearZ * farZ / depth,	 0.0f
		);
	}

	Matrix4 createPerspectiveProjection(const float aspectRatio, const float fieldOfViewY, const float nearZ, const float farZ)
	{
		const float top = nearZ * tanf(fieldOfViewY / 2.0f);
		const float bottom = -top;
		const float right = aspectRatio * top;
		const float left = -right;

		return createPerspectiveProjection(left, right, top, bottom, nearZ, farZ);
	}

	Matrix4 lookAt(const Vector3& fromPosition, const Vector3& toPosition, const Vector3& upDirection)
	{
		const Vector3 zAxis = (fromPosition - toPosition).normal();	// Forward Vector
		const Vector3 xAxis = upDirection.cross(zAxis).normal();	// Right Vector
		const Vector3 yAxis = zAxis.cross(xAxis);					// Up Vector

		//optimized
		Matrix4 viewMatrix
		(
			Vector4( xAxis.x,				   yAxis.x,					 zAxis.x,				   0),
			Vector4( xAxis.y,				   yAxis.y,					 zAxis.y,				   0),
			Vector4( xAxis.z,			       yAxis.z,					 zAxis.z,				   0),
			Vector4( -xAxis.dot(fromPosition), -yAxis.dot(fromPosition), -zAxis.dot(fromPosition), 1)
		); 

		return viewMatrix;
		/*Matrix4 orientation 
		(
			Vector4( xAxis.x, yAxis.x, zAxis.x, 0),
			Vector4( xAxis.y, yAxis.y, zAxis.y, 0),
			Vector4( xAxis.z, yAxis.z, zAxis.z, 0),
			Vector4( 0,		  0,	   0,		1)
		);
		
		Matrix4 translation
		(
			Vector4(			  1,			   0,				0,	    0),
			Vector4(			  0,			   1,				0,		0),
			Vector4(			  0,			   0,			    1,		0),
			Vector4(-fromPosition.x, -fromPosition.y, -fromPosition.z,		1)
		);

		return (orientation * translation);*/	
	}

	Matrix4 FPSview(Vector3 cameraPosition, float pitch, float yaw)
	{
		// If the pitch and yaw angles are in degrees,
    // they need to be converted to radians. Here
    // I assume the values are already converted to radians.
    float cosPitch = cos(pitch);
    float sinPitch = sin(pitch);
    float cosYaw = cos(yaw);
    float sinYaw = sin(yaw);
 
    Vector3 xaxis( cosYaw, 0, -sinYaw);
    Vector3 yaxis( sinYaw * sinPitch, cosPitch, cosYaw * sinPitch);
    Vector3 zaxis( sinYaw * cosPitch, -sinPitch, cosPitch * cosYaw);
 
    // Create a 4x4 view matrix from the right, up, forward and eye position vectors
    Matrix4 viewMatrix 
	( 
        Vector4(				   xaxis.x,					 yaxis.x,				   zaxis.x,     0 ),
        Vector4(				   xaxis.y,					 yaxis.y,				   zaxis.y,     0 ),
        Vector4(				   xaxis.z,					 yaxis.z,				   zaxis.z,     0 ),
        Vector4(-xaxis.dot(cameraPosition), -yaxis.dot(cameraPosition), -zaxis.dot(cameraPosition), 1 )
    );
     
    return viewMatrix;
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

	void initializeRandom(unsigned int seed)
	{
		if(seed == 0)
			seed = (unsigned int)time(NULL);

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