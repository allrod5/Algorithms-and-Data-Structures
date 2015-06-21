
#ifndef ED_H_INCLUDED
#define ES_H_INCLUDED

#include <iostream>
#include <stdexcept>

namespace ED {

    template <typename Tipo>
    struct Celula {
        Tipo el;
        Celula *prox, *ant;
    };

    template <typename Tipo>
    class Lista {
        public:
            // Construtor e Destrutor
            Lista();
            ~Lista();
            // Métodos
            void volta_cursor();
            bool tem_proximo();
            Tipo proximo() throw(std::logic_error);
            void insere_ordenado(Tipo el);
        private:
            int index;
            Celula<Tipo> *ini, *cursor;
    };

    template <typename Tipo>
    Lista<Tipo>::Lista() {
        ini = new Celula<Tipo>;
        ini->prox = ini;
        ini->ant = ini;
        cursor = ini;
    }

    template <typename Tipo>
    Lista<Tipo>::~Lista() {
        return;
    }

    template <typename Tipo>
    void Lista<Tipo>::volta_cursor() {
        cursor = ini->prox;
        return;
    }

    template <typename Tipo>
    bool Lista<Tipo>::tem_proximo() {
        return cursor->prox!=ini;
    }

    template <typename Tipo>
    Tipo Lista<Tipo>::proximo() throw(std::logic_error) {
        if(!tem_proximo())
            throw std::logic_error("Erro: Não há próximo elemento.\n");
        cursor = cursor->prox;
        return cursor->el;
    }

    template <typename Tipo>
    void Lista<Tipo>::insere_ordenado(Tipo el) {
        cursor = new Celula<Tipo>;
        cursor->el = el;
        cursor->prox = ini;
        cursor->ant = ini->ant;
        (ini->ant)->prox = cursor;
        ini->ant = cursor;
    }
}



#endif // DS_H_INCLUDED
