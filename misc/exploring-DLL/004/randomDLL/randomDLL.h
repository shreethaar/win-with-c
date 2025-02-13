// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the RANDOMDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// RANDOMDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RANDOMDLL_EXPORTS
#define RANDOMDLL_API __declspec(dllexport)
#else
#define RANDOMDLL_API __declspec(dllimport)
#endif

// This class is exported from the dll
extern "C" {
	RANDOMDLL_API int displayNumber();
	RANDOMDLL_API int getRandom();
	RANDOMDLL_API int displaySum();
	
}
