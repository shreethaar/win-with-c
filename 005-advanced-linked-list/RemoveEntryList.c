BOOLEAN RemoveEntryList(PLIST_ENTRY Entry){
    PLIST_ENTRY Blink;
    PLIST_ENTRY Flink;
    Flink = Entry->Flink;
    Blink = Entry->Blink;
    Blink->Flink = Flink;
    Flink->Blink = Blink;
    return (BOOLEAN)(Flink == Blink);
}

__asm("
        x86
        mov edx, [ecx]
        mov eax, [ecx+4]
        mov [eax], edx
        mov [edx+4], eax

        x64
        mov rdx, [rcx]
        mov rax, [rcx+8]
        mov [rax], rdx
        mov [rdx+8], rax
        ")
