#include <stdio.h>
#include <stdlib.h>

int main() {
    double *p;
    int i;

    p = malloc(sizeof(double)*1000000);
    *p = 0;
    p++;
    *p = 1;
    printf("%.0f\n%.0f\n", *(p-1), *p);
    for(i=0; i<1000000; i++)
    {
        p++;
        *p = *(p-1) + *(p-2);
        printf("%.0f\n", *p);
    }

    free(p);
    return 0;
}
