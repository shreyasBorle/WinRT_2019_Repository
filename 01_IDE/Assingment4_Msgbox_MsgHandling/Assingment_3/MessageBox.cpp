#include<windows.h>

LRESULT CALLBACK WndProc(HWND , UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Local variable
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("Windows");
	MessageBox(NULL,TEXT("Before wndclass start"),TEXT("Before WNDCLASS"),MB_OK);
	//code
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Registration
	RegisterClassEx(&wndclass);

	//creation of window
	hwnd = CreateWindow(AppName,
		TEXT("Shreyas Window"),
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
	TCHAR str[255];
	switch (iMsg)
	{
	case WM_CREATE:
		wsprintf(str, TEXT("Window is arived WM_CREATE"));
		MessageBox(hwnd, str, TEXT("WM_CREATE Message"), MB_OK|MB_ICONINFORMATION);
		break;
	case WM_KEYDOWN:
		wsprintf(str,TEXT("KEYDOWM is presed"));
		MessageBox(hwnd,str,TEXT("WM_KEYDOWN Message"),MB_OK|MB_ICONINFORMATION);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd,TEXT("WM_LBUTTONDOWN is press"), TEXT("WM_LBUTTOnDOWM Message"),MB_OK|MB_ICONINFORMATION);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}