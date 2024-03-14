//
// Created by João on 13/03/24.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef TBO_2024_01_NODO_H
#define TBO_2024_01_NODO_H


class Nodo {
public:
    int valor;
    int acessos;
    Nodo* proximo;
    Nodo* anterior;


    Nodo(int valor) : valor(valor), acessos(0), proximo(nullptr), anterior(nullptr) {}
};



#endif //TBO_2024_01_NODO_H
