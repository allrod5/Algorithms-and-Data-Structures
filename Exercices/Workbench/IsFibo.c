#include <stdio.h>
#include <stdlib.h>>
#include <math.h>

char isPerfectSquare(__uint128_t A);
char isFibo(int n);
__uint128_t getX0(__uint128_t A);

int main()
{
    int T, n;
    scanf("%d", &T);

    while(T>0)
    {
        scanf("%d", &n);
        if(isFibo(n)==1)
            printf("IsFibo\n");
        else
            printf("IsNotFibo\n");
        T--;
    }
    return 0;
}

char isPerfectSquare(__uint128_t A)
{
    __uint128_t x = getX0(A), last[2] = {0};
    int i = 0;
    while(1)
    {
        last[1] = last[0];
        last[0] = x;
        if(x==0) return 0;
        x = (x*x+A)/(2*x);
        if(x==last[0] && x*x==A) return 1;
        else if(x==last[1]) return 0;
    }
}

char isFibo(int n)
{
    __uint128_t A = 5*n*n+4;
    if(isPerfectSquare(A)==1) return 1;
    else
    {
        A -= 8;
        printf("%u\n", A);
        if(isPerfectSquare(A)==1) return 1;
        else return 0;
    }
}

__uint128_t getX0(__uint128_t A)
{
    if(A<100000)
        if(A<1000)
            if(A<100)
                if(A<10) return 1;             /* 1*10^0 */
                else return 1;                 /* 1*10^0 */
            else return 10;                    /* 1*10^1 */
        else if(A<10000) return 10;            /* 1*10^1 */
        else return 10;                        /* 1*10^2 */
    else if(A<100000000)
        if(A<10000000)
            if(A<1000000) return 100;          /* 1*10^2 */
            else return 100;                   /* 1*10^3 */
        else return 1000;                      /* 1*10^3 */
    else if(A<1000000000) return 1000;         /* 1*10^4 */
    else return 1000;                          /* 1*10^4 */
}
