#include <stdio.h>

int size = 4;

/* Neste caso o ID 1 é celebridade */
short int MATRIX[4][4] = {{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};

short int HaveAcquiantance(int a, int b) { return MATRIX[a][b]; }

short int L[4] = {1,1,1,1}; /* No início todos são potenciais celebridades */

int GetCelebrity(int size) {
    int i, j, C;
    C = -1; /* -1 significa nenhuma celebridade */
    for(i=0; i<size; i++) { /* loop para percorrer L */
        if(!L[i]) continue; /* Só continua se L[i] for potencial celebridade */
        for(j=i+1; j<size; j++) { /* loop para percorrer próximas pessoas */
            if(HaveAcquiantance(i, j)) break; /* Se i conhece j, então i não é celebridade */
            L[j] = 0; /* Se i não conhece j, então j não é celebridade */
        } if(j!=size) continue; /* simulação de uma estrutura for...else */
        for(j=0; j<size; j++) /* atual i é uma potencial celebridade, checa se todos o conhecem e se ele não conhece ninguém */
            if(i!=j && (!HaveAcquiantance(j ,i) || HaveAcquiantance(i, j))) break;
        if(j!=size) break;
        C = i; /* Caso a checagem tenha dado certo, então i é celebridade */
    }
    return C;
}

int main()
{
    int id = GetCelebrity(size);
    id == -1 ? printf("No celebrity\n") : printf("Celebrity ID %d\n", id);
    return 0;
}
