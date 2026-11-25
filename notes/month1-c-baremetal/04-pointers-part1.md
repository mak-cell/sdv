# 04 Pointers, part 1
Studied: 2026-10-08, recap 2026-10-22.

A pointer holds an **address**. `&x` = address of x. `*p` = go to the address in p.
```c
int x = 10; int *p = &x;
*p = 20;            // x is now 20
```

## Three big uses
1. Let a function change your variable: `void set_zero(int *v){ *v = 0; }` → `set_zero(&speed);`
2. Arrays/buffers: `uint8_t *p = buf;` → `p[2] == *(p + 2)`
3. Hardware registers: `*(volatile uint32_t *)0x40011000`

## Pointer arithmetic
`p + 1` moves by `sizeof(*p)` **bytes**, not by 1 and not by bits.
- `uint8_t *` +1, `uint16_t *` +2, `uint32_t *` +4
- `uint32_t *q` at 0x100 → `q + 1` = **0x104** (not 0x132: 32 bits = 4 bytes)

## Size of a pointer
8 bytes on a 64-bit PC, 4 bytes on STM32. Never store an address in `int`:
`int *d = (int)malloc(...)` cuts a 64-bit address in half. Use `int *d = malloc(10 * sizeof(int));` (no cast needed in C). If you need an address as a number, use `uintptr_t`.
`malloc(10)` = 10 bytes, not 10 ints.

## Next (part 2)
Pointer to pointer, `void *`, function pointers, common pointer bugs.
