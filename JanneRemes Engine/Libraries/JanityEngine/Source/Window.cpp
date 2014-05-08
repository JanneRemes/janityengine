#include <Window.h>
#include <Game.h>
#include <string>
#include <OpenGL.h>
#include <Util.h>
#pragma comment(lib, "opengl32.lib")
using namespace Janity;

HWND Window::handle;
HGLRC Window::OGLcontext;
HDC Window::hdc;

Window::Window(HINSTANCE instance,const char* windowName,int width,int height)
{
	//Windowclass, defines template for windows
	WNDCLASSEX wndClass;
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = wEventsProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = instance;
	wndClass.hIcon = NULL;
	wndClass.hCursor = NULL;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = L"windowClass";
	wndClass.hIconSm = NULL;

	//register window class
	if(!RegisterClassEx(&wndClass))
	{

	}

	//Creates window and return handle to it (a way to access the windows attributes)
	handle = CreateWindowA("windowClass", windowName, WS_POPUP, 0, 0, width, height, NULL, NULL, instance, NULL);

	if (handle == NULL)
	{
		//0.o
	}

	ShowWindow(handle, SW_SHOWNORMAL);
	UpdateWindow(handle);

	//pixel format description, only point worth of notice is if its 32 or 24 bit (alpha or no alpha)
	PIXELFORMATDESCRIPTOR pixelFormatDesc = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		24, 0, 0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	//Device Contex handle
	hdc = GetDC(handle); // Gets the display context

	if(hdc == NULL) {

		//0.o
	}

	int pixelFormat = ChoosePixelFormat(hdc, &pixelFormatDesc); // Chooses the pixel format

	if(pixelFormat == 0) {

		//0.o
	}

	// Sets the pixel format
	if(SetPixelFormat(hdc, pixelFormat, &pixelFormatDesc) == 0) {

		//return 0;
	}

	HGLRC hglrc = wglCreateContext(hdc); // Creates the rendering context

	if(hglrc == NULL) {

		//0.o
	}

	// Attaches the rendering context
	if(wglMakeCurrent(hdc, hglrc) == 0) {

		//return 0;
	}

	LoadOpenGLFunctions(); // Loads OpenGL 2.1 functions
	//glViewport(0, 0, width, height); // Sets up the OpenGL viewport

	MSG msg ={};
	Game* game = new Game(width,height+2,width,height);

		

	float dt = 0.0f;
	float oldTime = 0.0f;
	float newTime = 0.0f;
	// Main message loop:
	while(msg.message != WM_QUIT)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		else // We've processed all pending Win32 messages, and can now do a rendering update.
		{
		}

		oldTime = newTime;
		newTime =  Util::getTotalTime();
		dt = (newTime - oldTime) / 1000.0f;

		game->Update(dt);
		game->Draw();

		SwapBuffers(Window::hdc); // Swaps display buffers
	}
}


LRESULT CALLBACK Window::wEventsProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 1;
}


Window::~Window(void)
{
}

