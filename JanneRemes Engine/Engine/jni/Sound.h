#pragma once
#ifndef SOUND_H
#define SOUND_H

#include <string>
#include <AL\al.h>
#include <AL\alc.h>
#include <sndfile\sndfile.h>

#include <vector>

namespace JanityEngine
{
	class Sound
	{
	public:
		Sound(const std::string& fileName);
		Sound();
		~Sound();

		static Sound* Load(const std::string& fileName);
		void Play();
		void Play(float _offset);
		void PlayEffect();
		void Stop();
		void Pause();

		ALint Status();

		void Loop();
		void Loop(ALint _value);

	private:
		Sound(const Sound&);

		void Initialize(const std::string& fileName);
		static void CreateSources(ALuint &source);
		void Copy();

		ALuint source;
		ALuint buffer;
		float* data;

		bool loop;
		float duration;

		std::vector<ALuint> tempSource;
	};
}

#endif