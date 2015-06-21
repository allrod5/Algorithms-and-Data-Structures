#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
        long int *jars, N, M, a, b, k, i, j, soma = 0, media = 0;

        scanf("%li %li", &N, &M);

        jars = (int*)calloc(N, sizeof(jars));

        for(i=0; i<M; i++){
                scanf("%li %li %li", &a, &b, &k);
                for(j=a-1; j<b; j++){
                        if(jars[j]<0){
                                jars[j]=0;
                        }
                        jars[j]+=k;
                }
        }

        for(i=0; i<N; i++){
            soma+=jars[i];
        }

        free(jars);

        media = soma/N;

        printf("%li\n", media);
}
