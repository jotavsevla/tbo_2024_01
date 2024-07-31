//
// Created by João on 28/07/24.
//

#ifndef TBO_2024_01_ARQUIVO_H
#define TBO_2024_01_ARQUIVO_H
#include "Filme.h"
#include "Cinema.h"
#include "sstream"
#include "fstream"
#define MAX 638831 // ultimo valor que a hashFilme() é capaz de gerar
using namespace std;

class Arquivo {
public:
    vector<Filme> filmes;
    vector<Cinema> cinemas;
    string arquivo;

    Arquivo(const string& nomeArquivo) : arquivo(nomeArquivo) {}

    int lerArquivo() {
        ifstream file(arquivo);

        if (!file.is_open())
            return 1;

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
            cout << t_const << titleType<< primaryTitle<< originalTitle<< adult<<startY<<endY<<runTime<<genres;
            vector<string> genresVec; // Clear genresVec for each iteration
            stringstream genresStream(genres); // Create genresStream after genres is populated
            string genre;
            while (getline(genresStream, genre, ','))
                genresVec.push_back(genre);
            Filme atual(t_const, titleType, primaryTitle, originalTitle, adult, startY, endY, runTime, genresVec);
            filmes.push_back(atual);
        }
        file.close();
    }
    Filme getFilmePorId(int codeId){ return filmes[codeId];}
    Cinema getCinemaPorId(int codeId){ return cinemas[codeId];}

};


#endif //TBO_2024_01_ARQUIVO_H
