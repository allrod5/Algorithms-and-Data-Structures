/*!
  * A princípio é impossível determinar, pois mesmo que o algoritmo seja
  * baseado em comparações, é incerto se, com n<m, f(n) < f(m), onde f(x)
  * é a função que dá o número de comparações de acordo com x.
  * Se assumirmos um algoritmo de comparação ótimo, ou seja, O(x) = x.log(x),
  * então o algoritmo (b) é o que realizará menos comparações, pois para o
  * (a) teremos um número de comparações f(n,m) = A*m*(n*log(n))+B e para (b)
  * g(n,m) = A*n*(m*log(m))+B. Logo fazendo g(n,m) - f(n,m) = C, temos:
  * log(m)-log(n) = C/(A*n*m) = K. Como n < m, temos que log(m) > log(n)
  * portanto K > 0. Portanto g(n,m) > f(n,m).
  */

 /* Um exemplo de um algoritmo baseado em comparações para achar máximo
    de um vetor que não deixa claro se f(n) < f(m) */

int max(int v[], int n) {
    int a[n], i;
    int max = v[0];
    int seed = srand(0);
    a[0] = 1;
    while(1) {
        for(i=0; i<n; i++) {
            if(a[n]==0) break;
        } if(i==n) break;
        i = rand(seed)%n;
        if(i>max) max = i;
        a[i] = 1;
    }
    return max;
}
