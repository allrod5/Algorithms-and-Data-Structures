/*!
 * Partial Quicksort
 * @author Rodrigo Martins de Oliveira
 * @author Victor Campagner de Barros
 *
 * Universidade Federal do ABC
 * June - 2015
 */

#include <iostream>

void partial_quicksort(int *vet, int n, int k);
void partial_quicksort(int *vet, int esquerda, int direita, int k);

int main() {
    int i;
    int vet[16] = {5,6,4,-80,2,0,1,-3,100,10,900,600,500,300,0,111};
    int k = 5;
    for(i=0; i<16; i++) std::cout << "\033[1;31m" << vet[i] << "\033[0m ";
    std::cout << "\b\n";
    partial_quicksort(vet, 16, k);
    for(i=0; i<k; i++) std::cout << "\033[1;32m" << vet[i] << "\033[0m ";
    for(i; i<16; i++) std::cout << "\033[1;31m" << vet[i] << "\033[0m ";
    std::cout << "\b\n";

    return 0;
}

void partial_quicksort(int *vet, int n, int k) {
    if(k) partial_quicksort(vet, 0, n-1, k);
}

void partial_quicksort(int *vet, int esquerda, int direita, int k) {
    int i, j;
    int x, y;
    i = esquerda;
    j = direita;
    if(k > direita) x = vet[(esquerda + direita) / 2];
    else x = vet[(esquerda + k) / 2];

    while(i <= j) {
        while(vet[i] < x && i < direita) i++;
        while(vet[j] > x && j > esquerda) j--;
        if(i <= j)  {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda) partial_quicksort(vet, esquerda, j, k);
    if(i < direita && j-esquerda < k-1) partial_quicksort(vet,  i, direita, k);
}
