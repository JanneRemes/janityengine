#include <Sound.h>
#include <Debug.h>
#include <Util.h>
#include <math.h>

//RESTRUCTURE
#include "sndfile/sndfile.h"

using namespace KaMo;


Sound::Sound(const std::string& fileName)
	: loop(false)
{
	Initialize(fileName);
}

Sound::Sound()
{
}

Sound::~Sound()
{
	alDeleteSources(1, &source);
	alDeleteBuffers(1, &buffer);
	
	for(int i=0; i < tempSource.size(); i++)
	{
		alDeleteSources(1, &tempSource[i]);
	}
}


// PUBLIC
Sound* Sound::Load(const std::string& fileName)
{
	return new Sound(fileName);
}
// Plays source
void Sound::Play()
{
	alSourcePlay(source);
}
void Sound::Play(float _offset) // Play from specific second
{
	if(_offset >= duration)
	{
		
	}
	else
	{
		alSourcei(source, AL_SEC_OFFSET, _offset);
		alSourcePlay(source);
	}
}
void Sound::PlayEffect()
{
	if(Status() != AL_PLAYING)
		alSourcePlay(source);
	else
		Copy();
}
// Stops source (starting playing again will start it from beginning)
void Sound::Stop()
{
	alSourceStop(source);
}
// Toggles pause & play (continues from paused location)
void Sound::Pause()
{
	if(Status() == AL_PLAYING)
 		alSourcePause(source);
	else
		alSourcePlay(source);
		
}
// Gets playing status
ALint Sound::Status()
{
	ALint _state;
	alGetSourcei(source, AL_SOURCE_STATE, &_state);
	return _state;
}
// Toggles loop
void Sound::Loop()
{
	if(loop)
	{
		alSourcei(source, AL_LOOPING, AL_FALSE);
		loop = false;
	}
	else if(!loop)
	{
		alSourcei(source, AL_LOOPING, AL_TRUE);
		loop = true;
	}

	Debug::CheckALError("al_sourcei AL_LOOPING");
}
// Defines loop into given value.
void Sound::Loop(ALint _value)
{
	if(_value == AL_FALSE)
		loop = false;
	else
		loop = true;
	alSourcei(source, AL_LOOPING, _value);
	Debug::CheckALError("al_sourcei AL_LOOPING");
}

// PRIVATE
void Sound::Initialize(const std::string& fileName)
{
	Sound::CreateSources(source);
	
	// create buffer
	alGenBuffers(1, &buffer);
	Debug::CheckALError("alGenBuffers");

	// SOUNDFILE READING
	#ifdef __ANDROID__

		AAsset* asset = Util::loadSound(fileName);

		SF_VIRTUAL_IO virtualIO;
		virtualIO.get_filelen = &Util::getAssetLength;
		virtualIO.seek = &Util::seekAsset;
		virtualIO.read = &Util::readAsset;
		virtualIO.tell = &Util::tellAsset;

		SF_INFO soundInfo;
		SNDFILE* file = sf_open_virtual(&virtualIO, SFM_READ, &soundInfo, asset);

	#else

		SF_INFO soundInfo;
		SNDFILE* file = sf_open(fileName.c_str(), SFM_READ, &soundInfo);
		
	#endif

	if(!file)
	{
		int error = sf_error(file);
		Debug::WriteLog("** FAILED TO OPEN SOUND FILE, ERROR %d **", file, error);
		Debug::WriteLog(sf_error_number(error));
		return;
	}

	Debug::WriteLog("frames: %d\n", soundInfo.frames);
	Debug::WriteLog("samplerate: %d\n", soundInfo.samplerate);
	Debug::WriteLog("channels: %d\n", soundInfo.channels);
	Debug::WriteLog("format: %d\n", soundInfo.format);

	sf_count_t frames = soundInfo.frames * soundInfo.channels;

	short* data = new short[frames];

	sf_read_short(file, data, frames);

	Debug::WriteLog("frames: %d\n", frames);

	alBufferData(buffer, AL_FORMAT_STEREO16, data, frames * sizeof(short), soundInfo.samplerate);
	Debug::CheckALError("alBufferData");

	alSourcei(source, AL_BUFFER, buffer);
	Debug::CheckALError("alSourcei");

	duration = (float)soundInfo.frames / (float)soundInfo.samplerate;
	Debug::WriteLog("duration: %f\n", duration);


	sf_close(file);
}

void Sound::CreateSources(ALuint &source)
{
	// create source
	alGenSources(1, &source);
	Debug::CheckALError("alGen_sources");

	alSourcef(source, AL_PITCH, 1);
	Debug::CheckALError("al_sourcef AL_PITCH");

	alSourcef(source, AL_GAIN, 1);
	Debug::CheckALError("al_sourcef AL_GAIN");

	alSource3f(source, AL_POSITION, 0, 0, 0);
	Debug::CheckALError("al_source3f AL_POSITION");

	alSource3f(source, AL_VELOCITY, 0, 0, 0);
	Debug::CheckALError("al_source3f AL_VELOCITY");

	alSourcei(source, AL_LOOPING, AL_FALSE);
	Debug::CheckALError("al_sourcei AL_LOOPING");
}

void Sound::Copy()
{
	ALuint source;
	Sound::CreateSources(source);
	
	alSourcei(source, AL_BUFFER, buffer);
	Debug::CheckALError("alSourcei");

	tempSource.push_back(source);
	alSourcePlay(tempSource[tempSource.size()-1]);
	tempSource.erase(tempSource.begin());
}