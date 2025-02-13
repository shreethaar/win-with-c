#include <windows.h>

typedef DWORD PID; // based on Microsoft documentation

PID GetPid(HANDLE hProcess) {
    PID dwPid = GetProcessId(hProcess);
    return dwPid;
}
