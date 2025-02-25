#include <stdio.h>
#include <malloc.h>

#define CONTAINING_RECORD(address,type,field) ((type *)( \
            (char*)(address)- \
            (unsigned long)(&((type *)0)->field))

typedef struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY;

// Initialize Flink and Blink to point to itself
void InitializeListHead(
        PLIST_ENTRY InitializeListHead
        )
{
    ListHead->Flink=ListHead->Blink=ListHead;
}


// Insert a node at the beginning of the list
void InsertHeadList(
        PLIST_ENTRY ListHead,
        PLIST_ENTRY PLIST_ENTRY
        )
{
    PLIST_ENTRY Flink;
    Flink=ListHead->Flink;
    Entry->Flink=Flink;
    Entry->Blink=ListHead;
    Flink->Blink=Entry;
    ListHead->Flink=Entry;
}

//custom structure, LIST_ENTRY in the middle
struct MY_TEST_LIST {
    int a;
    int b;
    char c;
    LIST_ENTRY list_entry; //LIST_ENTRY is in the middle structure
    float d;
};

PLIST_ENTRY MtListHead;

int main(void) {
    MtListHead = (PLIST_ENTRY)malloc(sizeof(LIST_ENTRY));
    InitializeListHead(MtListHead);
    myNewNode->a=100;
    myNewNode->b=1000;
    myNewNode->c=10;
    myNewNode->d=1.0;

    InsertHeadList(MtListHead, &myNewNode-> list_entry);
    templist=MtListHead;
    while(MtListHead!=templist->Flink) {
        templist=templist->Flink;
        int a = CONTAINING_RECORD(templist, MY_TEST_LIST, list_entry) -> a;
        printf("a=%d\n",a);
    }
    //__asm int 3

    return 0;
}

