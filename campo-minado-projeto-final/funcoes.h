#ifndef _FUNCOES_H
#define _FUNCOES_H
#include <time.h>
void tempoDeJogo(clock_t tempoInicial, clock_t tempoFinal);

void inicializaJogo(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

void distribuiBombas(int numeroBombas, int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

int validaCordenada(int l, int c, int linha, int coluna);

int totalBombasVizinhas(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

void informaNumeroDeBombas(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

void imprimir(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

void revelaPosicaoCampoMinado(int l, int c, int linha, int coluna, Posicao campoMinado[linha][coluna]);

void abreCampoMinado(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

int vitoria(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

void jogoCampoMinado(int linhas, int colunas, Posicao campoMinado[linhas][colunas], clock_t *ptempoInicial, clock_t *ptempoFinal);

void reiniciar(int *pEscolha);

#endif