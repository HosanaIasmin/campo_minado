#ifndef _STRUCT_H
#define _STRUCT_H

typedef struct{
    int posicaoFoiEscolhida; //0 = falso; 1 = verdadeiro
    int temBomba; //0 = falso; 1 = verdadeiro
    int vizinhaca; //número de 0 a 8
    int naoabrirPosicao; //essa variável é dedicada apenas ao modo autônomo. 0 = falso; 1 = verdadeiro
}Posicao;

#endif