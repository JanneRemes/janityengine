#pragma once
#ifndef TEXTURE
#define TEXTURE

#include <Shader.h>
#include <Debug.h>
#include <FileReader.h>

namespace Janity
{
	class Texture
	{
	public:

			typedef unsigned char BYTE;
			typedef unsigned short USHORT;

			struct Header
			{
				BYTE type;
				USHORT width;
				USHORT height;
				BYTE depth;
				BYTE descriptor;
			};
		
			Texture(const char* Filename);
			Texture(const Header& header, BYTE* _pixels);
			~Texture();

			int GetWidth() const;
			int GetHeight() const;
			int GetID() const;
			static Texture* Load(const char* Filename);
		
	private:
			GLuint id;
			int width;
			int height;
			int depth;
			BYTE* pixels;

			void init();
			void destroy();

			Texture(const Texture&); 
		protected:
	

	};
}
#endif