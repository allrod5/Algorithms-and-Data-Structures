#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int A, V, i, j, *array, tmp[2], n = 0, max;

    while(1)
    {
        scanf("%d %d", &A, &V);
        if(A==0)
            break;
        else
        {
            n++;
            array = malloc(sizeof(int)*A);
            memset(array, 0, sizeof(int)*A);
            for(i=0; i<V; i++)
            {
                scanf("%d %d", &tmp[0], &tmp[1]);
                for(j=0; j<2; j++)
                    array[tmp[j]-1]++;
            }
        }
        max = 0;
        for(i=0; i<A; i++)
        {
            if(array[i]>max)
                max = array[i];
        }
        printf("Teste %d\n", n);
        for(i=0; i<A; i++)
        {
            if(array[i]==max)
                printf("%d ", i+1);
        }
        printf("\n\n");
        free(array);
    }
    return 0;
}
