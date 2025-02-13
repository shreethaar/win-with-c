#include <Windows.h>
#include <stdio.h>

int main() {
	HMODULE hDLL = LoadLibrary("simpledll.dll");
	if(!hDLL) {
		printf("Failed to load DLL\n");
		return 1;
	}
	int (*addFunc)(int,int)=(int (*)(int,int)) GetProcAddress(hDLL,"add");
	if(!addFunc) {
		printf("Failed to find function\n");
		FreeLibrary(hDLL);
		return 1;
	}
	printf("3+5=%d\n",addFunc(3,5));
	FreeLibrary(hDLL);
	return 0;
}

