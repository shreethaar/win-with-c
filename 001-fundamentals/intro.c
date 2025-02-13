#include <stdio.h>
#include <Windows.h>

// NOT WINDOWS PLATFORM SPECIFIC
/*int main() {
	int bestClass;
	unsigned int nextClass = 770;
	unsigned long long thirdClass = 0x870;
	printf("Welcome to the workshop\n");
	return 0;
}
*/

//WINDOWS PLATFORM SPECIFIC
INT main(VOID) {
	INT bestClass = 670; // int -> INT 
	UINT nextClass = 770; // unsigned int -> UNIT
	ULONGLONG thirdClass = 0x870;  // unsigned long long -> ULONGLONG
	printf("Welcome to the workshop\n");
	printf("bestClass: %d\n", bestClass);
	printf("nextChass: %u\n", nextClass);
	printf("thirdClass: %llu\n", thirdClass);
	printf("\n");
	//bestClass+nextClass;
	//bestClass+=nextClass;
	//bestClass*=nextClass;
	//bestClass++;
	//bestClass >> 1;   0011 -> 0001
	printf("bestClass >> 1: %d\n", bestClass >> 1);

	// OR  
	printf("OR %d\n", bestClass | nextClass);
	// AND
	printf("AND %d\n", bestClass & nextClass);
	// XOR
	printf("XOR %d\n", bestClass ^ nextClass);

	printf("and 1: %d\n", (770 >> 8) & 1); // test the 8 bit with a 1 to determine true/false


	return ERROR_SUCCESS; // exit error code, i know ... is weird ... blame windows ? or maybe switch to linux
	
	// the data types are typedef in windows header file
}

/*
This program is not specifically for Windows even though using Windows.h header file
To make it Windows platform specific:
- Use different data types that are defined in the header file
- Can be found in Microsoft Windows Data Type documentation
- Common: CALLBACK for calling convention and etc ...
*/


/* 
printf format strings with INTs
%[flags][width][.precision][size]type
	%d -> decimal
	%x -> hex
	%hh -> char
	%ll -> long long
	etc ...
*/