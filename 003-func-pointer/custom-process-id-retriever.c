/* Custom Process ID Retriever
 * Concepts: User-defined functions, Pointers, CDECL, GetCurrentProcessId
 * 
 * Task:
 * 1. Implement a function DWORD CDECL MyCustomGetID(PDWORD pPid) that retrieves the current process ID using GetCurrentProcessId and stores it in the pointer provided (pPid)
 * 2. In main(), declare a DWORD variable, pass its address to MyCustomGetPID, and print the retrieved process ID 
 *
 * Hints:
 * 1. Validate the pointer before dereferencing to avoid crashes
 */

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <processthreadsapi.h>
#include <tlhelp32.h>


/* Function signature
 * DWORD GetCurrentProcessId();
 * Return value is the process identifier of the calling process
 */

DWORD CDECL MyCustomGetPID() {
    return GetCurrentProcessId();
}



DWORD GetProcessIDByName(const char *procName) {
    DWORD pid = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    PROCESSENTRY32 pe;
    if(Process32First(hSnapshot,&pe)) {
        do {
            if(strcmp(pe.szExeFile,procName) == 0){
                    pid=pe.th32ProcessID;
                    break;
            }
        } 
        while(Process32Next(hSnapshot,&pe));
    }
    CloseHandle(hSnapshot);
    return pid;
}

INT CDECL main() {
    DWORD dwProcID = MyCustomGetPID();
    printf("[+] Current PID: %lu\n",dwProcID);

    dwProcID = GetProcessIDByName("notepad.exe");
    if(dwProcID!=0) {
        printf("[+] Notepad.exe PID: %lu\n",dwProcID);
    }
    else {
        printf("[!] Notepad.exe not found!\n");
    }
    
    return ERROR_SUCCESS;
}
