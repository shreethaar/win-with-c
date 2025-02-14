#include <windows.h>
#include <stdio.h>

typedef void (*HelloFunc)();

int main() {
    HMODULE hDll = LoadLibrary("hello.dll");
    if (!hDll) {
        printf("Failed to load DLL\n");
        return 1;
    }

    HelloFunc sayHello = (HelloFunc)GetProcAddress(hDll, "sayHello");
    if (!sayHello) {
        printf("Function not found\n");
        return 1;
    }

    sayHello(); // Call DLL function

    FreeLibrary(hDll);
    return 0;
}
