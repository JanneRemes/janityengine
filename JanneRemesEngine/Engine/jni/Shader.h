#pragma once
#ifndef SHADER
#define SHADER

#include <Win32toAndroid.h>
#include <stdlib.h>

#include <Debug.h>
#include <FileReader.h>

namespace JanityEngine
{
	class Shader
	{
	public:
		Shader();
		~Shader();
		
		GLuint CreateShader(const char* fragPath, const char* vertPath);
	
	private:
		Shader(const Shader&);

		GLuint ReadShaderFile(const char* path, GLenum type);
		GLuint CreateProgram(GLuint VS, GLuint PS);
		bool FrmLinkShaderProgram( GLuint Program );
	
		GLuint LoadShader(GLenum shaderType, const char* pSource);
	};
}
#endif