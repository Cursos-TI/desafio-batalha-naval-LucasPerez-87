#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // preencher tudo com 0
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // navio horizontal de tamanho 3
    int linhaH = 2; 
    int colunaH = 4;
    tabuleiro[linhaH][colunaH] = 3;
    tabuleiro[linhaH][colunaH+1] = 3;
    tabuleiro[linhaH][colunaH+2] = 3;

    // navio vertical de tamanho 3
    int linhaV = 6;
    int colunaV = 7;
    tabuleiro[linhaV][colunaV] = 3;
    tabuleiro[linhaV+1][colunaV] = 3;
    tabuleiro[linhaV+2][colunaV] = 3;

    // imprimir tabuleiro
    printf("***Jogo Batalha Naval***\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
