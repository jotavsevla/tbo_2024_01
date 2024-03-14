//
// Created by yango on 10/03/2024.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include "Nodo.h"

#define MAX_ELEMENTS 100
#define MAX_VALUE 1000
using namespace std;

#ifndef TRABALHOI_LISTALIGADA_H
#define TRABALHOI_LISTALIGADA_H

// a lista ligada, deve conter um vetor, para quantificar
//

class ListaLigada {
private:
    Nodo* cabeca;
    Nodo* cauda;
    int tamanho;

public:
    ListaLigada() : cabeca(nullptr), cauda(nullptr), tamanho(0) {}

    bool inserir(int valor, int posicao) {
        if (posicao < 0 || posicao > tamanho) {
            cout << "Posição inválida.\n";
            return false;
        }
        if (tamanho >= MAX_ELEMENTS) {
            cout << "Lista cheia" << endl;
            return false;
        }
        Nodo* novoNodo = new Nodo(valor);
        novoNodo->acessos = 1;
        if (posicao == 0) {
            novoNodo->proximo = cabeca;
            cabeca = novoNodo;
            if (tamanho == 0) {
                cauda = novoNodo;
            }
        } else {
            Nodo* atual = cabeca;
            for (int i = 0; i < posicao - 1; ++i) atual = atual->proximo;
            novoNodo->proximo = atual->proximo;
            atual->proximo = novoNodo;
            if (novoNodo->proximo == nullptr) cauda = novoNodo;
        }
        tamanho++;
        return true;
    }

    void limpar() {
        Nodo* atual = cabeca;
        Nodo* proximoNodo;
        while (atual != nullptr) {
            proximoNodo = atual->proximo;
            delete atual;
            atual = proximoNodo;
        }
        cabeca = nullptr;
        cauda = nullptr;
        tamanho = 0;
    }

    void trocar(int posicao1, int posicao2) {
        if (posicao1 < 0 || posicao1 >= tamanho || posicao2 < 0 || posicao2 >= tamanho) {
            cout << "Posição inválida.\n";
            return;
        }
        Nodo* nodo1 = encontrarNodo(posicao1);
        Nodo* nodo2 = encontrarNodo(posicao2);
        int valorTemp = nodo1->valor;
        nodo1->valor = nodo2->valor;
        nodo2->valor = valorTemp;
    }

    pair<int, int> buscar(int valor) {
        pair<int, int> posicaoEacessos(-1, -1);
        Nodo* atual = cabeca;
        int contador = 0;
        while (atual != nullptr) {
            if (atual->valor == valor) {
                posicaoEacessos.first = contador;
                atual->acessos++;
                posicaoEacessos.second = atual->acessos;
                break;
            }
            atual = atual->proximo;
            contador++;
        }
        return posicaoEacessos;
    }

    pair<int, int> encontrarMin() {
        if (tamanho == 0) {
            cout << "Lista vazia\n";
            return make_pair(-1, -1);
        }
        Nodo* atual = cabeca;
        Nodo* minNodo = atual;
        while (atual != nullptr) {
            if (atual->valor < minNodo->valor) {
                minNodo = atual;
            }
            atual = atual->proximo;
        }
        return make_pair(minNodo->valor, minNodo->acessos);
    }

    int getTamanho() {
        return tamanho;
    }

    void exibirLista() {
        Nodo* atual = cabeca;
        while (atual != nullptr) {
            cout << atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    void exibirListaInversa() {
        stack<int> pilha;
        Nodo* atual = cabeca; // Começa do último nó para ir ao primeiro

        // Empilha todos os valores da lista ligada na pilha
        while (atual != nullptr) {
            pilha.push(atual->valor);
            atual = atual->proximo; // Vai para o nó anterior
        }

        // Desempilha e imprime os valores
        while (!pilha.empty()) {
            cout << pilha.top() << " ";
            pilha.pop();
        }
        cout << endl;
    }

private:
    Nodo* encontrarNodo(int posicao) {
        Nodo* atual = cabeca;
        for (int i = 0; i < posicao; ++i) {
            atual = atual->proximo;
        }
        return atual;
    }
};

// função valores aleatórios
void insertRandom(ListaLigada &arg){
    srand(time(nullptr));
    int randomX = 0;
    int index = 0;

    while(arg.inserir(randomX, index)){
        randomX = rand() % MAX_VALUE + 1;
        index++;
    }

};



#endif //TRABALHOI_LISTALIGADA_H
