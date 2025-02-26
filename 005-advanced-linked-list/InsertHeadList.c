#include <cstdlib>
VOID InsertHeadList(PLIST_ENTRY ListHead, PLIST_ENTRY Entry) {
    PLIST_ENTRY Flink;
    Flink = ListHead->Flink;
    Entry->Flink = Flink;
    Entry->Blink = ListHead;
    Flink->Blink = Entry;
    ListHead->Flink = Entry;
    return;
}

__asm(" 
        x86
        mov edx, [ebx]
        mov [ecx], edx
        mov [ecx+4], ebx
        mov [edx+4], ecx
        mov [ebx], ecx


        x64
        mov rcx, [rdi]
        mov [rax+8], rdi
        mov [rax], rcx
        mov [rcx+8], rax
        mov [rdi], rax
      ")
