#include<windows.h>

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwRegion, LPVOID lpReserved)
{
	switch (dwRegion)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;

	}
	return(TRUE);

}

extern "C" int MakeSquare(int num)
{
	return(num*num);
}

extern "C" BOOL IsNumberNegative(int num)
{
	if (num >= 0)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}


