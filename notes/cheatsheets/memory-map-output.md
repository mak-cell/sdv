# Cheat sheet: memory map from real output (1 Nov 2026)

Program: `code/c-basics/where.c`, built with `gcc -Wall -o where where.c && ./where` in WSL.

## Two runs

| Section | Run 1 | Run 2 | Grows |
|---|---|---|---|
| .text (code) | 0x621a197d**11a9** | 0x61d98402**21a9** | fixed |
| .rodata (const, literals) | 0x621a197d**2008** | 0x61d98402**3008** | fixed |
| .data (global = non-zero) | 0x621a197d**4010** | 0x61d98402**5010** | fixed |
| .bss (global = 0 / uninit) | 0x621a197d**4018** | 0x61d98402**5018** | fixed |
| heap (malloc) | 0x621a4c5c**f2a0** | 0x61d98933**42a0** | UP |
| stack (locals) | 0x7fff2876b41c | 0x7ffe6295852c | DOWN |

## How to read it

1. Low addresses, in order: .text < .rodata < .data < .bss. That's the program image.
2. Sections are 0x1000 (4 KB) pages apart because each page has its own permission (.text can run, .rodata is read-only, .data/.bss are read-write).
3. .bss sits right after .data (4010 to 4018: 8 bytes apart).
4. Heap is just above .bss and grows up. Stack is at the top (0x7ff…) and grows down.
5. ASLR: the start address is random each run, but the last 3 hex digits and the gaps between sections stay the same, because the whole image moves as one block. The stack also gets a small random offset inside its page.

## Linux vs MCU (interview point)

| | Linux PC | STM32 |
|---|---|---|
| Start address | Random (ASLR) | Fixed by linker script |
| .text / .rodata | RAM pages, read-only | Flash, 0x0800xxxx |
| .data / .bss / heap / stack | RAM | RAM, 0x2000xxxx |
| Who sets up .data/.bss | OS loader | Reset handler: copy .data flash→RAM, zero .bss |

## Lines to remember

```c
uint32_t v = *(volatile uint32_t *)0x40021000;   // read a register
*(volatile uint32_t *)0x40021000 = 0x1;          // write a register
const volatile uint32_t *SR;                     // read-only HW status register
```
- volatile ≠ atomic. `count++` is read, add, write; an ISR can split it.
- `const char *msg = "CAN";` → "CAN" in .rodata, msg in .data.
