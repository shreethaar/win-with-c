// TODO #1: create the main function for the program 
// this includes, the following:
// 
// function return type
// function name
// function parameters, if any (not need) for this version)
// function body

// TODO #2: inside main's function body 
// create 3 variables (name the variables whatever you want) of the following types and
// initialize them with their respectiive values:
// INT with value 0x7FFFFFFF
// UINT with 0x1
// DWORD with value 1 << 12

// TODO #3: inside main's function body
// add and update INT variable with your UINT variable

//TODO #4: inside main's function body
// for this part, must choose the proper data type to hold the value
// create 3  variable to hold the following values:
// 0xDEADBEEFCAFEBABE
// 21307066433
// 0x7F0000001


#include <stdio.h>
#include <Windows.h>

INT main(void) {
	INT value1 = 0x7FFFFFFF;
	UINT value2 = 0x1;
	DWORD value3 = 1;
	value3 << 12;

	printf("INT value1 (hex)[%x] (dec)[%d]\n", value1, value1);
	printf("UNIT value2 (hex)[%x] (dec)[%d]\n", value2, value2);
	printf("DWORD value3 (hex)[%x] (dec)[%d]\n", value3, value3);
	printf("INT var + UINT var (hex)[%x] (signed)[%d] (unsigned)[%u]\n", value1 + value2, value1 + value2, value1 + value2, value1 + value2);
	ULONGLONG beef = 0xDEADBEEFCAFEBABE;
	UINT ip = 2130706433;
	ULONG localhost = 0x7F000001;
	return ERROR_SUCCESS;
}
