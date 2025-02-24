#include <Windows.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 3
INT main(VOID) {
	// type var_name[]; 
	INT classes[ARRAY_SIZE] = {670,770,870};
	printf("Index 0: %i, Index 1: %i, Index 2: %i\n", classes[0], classes[1], classes[2]);

	classes[1] = 660;
	printf("Index 0: %i, Index 1: %i, Index 2: %i\n", classes[0], classes[1], classes[2]);

    
	CHAR cmd[] = "cmd.exe";
	SIZE_T cmdlen = strlen(cmd);
	printf("strlen(cmd) -> %I64i\n", cmdlen);

	//cmd[3] = "\0"; // ascii 0 value 
	cmd[3] = '\0';   // null value, strlen relies on null bytes
	printf("The string is %s\n", cmd);
	printf("strlen(cmd -> %I64i\n", cmdlen);
	
	SIZE_T cmdLenSizeof = sizeof(cmd);
	printf("sizeof(cmd) -> %I64i\n", cmdLenSizeof);
	//sizeof doesnt care about null bytes, returns the size of variable and the bytes contain

	//compare strings
	CHAR k32[] = "kernel32.dll";  
	CHAR kbase[] = "kernelbase.dll";
	CHAR ntdll[] = "ntdll.dll";
	printf("\n");
	printf("is k32 == kbase? -> %i\n", strcmp(k32, kbase));
	printf("is ntdll == kbase? -> %i\n", strcmp(ntdll, kbase));
	printf("is ntdll == ntdlL? -> %in\n", strcmp(ntdll, ntdll));
	printf("atoi('23') -> %i\n", atoi("23"));
	
	PCHAR AddressofNames[ARRAY_SIZE] = {"GetProcAddress","LoadLibraryA","LoadLibraryW"};
	PVOID AddressOfFunctions[ARRAY_SIZE] = {&AddressofNames[0],&AddressofNames[1],&AddressofNames[2]};

	return ERROR_SUCCESS;
}
