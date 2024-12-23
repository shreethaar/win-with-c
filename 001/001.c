#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	/*
	* WinMain() is windows equivalent of main() from UNIX. This is where program starts execution. The parameter as follows:
	* HINSTANCE hInstance -> Handle to the program executable module (the .exe file in memory)
	* HINSTANCE hPrevInstance -> Always NULL for Win32 programs
	* LPSTR lpCmdLine -> The command line arguments as a single string NOT including the program name
	* int nCmdShow -> An integer value which may be passed to ShowWindow(). 
	*/
	MessageBox(NULL, L"0x251e was here!", L"HACKED", MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_TOPMOST);
	/*
	* MessageBox() displays modal dialog box that has four parameter to perform different functions
	* HWND hWnd -> A handle to the owner windows of the message box to be created. NULL for no owner window 
	* LPCTSTR lpText -> Message to be display. Use a carriage return and/or linefeed character between each line. 
	* Note: The L prefix in C/C++ is used to define wide-character string literals (also known as Unicode string literals). It ensures that the string is encoded in UTF-16 or UTF-32 (depending on the platform) rather than the default narrow ASCII or ANSI encoding.
	* LPCTSTR lpCaption -> Dialogbox title, if null will display Error as default title
	* UINT uType -> Makes up the contents and behaviour of dialog box, can be a combination of flags.
	*/
	
	return 0;

}

/* Dissamble Code ASM
* .text:00401000 ; int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
.text:00401000 _WinMain@16     proc near               ; CODE XREF: sub_4010EF+F3?p
.text:00401000
.text:00401000 hInstance       = dword ptr  4
.text:00401000 hPrevInstance   = dword ptr  8
.text:00401000 lpCmdLine       = dword ptr  0Ch
.text:00401000 nShowCmd        = dword ptr  10h
.text:00401000
.text:00401000                 push    40036h          ; uType
.text:00401005                 push    offset Caption  ; "HACKED"
.text:0040100A                 push    offset Text     ; "0x251e was here!"
.text:0040100F                 push    0               ; hWnd
.text:00401011                 call    ds:MessageBoxW
.text:00401017                 xor     eax, eax
.text:00401019                 retn    10h
.text:00401019 _WinMain@16     endp
* 
* Based on the assembly, WINAPI uses __stdcall calling convention, this is to set up the stack, push arguments and return values
* LP Prefix stands for Long Pointer
* LPCSTR indicates a pointer to a const string, one that can not or will not be modified
* LPSTR indicates a pointer to a const TCHAR string (wide char 
*/