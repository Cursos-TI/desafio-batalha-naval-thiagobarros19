#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void printTabuleiro(int tabuleiro[10][10]) {
    char line[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int i, j;
    int tamanhoTabuleiro = 10;

    printf("-------------------\n");
    for (i = 0; i < tamanhoTabuleiro; i++) {
        if (i == 0) {
            printf("  ");
        }
        printf(" %c", line[i]);
    }
    printf("\n");

    for (i = 0; i < tamanhoTabuleiro; i++){
        printf(i < 9 ? " %d" : "%d", i + 1);
        for (j = 0; j < tamanhoTabuleiro; j++){
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int checkHasShipOnCoordinate(int tabuleiro[10][10], int coordinateX, int coordinateY) {
    return tabuleiro[coordinateX][coordinateY] == 3;
}

int checkShipOverPassLimits(int boardSize, int coordinateX, int coordinateY, int shipSize, int shipVector) {
    if (shipVector == 0) {
        return coordinateX + shipSize > boardSize;
    }

    if (shipVector == 1) {
        return coordinateY + shipSize > boardSize;
    }

    return 1;
}

int setShipOnBoard(int tabuleiro[10][10], int shipPosition[2], int shipSize, int shipVector) {

    if (checkShipOverPassLimits(10, shipPosition[0], shipPosition[1], shipSize, shipVector)) {
        printf("Posição inválida. Tente novamente.\n");
        return 0;
    }

    for (int i = 0; i < shipSize; i++){
        if (checkHasShipOnCoordinate(tabuleiro, shipPosition[0], shipPosition[1])) {
            printf("Posição ocupada. Tente novamente.\n");
            return 0;
        }
        tabuleiro[shipPosition[0]][shipPosition[1]] = 3;
        if (shipVector == 0){
            shipPosition[1] = shipPosition[1] + 1;
        } else {
            shipPosition[0] = shipPosition[0] + 1;
        }
    }

    return 1;
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tamanhoTabuleiro = 10;
    // printf("Digite o tamanho do tabuleiro: ");
    // scanf("%d", &tamanhoTabuleiro);

    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];
    int i, j;

    for (i = 0; i < tamanhoTabuleiro; i++){
        for (j = 0; j < tamanhoTabuleiro; j++){
            tabuleiro[i][j] = 0;
        }
    }

    int shipPosition1[2] = {3,2};
    int shipSize1 = 3;
    int shipVector1 = 0;

    if (!setShipOnBoard(tabuleiro, shipPosition1, shipSize1, shipVector1)) {
        return 0;
    }

    int shipPosition2[2] = {4,5};
    int shipSize2 = 3;
    int shipVector2 = 1;

    if (!setShipOnBoard(tabuleiro, shipPosition2, shipSize2, shipVector2)) {
        return 0;
    }

    printTabuleiro(tabuleiro);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
