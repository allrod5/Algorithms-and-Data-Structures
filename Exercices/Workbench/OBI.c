#include <stdio.h>;

int main(){

    unsigned int counter = 0;
    unsigned int N, P, i;

	scanf("%d %d", &N, &P);
	for(i=0; i<N; i++) {

        unsigned int P1, P2;

        scanf("%d %d", &P1, &P2);
        if(P1+P2>=P){
            ++counter;
        }
	}

	printf("%d",counter);
}
