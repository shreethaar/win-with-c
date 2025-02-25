/* exercise 2 Dynamic DLL Loader
 * Concepts: User-defined functions, Windows API (LoadLibraryA, GetProcAddress),CDECL
 * Task:
 * 1. Implement a function `HMODULE CDECL MyLoadDLL(LPCSTR dllName) that loads a DLL using LoadLibraryA.
 * 2. Implement another function `FARPROC CDECL MyGetFunctionAddress(HMODULE hModule, LPCSTR funcName) that retrieves the address of a function using `GetProcAddress`.
 * 3. In main(), load kernel32.dll, get the address of `GetCurrentProcessId`, and call it using a function pointer to print the current process ID.
 *
 * Hints:
 * 1. Use function pointers with proper casting to call the dynamically loaded function.
 *
 * i686-w64-mingw32-gcc -o my_program.exe main.c my_loaddll.c my_getprocaddr.c -lkernel32
 */

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


/* Function signature
 * HMODULE LoadLibraryA(
 *  [in] LPCSTR lpLibFileName -> the name of the module 
 * );
 */

HMODULE CDECL MyLoadDLL(LPCSTR lpDllName) {
    HMODULE hLoadLib = LoadLibraryA(lpDllName);
    if (hLoadLib == NULL) {
        printf("[!] Failed to load DLL. Error code: %lu\n", GetLastError());
        return NULL;
    }
    printf("[+] Successfully loaded %s\n", lpDllName);
    return hLoadLib;
}
/* Function signature
 * FARPROC GetProcAddress
 *  [in] HMODULE hModule    --> Handle to DLL module which contains the functions or variable
 *  [in] LPCSTR lpProcName  --> Function or variable name, or ordinal value
 * );
 */
DWORD CDECL MyGetFunctionAddress(HMODULE hModule, LPCSTR lpProcName) {
    FARPROC fpGetFuncAddr = GetProcAddress(hModule,lpProcName);
    if(fpGetFuncAddr==NULL) {
        return GetLastError();
    }
    printf("[+] Address of exported function for %s DLL is %p\n",lpProcName,fpGetFuncAddr);
    return ERROR_SUCCESS;
}


int main() {
    LPCSTR lpDllName = "kernel32.dll";
    LPCSTR lpProcName = "GetCurrentProcessId";

    HMODULE hModule = MyLoadDLL(lpDllName);
    if (hModule == NULL) {
        return EXIT_FAILURE;
    }

    // Get function address
    DWORD resultFuncAddr = MyGetFunctionAddress(hModule, lpProcName);
    if (resultFuncAddr != ERROR_SUCCESS) {
        printf("[!] Failed to get function address. Error code: %lu\n", resultFuncAddr);
    }

    FreeLibrary(hModule);
    return EXIT_SUCCESS;
}


