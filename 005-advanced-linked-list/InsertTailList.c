VOID InsertTailList(PLIST_ENTRY ListHead, PLIST_ENTRY Entry) {
    PLIST_ENTRY Blink;
    Blink = ListHead->Blink;
    Entry->Flink = ListHead;
    Entry->Blink = Blink;
    Blink->Flink = Entry;
    ListHead->Blink = Entry;
    return;
}

__asm("
        x86
        mov ecx, [ebx+4]
        mov [eax], ebx
        mov [eax+4], ecx
        mov [ecx], eax
        mov [ebx+4], eax

        x64
        mov rcx, [rdi+8]
        mov [rax], rdi
        mov [rax+8], rcx
        mov [rcx], rax
        mov [rdi+8], rax
    ")
