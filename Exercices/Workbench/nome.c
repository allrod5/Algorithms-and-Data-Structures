#include <stdio.h>

int main(){
	long int N, M, a, b, k, i, j, soma = 0, media = 0, denominador = 0;

	scanf("%ld %ld", &N, &M);

	long int jars[N];

	for(i=0; i<N; i++){
		jars[i]=-1;
	}

	for(i=0; i<M; i++){
		scanf("%ld %ld %ld", &a, &b, &k);
		for(j=a; j<=b; j++){
			j--;
			if(jars[j]<0){
				jars[j]=0;
			}
			jars[j]+=k;
			j++;
		}
	}

	for(i=0; i<N; i++){
		if(jars[i]>=0){
			soma+=jars[i];
			denominador++;
		}
	}

	media = soma/denominador;

	printf("%l\n", media);
}
