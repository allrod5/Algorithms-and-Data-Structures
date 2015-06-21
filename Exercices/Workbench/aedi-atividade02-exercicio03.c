#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK 2000000
#define MAX_HEAP 2000000000

int main(){

    int i[MAX_STACK]={0};
    /* tamanho máximo de um bloco de memória na stack ~ 2000000*4 bytes = 8 Gb   */
    /* este resultado está conforme o esperado, já que possuo 8Gb de memória RAM */

    int *p, counter=0;
    p = malloc(sizeof(int)*MAX_HEAP);
    if(!memset(p, 0, sizeof(int)*MAX_HEAP)) return 1;
    /* tamanho máximo de um bloco de memória na heap ~ 2000000000*4 bytes = 8 Tb */
    /* não tenho certeza deste resultado, pois o meu computador congela por      */
    /* alguns instantes e retorna 0, ou seja, teoricamente ele conseguiu alocar  */
    /* o bloco de memória, mas 8Tb é impossível, sendo q nem no HDD tenho este   */
    /* espaço. Talvez isso seja por conta de eu utilizar Linux com 18GiB de      */
    /* memória SWAP, mas mesmo assim é um resultado muito estranho.              */

    return 0;
}
