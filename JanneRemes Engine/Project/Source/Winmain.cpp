#include <Windows.h>
#include <JanityEngine\Include\Window.h>
#include <JanityEngine\Include\Win32toAndroid.h>

/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) 
{
	Window * window = new Window(hInstance,"MyWindow",1280,752);
	return 0;
}

*/
int main(void)
{
	Window * window = new Window(NULL,"MyWindow",1280,752);
	return 0;
}