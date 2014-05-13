#include <Debug.h>

#ifndef WINDOWS_FRAMEWORK
#else
#include <iostream>
#endif

using namespace JanityEngine;

Debug::Debug()
{
}
Debug::~Debug()
{
}

void Debug::PrintGLString(const char *name, GLenum s) 
{
    const char *v = (const char *) glGetString(s);
	#ifndef WINDOWS_FRAMEWORK
    LOGI("GL %s = %s\n", name, v);
	#else
	printf("GL %s = %s\n", name, v);
	#endif
}

void Debug::CheckGlError(const char* op) 
{
    for (GLint error = glGetError(); error; error
            = glGetError()) {
    #ifndef WINDOWS_FRAMEWORK
	LOGI("after %s() glError (0x%x)\n", op, error);
	#else
	printf("after %s() glError (0x%x)\n", op, error);
	#endif
    }
}

void Debug::CheckALError(const char* op)
{
	for(ALCenum error = alGetError(); error != AL_NO_ERROR; error = alGetError())
	{
	#ifndef WINDOWS_FRAMEWORK
	LOGI("after %s() glError (0x%x)\n", op, error);
	#else
	printf("after %s() glError (0x%x)\n", op, error);
	#endif
	}
}

void Debug::Win32Assert(int expression)
{
	#ifndef WINDOWS_FRAMEWORK
	#else	

	assert(expression);

	#endif

}

void Debug::WriteLog(const char* text, ...)
{
	va_list v;
	va_start(v, text);
	#ifndef WINDOWS_FRAMEWORK
	__android_log_vprint(ANDROID_LOG_INFO, LOG_TAG, text, v);
	#else
	vprintf(text, v);
	#endif
	va_end(v);
}