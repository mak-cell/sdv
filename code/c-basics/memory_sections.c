/* Exercise 1 (2026-10-07): print the address of each memory section. */
#include <stdio.h>
#include <stdlib.h>

int a = 5;            /* .data   */
int e;                /* .bss    */
const int b = 10;     /* .rodata */

int main(void)
{
    int c;                                  /* stack */
    int *d = malloc(10 * sizeof(int));      /* d on stack, block on heap */

    printf("main (.text)  : %p\n", (void *)main);
    printf("b    (.rodata): %p\n", (void *)&b);
    printf("a    (.data)  : %p\n", (void *)&a);
    printf("e    (.bss)   : %p\n", (void *)&e);
    printf("d -> (heap)   : %p\n", (void *)d);
    printf("c    (stack)  : %p\n", (void *)&c);

    free(d);
    return 0;
}


.text 0x61d9840221a9
.rodata 0x61d984023008
.data 0x61d984025010
.bss 0x61d984025018
heap 0x61d9893342a0
stack 0x7ffe6295852c