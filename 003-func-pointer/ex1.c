/* exercise 1 Process Memory Allocator
 * Concepts: Pointer, User-defined functions, VirtualAlloc, CDECL
 * Task:
 * 1. Write a CDECL function PVOID CDECL MyAllocateMemory(SIZE_T size) that uses VirtualAlloc to allocate memory 
 * 2. Create another function VOID CDECL MyFreeMemory(PVOID ptr) that uses VirtualFree to release the memory
 * 3. In main(), call MyAllocateMemory to allocate 1024 bytes, fill the memory with a custom message, print it and then free the memory using MyFreeMemory
 *
 * Hints: 
 * - Use VirtualAlloc with MEM_COMMIT | MEM_RESERVE and PAGE_READWRITE
 * - For freeing, use MEM_RELEASE
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <memoryapi.h>
#include <tchar.h>
#include <string.h>


#define SIZE_ALLOC 1024

// Function signature for VirtualAlloc
/*LPVOID VirtualAlloc(
  [in, optional] LPVOID lpAddress,          -> starting address of the region for memory allocation 
  [in]           SIZE_T dwSize,             -> the size of the lpAddress 
  [in]           DWORD  flAllocationType,   -> type of memory allocation (MEM_COMMIT | MEM_RESERVE and PAGE_READWRITE) 
  [in]           DWORD  flProtect           -> memory protection for allocated region (PAGE_READWRITE)
);
*/
LPVOID CDECL MyAllocateMemory(SIZE_T memsize) {
    // VirtualAlloc with MEM_COMMIT | MEM_RESERVE and PAGE_READWRITE
    LPVOID lpVirtualAlloc = VirtualAlloc(NULL,memsize,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);
    if (lpVirtualAlloc==NULL) {
        _tprintf(_T("VirtualAlloc Failed\n"));
        return NULL;
    }
    return lpVirtualAlloc;
}

// Function signature for VirtualFree
/*BOOL VirtualFree(                 
  [in] LPVOID lpAddress,            -> A pointer to the base address of the allocated region 
  [in] SIZE_T dwSize,               -> Size of memory to be freed in bytes
  [in] DWORD  dwFreeType            -> Free operations (MEM_DECOMMIT or MEM_RELEASE)           
);
*/
LPSTR CDECL MyFreeMemory(PVOID ptr) {
    // VirtualFree to free allocated memory 
    if (VirtualFree(ptr,0,MEM_RELEASE) == TRUE) {
        return "[+] Memory Free!\n";
    }
    else {
        return "[!] Failure on VirtualFree!\n";
    }            
}

INT CDECL main(VOID) {
    //call MyAllocateMemory to allocate 1024 bytes
    LPVOID ptrMyAllocMemory = MyAllocateMemory(SIZE_ALLOC);
        
    if(ptrMyAllocMemory!=NULL) {
        printf("[*] Base address of allocated memory is: %p\n",ptrMyAllocMemory); 
        strcpy((char*)ptrMyAllocMemory,"Hello from allocated memory!");
        printf("[*] Message in allocated memory: %s\n",(char*)ptrMyAllocMemory);
        LPSTR ptrStrMyFreeMemory = MyFreeMemory(ptrMyAllocMemory);
        printf("%s",ptrStrMyFreeMemory);
    }
    /*printf("[*] Base address of allocated memory is: %p\n",ptrMyAllocMemory); 
    LPSTR *ptrStrMyFreeMemory = MyFreeMemory(ptrMyAllocMemory);
    printf("%s",ptrStrMyFreeMemory);
    */
    return ERROR_SUCCESS;
}



