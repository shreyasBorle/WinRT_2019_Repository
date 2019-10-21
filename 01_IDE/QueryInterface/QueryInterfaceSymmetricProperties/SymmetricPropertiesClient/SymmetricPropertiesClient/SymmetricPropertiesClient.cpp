#include<windows.h>
#include"SymmetricPropertiesDll.h"

LRESULT CALLBACK  WndProc(HWND, UINT, WPARAM, LPARAM);

ISum *pISum = NULL;
ISubtract *pISubtract = NULL;
ISum *pISumAgain = NULL;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Variable Initialization
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("ComClient");
	HRESULT hr;

	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM library can not be initilialize.\nProgram will Now Exit."), TEXT("Program error"), MB_OK);
		exit(0);
	}
	//code

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_VREDRAW | CS_HREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Register the class
	RegisterClassEx(&wndclass);

	//create the window
	hwnd = CreateWindow(AppName,
		TEXT("Client Of COM Dll Server"),
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

	CoUninitialize();
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	void SafeInterfaceRelease(void);
	//code
	TCHAR str[255];
	int iNum1, iNum2, iSum = 0;
	HRESULT hr;
	HRESULT hrSum;
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void **)&pISum);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("iSum interface can not be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		iNum1 = 50;
		iNum2 = 50;
		pISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);
		wsprintf(str, TEXT("Sum of %d and %d is %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		hrSum = pISum->QueryInterface(IID_ISum, (void **)&pISumAgain);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("ISumAgian Interface can not be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		if (hr == hrSum)
		{
			MessageBox(hwnd,TEXT("old Isum and new Isumagain is same ans sum will be differ"),TEXT("Result"),MB_OK);
		}
		iNum1 = 200;
		iNum2 = 200;
		pISumAgain->SumOfTwoIntegers(iNum1, iNum2, &iSum);
		wsprintf(str, TEXT("Sum of %d and %d is %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);
		pISumAgain->Release();
		pISumAgain = NULL;
		pISum->Release();
		pISum = NULL;
		

		DestroyWindow(hwnd);
		/*wsprintf(str, TEXT("Window is arived WM_CREATE"));
		MessageBox(hwnd, str, TEXT("WM_CREATE Message"), MB_OK | MB_ICONINFORMATION);*/
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}




