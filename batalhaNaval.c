#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // inicializar tabuleiro com 0
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal (linha 2, colunas 4-6)
    int linhaH = 2;
    int colunaH = 4;
    tabuleiro[linhaH][colunaH] = 3;
    tabuleiro[linhaH][colunaH+1] = 3;
    tabuleiro[linhaH][colunaH+2] = 3;

    // Navio vertical (coluna 7, linhas 6-8)
    int linhaV = 6;
    int colunaV = 7;
    tabuleiro[linhaV][colunaV] = 3;
    tabuleiro[linhaV+1][colunaV] = 3;
    tabuleiro[linhaV+2][colunaV] = 3;

    // Navio diagonal principal (começa em [0,0], [1,1], [2,2])
    int linhaD1 = 0;
    int colunaD1 = 0;
    tabuleiro[linhaD1][colunaD1] = 3;
    tabuleiro[linhaD1+1][colunaD1+1] = 3;
    tabuleiro[linhaD1+2][colunaD1+2] = 3;

    // Navio diagonal secundária (começa em [0,9], [1,8], [2,7])
    int linhaD2 = 0;
    int colunaD2 = 9;
    tabuleiro[linhaD2][colunaD2] = 3;
    tabuleiro[linhaD2+1][colunaD2-1] = 3;
    tabuleiro[linhaD2+2][colunaD2-2] = 3;

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