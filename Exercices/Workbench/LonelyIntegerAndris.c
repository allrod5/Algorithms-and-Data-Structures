#include <stdio.h>

int main () {

    int n;

    printf("Digite o número de slots (deve ser ímpar) do vetor: ");
    scanf("%d", &n);


    while (n%2 == 0) {
        printf("Digite um número ímpar: ");
        scanf("%d", &n);
    }


    int array[n], i, j;

    for (i=0; i<n; i++) {
        do{
        printf("Digite um valor entre 0 e 100 para ser armazenado na posição %d do vetor: ", i);
        scanf("%d", &array[i]);
        }while(array[i]<0 || array[i]>100);
    }

    if(n==1){
        printf("%d", array[0]);
    }
    else{
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                if(array[i]>=0 && array[j]>=0){
                    if(array[i]==array[j]){
                        array[i] = -1;
                        array[j] = -1;
                    }
                }
            }
        }
        for(i=0; i<n; i++){
            if(array[i]!=-1){
                printf(" %d ", array[i]);
            }
        }
    }

    return 0;
}
