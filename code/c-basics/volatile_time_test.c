#include<stdio.h>
#include<time.h>

int main()
{

    clock_t t = clock();
    double d = 0.0;
    for(int n =0;n<=10000;++n)
        for(int m = 0;m<=10000;++m)
            d += d * m * n;
    printf("Modifications of non volatile variable 100m time :\n time used = %.2f seconds \n", 
                                            (double)(clock() - t)/CLOCKS_PER_SEC);
    
    t = clock();
    volatile double vd = 0.0;
    for(int n =0;n<=10000;++n)
        for(int m = 0;m<=10000;++m){
            double prod = vd * m * n;
            vd += prod;
        }
            
    printf("Modifications of non volatile variable 100m time :\n time used = %.2f seconds \n", 
                                            (double)(clock() - t)/CLOCKS_PER_SEC);

}