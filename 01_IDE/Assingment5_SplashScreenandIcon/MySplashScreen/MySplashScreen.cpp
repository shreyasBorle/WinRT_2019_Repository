#include<windows.h>
#include "MyResource.h"
//#define MAKEINTRESOURCE MYICON

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//win main call
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declearation.
	WNDCLASSEX wndClass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("windows");

	//initializstion of the wndlcass
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszClassName = szAppName;
	wndClass.lpszMenuName = NULL;
	wndClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	//register wndlcass.
	RegisterClassEx(&wndClass);

	//create window
	hwnd = CreateWindow(szAppName, TEXT("My Splash Screen"),
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	
	//hBitmap = LoadBitmap(hInstance,MAKEINTRESOURCE(MYBITMAP)); //load the bitmap 
	//GetModuleHandle(hBitmap);
	

	//message loop

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,WPARAM wParam, LPARAM lParam)
{
	HDC hdc, cdc;
	PAINTSTRUCT ps;
	RECT rc;
	HINSTANCE hInstance;
	static HBITMAP hbitSS;
	BITMAP bitSS;

	switch (iMsg)
	{
	case WM_CREATE:
		hInstance = GetModuleHandle(NULL);
		hbitSS = LoadBitmap(hInstance, MAKEINTRESOURCE(MYBITMAP));
		if (hbitSS == NULL)
		{
			MessageBox(hwnd,TEXT("BMP didn't load !"),TEXT("message box"),MB_OK);
			DestroyWindow(hwnd);
		}

		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd,&rc);
		cdc = CreateCompatibleDC(NULL);
		SelectObject(cdc, hbitSS);
		GetObject(hbitSS, sizeof(BITMAP), &bitSS);
		StretchBlt(hdc, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, cdc, 0, 0, bitSS.bmWidth, bitSS.bmHeight, SRCCOPY);
		SetTextColor(hdc, RGB(0,0,0));
		SetBkColor(hdc, RGB(0, 255, 0));
		DeleteObject(cdc);
		EndPaint(hwnd,&ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
/*
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//variable decleare
	static HBITMAP hBitmap;
	HDC hdc;
	PAINTSTRUCT PS;
	RECT RC;
	HDC dc;
	BITMAP bitSS;

	//GetModuleHandle(hwnd);
	//LoadBitmap();
	HMODULE hModuleHandle;
	

	switch (iMsg)
	{
	case WM_CREATE:
		hModuleHandle = GetModuleHandle(NULL);
		if (hModuleHandle == NULL)
		{
			MessageBox(hwnd,TEXT("Test fail"),TEXT("error"),MB_OK);
			return 0;
		}
		hBitmap = LoadBitmap(hModuleHandle,MAKEINTRESOURCE(MYBITMAP));
		if (hBitmap == NULL)
		{
			MessageBox(hwnd, TEXT("Test fail"), TEXT("error"), MB_OK);
			return 0;
		}
		break;
	case WM_PAINT:
		BITMAP bm;
		HBITMAP hOldBitMap;
		BOOL bStrech;
		hdc = BeginPaint(hwnd, &PS);
		GetClientRect(hwnd, &RC);
		
		dc = CreateCompatibleDC(hdc);
		//hBitmapC = CreateCompatibleBitmap(hdc, 0, 0);
		if (dc == NULL)
		{
			MessageBox(hwnd, TEXT("Test fail"), TEXT("error"), MB_OK);
			return 0;
		}
		hOldBitMap = (HBITMAP) SelectObject(dc, hBitmap);
		GetObject(hBitmap, sizeof(bm), &bm);
		//hOldBitMap = (HBITMAP) SelectObject(dc, hBitmap);
		if (hOldBitMap == NULL)
		{
			MessageBox(hwnd, TEXT("TEST FAIL Old BITMAP null bhetat ahe"), TEXT("BITmap"), MB_OK);
			return 0;
		}
		//bStrech = StretchBlt(dc,12,12,80,80,hdc,10,10,50,50,SRCCOPY);
		bStrech = BitBlt(hdc, 500, 50, 1200, 1000, dc, 0, 0, SRCCOPY);

		if (bStrech == 0)
		{
			MessageBox(hwnd, TEXT("TEST FAIL b stretch"), TEXT("BITmap"), MB_OK);
			return 0;
		}
		//StretchBlt(hdc, 0, 0, 0, 0, NULL, 0, 0, 0, 0, NULL);
		SelectObject(dc, hOldBitMap);
		DeleteObject(dc);
		EndPaint(hwnd, &PS);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
*/

