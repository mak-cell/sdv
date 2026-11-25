/*
0x40021000  just a number - base+offset, from reference manual 
(uint32_t *)0x40021000 - this is number is the address of a 32 bit value
(volatile uint32_t *)0x40021000 - this is harware can change it, so always really access it 
*(volatile uint32_t *)0x40021000 - the * goes to that address : the register itself 
*/
/*
#define RCC_CR (*(volatile uint32_t *)0x40021000u)
uint32_t v = RCC_CR;        //read
RCC_CR = 0x1u;  //replacess all 32bit with 1 
RCC_CR |= (1u << 5)  //set bit 5 and keep other 
RCC_CR &= ~(1u << 5) // clear bit 5
if(RCC_CR & (1 << 5)) // test bit 5
*/

#include<stdio.h>
#include<stdint.h>
static uint32_t fake = 0;
#define REG (*(volatile uint32_t*)(uintptr_t)&fake)

int main(void)
{
   
    /*
    Honest note on my exercise: the (uintptr_t) in my macro wasn’t needed. I only added it to copy the “number → pointer” pattern of the real register. This simpler version works the same:

    uint32_t fake;
    #define REG (*(volatile uint32_t *)&fake)
    */
    printf("REG = 0x%08x\n", (unsigned)REG);
    REG |= (1u << 3);
    printf("REG = 0x%08x\n", (unsigned)REG);
    REG |= (1u << 0);
    printf("REG = 0x%08x\n", (unsigned)REG);
    REG &= ~(1u << 3);
    printf("REG = 0x%08x\n", (unsigned)REG);
}

/*
mak@Mak:/mnt/d/Codes/sdv-study/code/c-basics$ gcc -Wall -o reg register_exercise.c && ./reg
REG = 0x00000000
REG = 0x00000008
REG = 0x00000009
REG = 0x00000001
*/