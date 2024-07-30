//
// Created by João on 28/07/24.
//

#ifndef TBO_2024_01_ARQUIVO_H
#define TBO_2024_01_ARQUIVO_H
#include "string"
#include "vector"
#include "utility"
#include "string"
#include "iostream"
#include "sstream"
#include "fstream"
#include "Filme.h"
#define MAX 638832
#define FILMESARQ "../arquivosTexto/filmes.txt"
using namespace std;

class Arquivo {
public:
    vector<Filme> filmes;
    string arquivo;

    Arquivo(const string& nomeArquivo) : arquivo(FILMESARQ) {}

    void lerArquivo() {
        ifstream file(arquivo);

        if (!file.is_open())
            return;

        filmes.reserve(MAX);
        string linha;
        getline(file, linha); // Ignora a primeira linha (cabeçalho)
        string t_const, titleType, primaryTitle, originalTitle, isAdult, startYear, endYear, runtimeMinutes, genres;

        while (getline(file, linha)) {
            stringstream ss(linha);
            getline(ss, t_const, '\t');
            getline(ss, titleType, '\t');
            getline(ss, primaryTitle, '\t');
            getline(ss, originalTitle, '\t');
            getline(ss, isAdult, '\t');
            getline(ss, startYear, '\t');
            getline(ss, endYear, '\t');
            getline(ss, runtimeMinutes, '\t');
            getline(ss, genres, '\t');
            int startY = (startYear != "\\N") ? stoi(startYear) : -1;
            int endY = (endYear != "\\N") ? stoi(endYear) : -1;
            int runTime = (runtimeMinutes != "\\N") ? stoi(runtimeMinutes) : -1;
            bool adult = (isAdult == "1");
            // Converte a string de gêneros em um vetor de strings
            vector<string> genresVec;
            stringstream genresStream(genres);
            string genre;
            while (getline(genresStream, genre, ','))
                genresVec.push_back(genre);
            Filme atual(t_const, titleType, primaryTitle, originalTitle, adult, startY, endY, runTime, genresVec);
            filmes.push_back(atual);
        }
        file.close();
    }
};


#endif //TBO_2024_01_ARQUIVO_H
