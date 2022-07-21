#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funcoes.h"
#include "modo-automatico.h"
#include "struct.h"

void revelaPosicaoCampoMinadoMA(int l, int c, int linha, int coluna, Posicao campoMinado[linha][coluna]){
    if(validaCordenada(l, c, linha, coluna) == 1 && campoMinado[l][c].posicaoFoiEscolhida == 0 && campoMinado[l][c].temBomba == 1){
        campoMinado[l][c].posicaoFoiEscolhida = 1;
        return;
    }
    if(validaCordenada(l, c, linha, coluna) == 1 && campoMinado[l][c].posicaoFoiEscolhida == 0 && campoMinado[l][c].naoabrirPosicao == 0){
        campoMinado[l][c].posicaoFoiEscolhida = 1;

        if(campoMinado[l][c].vizinhaca == 0){ //entra na condição se nessa posição possui zero bomba na vizinhança
            //Chamada recurssiva para abrir células nas posições vizinhas
            revelaPosicaoCampoMinadoMA(l - 1, c, linha, coluna, campoMinado);
            revelaPosicaoCampoMinadoMA(l - 1, c + 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinadoMA(l, c + 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinadoMA(l + 1, c + 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinadoMA(l + 1, c, linha, coluna, campoMinado);
            revelaPosicaoCampoMinadoMA(l + 1, c - 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinadoMA(l, c - 1, linha, coluna, campoMinado);
            revelaPosicaoCampoMinadoMA(l - 1, c - 1, linha, coluna, campoMinado);
        }
    }
}

int gameOver(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    if(campoMinado[l][c].temBomba == 1){
        return 1;
    }
    return 0;
}

int totalPosicoesFechadasVizinhanca(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]){ //retorna o número de posições que não foram abertas ao redor de uma posição considerada
    int TotalPosicoesFechadas = 0;
    if(l - 1 >= 0 && l - 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de cima da posição considerada tem uma bomba
        if(campoMinado[l - 1][c].posicaoFoiEscolhida == 0){
            TotalPosicoesFechadas++;
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de cima direita da posição considerada tem uma bomba
        if(campoMinado[l - 1][c + 1].posicaoFoiEscolhida == 0){
            TotalPosicoesFechadas++;
        }
    }
    if(l >= 0 && l < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição da direita da posição considerada tem uma bomba
        if(campoMinado[l][c + 1].posicaoFoiEscolhida == 0){
            TotalPosicoesFechadas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de baixo direita da posição considerada tem uma bomba
        if(campoMinado[l + 1][c + 1].posicaoFoiEscolhida == 0){
            TotalPosicoesFechadas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de baixo da posição considerada tem uma bomba
        if(campoMinado[l + 1][c].posicaoFoiEscolhida == 0){
            TotalPosicoesFechadas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de baixo esquerda da posição considerada tem uma bomba
        if(campoMinado[l + 1][c - 1].posicaoFoiEscolhida == 0){
            TotalPosicoesFechadas++;
        }
    }
    if(l >= 0 && l < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição da esquerda da posição considerada tem uma bomba
        if(campoMinado[l][c - 1].posicaoFoiEscolhida == 0){
            TotalPosicoesFechadas++;
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de cima esquerda da posição considerada tem uma bomba
        if(campoMinado[l - 1][c - 1].posicaoFoiEscolhida == 0){
            TotalPosicoesFechadas++;
        }
    }
    return TotalPosicoesFechadas;
}

int totalPosicoesAbertasVizinhanca(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]){ //retorna o número de posições que não foram abertas ao redor de uma posição considerada
    int TotalPosicoesAbertas = 0;
    if(l - 1 >= 0 && l - 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de cima da posição considerada tem uma bomba
        if(campoMinado[l - 1][c].posicaoFoiEscolhida == 1){
            TotalPosicoesAbertas++;
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de cima direita da posição considerada tem uma bomba
        if(campoMinado[l - 1][c + 1].posicaoFoiEscolhida == 1){
            TotalPosicoesAbertas++;
        }
    }
    if(l >= 0 && l < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição da direita da posição considerada tem uma bomba
        if(campoMinado[l][c + 1].posicaoFoiEscolhida == 1){
            TotalPosicoesAbertas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de baixo direita da posição considerada tem uma bomba
        if(campoMinado[l + 1][c + 1].posicaoFoiEscolhida == 1){
            TotalPosicoesAbertas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de baixo da posição considerada tem uma bomba
        if(campoMinado[l + 1][c].posicaoFoiEscolhida == 1){
            TotalPosicoesAbertas++;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de baixo esquerda da posição considerada tem uma bomba
        if(campoMinado[l + 1][c - 1].posicaoFoiEscolhida == 1){
            TotalPosicoesAbertas++;
        }
    }
    if(l >= 0 && l < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição da esquerda da posição considerada tem uma bomba
        if(campoMinado[l][c - 1].posicaoFoiEscolhida == 1){
            TotalPosicoesAbertas++;
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de cima esquerda da posição considerada tem uma bomba
        if(campoMinado[l - 1][c - 1].posicaoFoiEscolhida == 1){
            TotalPosicoesAbertas++;
        }
    }
    return TotalPosicoesAbertas;
}

void marcaBombaVizinhanca(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]){    
    if(l - 1 >= 0 && l - 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de cima da posição considerada tem uma bomba
        if(campoMinado[l - 1][c].posicaoFoiEscolhida == 0){
            campoMinado[l - 1][c].naoabrirPosicao = 1; //naoabrirPosicao = 1 significa que o modo autônomo não pode abrir essa posição
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de cima direita da posição considerada tem uma bomba
        if(campoMinado[l - 1][c + 1].posicaoFoiEscolhida == 0){
            campoMinado[l - 1][c + 1].naoabrirPosicao = 1;
        }
    }
    if(l >= 0 && l < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição da direita da posição considerada tem uma bomba
        if(campoMinado[l][c + 1].posicaoFoiEscolhida == 0){
            campoMinado[l][c + 1].naoabrirPosicao = 1;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de baixo direita da posição considerada tem uma bomba
        if(campoMinado[l + 1][c + 1].posicaoFoiEscolhida == 0){
            campoMinado[l + 1][c + 1].naoabrirPosicao = 1;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de baixo da posição considerada tem uma bomba
        if(campoMinado[l + 1][c].posicaoFoiEscolhida == 0){
            campoMinado[l + 1][c].naoabrirPosicao = 1;
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de baixo esquerda da posição considerada tem uma bomba
        if(campoMinado[l + 1][c - 1].posicaoFoiEscolhida == 0){
            campoMinado[l + 1][c - 1].naoabrirPosicao = 1;
        }
    }
    if(l >= 0 && l < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição da esquerda da posição considerada tem uma bomba
        if(campoMinado[l][c - 1].posicaoFoiEscolhida == 0){
            campoMinado[l][c - 1].naoabrirPosicao = 1;
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de cima esquerda da posição considerada tem uma bomba
        if(campoMinado[l - 1][c - 1].posicaoFoiEscolhida == 0){
            campoMinado[l - 1][c - 1].naoabrirPosicao = 1;
        }
    }
}

void detectaBombaVizinhanca(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            if(campoMinado[l][c].posicaoFoiEscolhida == 1){
                if(campoMinado[l][c].vizinhaca == totalPosicoesFechadasVizinhanca(l, c, linhas, colunas, campoMinado)){
                    marcaBombaVizinhanca(l, c, linhas, colunas, campoMinado);
                }
            }
        }
    }
}

int abreUmaPosicao(int l, int c, int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    if(l - 1 >= 0 && l - 1 < linhas && c >= 0 && c < colunas){ //posição de cima da posição considerada
        if(campoMinado[l - 1][c].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c].naoabrirPosicao == 0){
            revelaPosicaoCampoMinadoMA(l - 1, c, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            detectaBombaVizinhanca(linhas, colunas, campoMinado);
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            return gameOver(l - 1, c, linhas, colunas, campoMinado);
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //posição diagonal de cima direita da posição considerada
        if(campoMinado[l - 1][c + 1].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c].naoabrirPosicao == 0){
            revelaPosicaoCampoMinadoMA(l - 1, c + 1, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            detectaBombaVizinhanca(linhas, colunas, campoMinado);
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            return gameOver(l - 1, c + 1, linhas, colunas, campoMinado); 
        }
    }
    if(l >= 0 && l < linhas && c + 1 >= 0 && c + 1 < colunas){ //posição da direita da posição considerada
        if(campoMinado[l][c + 1].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c].naoabrirPosicao == 0){
            revelaPosicaoCampoMinadoMA(l, c + 1, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            detectaBombaVizinhanca(linhas, colunas, campoMinado);
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            return gameOver(l, c + 1, linhas, colunas, campoMinado);
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //posição diagonal de baixo direita da posição considerada
        if(campoMinado[l + 1][c + 1].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c].naoabrirPosicao == 0){
            revelaPosicaoCampoMinadoMA(l + 1, c + 1, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            detectaBombaVizinhanca(linhas, colunas, campoMinado);
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            return gameOver(l + 1, c + 1, linhas, colunas, campoMinado); 
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c >= 0 && c < colunas){ //posição de baixo da posição considerada
        if(campoMinado[l + 1][c].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c].naoabrirPosicao == 0){
            revelaPosicaoCampoMinadoMA(l + 1, c, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            detectaBombaVizinhanca(linhas, colunas, campoMinado);
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            return gameOver(l + 1, c, linhas, colunas, campoMinado);
        }
    }
    if(l + 1 >= 0 && l + 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //posição diagonal de baixo esquerda da posição considerada
        if(campoMinado[l + 1][c - 1].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c].naoabrirPosicao == 0){
            revelaPosicaoCampoMinadoMA(l + 1, c - 1, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            detectaBombaVizinhanca(linhas, colunas, campoMinado);
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            return gameOver(l + 1, c - 1, linhas, colunas, campoMinado);  
        }
    }
    if(l >= 0 && l < linhas && c - 1 >= 0 && c - 1 < colunas){ //posição da esquerda da posição considerada
        if(campoMinado[l][c - 1].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c].naoabrirPosicao == 0){
            revelaPosicaoCampoMinadoMA(l, c - 1, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            detectaBombaVizinhanca(linhas, colunas, campoMinado);
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            return gameOver(l, c - 1, linhas, colunas, campoMinado);
        }
    }
    if(l - 1 >= 0 && l - 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //posição diagonal de cima esquerda da posição considerada
        if(campoMinado[l - 1][c - 1].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c].naoabrirPosicao == 0){
            revelaPosicaoCampoMinadoMA(l - 1, c - 1, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            detectaBombaVizinhanca(linhas, colunas, campoMinado);
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            return gameOver(l - 1, c - 1, linhas, colunas, campoMinado);  
        }
    }
}

int abrindoPosicaoMaisSegura(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int derrota = 0;
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            if(campoMinado[l][c].posicaoFoiEscolhida == 1 && campoMinado[l][c].vizinhaca == 1){
                if(totalPosicoesAbertasVizinhanca(l, c, linhas, colunas, campoMinado) == 0){ 
                    derrota = abreUmaPosicao(l, c, linhas, colunas, campoMinado);
                    if(derrota){
                        return derrota;
                    }  
                }
            }
            if(campoMinado[l][c].posicaoFoiEscolhida == 1 && campoMinado[l][c].vizinhaca == 1){
                if(totalPosicoesAbertasVizinhanca(l, c, linhas, colunas, campoMinado) == 1){
                    derrota = abreUmaPosicao(l, c, linhas, colunas, campoMinado);
                    if(derrota){
                        return derrota;
                    }
                }
            }
        }
    }
    return derrota;
}

int AbrindoPosicaoDeNumero2(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            if(campoMinado[l][c].posicaoFoiEscolhida == 1 && campoMinado[l][c].vizinhaca == 2 && l != 0 && l != linhas -1 && c != 0 && c != colunas - 1){
                if(totalPosicoesAbertasVizinhanca(l, c, linhas, colunas, campoMinado) == 0){
                    return abreUmaPosicao(l, c, linhas, colunas, campoMinado);   
                }
            }
        }
    }
}


int abrindoPosicoesRestantes(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int cont = 0;
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            if(l - 1 >= 0 && l - 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de cima da posição considerada tem uma bomba
                if(campoMinado[l - 1][c].naoabrirPosicao == 1){
                   cont++; 
                }
            }
            if(l - 1 >= 0 && l - 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de cima direita da posição considerada tem uma bomba
                if(campoMinado[l - 1][c + 1].naoabrirPosicao == 1){
                   cont++; 
                }
            }
            if(l >= 0 && l < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição da direita da posição considerada tem uma bomba
                if(campoMinado[l][c + 1].naoabrirPosicao == 1){
                   cont++; 
                }
            }
            if(l + 1 >= 0 && l + 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de baixo direita da posição considerada tem uma bomba
                if(campoMinado[l + 1][c + 1].naoabrirPosicao == 1){
                   cont++; 
                }
            }
            if(l + 1 >= 0 && l + 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de baixo da posição considerada tem uma bomba
                if(campoMinado[l + 1][c].naoabrirPosicao == 1){
                   cont++; 
                }
            }
            if(l + 1 >= 0 && l + 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de baixo esquerda da posição considerada tem uma bomba
                if(campoMinado[l + 1][c - 1].naoabrirPosicao == 1){
                   cont++; 
                }
            }
            if(l >= 0 && l < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição da esquerda da posição considerada tem uma bomba
                if(campoMinado[l][c - 1].naoabrirPosicao == 1){
                   cont++; 
                }
            }
            if(l - 1 >= 0 && l - 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de cima esquerda da posição considerada tem uma bomba
                if(campoMinado[l - 1][c - 1].naoabrirPosicao == 1){
                   cont++; 
                }
            }

            if(campoMinado[l][c].vizinhaca == cont){
                if(l - 1 >= 0 && l - 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de cima da posição considerada tem uma bomba
                    if(campoMinado[l - 1][c].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c].naoabrirPosicao == 0){
                        revelaPosicaoCampoMinadoMA(l - 1, c, linhas, colunas, campoMinado);
                        detectaBombaVizinhanca(linhas, colunas, campoMinado);
                        imprimir(linhas, colunas, campoMinado);
                        if(campoMinado[l - 1][c].temBomba){
                            return 1;
                        }
                    }
                }
                if(l - 1 >= 0 && l - 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de cima direita da posição considerada tem uma bomba
                    if(campoMinado[l - 1][c + 1].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c + 1].naoabrirPosicao == 0){
                        revelaPosicaoCampoMinadoMA(l - 1, c + 1, linhas, colunas, campoMinado);
                        detectaBombaVizinhanca(linhas, colunas, campoMinado);
                        imprimir(linhas, colunas, campoMinado);
                        if(campoMinado[l - 1][c + 1].temBomba){
                            return 1;
                        }
                    }
                }
                if(l >= 0 && l < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição da direita da posição considerada tem uma bomba
                    if(campoMinado[l][c + 1].posicaoFoiEscolhida == 0 && campoMinado[l][c + 1].naoabrirPosicao == 0){
                        revelaPosicaoCampoMinadoMA(l, c + 1, linhas, colunas, campoMinado);
                        detectaBombaVizinhanca(linhas, colunas, campoMinado);
                        imprimir(linhas, colunas, campoMinado);
                        if(campoMinado[l][c + 1].temBomba){
                            return 1;
                        }
                    }
                }
                if(l + 1 >= 0 && l + 1 < linhas && c + 1 >= 0 && c + 1 < colunas){ //testando se a posição diagonal de baixo direita da posição considerada tem uma bomba
                    if(campoMinado[l + 1][c + 1].posicaoFoiEscolhida == 0 && campoMinado[l + 1][c + 1].naoabrirPosicao == 0){
                        revelaPosicaoCampoMinadoMA(l + 1, c + 1, linhas, colunas, campoMinado);
                        detectaBombaVizinhanca(linhas, colunas, campoMinado);
                        imprimir(linhas, colunas, campoMinado);
                        if(campoMinado[l + 1][c + 1].temBomba){
                            return 1;
                        }
                    }
                }
                if(l + 1 >= 0 && l + 1 < linhas && c >= 0 && c < colunas){ //testando se a posição de baixo da posição considerada tem uma bomba
                    if(campoMinado[l + 1][c].posicaoFoiEscolhida == 0 && campoMinado[l + 1][c].naoabrirPosicao == 0){
                        revelaPosicaoCampoMinadoMA(l + 1, c, linhas, colunas, campoMinado);
                        detectaBombaVizinhanca(linhas, colunas, campoMinado);
                        imprimir(linhas, colunas, campoMinado);
                        if(campoMinado[l + 1][c].temBomba){
                            return 1;
                        }
                    }
                }
                if(l + 1 >= 0 && l + 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de baixo esquerda da posição considerada tem uma bomba
                    if(campoMinado[l + 1][c - 1].posicaoFoiEscolhida == 0 && campoMinado[l + 1][c - 1].naoabrirPosicao == 0){
                        revelaPosicaoCampoMinadoMA(l + 1, c - 1, linhas, colunas, campoMinado);
                        detectaBombaVizinhanca(linhas, colunas, campoMinado);
                        imprimir(linhas, colunas, campoMinado);
                        if(campoMinado[l + 1][c - 1].temBomba){
                            return 1;
                        }
                    }
                }
                if(l >= 0 && l < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição da esquerda da posição considerada tem uma bomba
                    if(campoMinado[l][c - 1].posicaoFoiEscolhida == 0 && campoMinado[l][c - 1].naoabrirPosicao == 0){
                        revelaPosicaoCampoMinadoMA(l, c - 1, linhas, colunas, campoMinado);
                        detectaBombaVizinhanca(linhas, colunas, campoMinado);
                        imprimir(linhas, colunas, campoMinado);
                        if(campoMinado[l][c - 1].temBomba){
                            return 1;
                        }
                    }
                }
                if(l - 1 >= 0 && l - 1 < linhas && c - 1 >= 0 && c - 1 < colunas){ //testando se a posição diagonal de cima esquerda da posição considerada tem uma bomba
                    if(campoMinado[l - 1][c - 1].posicaoFoiEscolhida == 0 && campoMinado[l - 1][c - 1].naoabrirPosicao == 0){
                        revelaPosicaoCampoMinadoMA(l - 1, c - 1, linhas, colunas, campoMinado);
                        detectaBombaVizinhanca(linhas, colunas, campoMinado);
                        imprimir(linhas, colunas, campoMinado);
                        if(campoMinado[l - 1][c - 1].temBomba){
                            return 1;
                        }
                    }
                }                
            }            
        }
    }
    return 0;
}


//Modo autônomo
void modoAutonomo(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int lin;
    int col;
    int cond = 1;
    int gameOver = 0;

    imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado

    srand(time(NULL)); //deixar fora
    while(vitoria(linhas, colunas, campoMinado) != 0){ //esse laço verifica se houve vitória e se o jogador não abriu uma posição bomba, dessa forma esse laço se repete enquanto o jogador ainda não venceu o jogo      
        while(cond){           
            lin = rand() % linhas; 
            col = rand() % colunas;
            if(campoMinado[lin][col].posicaoFoiEscolhida == 0 && campoMinado[lin][col].naoabrirPosicao == 0){ 
                cond = 0;
            } 
            if(campoMinado[lin][col].temBomba == 1 && campoMinado[lin][col].naoabrirPosicao == 0){ //condição de derrota no jogo
                revelaPosicaoCampoMinadoMA(lin, col, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
                imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
                printf("Voce encontrou uma bomba!\n**GAME***OVER**\n");
                return;
            }  
        }
        cond = 1;  

        if(campoMinado[lin][col].posicaoFoiEscolhida == 0 && campoMinado[lin][col].naoabrirPosicao == 0){
            revelaPosicaoCampoMinadoMA(lin, col, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            detectaBombaVizinhanca(linhas, colunas, campoMinado);
        }    
        
        gameOver = abrindoPosicaoMaisSegura(linhas, colunas, campoMinado); //Se gameOver for 1 o jogo se encerra
        detectaBombaVizinhanca(linhas, colunas, campoMinado);
        if(gameOver == 1){
            printf("Voce encontrou uma bomba!\n**GAME***OVER**\n");
            return;
        }
        
        gameOver = AbrindoPosicaoDeNumero2(linhas, colunas, campoMinado);
        detectaBombaVizinhanca(linhas, colunas, campoMinado);
        if(gameOver == 1){
            printf("Voce encontrou uma bomba!\n**GAME***OVER**\n");
            return;
        }
        
        gameOver = abrindoPosicoesRestantes(linhas, colunas, campoMinado);
        detectaBombaVizinhanca(linhas, colunas, campoMinado);
        if(gameOver == 1){
            printf("Voce encontrou uma bomba!\n**GAME***OVER**\n");
            return;
        }
    }

    
    if(vitoria(linhas, colunas, campoMinado) == 0){
        printf("--- PARABENS, VOCE VENCEU! ---\n");
        imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
    }           
}