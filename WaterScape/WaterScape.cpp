#include "WaterScape.h"

#define SCREEN_WIDTH 800								// We want our screen width 800 pixels
#define SCREEN_HEIGHT 600								// We want our screen height 600 pixels
#define SCREEN_DEPTH 16									// We want 16 bits per pixel


WaterScape::WaterScape()
{

}

WaterScape::WaterScape(HWND hwnd)
{
	this->fullscreen = true;
	this->windowHandle = hwnd;
	GetClientRect(windowHandle, &this->windowDimensions);
	this->deviceContext = GetDC(hwnd);
	this->renderContext = wglCreateContext(deviceContext);
	this->windowInstance;
	this->frameTime = 0; 
	wglMakeCurrent(deviceContext, renderContext);
}

WaterScape::~WaterScape()
{
	if (renderContext)
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(renderContext);
	}

	if (deviceContext)
		ReleaseDC(windowHandle, deviceContext);

	if (this->fullscreen)
	{
		ChangeDisplaySettings(NULL, 0);	
		ShowCursor(TRUE);
	}

	UnregisterClass(L"WaterScape", windowInstance);	

	PostQuitMessage(0);	
}

int __stdcall WaterScape::WinMain(HINSTANCE instance, HINSTANCE prev, PSTR cmdline, int ishow)
{
	return 0;
}

WPARAM WaterScape::MainLoop()
{
	return WPARAM();
}

void WaterScape::ChangeToFullScreen()
{
	DEVMODE settings;

	settings.dmPelsWidth = SCREEN_WIDTH;			// Selected Screen Width
	settings.dmPelsHeight = SCREEN_HEIGHT;			// Selected Screen Height
	settings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

	ChangeDisplaySettings(&settings, CDS_FULLSCREEN);
}

HWND WaterScape::CreateMyWindow(LPCWSTR strWindowName, int width, int height, DWORD dwStyle, bool bFullScreen, HINSTANCE hInstance)
{
	HWND hWnd;
	WNDCLASS wndclass;
	LPCWSTR name = L"WaterScape";

	memset(&wndclass, 0, sizeof(WNDCLASS));				// Init the size of the class
	wndclass.style = CS_HREDRAW | CS_VREDRAW;			// Regular drawing capabilities
	wndclass.lpfnWndProc = WinProc;						// Pass our function pointer as the window procedure
	wndclass.hInstance = hInstance;						// Assign our hInstance
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// General icon
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);		// An arrow for the cursor
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	// A white window
	wndclass.lpszClassName = name;						// Assign the class name

	RegisterClass(&wndclass);							// Register the class

	if (bFullScreen && !dwStyle) 						// Check if we wanted full screen mode
	{													// Set the window properties for full screen mode
		dwStyle = WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		ChangeToFullScreen();							// Go to full screen
		ShowCursor(FALSE);								// Hide the cursor
	}
	else if (!dwStyle)									// Assign styles to the window depending on the choice
		dwStyle = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	windowInstance = hInstance;							// Assign our global hInstance to the window's hInstance

	RECT rWindow;
	rWindow.left = 0;								// Set Left Value To 0
	rWindow.right = width;							// Set Right Value To Requested Width
	rWindow.top = 0;								// Set Top Value To 0
	rWindow.bottom = height;							// Set Bottom Value To Requested Height

	AdjustWindowRect(&rWindow, dwStyle, false);		// Adjust Window To True Requested Size

														// Create the window
	hWnd = CreateWindow(name, strWindowName, dwStyle, 0, 0,
		rWindow.right - rWindow.left, rWindow.bottom - rWindow.top,
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return NULL;								// If we could get a handle, return NULL

	ShowWindow(hWnd, SW_SHOWNORMAL);					// Show the window
	UpdateWindow(hWnd);									// Draw the window

	SetFocus(hWnd);										// Sets Keyboard Focus To The Window	

	return hWnd;
}

bool WaterScape::SetupPixelFormat(HDC hdc)
{
	return false;
}

void WaterScape::SizeOpenGLScreen(int width, int height)
{
}

void WaterScape::InitializeOpenGL(int width, int height)
{
}

void WaterScape::RenderScene()
{
}

LRESULT WaterScape::WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	WaterScape* scape = reinterpret_cast<WaterScape*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

	if (scape) {
		return scape->realWndProc(hwnd, message, wParam, lParam);
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT WaterScape::realWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT    ps;

	switch (message)
	{
	case WM_PAINT:														// If we need to repaint the scene
		BeginPaint(windowHandle, &ps);									// Init the paint struct		
		EndPaint(windowHandle, &ps);									// EndPaint, Clean up
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:								// Check if we hit the ESCAPE key.
			PostQuitMessage(0);						// Tell windows we want to quit
			break;
		}
		break;

	case WM_CLOSE:										// If the window is closed
		PostQuitMessage(0);								// Tell windows we want to quit
		break;

	default:
		break;
	}

	return DefWindowProc(windowHandle, message, wParam, lParam);
}
