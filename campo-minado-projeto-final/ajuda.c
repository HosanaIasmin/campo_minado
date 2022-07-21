#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ajuda.h"
#include "struct.h"
#include "funcoes.h"
#include "modo-automatico.h"


void indicaBombaVizinhanca(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]){    
    if(l - 1 >= 0 && l - 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de cima da posição considerada tem uma bomba
        if(campoMinado[l - 1][c].posicaoFoiEscolhida == 0){
            printf("Na posicao de linha %d e coluna %d possui 1 bomba\n", l - 1, c);
            return;
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de cima direita da posição considerada tem uma bomba
        if(campoMinado[l - 1][c + 1].posicaoFoiEscolhida == 0){
            printf("Na posicao de linha %d e coluna %d possui 1 bomba\n", l - 1, c + 1);
            return;
        }
    }
    if(l >= 0 && l < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição da direita da posição considerada tem uma bomba
        if(campoMinado[l][c + 1].posicaoFoiEscolhida == 0){
            printf("Na posicao de linha %d e coluna %d possui 1 bomba\n", l, c + 1);
            return;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de baixo direita da posição considerada tem uma bomba
        if(campoMinado[l + 1][c + 1].posicaoFoiEscolhida == 0){
            printf("Na posicao de linha %d e coluna %d possui 1 bomba\n", l + 1, c + 1);
            return;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de baixo da posição considerada tem uma bomba
        if(campoMinado[l + 1][c].posicaoFoiEscolhida == 0){
            printf("Na posicao de linha %d e coluna %d possui 1 bomba\n", l + 1, c);
            return;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de baixo esquerda da posição considerada tem uma bomba
        if(campoMinado[l + 1][c - 1].posicaoFoiEscolhida == 0){
            printf("Na posicao de linha %d e coluna %d possui 1 bomba\n", l + 1, c - 1);
            return;
        }
    }
    if(l >= 0 && l < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição da esquerda da posição considerada tem uma bomba
        if(campoMinado[l][c - 1].posicaoFoiEscolhida == 0){
            printf("Na posicao de linha %d e coluna %d possui 1 bomba\n", l, c - 1);
            return;
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de cima esquerda da posição considerada tem uma bomba
        if(campoMinado[l - 1][c - 1].posicaoFoiEscolhida == 0){
            printf("Na posicao de linha %d e coluna %d possui 1 bomba\n", l - 1, c - 1);
            return;
        }
    }
}

void ajuda(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int proximaDica = 1;
    int ajudou = 0;
    int cont = 0;

    if(proximaDica == 1){
        for(int l = 0; l < linhas && cont == 0; l++){
            for(int c = 0; c < colunas && cont == 0; c++){
                if(campoMinado[l][c].posicaoFoiEscolhida == 1 && campoMinado[l][c].vizinhaca == totalPosicoesFechadasVizinhanca(l, c, linhas, colunas, campoMinado) && campoMinado[l][c].vizinhaca != 0){
                    indicaBombaVizinhanca(l, c, linhas, colunas, campoMinado);  
                    proximaDica = 0;
                    ajudou++;
                    cont++;
                }
            }
        }
    }

    if(proximaDica == 1){
        for(int l = 0; l < linhas; l++){
            for(int c = 0; c < colunas; c++){
                if(campoMinado[l][c].posicaoFoiEscolhida == 1 && campoMinado[l][c].vizinhaca == 1){
                    if(totalPosicoesAbertasVizinhanca(l, c, linhas, colunas, campoMinado) == 0){ 
                        printf("Na vizinhanca da posicao de linha %d e coluna %d possui 1 bomba\n", l, c);  
                        proximaDica = 0;
                        ajudou++;
                    }
                }
            }
        }
    }

    if(proximaDica == 1){
        for(int l = 0; l < linhas; l++){
            for(int c = 0; c < colunas; c++){
                if(campoMinado[l][c].posicaoFoiEscolhida == 1 && campoMinado[l][c].vizinhaca == 1){
                    if(totalPosicoesAbertasVizinhanca(l, c, linhas, colunas, campoMinado) == 1){ 
                        printf("Na vizinhanca da posicao de linha %d e coluna %d possui 1 bomba\n", l, c); 
                        proximaDica = 0; 
                        ajudou++;
                    }
                }
            }
        }
    }

    if(proximaDica == 1){
        for(int l = 0; l < linhas; l++){
            for(int c = 0; c < colunas; c++){
                if(campoMinado[l][c].posicaoFoiEscolhida == 1 && campoMinado[l][c].vizinhaca == 2){
                    if(totalPosicoesAbertasVizinhanca(l, c, linhas, colunas, campoMinado) == 0){ 
                        printf("Na vizinhanca da posicao de linha %d e coluna %d possuem 2 bombas\n", l, c);
                        ajudou++; 
                    }
                }
            }
        }
    }

    if(ajudou == 0){
        printf("Nao localizei nenhuma posicao com baixa chance de ser uma mina\n");
    }
}