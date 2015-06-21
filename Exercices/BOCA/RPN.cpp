#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <algorithm>

using namespace std;    // pra evitar de escrever std:: toda vez...
stack<float> s;         // declaro a pilha globlamente

void normalize ( string *expression );      // função para regularizar os espaços da expresso inserida (e.g. 9 8- fica 9 8 -)
bool evaluate ( const string& expression ); // analisar se afunção é válida e calcular o resultado

int main () {
    string expression;                  // string para armazenar a entrada
    while ( true ) {                    // loop principal
        getline ( cin, expression );    // obter a linha inserida
        if ( expression=="#" ) break;   // identificar símbolo de parada
        normalize ( &expression );      // regularizar a entrada
        if ( evaluate ( expression ) )  // se o valor for verdadeiro, a expressão é válida
            cout << s.top() << endl;    // o resultado é o último elemento restante na pilha
        else                            // se não for válida
            cout << "erro\n";           // imprima mensagem de erro
        while ( !s.empty() )            // enquanto a pilha não estiver vazia
            s.pop();                    // esvazie ela para receber a próxima linha
    }
    return 0;
}

void normalize ( string *expression ) {
    int i, k, sz;                                       // declaração de variáveis int
    string normalized = "", item;                       // declaração de strings. "normalized" será construída de maneira apropriada (com espaços adequados)
    istringstream ss ( *expression );                   // stringstream da expressão inserida
    while ( ss >> item ) {                              // enquanto a linha não acabou, atribúa um elemento da linha a item
        sz = item.length();                             // tamanho, em número de caracteres, do elemento
        k = 0;                                          // k conta quantos caracteres não são números
        for ( i=0; i<sz || sz==0; i++ ) {               // para cada caracter do elemento
            try {                                       // tente
                stoi ( item.substr(i, 1 ));             // converter o caracter para um número
            } catch ( const invalid_argument& e ) {     // se der errado o caracter não é um número
                k++;                                    // atualize k
            }
        }
        if ( k==0 )                                     // se k==0, o elemento é composto apenas de números, portanto ele já está regularizado
            normalized += item+" ";                     // adicione ele na expressão normalizada
        else if ( k==sz )                               // se k==sz, então o elemento é composto apenas de não-númerais
            for ( i=0; i<sz; i++ )                      // para cada caracter do elemento,
                normalized += item.substr( i, 1 )+" ";  // adicioná-lo à expressão normalizada como um elemento individual
        else                                                                                        // se o elemento é composto de números e não-números
            for (i=0; i<sz; i++) {                                                                  // para cada caracter do elemento
                try {                                                                           // tente
                    stoi(item.substr( i, 1 ));                                                  // converter para número
                    normalized += item.substr( i, 1 );                                          // se a conversão for bem sucedida, adicionar o caracter na espressão normalizada, note que não insiro espaço, pois o próximo caracter pode ser um número também e portanto o elemento deve ser um número de mais de uma casa
                } catch ( const invalid_argument& e ) {                                         // se der erro, o caracter não é um número
                    if (normalized!="" && normalized.substr( normalized.length()-1, 1 )!=" ")   // se não estamos no início da expressãp && não há um espaço na última posição da expressão normalizada
                        normalized += " ";                                                      // insira esse espaço
                    normalized += item.substr( i, 1 )+" ";                                      // adicione o caracter à expressão normalizada
                }
            }
            if(normalized.substr( normalized.length()-1, 1 )!=" ")                              // se não há um espaço na última posição da expressão normalizada
                normalized += " ";                                                              // insira esse espaço
    }
    *expression = normalized;                                                                   // atribua à variável expression da função main() à expressão normalizada
}

bool evaluate ( const string& expression ) {
    float a, b, ans;                                                                            // declaração de variáveis float para calcular a expressão
    stringstream RPN(expression);                                                               // cria uma stringstream com a expressão
    string el;                                                                                  // string para receber os elementos de RPN
    while ( RPN >> el ) {                                                                       // enquanto houver elementos em RPN, atribúa-os à el
        if ( find_if(el.begin(), el.end(), [](char c) { return !isdigit(c); }) == el.end() ) {  // se for um número
            s.push( stoi(el) );                                                                 // coloca na pilha
        } else {                                                                                // se não for um número, começa o processo de cálculo
            if ( s.size()>1 ) {                                                                 // se a pilha tiver ao menos 2 números
                b = s.top();                                                                    // coloque o topo da pilha em b
                s.pop();                                                                        // desempilhe
                a = s.top();                                                                    // coloque o topo em a
                s.pop();                                                                        // desempilhe
            } else {                                                                            // caso a pilha não tenha ao menos 2 nmeros
                return false;                                                                   // retorne falso (espressão inválida)
            }
            if ( el == "+" )                                                                    // +
                ans =  a + b ;                                                                  // some a e b
            else if ( el == "-" )                                                               // -
                ans =  a - b ;                                                                  // subtraia b de a
            else if ( el == "*" )                                                               // *
                ans =  a * b ;                                                                  // multiplique a e b
            else if ( el == "/" && b != 0 )                                                     // /, que não seja o denominador==0
                ans =  a / b ;                                                                  // divida a por b
            else                                                                                // nenhum operador previsto
                return false;                                                                   // retorne falso
            s.push( ans );                                                                      // empilhe o resultado
        }
    }
    if( s.size()!=1 ) return false;                                                             // se sobrar na pilha mais do que um elemento (o resultado), a expressão  inválida, retorne falso
    else return true;                                                                           // caso contrário retorne true (espressão válida e resultado obtido)
}
