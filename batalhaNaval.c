#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializar tabuleiro com água (0)
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;

    // ----------------------
    // Posicionar navios (3)
    // ----------------------
    tabuleiro[2][4] = 3; tabuleiro[2][5] = 3; tabuleiro[2][6] = 3; // horizontal
    tabuleiro[6][7] = 3; tabuleiro[7][7] = 3; tabuleiro[8][7] = 3; // vertical
    tabuleiro[0][0] = 3; tabuleiro[1][1] = 3; tabuleiro[2][2] = 3; // diagonal principal
    tabuleiro[0][9] = 3; tabuleiro[1][8] = 3; tabuleiro[2][7] = 3; // diagonal secundária

    // ----------------------
    // Habilidades especiais
    // ----------------------
    int tamanho = 5; // tamanho das matrizes de habilidade

    // Função para aplicar área de habilidade (5) sem sobrescrever navios
    void aplicarHabilidade(int origemLinha, int origemColuna, int habilidade[5][5]) {
        for (i = 0; i < tamanho; i++) {
            for (j = 0; j < tamanho; j++) {
                int linhaTab = origemLinha - 2 + i;
                int colTab = origemColuna - 2 + j;
                if (linhaTab >= 0 && linhaTab < 10 && colTab >= 0 && colTab < 10 && habilidade[i][j] == 1) {
                    if (tabuleiro[linhaTab][colTab] != 3) // não sobrescrever navios
                        tabuleiro[linhaTab][colTab] = 5;
                }
            }
        }
    }

    // Cone
    int cone[5][5] = {0};
    for (i = 0; i < tamanho; i++)
        for (j = 0; j < tamanho; j++)
            if (j >= 2 - i && j <= 2 + i) cone[i][j] = 1;
    aplicarHabilidade(2, 5, cone);

    // Cruz
    int cruz[5][5] = {0};
    for (i = 0; i < tamanho; i++) { cruz[2][i] = 1; cruz[i][2] = 1; }
    aplicarHabilidade(5, 2, cruz);

    // Octaedro (losango)
    int octaedro[5][5] = {0};
    for (i = 0; i < tamanho; i++)
        for (j = 0; j < tamanho; j++)
            if (i + j >= 2 && i + j <= 6 && j - i <= 2 && i - j <= 2)
                octaedro[i][j] = 1;
    aplicarHabilidade(7, 7, octaedro);

    // ----------------------
    // Imprimir tabuleiro
    // ----------------------
    printf("***Jogo Batalha Naval - Nível Mestre***\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
