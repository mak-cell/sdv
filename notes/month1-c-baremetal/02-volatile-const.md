# 02 volatile and const
Studied: 2026-10-07. Checks: 4/4 and 4/4.

## volatile
"This value can change behind the compiler's back, so read/write memory every time."
Without it, the optimizer may keep the value in a CPU **register** and never re-read it.

```c
volatile int flag = 0;          // set by an ISR
void ISR_Button(void) { flag = 1; }
while (flag == 0) { }           // without volatile, -O2 can make this while(1)
```

Use it for:
1. Hardware registers: `#define UART_SR (*(volatile uint32_t *)0x40011000)`
2. Variables shared between an ISR and main code
3. Variables changed by another task or by DMA

**volatile is not atomic.** `count++` is still read-add-write; an interrupt can hit in the middle. You need a critical section or atomics.

### Memory-mapped registers
`(*(volatile uint32_t *)0x40011000)` read inside out: number → pointer to a volatile 32-bit register → `*` = the register itself.
Put `volatile` on the **data**, not the pointer: `volatile uint32_t *p` ✅, `uint32_t * volatile p` (only the pointer is volatile).

## const
"My code promises not to change this." Global const → .rodata (Flash), saves RAM.

Left of `*` = data, right of `*` = pointer:
```c
const int *p;              // data fixed:    *p = 5 ❌, p = &y ✅
int * const p = &x;        // pointer fixed: *p = 5 ✅, p = &y ❌
const int * const p = &x;  // both fixed
void send(const uint8_t *data, int len);   // promises not to modify data
```

## const volatile
Not a contradiction: my code can't write it, but hardware can change it.
`const volatile uint32_t *STATUS = (const volatile uint32_t *)0x40011000;`

## Casting away const
`int *p = (int *)&x; *p = 20;` is **UB** if x was defined const.
Global const: segfault on Linux, ignored write or HardFault on an MCU (Flash). Local const: may print the old value (compiler assumed it never changes). Legal only when the original object was not const.
