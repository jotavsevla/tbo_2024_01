#include <iostream>
#include "Classes/Arquivo.h"
#define FILMESARQ "..\arquivosTexto\filmes.txt"
int main() {
    Arquivo filmes(FILMESARQ);
    filmes.lerArquivo();
    return 0;
}
