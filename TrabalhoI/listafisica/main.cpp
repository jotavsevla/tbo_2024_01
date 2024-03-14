
#include <iostream>
#include "classes/StaticLista.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Programa Lista Física Inicializando..." << endl;
    int qnt_elements;
    int aux_element_value;

//    ifstream inFile("in1.txt");
//
//    if (!inFile) {
//        cerr << "Nao foi possivel abrir o arquivo";
//        return 1;
//    }

//    inFile  >> qnt_elements;
    cin >> qnt_elements;
    StaticLista lista;
    int i = 0;
    while (i < qnt_elements) {
//        inFile  >> aux_element_value;
        cin >> aux_element_value;
        lista.insert(aux_element_value, i);
        i++;
    }
    pair<int, int> minEi, posicaoEacesso;
    int operation, x, indice;
    while (cin >> operation) {
        switch (operation) {
            case 1: // limpar lista
                lista.limpar();
            case 2:
                insertRandom(lista);
                break;
            case 3: // insere_x_no_i
//                inFile  >> x >> i;
                cin >> x >> indice;
                cout << endl;
                lista.insert(x, indice);
                break;
            case 4: // fazer transposicao
//                inFile  >> x >> i;
                cin >> x >> indice;
                cout << endl;
                lista.transpoe(x,indice);
                break;
            case 5: // procura o elemento x na lista
                //                inFile  >> x;
                cin >> x;
                posicaoEacesso = lista.search(x);
                cout <<  posicaoEacesso.first << " " << posicaoEacesso.second << endl;
                break;
            case 6: // acha o elemento minimo
                minEi = lista.findMin();
                cout << get<0>(minEi) << " " << get<0>(minEi) << endl;
                break;
            case 7: // imprime
                lista.displayList();
                break;
            case 8: // imprime ao contrario
                lista.displayListInReverse();
                break;
            default:
                cout << "Operação inválida.\n";
                break;
            case 0: // fechar programa
                return 0;
        }
    }
}