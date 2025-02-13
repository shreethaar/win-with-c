#include <windows.h>
#include <stdio.h>

typedef BOOL(WINAPI *DllMainFunc)(HMODULE, DWORD, LPVOID);

void listExportedFunctions(HMODULE hDLL) {
    if (!hDLL) {
        printf("Invalid DLL handle.\n");
        return;
    }

    // Get the address of the DLL in memory
    FARPROC dllBaseAddr = (FARPROC) hDLL;
    PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER) dllBaseAddr;
    PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((BYTE*)dllBaseAddr + dosHeader->e_lfanew);
    PIMAGE_EXPORT_DIRECTORY exportDir = (PIMAGE_EXPORT_DIRECTORY)((BYTE*)dllBaseAddr + 
                                    ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

    DWORD* funcNames = (DWORD*)((BYTE*)dllBaseAddr + exportDir->AddressOfNames);
    for (DWORD i = 0; i < exportDir->NumberOfNames; i++) {
        char* functionName = (char*)((BYTE*)dllBaseAddr + funcNames[i]);
        printf("Exported Function: %s\n", functionName);
    }
}

int main() {
    HMODULE hDLL = LoadLibrary("hello.dll"); // Change to the target DLL
    if (!hDLL) {
        printf("Failed to load DLL\n");
        return 1;
    }

    printf("Listing exported functions:\n");
    listExportedFunctions(hDLL);

    FreeLibrary(hDLL);
    return 0;
}
