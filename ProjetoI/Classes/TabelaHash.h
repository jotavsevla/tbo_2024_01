//
// Created by João on 31/07/24.
//

#ifndef TBO_2024_01_TABELAHASH_H
#define TBO_2024_01_TABELAHASH_H
#include "Filme.h"
#include "Cinema.h"

class TabelaHashFilmes{
private:
    string chave;
    int qntAtualItens;
    vector<int> codeIdFilmes;
public:
    TabelaHashFilmes(string chave): chave(chave){}
    int procuraNaTabelaHash(int codeId){
        int atual = codeIdFilmes[0];
        while(atual < codeId)
            atual++;
        return atual == codeId ? codeId : -1;
    }
    string getChave(){return this->chave;}
};


#endif //TBO_2024_01_TABELAHASH_H
