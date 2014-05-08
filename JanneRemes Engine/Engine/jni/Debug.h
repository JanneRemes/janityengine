#pragma once
#ifndef DEBUG
#define DEBUG
#include <assert.h>
#include <AL\al.h>
#include <AL\alc.h>

#include <Win32toAndroid.h>

namespace Janity
{
	class Debug
	{
	public:
		Debug();
		~Debug();

		static void PrintGLString(const char *name, GLenum s);
		static void CheckGlError(const char* op);
		static void CheckALError(const char* op);
		static void Win32Assert(int expression);
		static void WriteLog(const char* text, ...);
	private:
		Debug(const Debug&);
	
	};
}
#endif

