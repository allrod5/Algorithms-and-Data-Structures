#include <stdio.h>

int main (){
        long int N, M, a, b, k, i, resultado = 0;

        scanf ( "%ld %ld", &N, &M );

        for ( i=0; i<M; i++ ) {
            scanf ( "%ld %ld %ld", &a, &b, &k );
            resultado += k*(b-a+1);
        }
        resultado /= N;
        printf ( "%ld", resultado);
        return 0;
}
