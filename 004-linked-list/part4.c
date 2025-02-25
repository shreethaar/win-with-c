#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include "ListHelpers.h"

#define __cdecl CDECL

#define RTL_CONSTANT_STRINGA(s) {sizeof(s)-sizeof((s)[0]),sizeof(s),(PSTR)s}
#define RTL_CONSTANT_STRINGW(s) {sizeof(s)-sizeof((s)[0]),sizeof(s),(PWSTR)s}

#ifdef UNICODE 
#define RTL_CONSTANT_STRING RTL_CONSTANT_STRINGW
#else 
#define RTL_CONSTANT_STRING RTL_CONSTANT_STRINGA
#endif

// reason for typedef struct is to remove repetitions
typedef struct _UNICODE_STRING 
{
	USHORT Length;			// every member in the struct ends with ;
	USHORT MaximumLength;
	PWSTR Buffer;			// PWSTR -> pointer to wchar 
} UNICODE_STRING, * PUNICODE_STRING;
	
#pragma pack(1)				// pack structure members with single byte boundary, NO PADDING 
typedef struct _STRING_EX
{
	USHORT Length;			
	USHORT MaximumLength;
#ifdef UNICODE 
	PWSTR Buffer;
#else 
	PSTR Buffer;
#endif

} STRING_EX, *PSTRING_EX;

typedef struct _PROCESS_INFO_EX
{
	DWORD ProcessID;
	LIST_ENTRY ProcessInfoLinks;
	UNICODE_STRING Name;
	HMODULE ImageBaseAddress;
	HANDLE CurrentThread;
}PROCESS_INFO_EX, *PPROCESS_INFO_EX;


/// <summary>
/// DumpStruct blah blah
/// </summary>
/// <param name="ProcessName">pointer to STRING_EX object</param>
/// <returns>VOID</returns>
VOID
WINAPI
DumpStruct(
	_In_ PSTRING_EX ProcessName    //SAL annonation (structure annonation language)

);


INT
CDECL
main(VOID)
{
	DWORD dwStatus = ERROR_SUCCESS;

	STRING_EX Name;
	STRING_EX Name2 = { 0 };
	STRING_EX Name3;
	RtlSecureZeroMemory(&Name3, sizeof(STRING_EX));    // zero-out function for structure with runtime library

	PTSTR s = _T("Hello");  // _T is expands to WCHAR (with tchar.h), is to change type of the string to wchar to char, a flexibility function
	STRING_EX Name4 = { .Buffer = s,.MaximumLength = sizeof(s),.Length = sizeof(s) - sizeof((s)[0]) };
	STRING_EX Name5 = { sizeof(s) - sizeof((s)[0]),sizeof(s),s };
	STRING_EX Name6 = RTL_CONSTANT_STRING(_T("hey hey hey")); // using macros 
	//DumpStruct(&Name6);
	//DumpStruct(NULL);

	// Linked-List 
	BOOLEAN bIsEmpty = FALSE;
	PLIST_ENTRY TempHeadList = NULL;
	PLIST_ENTRY Temp = NULL;
	PPROCESS_INFO_EX pProcInfo = NULL;
	
	TempHeadList = (PLIST_ENTRY)HeapAlloc(
		GetProcessHeap(), 
		HEAP_ZERO_MEMORY, 
		sizeof(LIST_ENTRY)
	);
	
	//error-check memory allocation
	if (!TempHeadList) {
		dwStatus = GetLastError();
		printf("HeapAlloc failed with error: %lu\n", dwStatus);
		return dwStatus;
	}
	InitializeListHead(TempHeadList);
	bIsEmpty = IsListEmpty(TempHeadList);
	pProcInfo = (PPROCESS_INFO_EX)HeapAlloc(
		GetProcessHeap(),
		HEAP_ZERO_MEMORY,
		sizeof(PROCESS_INFO_EX)
	);

	if (!pProcInfo)
	{
		dwStatus = GetLastError();
		printf("HeapAlloc failed wtih error: %lu\n", dwStatus);
		return dwStatus;
	}

	UNICODE_STRING usProcName = RTL_CONSTANT_STRING(_T("explorer.exe"));
	pProcInfo->CurrentThread = GetCurrentThread();
	pProcInfo->Name = usProcName;

	InsertTailList(TempHeadList, &(pProcInfo->ProcessInfoLinks));
	bIsEmpty = IsListEmpty(TempHeadList);

	return dwStatus;
}
// _Use_decl_annotations_ VOID WINAPI DumpStruct(PSTRING_EX ProcessName) {..} -> simplified version
_Use_decl_annotations_    //apply the parameter down below 
VOID
WINAPI
DumpStruct(
	PSTRING_EX ProcessName
)
{
	//printf("Name: %hZ\n", ProcessName); hZ for ascii
	printf("Name: %wZ\n", ProcessName); //wZ for wide 
}



