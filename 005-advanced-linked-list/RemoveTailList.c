PLIST_ENTRY RemoveTailList(PLIST_ENTRY ListHead) {
    PLIST_ENTRY Blink;
    PLIST_ENTRY Entry;
    Entry = ListHead->Blink;
    Blink = Entry->Blink;
    ListHead->Blink = Blink;
    Blink->Flink = ListHead;
    return Entry;
}

__asm("
        x86
        mov ebx, [edi+4]
        mov eax, [ebx+4]
        mov [edi+4], eax
        mov [eax], edi

        x64
        mov rsi, [rdi+8]
        mov rax, [rsi+8]
        mov [rdi+8], rax
        mov [rax], rdi
    ")
