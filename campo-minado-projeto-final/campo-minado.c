#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "funcoes.h"
#include "modo-automatico.h"
#include "ajuda.h"
#include "struct.h"

int main(int argc, char const *argv[]){
    
    Posicao campoMinado[10][20]; 
    int linhas = 10;
    int colunas = 20;
    
    int escolha = 0;
    int *pEscolha = &escolha;

    double tempoTotal = 0.0;
    clock_t tempoInicial;
    clock_t tempoFinal;
    clock_t *ptempoInicial = &tempoInicial;
    clock_t *ptempoFinal = &tempoFinal;

    while(escolha < 1 || escolha > 3){
        inicializaJogo(linhas, colunas, campoMinado); //inicializa e zera todos os valores do struct da matriz campoMinado[10][20]
        distribuiBombas(40, linhas, colunas, campoMinado); //distribuição das bombas na matriz campoMinado[][]
        informaNumeroDeBombas(linhas, colunas, campoMinado); //distribui números de 0 a 4 informando o total de bombas na vizinhança

        printf("\nEscolha uma opcao abaixo:\n");
        printf("1 - Jogar\n");
        printf("2 - Modo automatico\n");
        printf("3 - Sair\n");
        scanf("%d", &escolha);

        if(escolha == 1){
            tempoInicial = clock();
            printf("\n\t\t\t   ** C * A * M * P * O *** M * I * N * A * D * O **");
            jogoCampoMinado(linhas, colunas, campoMinado, &tempoInicial, &tempoFinal);
            reiniciar(&escolha);
        }
        else if(escolha == 2){
            modoAutonomo(linhas, colunas, campoMinado);
            reiniciar(&escolha);
        }
        else if(escolha == 3){
            return 0;
        }
    }
    return 0;
}
