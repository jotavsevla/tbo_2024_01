#ifndef TRABALHOI_STATICLISTA_H
#define TRABALHOI_STATICLISTA_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

#define MAX_VALUE 1000
#define MAX_ELEMENTS 100

using namespace std;

class StaticLista {
public:
    vector<int> list;
    vector<int> acess;

public:
    // metodo para inserir um valor em uma posição especifica
    // respectivesize' deve ser aumentado pra cada vez que houver inserção
    bool insert(int value, int position){
        if (position < 0){
            cout << "posicao invalida.\n";
            return false;
        }
        if (!(list.size() < MAX_ELEMENTS)){
            cout << "lista cheia" << endl;
            return false;
        }
        if(list.size() == position) {
            list.push_back(value);
            acess.push_back(0);
        }
        list.insert(list.begin() + position, value);
        acess.insert(acess.begin() + position, 1);
        return true;
    }
    void limpar(){
        list.clear();
        acess.clear();
    }

    // metodo para trocar duas posicoes
    void transpoe(int position1, int position2){
        if (position1 < 0 || position1 >= list.size() || position2 < 0 || position2 >= list.size()){
            cout << "posicao invalida.\n";
            return;
        }
        swap(list[position1], list[position2]);
        swap(acess[position1],acess[position2]);
    }

    // metodo para procurar um valor
    pair <int, int> search(int value){
        pair<int,int> posicaoEacessos(-1,-1);
        for(int i = 0; i < list.size(); ++i){
            if (list[i] == value) {
                posicaoEacessos.first = i;
                posicaoEacessos.second = ++acess[i];
            }
        }
        cout << endl;
        return posicaoEacessos;
    }

    // metoda para encontrar o menor valor
    pair <int, int> findMin(){
        pair<int,int> minEacessos(-1,-1);
        if (list.empty()) {
            cout << "lista vazia\n";
            return minEacessos;
        }
        auto min_it = min_element(list.begin(), list.end());
        get<0>(minEacessos) = *min_it;

        acess[distance(list.begin(), min_it)]++;  // incrementa o contador de acessos para o menor valor
        minEacessos.first = ++acess[distance(list.begin(), min_it)];

        // considerando o acesso da instância atual, foi acessado<1>(minEacessos)...
        return minEacessos;
    }
    unsigned long int tam(){
        unsigned long int actual_size = list.size();
        return actual_size;
    }

    void displayList(){
        for(unsigned long int i = 0; i < list.size()-1; i++)
            cout << list[i] << " ";
        cout << endl;
    }
    void displayListInReverse(){
        for (unsigned long int i = list.size()-1; i >= 0 && i < list.size(); i--)
            cout << list[i] << " ";
        cout << endl;
    }
};
// o que este código falta fazer é deletar a lista antiga
void insertRandom(StaticLista &arg){
    srand(time(nullptr));
    int randomX = 0;
    int index = arg.tam()-1;
    if (index < 0) index = 0;

    while(arg.insert(randomX, index)){
        randomX = rand() % MAX_VALUE + 1;
        index++;
    }

};

#endif //TRABALHOI_STATICLISTA_H
