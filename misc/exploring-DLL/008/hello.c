#include <Windows.h>
#include <stdio.h>

__declspec(dllexport) void say_hello() {
	printf("hello,world!\n");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	return TRUE;
}
