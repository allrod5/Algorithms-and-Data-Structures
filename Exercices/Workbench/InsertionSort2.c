#include <stdio.h>

int main() {

    int N, i, j, aux, shifts = 0;

    scanf("%d", &N);

    int array[N];

    for(i=0; i<N; i++) {
        scanf("%d", &array[i]);
    }

    for(i=1; i<N; i++) {
        j = i;
        while(array[j]<array[j-1]) {
            aux = array[j-1];
            array[j-1] = array[j];
            array[j--] = aux;
            shifts++;
        }
    }
    printf("%d", shifts);
    return 0;
}
