# LIST_ENTRY structure (ntdef.h)

```c
typedef struct _LIST_ENTRY {
  struct _LIST_ENTRY *Flink;
  struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, PRLIST_ENTRY;
```

+--------+--------+     +--------+--------+     +--------+--------+
| Flink  | Blink  |<----| Flink  | Blink  |<----| Flink  | Blink  |
+--------+--------+     +--------+--------+     +--------+--------+
     |                       |                       |
     +---------------------->+---------------------->+



