#include <Util.h>
#include <ctime>
#include <string>

float Util::getTotalTime()
{
	static bool	initialized = false;
	static clock_t baseTime;
	
	if (!initialized)
	{
		baseTime = clock();
		initialized = true;
		return 0.0f;
	}

	float time = float(clock() - baseTime) / float(CLOCKS_PER_SEC);
	return time;
}