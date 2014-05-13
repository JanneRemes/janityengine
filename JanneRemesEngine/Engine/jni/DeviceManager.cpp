#include <DeviceManager.h>
using namespace JanityEngine;


DeviceManager::DeviceManager()
{
	  scale = blackBarH = blackBarV = 0;
}

DeviceManager::~DeviceManager()
{
}


void DeviceManager::FixAspectRatio(float desiredWidth,float desiredHeight,float width,float height)
{
	//Calculate desired Aspect Ratio
	float dAR =  desiredWidth/ desiredHeight;

	//Calculate real Aspect Ratio
	float rAR = width/height;
	
	//Check Aspect Ratio's
	if(dAR==rAR)
	{
		//Same aspect, no letterboxing needed!
		scale = width/desiredWidth;
	}
	else if(dAR<rAR)
	{
		//Horizontal letterboxing needed!
		scale = height/desiredHeight;
		blackBarH = (width-scale*desiredWidth)/2;
		
	}
	else
	{
		//Vertical letterboxing needed!
		scale = width/desiredWidth;
		blackBarV = (height-(scale*desiredHeight))/2;
	}
	 w = desiredWidth*scale;
	 h = desiredHeight*scale;
	 glViewport((int)blackBarH, (int)blackBarV,(int)w,(int)h); // Sets up the OpenGL viewport
	
 }


 //Private
DeviceManager::DeviceManager(const DeviceManager& deviceManager)
{
}