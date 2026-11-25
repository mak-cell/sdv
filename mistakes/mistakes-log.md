# Mistakes log
Every wrong quiz answer, why it was wrong, and the rule to remember. Re-read before each new topic.

| Date | Question | My answer | Correct | Rule |
|---|---|---|---|---|
| 2026-10-07 | `int speed = 60;` (global) | .rodata | .data | No `const` → can change → RAM. Non-zero → .data |
| 2026-10-07 | `static int calls = 0;` | .data | .bss | Zero → .bss |
| 2026-10-07 | `int *buf = malloc(64);` where is buf | heap | stack (bytes on heap) | Pointer and what it points to live in different places |
| 2026-10-07 | `char *name = "ECU1";` where is "ECU1" | heap | .rodata | No malloc → no heap. String literals → .rodata |
| 2026-10-07 | function code | .data | .text | Code → .text, always (missed twice) |
| 2026-10-07 | `static int retries = 3;` | .rodata | .data | static ≠ read-only |
| 2026-10-07 | `char msg[] = "HI";` (local) | .data | stack | Local array = own copy on the stack |
| 2026-10-07 | `static char *buf = NULL;` | .data | .bss | NULL is zero → .bss |
| 2026-10-07 | `const char *ver = "v1.2";` where is ver | .rodata | .data | const protects the text, not the pointer |
| 2026-10-07 | `int arr[3] = {1,2,3};` (local) | .data | stack | Every non-static local → stack, whatever its value |
| 2026-10-07 | `static const int k = 7;` (local) | stack | .rodata | static takes it off the stack, const keeps it in Flash |
| 2026-10-07 | `char *s = malloc(16);` where is s | .data | stack | The pointer dies with the function; the heap block stays → leak |
| 2026-10-07 | `int *d = (int)malloc(10);` | (code) | `int *d = malloc(10 * sizeof(int));` | Never cast an address to int; malloc takes bytes |
| 2026-10-08 | `unsigned u = UINT_MAX; u++;` | UB | OK (wraps to 0) | Only signed overflow is UB |
| 2026-10-08 | `uint8_t b = 200; b = b + 100;` | UB | OK (b = 44) | Integer promotion to int, then defined unsigned conversion |
| 2026-10-22 | ISR flag without volatile kept in... | cache | register | The compiler caches values in CPU registers |
| 2026-10-22 | `uint32_t *q` at 0x100, `q + 1` | 0x132 | 0x104 | Pointer math counts bytes: 32 bits = 4 bytes |
| 2026-10-22 | Is `count++` safe with volatile? | No: volatile doesn't guarantee type safety | No: volatile isn't atomic; read, add, write can be split by an ISR | Use interrupt disable or atomics for shared counters |
| 2026-10-22 | `const int *p` | "pointer to p is const" | Data is const, p can move | const LEFT of * = data locked; RIGHT of * = pointer locked |
| 2026-10-22 | Real const volatile example | `volatile const a = 100;` | Read-only HW status register `const volatile uint32_t *SR` | Code can't write it, hardware changes it |
| 2026-10-22 | Read register at 0x40011000 | `int &p = 0x40011000;` | `uint32_t sr = *(volatile uint32_t *)0x40011000;` | `&` reference is C++; in C cast to volatile pointer, then dereference |

| 2026-11-01 | `const char *msg = "CAN";` (global): where is msg? | .rodata | .data | Only the text is const (const LEFT of *). The pointer is a writable global with a non-zero value, so .data. `const char * const msg` puts it in .rodata |
| 2026-11-01 | ISR does `count++`, main does `count--`, count is volatile: safe? | Safe, no fix | Not safe (2nd miss) | volatile is NOT atomic. Read-modify-write can be split by the ISR. Disable IRQs around main's access or use atomics |
| 2026-11-01 | Read 32-bit register at 0x40021000 | `volatile uint32_t *p = 0x40021000;` | `uint32_t v = *(volatile uint32_t *)0x40021000;` | Cast the integer to a volatile pointer, then dereference to actually read |