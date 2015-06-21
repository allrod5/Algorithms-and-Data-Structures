#include <stdio.h>
#include <stdlib.h>>
#include <math.h>

int main()
{
    int T;
    scanf("%d", &T);

    int fib[60], i, n, IsFibo;

    fib[0] = 0;
    fib[1] = 1;

    for(i=2; i<60; i++)
        fib[i] = fib[i-1] + fib[i-2];

    while(T>0)
    {
        IsFibo = 0;
        scanf("%d", &n);
        for(i=0; i<60; i++)
            if(n==fib[i])
                IsFibo = 1;
        if(IsFibo==1)
            printf("IsFibo\n");
        else
            printf("IsNotFibo\n");
        T--;
    }
    return 0;
}
