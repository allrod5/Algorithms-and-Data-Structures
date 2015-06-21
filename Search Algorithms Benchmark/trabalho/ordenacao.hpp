#ifndef ORDENACAO_HPP_INCLUDED
#define ORDENACAO_HPP_INCLUDED

#include <time.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include "RandomCL.hpp"

namespace ED {
	template <typename T>
	class Ordenacao {
		public:
            static void bubblesort(T *vet, int n);
            static void selectsort(T *vet, int n);
            static void insertsort(T *vet, int n);
			static void shellsort(T *vet, int n);
			static void mergesort(T *vet, int n);
			static void heapsort(T *vet, int n);
			static void quicksort(T *vet, int n);
			static void qsort_C(T *vet, int n);
			static void sort_CPP(T *vet, int n);
			static bool isOrdered(T *vet, int n);
			static void benchmark(void (*sort)(T *vet, int n), int n, int seed);
        private:
			static void mergesort(T *vet, int r, int l); // Overload
			static void quicksort(T *vet, int esquerda, int direita); // Overload
            static void merge(T *vet, int r, int l);
            static void heapify(T *vet, int pai, int heapsize);
            static int Time(void (*algorithm)(T *vet, int n), T *vet, int n);
            static void writeFile(int tempo, int n, int seed);
            static int cmpfunc(const void *a, const void *b);
	};

    template <typename T>
    void Ordenacao<T>::bubblesort(T *vet, int n) {
        while(n>1) {
            for(int i=0; i<n-1; i++) {
                if(vet[i] > vet[i+1]) {
                    T aux = vet[i+1];
                    vet[i+1] = vet[i];
                    vet[i] = aux;
                }
            }
            n--;
        }
    }

    template <typename T>
	void Ordenacao<T>::selectsort(T *vet, int n) {
		T temp;
		int imenor, i, j;
		for (i = 0; i < n - 1; i++) {
			imenor = i;
			for (j = i + 1; j < n; j++)
				if (vet[j] < vet[imenor]) imenor = j;
			temp = vet[i];
			vet[i] = vet[imenor];
			vet[imenor] = temp;
		}
	}

	template <typename T>
    void Ordenacao<T>::insertsort(T *vet, int n) {
        for(int i=1; i<n; i++) {
			int j = i;
			while(vet[j-1]>vet[j]) {
				T aux = vet[j];
				vet[j] = vet[j-1];
				vet[j-1] = aux;
				j--;
			}
		}
    }

	template <typename T>
	void Ordenacao<T>::shellsort(T *vet, int n) {
        T aux;
        int i, j, h, k, m, jumps[13] = {217378076, 45806244, 9651787, 2034035, 428481, 90358, 19001, 4025, 836, 182, 34, 9, 1};

        k = jumps[i=0];
        while(k>n)
            k = jumps[++i];
        for(h=i;h<13;h++) {
            k = jumps[h];
            for(m=0; m<k; m++) {
                for(i=k+m;i<n;i+=k) {
                    j = i;
                    while(n>j && j>=k && vet[j]<vet[j-k]) {
                        aux = vet[j];
                        vet[j] = vet[j-k];
                        vet[j-k] = aux;
                        j -= k;
                    }
                }
            }
        }
	}

    template <typename T>
    void Ordenacao<T>::mergesort(T *vet, int n) {
        mergesort(vet, n-1, 0);
    }

	template <typename T>
    void Ordenacao<T>::mergesort(T *vet, int r, int l) {
        if(r-l==0) return;
        mergesort(vet, l+(r-l)/2, l);
        mergesort(vet, r, 1+l+(r-l)/2);
        merge(vet, r, l);
    }

    template <typename T>
    void Ordenacao<T>::merge(T *vet, int r, int l) {
        int start = l;
        int n = r-l+1;
        int m = 1+l+(r-l)/2;
        r = m;
        T *aux = new T[n];
        for(int i=0; i<n; i++) {
            if(r>=l+n || (l<m && vet[l]<vet[r]))
                aux[i] = vet[l++];
            else
                aux[i] = vet[r++];
        }
        for(int i=0; i<n; i++) {
            vet[start+i] = aux[i];
        }
        delete aux;
    }

	template <typename T>
	void Ordenacao<T>::heapify(T *vet, int pai, int heapsize) {
		int fl, fr, imaior;
		fl = (pai << 1) + 1;
		fr = fl + 1;
		while (true) {
			if ((fl < heapsize) && (vet[fl] > vet[pai])) imaior = fl;
			else imaior = pai;
			if ((fr < heapsize) && (vet[fr] > vet[imaior])) imaior = fr;
			if (imaior != pai){
				T aux = vet[pai];
				vet[pai] = vet[imaior];
				vet[imaior] = aux;
				pai = imaior;
				fl = (pai << 1) + 1;
				fr = fl + 1;
			}
			else break;
		}
	}

	template <typename T>
	void Ordenacao<T>::heapsort(T *vet, int n) {
		int i;
		for (i = (n >> 1) - 1; i >= 0; i--) heapify(vet, i, n);
		for (i = n - 1; i > 0; i--) {
			T aux = vet[0];
			vet[0] = vet[i];
			vet[i] = aux;
			heapify(vet, 0, i);
		}
	}

    template <typename T>
    void Ordenacao<T>::quicksort(T *vet, int n) {
        quicksort(vet, 0, n-1);
    }

	template <typename T>
    void Ordenacao<T>::quicksort(T *vet, int esquerda, int direita) {
            int i, j;
            T x, y;
            i = esquerda;
            j = direita;
            x = vet[(esquerda + direita) / 2];

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
            if(j > esquerda) quicksort(vet, esquerda, j);
            if(i < direita) quicksort(vet,  i, direita);
    }

    template<typename T>
    void Ordenacao<T>::qsort_C(T *vet, int n) {
        qsort(vet, n, sizeof(T), cmpfunc);
    }

    template<typename T>
    void Ordenacao<T>::sort_CPP(T *vet, int n){
        std::sort(vet, vet+n);
    }

	template<typename T>
    bool Ordenacao<T>::isOrdered(T *vet, int n) {
        for(int i=1; i<n; i++)
            if(vet[i-1]>vet[i])
                return false;
        return true;
    }

    template<typename T>
    int Ordenacao<T>::Time(void (*algorithm)(T *vet, int n), T *vet, int n) {
        int start;
        int tmili;

        start = clock();
        algorithm(vet, n);
        tmili = (int)((clock() - start)*1000/CLOCKS_PER_SEC);
        return(tmili);
    }

    template<typename T>
    void Ordenacao<T>::benchmark(void (*sort)(T *vet, int n), int n, int seed) {
        unsigned long int *vet = new unsigned long int[n];
        RandomCL<unsigned long int> gerador(seed);

        for(int i=0; i<n; i++)
            vet[i] = gerador.nextr();

        Ordenacao<unsigned long int>::writeFile(Ordenacao<unsigned long int>::Time(sort, vet, n), n, seed);
        //std::cout << isOrdered(vet, n);
        delete vet;
    }

    template<typename T>
    void Ordenacao<T>::writeFile(int tempo, int n, int seed) {
        std::ofstream arquivo("Resultados2.csv", std::ios::app);
        arquivo.is_open();
        arquivo<<n<<";"<<seed<<";"<<tempo<<";\n";
        arquivo.close();
    }

    template<typename T>
    int Ordenacao<T>::cmpfunc(const void *a, const void *b) {
       return ( *(T*)a > *(T*)b );
    }
}

#endif // ORDENACAO_HPP_INCLUDED
