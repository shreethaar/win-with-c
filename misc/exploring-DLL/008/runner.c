#include <Windows.h>
#include <stdio.h>

int main() {
	HMODULE hDLL = LoadLibrary("hello.dll");
	if(!hDLL) {
		printf("Failed to load DLL\n");
		return 1;
	}

	void (*say_hello)() = (void (*)()) GetProcAddress(hDLL, "say_hello");
	if (!say_hello) {
		printf("Failed to find function\n");
		FreeLibrary(hDLL);
		return 1;
	}
	
	say_hello();
	FreeLibrary(hDLL);
	return 0;
}

