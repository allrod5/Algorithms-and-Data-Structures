
#include <stdio.h>
#include <time.h>

void quickSort (int *V, int n);

int main(){
        int N, K, i;
        scanf("%d", &N);
        scanf("%d", &K);

        int n_integers[N];

        for(i=0; i < N; i++){
                scanf("%d", &n_integers[i]);
        }

        quickSort(n_integers, N);

        return 0;
}

void quickSort (int *V, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = V[n/2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (V[i] < p)
            i++;
        while (V[j] > p)
            j--;
        if (i >= j)
            break;
        t = V[i];
        V[i] = V[j];
        V[j] = t;
    }
    quickSort(V, i);
    quickSort(V+i, n-i);
}
