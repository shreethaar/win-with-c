#include <Windows.h>
#include <stdio.h>

#define __cdecl CDECL               // C Runtime API Calling Convention
#define COUNTOF_NAMES 4

/// <summary>
/// the procedure obtains the PID of self
/// </summary>
/// <param name=""></param>
/// <returns>DWORD of PID</returns>
DWORD					//return type of function
WINAPI					// using stdcall calling convention with WINAPI
MyGetCurrentProcID(VOID);  //function name

FARPROC
WINAPI
MyGetProcAddress(VOID);

HANDLE
WINAPI
MyLoadLibraryA();

BOOL
WINAPI
MyEnumProcesses();

INT
CDECL
main(VOID) 
{
	printf("[#] %s:%d this program was compiled on %s %s\n", __FUNCTION__, __LINE__, __DATE__, __TIME__);
	// printf("---> %s\n",__FUNCTION__); // function called
	// printf("<--- %s\n",__FUNCTION__); // function returned

	// Pointers is a variable which hold a memory address
	ULONG ulCourse = 670UL;				// local variables located at the stack
	PULONG ptrCourse = &ulCourse;       // pointer of ptrCourse contains the address of ulCourse
	printf("[#] %s:%d the address of ulCourse is 0x%p\n", __FUNCTION__, __LINE__, ptrCourse);
	printf("[#] %s:%d after deref ptrCourse, the value is %lu\n", __FUNCTION__, __LINE__, *ptrCourse);

	// (PUCHAR)VirtualAlloc();			// Pointer casting 
	// LoadLibraryA();

	PCHAR AddressOfNames[COUNTOF_NAMES] = { "MyGetCurrentProcID","MyGetProcAddress","MyLoadLibraryA","MyEnumProcesses" };
	PVOID AddressOfFunctions[COUNTOF_NAMES] = { MyGetCurrentProcID,MyGetProcAddress,MyLoadLibraryA,MyEnumProcesses };
	ULONG AddressOfNameOrdinals[COUNTOF_NAMES] = { 0,1,2,3 };

	for (ULONG i = 0UL;i < COUNTOF_NAMES;i++) 
	{
		if(0==strcmp("MyLoadLibraryA",AddressOfNames[i]))
		{
			printf("[+] found the procedure at index %lu\n", i);
			break;
		}
		else 
		{
			printf("[!] procedure not found at index %lu\n", i);
		}
	}

	return ERROR_SUCCESS;
}

DWORD
WINAPI
MyGetCurrentProcID(VOID)
{

	return ERROR_SUCCESS;
}

FARPROC
WINAPI
MyGetProcAddress() 
{

	return NULL;
}

HANDLE
WINAPI
MyLoadLibraryA()
{

	return INVALID_HANDLE_VALUE;
}

BOOL
WINAPI
MyEnumProcesses()
{

	return TRUE;
}