#pragma once
#include <Windows.h>

FORCEINLINE
VOID
InitializeListHead(
	_Out_ PLIST_ENTRY ListHead
)
{
	ListHead->Flink = ListHead->Blink = ListHead;
	return;
}

_Must_inspect_result_
BOOLEAN
CFORCEINLINE
IsListEmpty(
	_In_ const LIST_ENTRY* ListHead
)
{
	return (BOOLEAN)(ListHead->Flink == ListHead);
}

FORCEINLINE
VOID
InsertTailList(
	_Inout_ PLIST_ENTRY ListHead,
	_Inout_ PLIST_ENTRY Entry
)
{
	PLIST_ENTRY Blink;
	Blink = ListHead->Blink;
	Entry->Flink = ListHead;
	Entry->Blink = Blink;
	Blink->Flink = Entry;
	ListHead->Blink = Entry;
	return;
}