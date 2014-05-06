#include <Util.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "sndfile\sndfile.h"

const std::string Util::resourcePath = "assets/";

float Util::getTotalTime()
{
	static bool initialized = false;
	static float basetime;

	if(!initialized)
	{
		initialized = true;
		basetime = GetTickCount() / 1000.0f;
	}

	return float(GetTickCount()) / 1000.0f - basetime;
}

float* Util::loadSound(const std::string& fileName, int& size)
{
	SF_INFO soundInfo;
	SNDFILE* file = sf_open(fileName.c_str(), SFM_READ, &soundInfo);

	if(!file)
	{
		printf("Failed to open sound file");
		return 0;
	}



	sf_count_t frames = soundInfo.frames * soundInfo.channels;
	size = frames;

	float* data = new float[frames];

	sf_readf_float(file, data, frames);

	/*
	for(int i = 0; i < frames; i++)
	{

	}
	*/

	sf_close(file);

	return data;
}