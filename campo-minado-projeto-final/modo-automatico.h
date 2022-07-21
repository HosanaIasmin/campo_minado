#ifndef _MODO_AUTOMATICO_H
#define _MODO_AUTOMATICO_H

void revelaPosicaoCampoMinadoMA(int l, int c, int linha, int coluna, Posicao campoMinado[linha][coluna]);

int gameOver(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

int totalPosicoesFechadasVizinhanca(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

int totalPosicoesAbertasVizinhanca(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

void marcaBombaVizinhanca(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

void detectaBombaVizinhanca(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

int abreUmaPosicao(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

int abrindoPosicaoMaisSegura(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

int AbrindoPosicaoDeNumero2(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

int abrindoPosicoesRestantes(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

void modoAutonomo(int linhas, int colunas, Posicao campoMinado[linhas][colunas]);

#endif