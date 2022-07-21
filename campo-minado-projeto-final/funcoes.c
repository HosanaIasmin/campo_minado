#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "funcoes.h"
#include "struct.h"

//calcula tempo de jogo
void tempoDeJogo(clock_t tempoInicial, clock_t tempoFinal){
    int tempoSegundos = (int)(tempoFinal - tempoInicial) / CLOCKS_PER_SEC;
    int tempoMinutos = 0;
    if(tempoSegundos > 60){
        tempoMinutos = tempoSegundos / 60;
        tempoSegundos = tempoSegundos / 60;
    }
    printf("Tempo de jogo: %d min %d seg\n", tempoMinutos, tempoSegundos);
}

//inicializando o jogo
void inicializaJogo(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            campoMinado[l][c].posicaoFoiEscolhida = 0;
            campoMinado[l][c].temBomba = 0;
            campoMinado[l][c].vizinhaca = 0;
            campoMinado[l][c].naoabrirPosicao = 0;
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
        lin = rand() % linhas; //escolha de um número aleatório para as linhas entre 0 e int linhas para distribuir as bombas
        col = rand() % colunas; //escolha de um número aleatório para as colunas entre 0 e int colunas para distribuir as bombas 
        if(campoMinado[lin][col].temBomba == 0){ //esse if garante que seja distribuído o total de bombas desejado
            campoMinado[lin][col].temBomba = 1;
            cont++;
        }       
    }
}

int validaCordenada(int l, int c, int linha, int coluna){
    if(l >= 0 && l < linha && c >= 0 && c < coluna){ //validação com base no numéro das linhas e colunas da matriz campo minado
        return 1;
    }
    else{
        return 0;
    }
}

//função que retorna a quantidade de bombas na vizinhanca de [l][c]
int totalBombasVizinhas(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int quantidadeBombas = 0;
    if(l - 1 >= 0 && l - 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de cima da posição considerada tem uma bomba
        if(campoMinado[l - 1][c].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de cima direita da posição considerada tem uma bomba
        if(campoMinado[l - 1][c + 1].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l >= 0 && l < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição da direita da posição considerada tem uma bomba
        if(campoMinado[l][c + 1].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de baixo direita da posição considerada tem uma bomba
        if(campoMinado[l + 1][c + 1].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de baixo da posição considerada tem uma bomba
        if(campoMinado[l + 1][c].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de baixo esquerda da posição considerada tem uma bomba
        if(campoMinado[l + 1][c - 1].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l >= 0 && l < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição da esquerda da posição considerada tem uma bomba
        if(campoMinado[l][c - 1].temBomba == 1){
            quantidadeBombas++;
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de cima esquerda da posição considerada tem uma bomba
        if(campoMinado[l - 1][c - 1].temBomba == 1){
            quantidadeBombas++;
        }
    }
    return quantidadeBombas;
}

//informando as bombas na vizinhança
void informaNumeroDeBombas(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
           campoMinado[l][c].vizinhaca = totalBombasVizinhas(l, c, linhas, colunas, campoMinado);
        }
    }
}

//imprimindo o jogo
void imprimir(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    printf("\n\n\t   "); //\t significa tabulação
    for(int c = 0; c < colunas; c++){ //imprimindo o número de colunas do jogo
        (c < 10)? printf("  %d ", c) : printf(" %d ", c);
    }
    printf("\n\t   ---------------------------------------------------------------------------------\n");
    for(int l = 0; l < linhas; l++){
        printf("\t%d  |", l); 
        for(int c = 0; c < colunas; c++){
            if(campoMinado[l][c].posicaoFoiEscolhida){
                 if(campoMinado[l][c].temBomba){
                     printf(" *");
                 }
                 else{
                     printf(" %d", campoMinado[l][c].vizinhaca);
                 }
            }
            else{
                 printf("  ");
            }
            printf(" |");          
        }
        printf("\n\t   ---------------------------------------------------------------------------------\n");
    }
}

//Revelando uma posição do campo minado a partir das coordenadas digitadas pelo jogador
void revelaPosicaoCampoMinado(int l, int c, int linha, int coluna, Posicao campoMinado[linha][coluna]){
    if(validaCordenada(l, c, linha, coluna) == 1 && campoMinado[l][c].posicaoFoiEscolhida == 0 && campoMinado[l][c].temBomba == 1){
        campoMinado[l][c].posicaoFoiEscolhida = 1;
        return;
    }
    if(validaCordenada(l, c, linha, coluna) == 1 && campoMinado[l][c].posicaoFoiEscolhida == 0){
        campoMinado[l][c].posicaoFoiEscolhida = 1;

        if(campoMinado[l][c].vizinhaca == 0){ //entra na condição se nessa posição possui zero bomba na vizinhança
            //Chamada recurssiva para abrir células nas posições vizinhas
            revelaPosicaoCampoMinado(l - 1, c, linha, coluna, campoMinado);
            revelaPosicaoCampoMinado(l - 1, c + 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinado(l, c + 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinado(l + 1, c + 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinado(l + 1, c, linha, coluna, campoMinado);
            revelaPosicaoCampoMinado(l + 1, c - 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinado(l, c - 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinado(l - 1, c - 1, linha, coluna, campoMinado);
        }
    }
}

//Revelando todas as posições do campo minado
void abreCampoMinado(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            campoMinado[l][c].posicaoFoiEscolhida = 1;
        }
    }
    imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
}

//Verificando se houve vitória no jogo. ganhou = 0; ainda não ganhou > 0
int vitoria(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int posicoesRestantes = 0;
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            if(campoMinado[l][c].posicaoFoiEscolhida == 0 && campoMinado[l][c].temBomba == 0){
                posicoesRestantes++;
            }
        }
    }
    return posicoesRestantes; //informa o numero de campos que não possuem bombas e ainda não foram abertos
}

//Solicitando ajuda ----------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------

//Jogando campo minado (fazendo a leitura das coordenadas do jogo)
void jogoCampoMinado(int linhas, int colunas, Posicao campoMinado[linhas][colunas], clock_t *ptempoInicial, clock_t *ptempoFinal){
    int lin = -1; //posições inválidas qualquer
    int col = -1; 

    imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado

    while(vitoria(linhas, colunas, campoMinado) != 0){ //esse laço verifica se houve vitória e se o jogador não abriu uma posição bomba, dessa forma esse laço se repete enquanto o jogador ainda não venceu o jogo
        while (!validaCordenada(lin, col, linhas, colunas) && vitoria(linhas, colunas, campoMinado) != 0){ //laço para verificar se as coordenadas de um campo são válidas
            printf("\nDigite as coordenadas (linha e coluna) da posicao desejada:\n");
            scanf("%d", &lin);
            scanf("%d", &col);

            if(!validaCordenada(lin, col, linhas, colunas) || campoMinado[lin][col].posicaoFoiEscolhida == 1){
                printf("Posicao invalida ou ja aberta\n");
            }
        }

        revelaPosicaoCampoMinado(lin, col, linhas, colunas, campoMinado); //vai abrir as posições do campo minado

        if(campoMinado[lin][col].temBomba == 0){
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
        }

        if(campoMinado[lin][col].temBomba == 1){ //condição de derrota no jogo
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            printf("\nVoce encontrou uma bomba!\n\n**GAME***OVER**\n");
            *ptempoFinal = clock(); 
            tempoDeJogo(*ptempoInicial, *ptempoFinal);
            break;
        }

        if(vitoria(linhas, colunas, campoMinado) == 0){
            printf("\n--- PARABENS, VOCE VENCEU! ---\n");
            *ptempoFinal = clock(); 
            tempoDeJogo(*ptempoInicial, *ptempoFinal);
            break;
        }

        printf("\nDigite 1 para ver o tempo da partida, 2 para solicitar ajuda na proxima jogada ou digite qualquer tecla para continuar: ");
        char opcao = '0';
        fflush(stdin); //limpa o buffer
        scanf("%c ", &opcao);
        if(opcao == '1'){
            *ptempoFinal = clock(); 
            tempoDeJogo(*ptempoInicial, *ptempoFinal);
            fflush(stdin);
        }
        if(opcao == '2'){
            ajuda(linhas, colunas, campoMinado);
        }
        fflush(stdin); 
        lin = -1; //posições inválidas qualquer
        col = -1;
    }   
}

// INÍCIO DO MODO AUTÔNOMO -----------------------------------------------------------------------------------------------------------------------------



//FIM DO MODO AUTÔNOMO ---------------------------------------------------------------------------------------------------------------------

void reiniciar(int *pEscolha){
    int reiniciar;
    printf("\nDigite 1 para acessar o menu: ");
    scanf("%d", &reiniciar);
    if(reiniciar == 1){
        *pEscolha = -1;
    }
    else{
        *pEscolha = 3;
    }
}