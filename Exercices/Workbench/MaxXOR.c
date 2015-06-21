#include <stdio.h>

int maxXOR(int L, int R);

int main() {
    int L, R;
    scanf("%d", &L);
    scanf("%d", &R);

    printf("%d", maxXOR(L, R));

    return 0;
}

int maxXOR(int L, int R) {
    int i, j, max = 0;
    for(i=L; i<=R; i++) {
        for(j=L; j<=R; j++) {
            if((i^j) > max) {
                max = (i^j);
            }
        }
    }

    return max;
}

