#include <Windows.h>

__declspec(dllexport) int add(int a, int b) {
	return a+b;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	return TRUE;
}

