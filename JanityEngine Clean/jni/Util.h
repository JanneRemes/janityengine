#pragma once
#ifndef UTIL
#define UTIL

#include <Debug.h>
#include <stdlib.h>
#include <OpenGL.h>
#include <string>

#ifdef __ANDROID__
#include "AssetManager.h"
#include <sndfile\sndfile.h>
#endif


class Util
{
public:
	static float getTotalTime();

	static const std::string resourcePath;

#ifdef __ANDROID__

	static AAsset* loadSound(const std::string& fileName);

	static sf_count_t getAssetLength(void* asset);
	static sf_count_t seekAsset(sf_count_t offset, int whence, void* asset);
	static sf_count_t readAsset(void* buffer, sf_count_t count, void* asset);
	static sf_count_t tellAsset(void* asset);

#else

	static float* loadSound(const std::string& fileName, int& size);

#endif


};

#endif