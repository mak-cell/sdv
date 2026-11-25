#include <stdio.h>
#include <stdlib.h>
int g0; 
int g1 = 1; 
const int k = 2;
int main(void) {
    int s; 
    int *h = malloc(4);
    
    printf(".text %p\n.rodata %p\n.data %p\n.bss %p\nheap %p\nstack %p\n",
           (void*)main, (void*)&k, (void*)&g1, (void*)&g0, (void*)h, (void*)&s);
    free(h);
}