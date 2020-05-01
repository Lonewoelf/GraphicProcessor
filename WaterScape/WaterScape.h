#pragma once

#include <windows.h>
#include <iostream>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>

#define _CRT_SECURE_NO_DEPRECATE

class WaterScape
{
public:
	WaterScape();
	WaterScape(HWND hwnd);
	~WaterScape();

	int WINAPI WinMain(HINSTANCE instance, HINSTANCE prev, PSTR cmdline, int ishow);
	WPARAM MainLoop();
	void ChangeToFullScreen();
	HWND CreateMyWindow(LPCWSTR strWindowName, int width, int height, DWORD dwStyle, bool bFullScreen, HINSTANCE hInstance);
	bool SetupPixelFormat(HDC hdc);
	void SizeOpenGLScreen(int width, int height);
	void InitializeOpenGL(int width, int height);
	void RenderScene();

	static LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam); //Solution for using this function within a class
	LRESULT CALLBACK realWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

private:

	bool fullscreen;
	HWND  windowHandle;									// This is the handle for the window
	RECT  windowDimensions;								// This holds the window dimensions
	HDC   deviceContext;								// General HDC - (handle to device context)
	HGLRC renderContext;								// General OpenGL_DC - Our Rendering Context for OpenGL
	HINSTANCE windowInstance;							// This holds our window hInstance
	float frameTime;									// Global float that stores the elapsed time between the current and last frame

};

