/* Exercise 2 (2026-10-22): toolchain check - pointers, array decay, swap.
 * Ctrl+Shift+B builds it, F5 debugs it. Put a breakpoint on the swap() call
 * and watch x, y, px and *px change. */
#include <stdio.h>

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int x = 1, y = 2;
    int *px = &x;
    int arr[4] = {10, 20, 30, 40};
    int *p = arr;                         /* array decays to &arr[0] */

    printf("hello from WSL: x=%d y=%d *px=%d\n", x, y, *px);

    swap(&x, &y);                         /* breakpoint here */
    printf("after swap:     x=%d y=%d *px=%d\n", x, y, *px);

    printf("sizeof arr=%zu sizeof p=%zu\n", sizeof arr, sizeof p);
    printf("p[2]=%d *(p+2)=%d 2[p]=%d\n", p[2], *(p + 2), 2[p]);
    return 0;
}
