#include <windows.h>

// Exported function
__declspec(dllexport) void sayHello() {
    MessageBox(0, "Hello from DLL!", "DLL Message", MB_OK);
}

// Entry Point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            break;
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
