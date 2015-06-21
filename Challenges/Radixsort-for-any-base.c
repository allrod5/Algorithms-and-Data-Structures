/*!
 *  Radix Sort algorithm
 *  @author Rodrigo Martins de Oliveira
 *  Universidade Federal do ABC (UFABC)
 *  Santo André - SP, Brazil
 *  June, 2015
 *
 *  This code was produced for the "Algoritmos e Estruturas de Dados II" class at UFABC
 *  Lectured by professor Jesús P. Mena-Chalco
 *
 *  The main() and getMaxFunc() functions serve for the sole purpose of providing a
 *  fast demo of how to use radixSort_base()
 */

#include <stdio.h>

/*!
 *  @def        radixSort
 *  @abstract   Variadic macro
 *  @discussion This macro enables calling radixSort_base with just
 *              relevant parameters for the case of usage
 */
#define radixSort(v, n, getMax, ...) var_f(v, n, getMax, (f_args){__VA_ARGS__})

/*!
 *  @struct     f_args
 *  @abstract   Supporting struct
 *  @discussion This struct holds default arguments for radixSort_base
 */
typedef struct {
    long unsigned int D;
    long unsigned int *m;
    char big_endian;
} f_args;

void radixSort_base(void*[], long unsigned int, long unsigned int (void*[], long unsigned int), long unsigned int, long unsigned int*, char);
long unsigned int getMaxFunc(void*[], long unsigned int);
void var_f(void*[], long unsigned int, long unsigned int (void*[], long unsigned int), f_args);

int main() {
    int i, j;
	int *b10v[4] = {0,80,4,91};
	char *b26v[4] = {'a','x','b','j'};
	int *b16v[7] = {0x14, 0x0, 0x8f6, 0x80, 0x56, 0xa, 0x80};
	char *b36v[7] = {"014", "000", "8f6", "080", "056", "00a", "080"};
	long unsigned int *m36[1] = {3};
	char **b1296v[4][2] = {{"xxx","aaa"},{"aaa","xxx"},{"7dg","0f1"},{"7dg","1f0"}};
	long unsigned int *m1296[2] = {2,3};
	int **b1000v[4][3] = {{1,8,0},{9,1,1},{0,0,0},{0,0,1}};
	long unsigned int *m1000[1] = {3};

	printf("b10v unsorted: "); for(i=0; i<4; i++) printf("%d ", b10v[i]); printf("\n");
	radixSort(b10v, 4, getMaxFunc);
	printf("b10v sorted  : "); for(i=0; i<4; i++) printf("%d ", b10v[i]); printf("\n");

	printf("b26v unsorted: "); for(i=0; i<4; i++) printf("%s ", b26v+i); printf("\n");
	radixSort(b26v, 4, getMaxFunc);
	printf("b26v sorted  : "); for(i=0; i<4; i++) printf("%s ", b26v+i); printf("\n");

	printf("b16v unsorted: "); for(i=0; i<7; i++) printf("%x ", b16v[i]); printf("\n");
	radixSort(b16v, 7, getMaxFunc);
	printf("b16v sorted  : "); for(i=0; i<7; i++) printf("%x ", b16v[i]); printf("\n");

	printf("b36v unsorted: "); for(i=0; i<7; i++) printf("%s ", b36v[i]); printf("\n");
	radixSort(b36v, 7, getMaxFunc, 1, m36, 1);
	printf("b36v sorted  : "); for(i=0; i<7; i++) printf("%s ", b36v[i]); printf("\n");

	printf("b1296v sorted  : "); for(i=0; i<4; i++) {for(j=0; j<2; j++) printf("%s-", b1296v[i][j]); printf("\b ");} printf("\n");
	radixSort(b1296v, 7, getMaxFunc, 2, m1296, 1);
	printf("b1296v sorted  : "); for(i=0; i<4; i++) {for(j=0; j<2; j++) printf("%s-", b1296v[i][j]); printf("\b ");} printf("\n");

	return 0;
}

/*!
 *  @function   radixSort_base
 *  @abstract   Sort an array using Radix Sort.
 *  @discussion This function takes an array of positive
 *              integers in any base (radix) and sorts
 *              it in ascending order using the Radix
 *              Sort algorithm.
 *  @param      v           the array with elements to sort
 *  @param      n           the length of the array v
 *  @param      getMax      the function to get the maximum element of v
 *  @param      D           the depth of the array v, the depth of an array
 *                          is considered as its dimension - 1. So an 1D
 *                          array of ints has depth 0 and an array of strings
 *                          is a 2D array of chars and has depth 1
 *  @param      m           is an array with the size of the arrays inside v
 *                          m must have a length equal to D
 *  @param      big_endian  indicates if items in the array are little endian
 *                          (big_endian == 0) or big endian (big_endian > 0);
 */
void radixSort_base(void *v[], long unsigned int n, long unsigned int (*getMax)(void*[], long unsigned int), long unsigned int D, long unsigned int *m, char big_endian) {
    long unsigned int i, j, k;
    long unsigned int significantDigit;
    long unsigned int max;
    void *semiSorted[n];
    void *tmp[n];
    char visited[n];
    char *original[n];
    char *u[n];

    if(D) {
        for(i=0; i<m[0]; i++) {
            for(j=0; j<n; j++) {
                if(D==1) {
                    char *str = v[j]+abs(big_endian*(m[0]-1)-i);
                    u[j] = str[0];
                    original[j] = str[0];
                }
                else semiSorted[j] = v[j]+abs(big_endian*(m[0]-1)-i);
            }
            if(D==1) radixSort(u, n, getMax);
            else radixSort(semiSorted, n, getMax, D-1, m+1, big_endian);
            for(j=0; j<n; j++) visited[j] = 0;
            for(j=0; j<n; j++) {
                for(k=0; k<n; k++) {
                    if(D!=1 && v[j]+abs(big_endian*(m[0]-1)-i) == semiSorted[k] && !visited[k]) {
                        tmp[k] = v[j];
                        visited[k] = 1;
                        break;
                    }
                    if(D==1 && original[j] == u[k] && !visited[k]) {
                        tmp[k] = v[j];
                        visited[k] = 1;
                        break;
                    }
                }
            }
            for(j=0; j<n; j++) v[j] = tmp[j];
        }
        return;
    }

    significantDigit = 1;
    max = (*getMax)(v, n);

    while (max / significantDigit > 0){
        long unsigned int intermediate[10] = {0};
        for(i=0; i<n; i++)
            intermediate[(long unsigned int)v[i]/significantDigit % 10]++;
        for(i=1; i<10; i++)
            intermediate[i] += intermediate[i-1];
        for(i=n; i>0; i--)
            semiSorted[--intermediate[(long unsigned int)v[i-1]/significantDigit % 10]] = v[i-1];
        for(i=0; i<n; i++)
            v[i] = semiSorted[i];
        significantDigit *= 10;
    }
}

long unsigned int getMaxFunc(void *v[], long unsigned int n) {
    long unsigned int i;
    long unsigned int max = (long unsigned int) v[0];
    for(i=1; i<n; i++)
        if((long unsigned int)v[i]>max) max = (long unsigned int) v[i];
    return max;
}

/*!
 *  @function   var_f
 *  @abstract   Wrapper function
 *  @discussion This function takes the arguments passed to it by radixSort macro
 *              completes the default parameters with their default values if not
 *              informed and call radixSort_base
 */
void var_f(void *v[], long unsigned int n, long unsigned int (*getMax)(void*[], long unsigned int), f_args in) {
    long unsigned int D = in.D ? in.D : 0;
    long unsigned int *m = in.m ? in.m : (void*) 0;
    char big_endian = in.big_endian ? in.big_endian : 0;
    radixSort_base(v, n, getMax, D, m, big_endian);
}
