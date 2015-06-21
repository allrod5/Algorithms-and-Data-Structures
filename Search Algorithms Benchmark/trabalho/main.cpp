#include <iostream>
#include <cstdlib>
#include "ordenacao.hpp"

using namespace std;
using namespace ED;

int main() {
    unsigned long int seeds[] = {4, 81, 151, 1601, 2307, 4207};
	unsigned long int tamanho[] = {10000, 30000, 90000, 270000, 810000, 2430000, 7290000, 21870000, 65610000};
	unsigned long int tamanho2[] = {10000, 20000, 30000, 40000, 50000, 70000, 90000, 120000, 150000};

	void (*algorithm[9])(unsigned long int *vet, int n) = {Ordenacao<unsigned long int>::bubblesort,
														   Ordenacao<unsigned long int>::selectsort,
														   Ordenacao<unsigned long int>::insertsort,
														   Ordenacao<unsigned long int>::quicksort,
														   Ordenacao<unsigned long int>::heapsort,
														   Ordenacao<unsigned long int>::mergesort,
														   Ordenacao<unsigned long int>::shellsort,
														   Ordenacao<unsigned long int>::qsort_C,
														   Ordenacao<unsigned long int>::sort_CPP};

    /*for(int f=7; f<9; f++)
        Ordenacao<unsigned long int>::benchmark(algorithm[f], 10, 0);*/

	// Algoritmos eficientes
	for(int f=3; f<9; f++){
		for(int i=0; i<9; i++){
			cout<<endl<<"Tamanho = "<<tamanho[i]<<endl;
			for(int j=0; j<6; j++){
				cout<<endl<<"Seed = "<<seeds[j]<<endl;
				Ordenacao<unsigned long int>::benchmark(algorithm[f], tamanho[i], j);
			}
		}
	}

	// Algoritmos ineficientes
	for(int f=0; f<3; f++){
		for(int i=0; i<9; i++){
			cout<<endl<<"Tamanho = "<<tamanho2[i]<<endl;
			for(int j=0; j<6; j++){
				cout<<endl<<"Seed = "<<seeds[j]<<endl;
				Ordenacao<unsigned long int>::benchmark(algorithm[f], tamanho2[i], j);
			}
		}
	}

	return 0;
}
