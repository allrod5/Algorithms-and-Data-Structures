#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int *p;
    char option;
    while(1){
        printf("a) Alocar um novo bloco de 10Mb na Heap e prencher com zeros\nb) Sair\n");
        scanf("%s", &option);
        if(option=='a')
        {
            p = malloc(sizeof(int)*1000000);
            memset(p, 0, sizeof(int)*1000000);
            if(!p)break;
        } else break;
    } /* Meu computador começa a travar quando a memria RAM chega perto dos 100% (8Gb),
        mas como eu tenho memória 8Gb de SWAP (Linux) então ele vai movendo aos
        poucos a memória para a SWAP, mas isso após longos períodos de travamento*/
}
