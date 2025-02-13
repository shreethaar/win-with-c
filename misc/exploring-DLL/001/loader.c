#include <windows.h>
#include <stdio.h>

typedef void (*ExtractFunc)();

int main() {
	HMODULE hDll=LoadLibrary("mydll.dll");
	if(!hDll) {
		printf("Failed to load DLL: %lld\n",GetLastError());
		return 1;
	}
	ExtractFunc extractFunc = (ExtractFunc)GetProcAddress(hDll,"ExtractAndOpenTextFile");
	if(!extractFunc) {
		printf("Failed to locate function: %lu\n",GetLastError());
		FreeLibrary(hDll);
		return 1;
	}
	extractFunc();
	FreeLibrary(hDll);
	return 0;
}

