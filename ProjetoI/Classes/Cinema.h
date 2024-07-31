//
// Created by João on 18/07/24.
//
#ifndef TBO_2024_01_CINEMA_H
#define TBO_2024_01_CINEMA_H


// construtor feito desse modo tira a necessidade de fazer vários setters
// mas também implica em armazenar os dados em outras variaveis,
// antes de instanciar o objeto

#include "string"
#include "vector"
#include "utility"
#include "string"
#include "iostream"
using namespace std;

class Cinema {
private :
    int codeId;
    string name;
    vector<int> moviePosterId;
    pair <double,double> cordinate;
    int ticketValue;

public:
    Cinema (int codeId, string name, vector<int> moviePosterId, pair<double,double> cordinate, int ticketValue);
    int getCodeId() const { return codeId; }
    string getName() const { return name; }
    vector<int> getMoviePosterId() const { return moviePosterId; }
    pair<double, double> getCoordinate() const { return cordinate; }
    int getTicketValue() const { return ticketValue; }
};


#endif //TBO_2024_01_CINEMA_H
