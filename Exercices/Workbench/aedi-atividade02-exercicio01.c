#include <stdio.h>

int main() {
    double x, *p;
    p = &x;
    *p = 10.4;
    printf("Valor de x: %.1f\nTamanho da variável p: %lu\nEndereço de p: %p\n", x, sizeof(p), p);
    p++;
    printf("Endereço de p++: %p\n", p);
    return 0;
}
