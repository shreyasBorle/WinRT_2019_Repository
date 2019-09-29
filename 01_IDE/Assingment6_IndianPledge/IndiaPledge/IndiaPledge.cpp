#include<Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpzCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("My India Pleadge");

	//initialization of the wnd class
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

	//rgister class
	RegisterClassEx(&wndclass);

	//createwindow
	hwnd = CreateWindow(szAppName, TEXT("My India Pleadge"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	
	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//vaiable decalration
	PAINTSTRUCT PS;
	RECT RC;
	HDC hdc;
	
	//TCHAR MyPleadge[] = TEXT("India is my country. All Indians are my Brothers and Sisters. \r\n I love my country and I am proud of its rich and varied heritage. I shall always strive to be worthy of it. I shall give my parents, teachers and all elders respect and treat everyone with courtesy. To my country and my people, I pledge my devotion. In their well being and prosperity alone, lies my happiness.");
	TCHAR MyPleadge[] = TEXT("India is my country. All Indians are my Brothers and Sisters.\n");
	TCHAR MyPleadge1[] = TEXT("I love my country and I am proud of its rich and varied heritage.\n");
	TCHAR MyPleadge5[] = TEXT("I shall always strive to be worthy of it.");
	TCHAR MyPleadge2[] = TEXT("I shall give my parents, teachers and all elders respect and treat everyone with courtesy.");
	TCHAR MyPleadge3[] = TEXT("To my country and my people, I pledge my devotion. ");
	TCHAR MyPleadge4[] = TEXT("In their well being and prosperity alone, lies my happiness.");
	//message handle
	switch (iMsg)
	{
	case WM_CREATE:
		
		break;
	case WM_PAINT:
		GetClientRect(hwnd, &RC);
		hdc = BeginPaint(hwnd, &PS);
		SetBkColor(hdc, RGB(0, 0, 0));
		SetTextColor(hdc, RGB(255, 128, 0));
		//DrawText(hdc, MyPleadge, 61, &RC, DT_VCENTER| DT_CENTER|DT_SINGLELINE);
		//DrawText(hdc, MyPleadge, -1, &RC,DT_CENTER|DT_WORDBREAK);
		RC.bottom = 500;
		DrawText(hdc, MyPleadge, -1, &RC, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
		RC.bottom = 500+50;
		DrawText(hdc, MyPleadge1, -1, &RC, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
		SetTextColor(hdc, RGB(255, 255, 255));
		RC.bottom = 500+100;
		DrawText(hdc, MyPleadge5, -1, &RC, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
		RC.bottom = 500+150;
		DrawText(hdc, MyPleadge2, -1, &RC, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
		RC.bottom = 500+200;
		SetTextColor(hdc, RGB(0, 255, 0));
		DrawText(hdc, MyPleadge3, -1, &RC, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
		RC.bottom = 500+250;
		DrawText(hdc, MyPleadge4, -1, &RC, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
		RC.bottom = 500+300;
		
		//SetBkColor(hdc, RGB(0,0,0));
		//SetTextColor(hdc,RGB(255, 128, 0));
		//TextOut(hdc, RC.left, RC.top, MyPleadge, ARRAYSIZE(MyPleadge));
		//TextOut(hdc, RC.left, 15, MyPleadge1, ARRAYSIZE(MyPleadge1));
		//SetTextColor(hdc, RGB(255, 255, 255));
		//TextOut(hdc, RC.left, 30, MyPleadge5, ARRAYSIZE(MyPleadge5));
		//TextOut(hdc, RC.left, 55, MyPleadge2, ARRAYSIZE(MyPleadge2));
		//SetTextColor(hdc, RGB(0, 255, 0));
		//TextOut(hdc, RC.left, 75, MyPleadge3, ARRAYSIZE(MyPleadge3));
		//TextOut(hdc, RC.left, 105, MyPleadge4, ARRAYSIZE(MyPleadge4));
		//TextOut(hdc,RC.left,RC.top,MyPleadge,ARRAYSIZE(MyPleadge));
		
		GetTextAlign(hdc);
		
		SetTextAlign(hdc,TA_RIGHT);
		EndPaint(hwnd, &PS);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}