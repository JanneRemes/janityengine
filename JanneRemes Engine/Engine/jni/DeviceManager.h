#pragma once
#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <Win32toAndroid.h>

namespace KaMo
{
	class DeviceManager
	{
	public:
		DeviceManager();
		~DeviceManager();
		void FixAspectRatio(float desiredWidth,float desiredHeight,float width,float height);	//TODO: to DeviceManager
		
		float scale,blackBarH,blackBarV;
		float w,h;
	private:
		DeviceManager(const DeviceManager& deviceManager);
		

	};

}

#endif