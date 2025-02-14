#include <Windows.h>

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved )  // reserved
{
	return true;
}



__declspec(dllexport) int Add(int a, int b) {
	return a+b;
}
