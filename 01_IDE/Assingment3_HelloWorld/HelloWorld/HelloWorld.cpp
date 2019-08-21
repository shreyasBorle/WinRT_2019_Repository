#include<windows.h>

LRESULT CALLBACK  WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine,int iCmdShow) 
{
	//Variable Initialization
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("Windows");

	//code

	wndclass.cbSize=sizeof(WNDCLASSEX);
	wndclass.style = CS_VREDRAW | CS_HREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Register the class
	RegisterClassEx(&wndclass);

	//create the window
	hwnd = CreateWindow(AppName,
		TEXT("HELLO WORLD"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//code
	HDC hdc;
	PAINTSTRUCT PS;
	RECT RC;
	TCHAR str[] = TEXT("HELLO WORLD!!!!!");

	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		//get changing the rectangle
		GetClientRect(hwnd,&RC);
		//call specialist i.e. create the hdc
		hdc = BeginPaint(hwnd,&PS);
		//set text color
		SetTextColor(hdc, RGB(0,255,0));
		//set backgroud color
		SetBkColor(hdc, RGB(0,0,0));
		//draw the text
		DrawText(hdc,str,-1,&RC,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		//sent back the specilist and stopp panting
		EndPaint(hwnd,&PS);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}