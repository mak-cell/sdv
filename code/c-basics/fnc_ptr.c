#include<stdio.h> 

int add(int a, int b) { return a + b ; }
int sub(int a, int b) { return a - b ; }
int mul(int a, int b) { return a * b ; }

typedef int (*Operation)(int, int);

int op(Operation func, int a, int b){
    return func(a, b);
}

int main()
{
    printf("Hello Mohan");
}