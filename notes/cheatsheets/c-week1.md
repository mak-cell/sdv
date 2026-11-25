# Week 1 cheat sheet (C in depth)

**Sections:** code → .text · string literal / global const → .rodata · malloc → heap · non-static local → stack · global/static zero → .bss · global/static non-zero → .data

**static** = keeps value, NOT read-only. **const local** = still stack.

**volatile** = re-read memory every time (hardware regs, ISR flags, DMA buffers). Not atomic.
**const** = my code can't change it. Left of `*` → data, right of `*` → pointer.
**const volatile** = read-only for me, hardware can change it.

**UB:** out-of-bounds, signed overflow, uninitialized read, NULL/freed pointer, shift ≥ width, i++ twice, modifying const.
**Defined:** unsigned overflow wraps. Small types promote to int before math.

**Pointers:** `p + 1` moves `sizeof(*p)` bytes. Pointer = 8 bytes on 64-bit PC, 4 on STM32. Never store addresses in int (use `uintptr_t`).
