
/*
C:\Program Files\Far Manager\Plugins\True Template\templates\source\Win32 OpenGL application.c
@@INCLUDE:$\templates\source\header-base@@
*/
/*--------------------------------------------------------------------------*/
/*
@@INCLUDE:$\templates\source\header-gnu@@
*/
/*--------------------------------------------------------------------------*/
/*
@@INCLUDE:$\templates\source\header-cvs@@
*/
/*==========================================================================*/
#ifndef __@@UPPERFILE_NAME@@_@@UPPERFILE_EXT@@__
#define __@@UPPERFILE_NAME@@_@@UPPERFILE_EXT@@__
/*==========================================================================*/
#include <windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
/*==========================================================================*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HGLRC hGLRC;
	static HDC hDC;
	PAINTSTRUCT ps;

	switch (iMsg)
	{
		case WM_CREATE:
		{
			int PixelFormat;
			PIXELFORMATDESCRIPTOR PixelFormatDescriptor=
			{
				// Size of PIXELFORMATDESCRIPTOR
				sizeof(PIXELFORMATDESCRIPTOR),
				// Version number
				1,
				// Support window
				PFD_DRAW_TO_WINDOW |
				// Support OpenGL
				PFD_SUPPORT_OPENGL |
				// Double buffered (Single default)
				PFD_DOUBLEBUFFER,
				// Indexed or RGBA color type (RGBA default)
				PFD_TYPE_RGBA,
				// 8-bit(ColorIndex) or 24-bit(RGBA) color depth (24-bits default)
				24,
				// Color bits ignored
				0, 0, 0, 0, 0, 0,
				// Alpha buffer
				8,
				// Alpha bit ignored
				0,
				// Accumulation buffer
				0,
				// Accum bits ignored
				0, 0, 0, 0,
				// Z-buffer
				32,
				// Stencil buffer
				8,
				// No auxiliary buffer
				0,
				// Main layer
				PFD_MAIN_PLANE,
				// Reserved
				0,
				// Layer masks ignored
				0, 0, 0
			};

			hDC = GetDC(hWnd);

			// Choosing and setting pixel format
			PixelFormat = ChoosePixelFormat(hDC, &PixelFormatDescriptor);
			if (PixelFormat != 0)
			{
				SetPixelFormat(hDC, PixelFormat, &PixelFormatDescriptor);

				// Creating OpenGL rendering context
				hGLRC = wglCreateContext(hDC);

				// Making is current
				if (hGLRC != NULL)
					wglMakeCurrent(hDC, hGLRC);
			}

			// Select clearing color
			glClearColor(0.0, 0.0, 0.0, 0.0);
			glShadeModel(GL_SMOOTH);
			return 0;
		}
		case WM_SIZE:
		{
			glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
			glMatrixMode(GL_MODELVIEW);
			return 0;
		}
		case WM_PAINT:
		{
			BeginPaint(hWnd, &ps);
			wglMakeCurrent(hDC,hGLRC);

			// Clear all pixels
			glClear(GL_COLOR_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

			// Clear the matrix
			glLoadIdentity();

			// Viewing transformation
			gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

			// Do a simple rotations
			glRotated(10.0, 1.0, 0.0, 0.0);
			glRotated(15.0, 0.0, 1.0, 0.0);
			glRotated(20.0, 0.0, 0.0, 1.0);

			// Render triangle
			glBegin(GL_TRIANGLES);
			{
				glColor3f(1.0, 0.0, 0.0);
				glVertex2f(1.0, 1.0);
				glColor3f(0.0, 1.0, 0.0);
				glVertex2f(0.0, 1.0);
				glColor3f(0.0, 0.0, 1.0);
				glVertex2f(1.0, 0.0);
			}
			glEnd();

			// Start processing buffered OpenGL routines
			glFlush();
			SwapBuffers(hDC);
			EndPaint(hWnd, &ps);
			return 0;
		}
		case WM_DESTROY:
		{
			wglMakeCurrent(hDC, hGLRC);

			// Release device context
			ReleaseDC(hWnd, hDC);

			// Delete rendering context
			wglMakeCurrent(NULL, NULL);
			wglDeleteContext(hGLRC);
			PostQuitMessage(0);
			return 0;
		}
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}
/*==========================================================================*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	@@HERE@@const char ClassName[] = "Win32 class";
	WNDCLASSEX WndClass;
	HWND hWnd;
	MSG Msg;

	WndClass.cbSize			= sizeof(WndClass);
	WndClass.style			= CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc	= WndProc;
	WndClass.cbClsExtra		= 0;
	WndClass.cbWndExtra		= 0;
	WndClass.hInstance		= hInstance;
	WndClass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName	= NULL;
	WndClass.lpszClassName	= ClassName;
	WndClass.hIconSm		= LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&WndClass);

	hWnd = CreateWindow(ClassName,	// Window class name
		"The Hello Program",		// Window caption
		WS_OVERLAPPEDWINDOW,		// Window style
		CW_USEDEFAULT,				// Initial x position
		CW_USEDEFAULT,				// Initial y position
		CW_USEDEFAULT,				// Initial x size
		CW_USEDEFAULT,				// Initial y size
		NULL,						// Parent window handle
		NULL,						// Window menu handle
		hInstance,					// Program instance handle
		NULL);						// Creation parameters

	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return (int)Msg.wParam;
}
/*==========================================================================*/
#endif
