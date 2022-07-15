#ifndef _FUNCOES_CAMPO_MINADO_H
#define _FUNCOES_CAMPO_MINADO_H

typedef struct{
    int posicaoFoiEscolhida; //0 = falso; 1 = verdadeiro
    int temBomba; //0 = falso; 1 = verdadeiro
    int vizinhaca; //número de 0 a 8
}Posicao;

//typedef Posicao Campo [10][20];

//inicializando o jogo

//void inicializaJogo(Campo jogo);
void inicializaJogo(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

//distribuindo as bombas aleatoriamente
void distribuiBombas(int numeroBombas, int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

//validação com base no numéro das linhas e colunas da matriz campo minado
int validaCordenada(int l, int c, int linha, int coluna);

//função que retorna a quantidade de bombas na vizinhanca de [l][c]
int totalBombasVizinhas(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

//informando as bombas na vizinhança
void informaNumeroDeBombas(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

//imprimindo o jogo
void imprimir(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

//Revelando uma posição do campo minado a partir das coordenadas digitadas pelo jogador
void revelaPosicaoCampoMinado(int l, int c, int linha, int coluna, Posicao campoMinado[linha][coluna]);

//Revelando todas as posições do campo minado
void revelaTodasAsPosicaoCampoMinado(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

//Verificando se houve vitória no jogo. ganhou = 0; ainda não ganhou > 0
int vitoria(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

//Jogando campo minado (fazendo a leitura das coordenadas do jogo)
void jogoCampoMinado(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

//Modo autônomo
void modoAutonomo(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

#endif