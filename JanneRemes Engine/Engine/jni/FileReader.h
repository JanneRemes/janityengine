#pragma once
#ifndef FILE_READER
#define FILE_READER

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

namespace KaMo
{
	class FileReader
	{
		public:
			FileReader(const char* path);
			~FileReader();
		
			bool FileSeek(int offset,int relation);
			bool ReadBytes(unsigned int count,void*buffer);
		
			off_t FileLength();
		
			static AAssetManager * mgr;		
		private:
			AAsset* asset;
	};
}
#endif