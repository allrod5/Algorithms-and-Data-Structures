#include <stdio.h>

int main() {

    int N, i, j, skip;

    scanf("%d", &N);

    int array[N];

    for(i=0; i<N; i++) {
        scanf("%d", &array[i]);
    }

    for(i=0; i<N; i++) {
        skip = 0;
        for(j=i+1; j<N; j++) {
            if(array[i]==-1) {
                skip = 1;
                break;
            }else if(array[i]==array[j]) {
                array[j] = -1;
                skip = 1;
                break;
            }
        }
        if(skip==0) {
            printf("%d", array[i]);
            return 0;
        }
    }
    return 1;
}
