#include <iostream>
#include "vector"
#include "random"
#include "fstream"
#include "cstdlib"

using namespace std;

class Lista{
public:
    Lista(){

        cout<< "### INSERTION SORT ###" << endl << endl;
        for(int i = 1; i <= 100; i++){
            acessos = 0;
            criar_lista(i);
            imprime_lista();
            insertion_sort();
            acessos_insertion.push_back(acessos);
            cout << endl << "-------------------" << endl;
            lista.clear();
        }

        cout << endl << endl << "### SELECTION SORT ###" << endl << endl;
        for(int i = 1; i <= 100; i++) {
            acessos = 0;
            criar_lista(i);
            imprime_lista();
            selection_sort();
            cout << endl << "-------------------" << endl;
            acessos_selection.push_back(acessos);
            lista.clear();
        }
        insere_arquivo();
        system("python3 main.py");
    }


    void criar_lista(int size) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000);

        for (int i = 0; i < size; i++) {
            lista.push_back(dis(gen));
        }
    }

    void insertion_sort(){
        int cursor;
        for(int i = 1; i < lista.size(); i++){
            cursor = i;
            for(int j = i - 1; j >= 0; j--){
                ++acessos;
                if(lista[i] < lista[j]) swap(i, j);
                else break;
                --i;
            }
            imprime_lista();
            i = cursor;
        }
        cout << "Acessos: " << acessos;
    }

    void selection_sort() {
        for(int i = 0; i < lista.size() - 1; i++){
            for(int j = i + 1; j < lista.size(); j++){
                ++acessos;
                if(lista[j] < lista[i]) swap(j, i);
            }
            imprime_lista();
        }
        cout << "Acessos: " << acessos;
    }

    void swap(int pos1, int pos2){
        acessos += 3;
        int aux = lista[pos1];
        lista[pos1] = lista[pos2];
        lista[pos2] = aux;
    }

    void imprime_lista(){
        for(int i = 0; i < lista.size(); i++){
            cout << lista[i] << " ";
        }
        cout << endl;
    }

    void insere_arquivo(){
        ofstream arquivo("data_of_chart.txt");

        if(!arquivo.is_open()){
            cout << "Nao foi possivel abrir o arquivo!" << endl;
            return;
        }

        for (const auto& elemento : acessos_insertion) {
            arquivo << elemento << " ";
        }
        arquivo << endl;

        for (const auto& elemento : acessos_selection) {
            arquivo << elemento << " ";
        }
        arquivo << endl;

        acessos_insertion.clear();
        acessos_selection.clear();
        arquivo.close();

    }

private:
    vector <int> lista;
    vector <int> acessos_insertion;
    vector <int> acessos_selection;
    int acessos;

};

int main() {

    Lista lista;

}
