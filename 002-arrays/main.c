#include <Windows.h>
#include <stdio.h>

/*
	MACRO -> using #define, above main function

*/

#define FlagOn(Flags,TheFlag) ((Flags)&(TheFlag))
#define SetFlag(Flags,TheFlag) ((Flags)|=(TheFlag))
#define ClearFlag(Flags,TheFlag) ((Flags)&= ~(TheFlag))
#define MULTIPLE_OF_16 0x10
#define RANDOM_VALUE 50
#define ODD_NUMBER 0x1

#define PAGE_EXECUTE 0x10
#define PAGE_EXECUTE_READ 0x20
#define PAGE_EXECUTE_READWRITE 0x40

#define MEM_COMMIT 0x00001000
#define MEM_RESERVE 0x00002000

ULONG memory = MEM_COMMIT | MEM_RESERVE;




INT main(VOID) {
	INT min = -1; 
	UINT max = 4294967295;

	UINT nextClass = 770;

	printf("Is the min value == max value ? %s\n", (min == max) ? "YES" : "NO");
	// mismatch of data type of INT and UINT
	printf("Is the max > min ? %s \n",(max>min) ? "YES" : "NO");
	printf("Is 770 a multiply of 16 %s\n", FlagOn(nextClass, MULTIPLE_OF_16) ? "YES" : "NO");
	printf("Random value %d\n", RANDOM_VALUE);
	printf("Is 770 an odd number? %s \n", FlagOn(nextClass, ODD_NUMBER) ? "YES" : "NO");
	
	SetFlag(nextClass, ODD_NUMBER);
	printf("is 771 an odd number ? %s\n", FlagOn(nextClass,ODD_NUMBER) ? "YES" : "NO");

	ClearFlag(nextClass, ODD_NUMBER);
	printf("ClearFlag(nextClass,OOD_NUMBER) = %i (0x%08x) \n",nextClass,nextClass);
	
	//VirtualAlloc(nullptr,0x1000,memory,PAGE_EXECUTE_READ);
	printf("Is memory being committed ? %s \n", FlagOn(memory, MEM_COMMIT) ? "YES" : "NO");


	return ERROR_SUCCESS;
}