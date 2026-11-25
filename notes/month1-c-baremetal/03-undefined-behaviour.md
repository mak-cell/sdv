# 03 Undefined behaviour (UB)
Studied: 2026-10-07/08. Check: 2/4 (missed unsigned wrap and integer promotion).

The standard says "anything can happen". The compiler assumes UB never happens and optimizes around it, so UB bugs often appear only at -O2.

## Common UB
1. Array out of bounds: `int a[5]; a[5] = 1;`
2. Reading an uninitialized local
3. NULL dereference, use after free
4. **Signed** overflow: `INT_MAX + 1`
5. Shift ≥ width (`1u << 32`), shifting into the sign bit (`1 << 31`)
6. Modifying a variable twice in one expression: `i = i++ + ++i;`
7. Modifying a const object
8. Using the result of a non-void function that didn't return

## NOT UB (common traps)
- **Unsigned overflow wraps** (defined): `UINT_MAX + 1 == 0`.
- **Integer promotion**: `uint8_t`, `char`, `short` become `int` before math. `uint8_t b = 200; b = b + 100;` → 300 as int, stored as 300 − 256 = **44**. Defined.

## Embedded example
`for (int i = 0; i <= 5; i++) buf[i] = 0;` with `buf[5]` → overwrites the next variable or the return address → random resets in the field.

## Catch it
`-Wall -Wextra`, `-fsanitize=address,undefined` on a PC, MISRA C rules.

## Interview answer
"UB means the standard puts no requirement on the result. The compiler assumes UB never happens, so it can cause bugs that appear only with optimization. Common cases: out-of-bounds, signed overflow, uninitialized reads, NULL dereference, bad shifts. Unsigned overflow is defined and wraps."
