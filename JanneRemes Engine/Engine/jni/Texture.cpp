#include <Texture.h>
using namespace JanityEngine;

//public
Texture::Texture(const char* Filename)
{
	Load(Filename);
}

Texture::Texture(const Header& header, BYTE* _pixels)
	: id(0),
	  width(header.width),
	  height(header.height),
	  depth(header.depth),
	  pixels(_pixels)
{
	init();
}
Texture::~Texture()
{
	destroy();
}

int Texture::GetWidth() const
{
	return width;
}


int Texture::GetHeight() const
{
	return height;
}

int Texture::GetID() const
{
	return id;
}
Texture* Texture::Load(const char* Filename)
{
	FileReader *FR = new FileReader(Filename);
	BYTE* buffer = (BYTE*)malloc(sizeof(BYTE)*1);

	//header
	Header header;
	FR->FileSeek(2,0);			//TODO: stream != NULL
	FR->ReadBytes(1,buffer);
	header.type = buffer[0];
	//Debug.win32Assert((int)header.type == 2);
	free(buffer);

	buffer = (BYTE*)malloc(sizeof(BYTE)*4);
	FR->FileSeek(12,0);
	FR->ReadBytes(4, buffer);
	header.width = buffer[0] + buffer[1] * 256;
	header.height = buffer[2] + buffer[3] * 256;
	free(buffer);

	//bpp
	buffer = (BYTE*)malloc(sizeof(BYTE)*1);
	FR->FileSeek(16,0);
	FR->ReadBytes(1, buffer);
	header.depth = buffer[0];
	//Debug.win32Assert(header.depth == 24 || header.depth == 32);
	free(buffer);

	//data
	int datasize = header.width * header.height * header.depth/8;
	BYTE* pixels = (BYTE*)(malloc(sizeof(BYTE)*datasize));
	buffer = (BYTE*)malloc(sizeof(BYTE)*datasize);
	FR->FileSeek(18,0);
	FR->ReadBytes(datasize, buffer);

	//(pixels) rgb = bgr(tga)
	for(int i = 0; i < datasize; i +=4)
	{
		pixels[i+0] = buffer[i+2];	
		pixels[i+1] = buffer[i+1];
		pixels[i+2] = buffer[i+0];
		pixels[i+3] = buffer[i+3];
	}
	free(buffer);
	delete FR;

	return new Texture(header, pixels);
}

//private

void Texture::init()
{
	glGenTextures(1, &id);
	Debug::CheckGlError("glGenTextures: ");
	glBindTexture(GL_TEXTURE_2D, id);

	GLint format = GL_RGB;

	if(depth == 32)
	{
		format = GL_RGBA;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height,0, format, GL_UNSIGNED_BYTE, pixels);
	Debug::CheckGlError("glTexImage2D: ");
	glActiveTexture(GL_TEXTURE0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
}

void Texture::destroy()
{
	glDeleteTextures(1, &id);
	Debug::CheckGlError("Texture create object: ");

	delete[] pixels;
}


