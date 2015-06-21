#include <stdio.h>
#include <stdlib.h>

int main(){
	double *p, *vetor = (double*)malloc(10*sizeof(double));

	p = vetor + 10*sizeof(double);

	*vetor = 0;
	vetor++;
	*vetor = 1;
	vetor++;

	for(; vetor <= p; vetor++){
		*vetor = *(vetor-1) + *(vetor-2);

		printf("%f\n", *vetor);

	}

}
