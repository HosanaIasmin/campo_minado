#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes-campo-minado.h"


int main(int argc, char const *argv[]){
    
    Posicao campoMinado[10][20]; 
    int linhas = 10;
    int colunas = 20;
    int escolha = 0;

    inicializaJogo(linhas, colunas, campoMinado); //inicializa e zera todos os valores do struct da matriz campoMinado[10][20]
    distribuiBombas(40, linhas, colunas, campoMinado); //distribuição das bombas na matriz campoMinado[][]
    informaNumeroDeBombas(linhas, colunas, campoMinado); //distribui números de 0 a 4 informando o total de bombas na vizinhança

    while(escolha < 1 || escolha > 3){
        printf("Escolha uma opcao abaixo:\n");
        printf("1 - Jogar\n");
        printf("2 - Modo automatico\n");
        printf("3 - Sair\n");
        scanf("%d", &escolha);

        if(escolha == 1){
            printf("\n\t\t\t   ** C * A * M * P * O *** M * I * N * A * D * O **");
            jogoCampoMinado(linhas, colunas, campoMinado);
        }
        else if(escolha == 2){
            modoAutonomo(linhas, colunas, campoMinado);
        }
        else if(escolha == 3){
            return 0;
        }
        else{
            printf("Opcao invalida\n");
        }
    }
    return 0;
}
