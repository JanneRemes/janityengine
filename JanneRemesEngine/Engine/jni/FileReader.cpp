//Provides filereading functionality under android.
//Hides FILE* reading under Windows.
// for Windows version of the file, see ../FileReader.cpp/.h

#include <FileReader.h>
using namespace KaMo;
	
AAssetManager* FileReader::mgr = NULL;

FileReader::FileReader(const char* path)
{
	asset = AAssetManager_open(mgr,path,2);
}

FileReader::~FileReader()
{
	AAsset_close(asset);
}

bool FileReader::FileSeek(int offset,int relation)
{
	if(AAsset_seek(asset,offset,relation)!=1)
		return true;
	return false;
}

bool FileReader::ReadBytes(unsigned int count,void*buffer)
{
	if(asset != NULL)
		if(AAsset_read(asset, buffer, count)>=0)
			return true;
	return false;
}

off_t FileReader::FileLength()
{
	off_t length = AAsset_getLength(asset);
	return length;
}