// C program that demonstrates the usage of memory-mapped files with CreateFileMappingA and MapViewOfFile
//
// Scenario:
// - the program creates (or opens) a file 
// - maps it into memory 
// - writes data to the mapped memory 
// - unmaps and closes everything 


#include <cstddef>
#include <windows.h>
#include <stdio.h>


#define FILE_NAME "testfile.txt"
#define MAPPING_NAME "Local\\MyFileMapping"
#define BUFFER_SIZE 1024

int main() {
    HANDLE hFile, hMap;
    LPVOID pMappedMemory;
    
    // Step 1: Open or create a file
    hFile=CreateFileA(
            FILE_NAME,GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
            );

    if(hFile==INVALID_HANDLE_VALUE) {
        printf("Error opening file: %lu\n", GetLastError());
        return 1;
    }

    // Step 2: Create a File Mapping Object
    hMap=CreateFileMappingA(
            hFile,NULL,PAGE_READWRITE,0,BUFFER_SIZE,MAPPING_NAME
            );
    if(!hMap) {
        printf("Error creating file mapping: %lu\n",GetLastError());
        CloseHandle(hFile);
        return 1;
    }

    // Step 3: Map View of File into Process Memory 
    pMappedMemory=MapViewOfFile(hMap,FILE_MAP_WRITE,0,0,BUFFER_SIZE);
    if(!pMappedMemory) {
        printf("Error mapping view of file: %lu\n",GetLastError());
        CloseHandle(hMap);
        CloseHandle(hFile);
        return 1;
    }

    // Step 4: Write Data to Mapped Memory 
    sprintf((char *)pMappedMemory, "Hello, Memory-Mapped File!\n");
    printf("Data written: %s\n",(char *)pMappedMemory);

    // Step 5: Cleanup - Unmap, Close Handles
    UnmapViewOfFile(pMappedMemory);
    CloseHandle(hMap);
    CloseHandle(hFile);

    return 0;
}


// Outputs (Contents of testfile.txt after running the program)
// Hello, Memory-Mapped File!
// 
// This method is faster than normal file I/O because it avoid repeated usage of ReadFile and WriteFile system calls
