#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");


	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT("My Hello DLL Cient"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hDll = NULL;
	typedef int(*MakeSquareFn)(int);
	MakeSquareFn pFn = NULL;

	int iResult, i;
	TCHAR str[225];
	i = 20;
	switch (iMsg)
	{
	case WM_CREATE:
		hDll = LoadLibrary(TEXT("G:\\WINRT\\WIN32 SDK\\01_IDE\\DLL\\DllClient\\DefDllExplicit\\DefDll.dll"));

		if (hDll == NULL)
		{
			MessageBox(hwnd, TEXT("Dll file not found it is null"), TEXT("Error Information"), MB_OK | MB_ICONINFORMATION);
		}

		pFn = (MakeSquareFn)GetProcAddress(hDll, "MakeSquare");
		if (pFn == NULL)
		{
			MessageBox(hwnd, TEXT("pFn is null funtion is not found"), TEXT("Error Information"), MB_OK);
		}

		iResult = pFn(i);

		wsprintf(str, TEXT("Square of %d is %d"), i, iResult);
		MessageBox(hwnd, str, TEXT("Message box Test"), MB_OK | MB_ICONINFORMATION);
		FreeLibrary(hDll);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}



