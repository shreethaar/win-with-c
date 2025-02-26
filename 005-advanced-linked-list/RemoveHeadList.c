PLIST_ENTRY RemoveHeadList(PLIST_ENTRY ListHead) {
    PLIST_ENTRY Flink;
    PLIST_ENTRY Entry;
    Entry = ListHead->Flink;
    Flink = Entry->Flink;
    ListHead->Flink = Flink;
    Flink->Blink = ListHead;
    return Entry;

}

__asm("
        x86 
        mov eax, [esi]
        mov ecx, [eax]
        mov [esi], ecx
        mov [ecx+4], esi

        x64
        mov rax, [rbx]
        mov rcx, [rax]
        mov [rbx], rcx
        mov [rcx+8], rbx
    ")
