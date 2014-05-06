#include <SoundManager.h>
#include <Debug.h>

using namespace Janity;


bool SoundManager::initialized = false;
ALCdevice* SoundManager::device = 0;
ALCcontext* SoundManager::context = 0;


SoundManager::SoundManager()
{
	CreateContext();
}

SoundManager::~SoundManager()
{
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

void SoundManager::CreateContext()
{
	if(!initialized)
	{
		initialized = true;

		device = alcOpenDevice(0);
		if(!device)
			Debug::WriteLog("Failed to open audio device!");

		//Debug::WriteLog("Audio device opened.\n");

		context = alcCreateContext(device, 0);
		if(!alcMakeContextCurrent(context))
		{
			Debug::WriteLog("Failed to make context current!");
			Debug::CheckALError("alcMakeContextCurrent");
		}
	}
}