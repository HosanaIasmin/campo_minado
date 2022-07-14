#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int posicaoFoiEscolhida; //0 = falso; 1 = verdadeiro
    int temBomba; //0 = falso; 1 = verdadeiro
    int vizinhaca; //número de 0 a 8
}Posicao;

//inicializando o jogo
void inicializaJogo(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            campoMinado[l][c].posicaoFoiEscolhida = 0;
            campoMinado[l][c].temBomba = 0;
            campoMinado[l][c].vizinhaca = 0;
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
revelaPosicaoCampoMinado(int l, int c, int linha, int coluna, Posicao campoMinado[linha][coluna]){
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
revelaTodasAsPosicaoCampoMinado(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int opcao;
    printf("\nDigite 1 para revelar todas as posicoes do campo minado: ");
    scanf("%d", &opcao);

    if(opcao == 1){
        for(int l = 0; l < linhas; l++){
            for(int c = 0; c < colunas; c++){
                campoMinado[l][c].posicaoFoiEscolhida = 1;
            }
        }
        imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
    }
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

//Jogando campo minado (fazendo a leitura das coordenadas do jogo)
void jogoCampoMinado(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int lin = -1; //posições inválidas qualquer
    int col = -1;

    while(vitoria(linhas, colunas, campoMinado) != 0){ //esse laço verifica se houve vitória e se o jogador não abriu uma posição bomba, dessa forma esse laço se repete enquanto o jogador ainda não venceu o jogo
        imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
        while (!validaCordenada(lin, col, linhas, colunas) && vitoria(linhas, colunas, campoMinado) != 0){ //laço para verificar se as coordenadas de um campo são válidas
            printf("\nDigite as coordenadas (linha e coluna) da posicao desejada:\n");
            scanf("%d", &lin);
            scanf("%d", &col);

            if(!validaCordenada(lin, col, linhas, colunas) || campoMinado[lin][col].posicaoFoiEscolhida == 1){
                printf("Posicao invalida ou ja aberta\n");
            }
        }
        revelaPosicaoCampoMinado(lin, col, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
        if(campoMinado[lin][col].temBomba == 1){ //condição de derrota no jogo
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            printf("Voce encontrou uma bomba!\n");
            printf("**GAME***OVER**\n");
            break;
        }
        lin = -1; //posições inválidas qualquer
        col = -1;
    }
    
    if(vitoria(linhas, colunas, campoMinado) == 0){
        printf("--- PARABENS, VOCE VENCEU! ---\n");
        imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
    }

    revelaTodasAsPosicaoCampoMinado(linhas, colunas, campoMinado); //abre todas as posições do campo minado em caso de vitória ou derrota
}

//Modo autônomo
void modoAutonomo(int linhas, int colunas, Posicao campoMinado[linhas][colunas]){
    int lin;
    int col;
    int cond = 1;

    imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado

    while(vitoria(linhas, colunas, campoMinado) != 0){ //esse laço verifica se houve vitória e se o jogador não abriu uma posição bomba, dessa forma esse laço se repete enquanto o jogador ainda não venceu o jogo      
        while(cond){
            srand(time(NULL));
            lin = rand() % linhas; 
            col = rand() % colunas;
            if(campoMinado[lin][col].temBomba == 0){
                cond = 0;
            }
        }
        cond = 1;       
    
        if(campoMinado[lin][col].posicaoFoiEscolhida == 0){
            revelaPosicaoCampoMinado(lin, col, linhas, colunas, campoMinado); //vai abrir as posições do campo minado
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
        } 

        if(campoMinado[lin][col].temBomba == 1){ //condição de derrota no jogo
            imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
            printf("Voce encontrou uma bomba!\n");
            printf("**GAME***OVER**\n");
            break;
        }
    }

    if(vitoria(linhas, colunas, campoMinado) == 0){
        printf("--- PARABENS, VOCE VENCEU! ---\n");
        imprimir(linhas, colunas, campoMinado); //impressão do jogo campo minado
    }           
}



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
