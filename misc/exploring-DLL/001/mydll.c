#include <stdio.h>
#include <windows.h>
#include <shellapi.h>

#define IDR_TEXTFILE 101 // Resource ID

__declspec(dllexport) void ExtractAndOpenTextFile() {
	HMODULE hModule = GetModuleHandle(TEXT("mydll.dll"));
	if(!hModule){
		return;
	}
	HRSRC hRes = FindResource(hModule, MAKEINTRESOURCE(IDR_TEXTFILE), TEXT("TEXT"));
	if(!hRes) {
		return;
	}

	HGLOBAL hData = LoadResource(hModule,hRes);
	DWORD size = SizeofResource(hModule,hRes);
	if(!hData||size==0) {
		return;
	}
	
	void* pData = LockResource(hData);
	if(!pData) {
		return;
	}

	FILE* file = fopen("extracted.txt","wb");
	if(file) {
		fwrite(pData,1,size,file);
		fclose(file);
		ShellExecute(NULL,"open","extracted.txt",NULL,NULL,SW_SHOW);
	}
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	switch(fdwReason) {
		case DLL_PROCESS_ATTACH:
			break;
		case DLL_PROCESS_DETACH:
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
	}
	return TRUE;
}
