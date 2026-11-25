# 01 Memory layout (.text, .rodata, .data, .bss, stack, heap)
Studied: 2026-10-07. Quiz scores: 3/6 → 2/5 → 4/7 → 4.5/7 → 8/9.

## The sections
| Section | Holds | Lives in |
|---|---|---|
| .text | Code (every function) | Flash |
| .rodata | Global/static `const`, string literals `"..."` | Flash |
| .data | Global/static with a **non-zero** initial value | RAM (copied from Flash at startup) |
| .bss | Global/static with **zero / NULL / no** initial value | RAM (zeroed at startup) |
| stack | Locals, function arguments, return addresses | RAM |
| heap | Only memory from `malloc()` | RAM |

## Decide in this order
1. Is it code? → .text
2. String literal, or global/static `const`? → .rodata
3. Came from `malloc`? → heap
4. Local and not `static`? → stack
5. Otherwise (global or static): value 0 / NULL / missing → .bss, anything else → .data

## Traps
- `static` means "keeps its value between calls", **not** read-only.
- A `const` local is still on the stack.
- `char *p = "HI";` → p is a pointer (stack if local, .data if global); "HI" is in .rodata.
- `char a[] = "HI";` (local) → the whole array is on the stack, and you can change it.
- `int *p = malloc(8);` → p is on the stack, the 8 bytes are on the heap.
- `int arr[4] = {0};` (global) → .bss. `{1,0,0,0}` → .data (one non-zero is enough).
- When the function returns, the pointer dies but the heap block stays → **memory leak** if not freed.

## Startup (why .data and .bss matter)
Before `main()`, startup code copies .data from Flash to RAM and zero-fills .bss.
On STM32: .text/.rodata at 0x0800xxxx (Flash), RAM at 0x2000xxxx.

## Interview answer
"Non-zero globals and statics go in .data, zero or uninitialized ones in .bss, constants and string literals in .rodata, code in .text, locals on the stack, and malloc memory on the heap. Startup code copies .data from Flash to RAM and zeroes .bss before main()."

## Proof (run on Linux, see code/c-basics/memory_sections.c)
```
main (.text)  : 0x401196
b    (.rodata): 0x402004
a    (.data)  : 0x404030
e    (.bss)   : 0x404038
d -> (heap)   : 0x3262c2a0
c    (stack)  : 0x7ffdbef28a3c
```
