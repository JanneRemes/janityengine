#pragma once
#ifndef FILE_READER
#define FILE_READER
#include <stdio.h>
#include <string>
class FileReader
{
	public:
		FileReader(const char* path);
		~FileReader();
		
		bool FileSeek(int offset,int relation);
		bool ReadBytes(unsigned int count,void*buffer);

		long FileLength();
	private:
		FILE* file;
		std::string FilePath;
};

#endif