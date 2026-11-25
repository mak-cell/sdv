# 06 Pointers, part 2
Studied: 2026-10-22.

## Pointer to pointer (`int **`)
Holds the address of another pointer.
```c
int x = 5; int *p = &x; int **pp = &p;
**pp = 9;      // x is now 9
```
Use: a function that must change the caller's pointer.
```c
void alloc_buf(uint8_t **out) { *out = malloc(64); }
uint8_t *buf = NULL; alloc_buf(&buf);   // buf now points to 64 bytes
```
With `uint8_t *out` the function only changes its own copy.

## `void *`
Holds any address. Cast before reading: `int n = *(int *)v;`
Used by malloc, memcpy, callback context (`void *ctx`). No pointer arithmetic on `void *` in standard C.

## Function pointers
A variable holding the address of a function.
```c
void (*action)(void) = led_on;   action();
typedef void (*Callback)(uint8_t);   Callback rx_cb = my_handler;
```
Read right to left: `int (*fp)(int)` = fp is a pointer to a function taking int, returning int.
Embedded uses: vector table (array of handler pointers), driver callbacks, state-machine tables.

## Classic pointer bugs
- NULL dereference → check `if (p != NULL)`
- Dangling pointer (use after free) → set `p = NULL` after `free(p)`
- Returning the address of a local → the local dies when the function returns
- Uninitialized pointer → writes to a random address

## Interview answer
"A double pointer lets a function change the caller's pointer, for example to allocate a buffer. void * is a generic address you must cast before use. Function pointers store a function's address; in embedded they're used for the vector table, callbacks and state machines."
