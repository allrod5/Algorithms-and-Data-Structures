#include <iostream>
#include "ListaDEnc.h"

int main()
{
    int i;
    ED::Lista<int> L;
    for(i=0; i<51; i+=10)
        L.insere_ordenado(i);
    std::cout << (L.tem_proximo() ? "O cursor não está no fim da lista.\n" : "O cursor está no fim da lista.\n");
    L.volta_cursor();
    std::cout << "O segundo elemento da lista é: " << L.proximo() << std::endl;
    std::cout << (L.tem_proximo() ? "O cursor não está no fim da lista.\n" : "O cursor está no fim da lista.\n");
    return 0;
}
