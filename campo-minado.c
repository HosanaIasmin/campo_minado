#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int posicaoEscolhida; //0 = falso; 1 = verdadeiro
    int temBomba; //0 = falso; 1 = verdadeiro
    int vizinhaca; //número de 0 a 4
}Posicao;

//inicializando o jogo
void inicializaJogo(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            campoMinado[i][j].posicaoEscolhida = 0;
            campoMinado[i][j].temBomba = 0;
            campoMinado[i][j].vizinhaca = 0;
        }
    }
}

//distribuindo as bombas aleatoriamente
void distribuiBombas(int numeroBombas, int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int lin;
    int col;
    int cont = 0;
    srand(time(NULL));
    while(cont < numeroBombas){
        lin = rand() % linhas; //escolha aleatória das linhas e colunas do campo minado para distribuir as bombas
        col = rand() % colunas;  
        if(campoMinado[lin][col].temBomba == 0){ //esse if garante que seja distribuído o total de bombas desejado
            campoMinado[lin][col].temBomba = 1;
            cont++;
        }       
    }
}

int validaCordenada(int l, int c, int linha, int coluna){
    if(l >= 0 && l < linha && c >= 0 && c < coluna){
        return 1;
    }
    else{
        return 0;
    }
}

//função que retorna a quantidade de bombas na vizinhanca de [l][c]
int totalBombasVizinhas(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int quantidadeBombas = 0;
    if(l - 1 >= 0 && l - 1 < linhas && c >= 0 && c < colunas){ //testando se a vizinhança de uma certa posição existe na matriz campoMinado
        if(campoMinado[l - 1][c].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c >= 0 && c < colunas){ //testando se a vizinhança de uma certa posição existe na matriz campoMinado
        if(campoMinado[l + 1][c].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l >= 0 && l < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a vizinhança de uma certa posição existe na matriz campoMinado
        if(campoMinado[l][c + 1].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l >= 0 && l < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a vizinhança de uma certa posição existe na matriz campoMinado
        if(campoMinado[l][c - 1].temBomba == 1){
            quantidadeBombas++;
        }
    }
    return quantidadeBombas;
}

//informando as bombas na vizinhança
void informaNumeroDeBombas(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
           campoMinado[i][j].vizinhaca = totalBombasVizinhas(i, j, linhas, colunas, campoMinado);
        }
    }
}

int main(int argc, char const *argv[]){
    
    Posicao campoMinado[10][20]; 
    int linhas = 10;
    int colunas = 20;

    inicializaJogo(linhas, colunas, campoMinado); //inicializa e zera todos os valores do struct da matriz campoMinado[10][20]
    distribuiBombas(40, linhas, colunas, campoMinado); //distribuição das bombas na matriz campoMinado[][]
    informaNumeroDeBombas(linhas, colunas, campoMinado); //distribui números de 0 a 4 informando o total de bombas na vizinhança
    return 0;
}
