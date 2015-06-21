#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b);

int main()
{
    int i, N, K, unfairness, *array;
    scanf("%d\n%d", &N, &K);

    array = malloc(sizeof(int)*N);

    for(i=0; i<N; i++)
        scanf("%d", &array[i]);

    qsort(array, N, sizeof(int), cmpfunc);

    unfairness = array[K-1]-array[0];
    for(i=1; i<N-K; i++)
        if(array[i+K-1]-array[i]<unfairness)
            unfairness = array[i+K-1]-array[i];
    printf("%d", unfairness);

    return 0;
}

int cmpfunc(const void *a, const void *b)
{
   return ( *(int*)a - *(int*)b );
}
