/* wmain function prototypes
 * Examples:
 * int wmain(void);
 * int wmain(int argc, wchar_t **argv);
 * int wmain(int argc, whar_t *argv[]);
 *
 *  wmain function -> receive wide characters
 *  GetStdHandle function returns a handle to the standard output
 *  WriteConsoleW function to write to the console in wide characters
 *  CloseHandle(std) function closed the opened handle to the standard output 
 */

#include <windows.h>
#include <wchar.h>

int main(int argc, wchar_t **argv) {
    PDWOD cChars = NULL;
    HANDLE std = GetStdHandle(STD_OUTPUT_HANDLE);
    if(std==INVALID_HANDLE_VALUE) {
        wprintf(L"Cannot retrieve standard output handle\n" (%d)",
                GetLastError());
    }
    if(argv[1]) {
        WriteConsoleW(std,argv[1],wcslen(argv[1]),cChars,NULL);

    }
    CloseHandle(std);
    return 0;
}

