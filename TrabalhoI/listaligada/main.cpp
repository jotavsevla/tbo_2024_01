#include "classes/ListaLigada.h"
#include <iostream>



using namespace std;

int main(int argc, char *argv[]) {
    cout << "Programa Lista Ligada Inicializando..." << endl;
    int qnt_elements;
    int aux_element_value;

    cin >> qnt_elements;
    ListaLigada lista;

    for (int i = 0; i < qnt_elements; ++i) {
        cin >> aux_element_value;
        lista.inserir(aux_element_value, i);
    }
    pair<int, int> minEi, posicaoEacesso;
    int operation, x, i;
    while (cin >> operation) {
        switch (operation) {
            case 1:
                lista.limpar();
            case 2:
                insertRandom(lista);
                break;
            case 3: // insere_x_no_i
                cin >> x >> i;
                cout << endl;
                lista.inserir(x, i);
                break;
            case 4: // fazer transposicao
                cin >> x >> i;
                cout << endl;
                lista.trocar(x,i);
                break;
            case 5: // procura o elemento x na lista
                cin >> x;
                posicaoEacesso = lista.buscar(x);
                cout << posicaoEacesso.first << " " << posicaoEacesso.second;
                break;
            case 6: // acha o elemento minimo
                minEi = lista.encontrarMin();
                cout << minEi.first << " " << minEi.second;
                break;
            case 7: // imprime
                lista.exibirLista();
                break;
            case 8: // imprime ao contrario
                lista.exibirListaInversa();
                break;
            default:
                cout << "Operação inválida.\n";
                break;
            case 0: // fechar programa
                return 0;
        }
    }
}

