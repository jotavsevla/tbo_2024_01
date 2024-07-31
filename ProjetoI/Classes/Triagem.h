//
// Created by João on 31/07/24.
//

#ifndef TBO_2024_01_TRIAGEM_H
#define TBO_2024_01_TRIAGEM_H
#include "TabelaHash.h"

class Triagem {
private:
    vector<TabelaHashFilmes> typeList;
    vector<TabelaHashFilmes> genresList;
public:
    bool insereNaHashType(string type){}
    bool insereNaHashGenres(vector<string> genres){}
};


#endif //TBO_2024_01_TRIAGEM_H
