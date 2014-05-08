//Provides filereading functionality under Windows.
//Hides AssetManager* reading under Android.
// for Android version of the file, see jni/FileReader.cpp/.h

#include <FileReader.h>


FileReader::FileReader(const char* path)
{
	FilePath = std::string("Assets\\");
	FilePath+=path;
	file = fopen(FilePath.c_str(),"rb");
}

FileReader::~FileReader()
{
	fclose(file);
}

bool FileReader::FileSeek(int offset,int relation)
{
	if(fseek(file,offset,relation)!=1)
		return true;
	return false;
}

bool FileReader::ReadBytes(unsigned int count,void*buffer)
{
	if(file != NULL)
		if(fread(buffer, 1,count,file)==count)
			return true;
	return false;
}

long FileReader::FileLength()
{
	FileSeek(0,2);
	long length = ftell(file);
	FileSeek(0,0);
	return length;
}