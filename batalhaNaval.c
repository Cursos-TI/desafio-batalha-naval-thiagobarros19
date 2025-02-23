#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

void printTabuleiroEspecial(int tabuleiro[10][10]) {
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

int setShipOnBoard(int tabuleiro[10][10], int shipPosition[2], int shipSize, int shipVector, int isDiagonal) {

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
            if (isDiagonal == 1) {
                shipPosition[0] = shipPosition[0] + 1;
                shipPosition[1] = shipPosition[1] + 1;
            } else {
                shipPosition[1] = shipPosition[1] + 1;
            }
        } else {
            if (isDiagonal == 1) {
                shipPosition[0] = shipPosition[0] - 1;
                shipPosition[1] = shipPosition[1] + 1;
            } else {
                shipPosition[0] = shipPosition[0] + 1;
            }
        }
    }

    return 1;
}

void createConeEspecial(int tabuleiro[10][10], int tabuleiroSize, int size, int coordinateX, int coordinateY) {
    for (int i = coordinateX; i < size + coordinateX; i++){
        for (int j = 0; j < tabuleiroSize; j++){
            if (j >= coordinateY - i + coordinateX && j <= coordinateY + i - coordinateX) {
                tabuleiro[i][j] = 5;
            }
        }
    }
}

void createCruzEspecial(int tabuleiro[10][10], int tabuleiroSize, int coordinateX, int coordinateY) {
    for (int i = 0; i < tabuleiroSize; i++){
        for (int j = 0; j < tabuleiroSize; j++){
            if (i == coordinateX || j == coordinateY) {
                tabuleiro[i][j] = 5;
            }
        }
    }
}

void createOctaedroEspecial(int tabuleiro[10][10], int tabuleiroSize, int octaedroSize, int coordinateX, int coordinateY) {
    int radius = octaedroSize / 2;

    for (int i = 0; i < tabuleiroSize; i++) {
        for (int j = 0; j < tabuleiroSize; j++) {
            int dist = abs(i - coordinateX);
            if (dist <= radius) {
                int range = radius - dist;
                if (j >= coordinateY - range && j <= coordinateY + range) {
                    tabuleiro[i][j] = 5;
                }
            }
        }
    }
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
    int isDiagonal1 = 0;

    if (!setShipOnBoard(tabuleiro, shipPosition1, shipSize1, shipVector1, isDiagonal1)) {
        return 0;
    }

    int shipPosition2[2] = {4,5};
    int shipSize2 = 3;
    int shipVector2 = 1;
    int isDiagonal2 = 0;

    if (!setShipOnBoard(tabuleiro, shipPosition2, shipSize2, shipVector2, isDiagonal2)) {
        return 0;
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int shipPosition3[2] = {0,4};
    int shipSize3 = 3;
    int shipVector3 = 0;
    int isDiagonal3 = 1;

    if (!setShipOnBoard(tabuleiro, shipPosition3, shipSize3, shipVector3, isDiagonal3)) {
        return 0;
    }

    int shipPosition4[2] = {7,0};
    int shipSize4 = 3;
    int shipVector4 = 1;
    int isDiagonal4 = 1;

    if (!setShipOnBoard(tabuleiro, shipPosition4, shipSize4, shipVector4, isDiagonal4)) {
        return 0;
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    int tamanhoTabuleiroCone = 10;
    int tabuleiroCone[tamanhoTabuleiroCone][tamanhoTabuleiroCone];

    for (i = 0; i < tamanhoTabuleiroCone; i++){
        for (j = 0; j < tamanhoTabuleiroCone; j++){
            tabuleiroCone[i][j] = 0;
        }
    }

    int conePosition[2] = {7,2};
    int coneSize = 3;

    createConeEspecial(tabuleiroCone, tamanhoTabuleiroCone, coneSize, conePosition[0], conePosition[1]);

    printTabuleiroEspecial(tabuleiroCone);

    int tamanhoTabuleiroCruz = 10;
    int tabuleiroCruz[tamanhoTabuleiroCruz][tamanhoTabuleiroCruz];

    for (i = 0; i < tamanhoTabuleiroCruz; i++){
        for (j = 0; j < tamanhoTabuleiroCruz; j++){
            tabuleiroCruz[i][j] = 0;
        }
    }

    int cruzPosition[2] = {1,8};

    createCruzEspecial(tabuleiroCruz, tamanhoTabuleiroCruz, cruzPosition[0], cruzPosition[1]);

    printTabuleiroEspecial(tabuleiroCruz);

    int tamanhoTabuleiroOctaedro = 10;
    int tabuleiroOctaedro[tamanhoTabuleiroOctaedro][tamanhoTabuleiroOctaedro];

    for (i = 0; i < tamanhoTabuleiroOctaedro; i++){
        for (j = 0; j < tamanhoTabuleiroOctaedro; j++){
            tabuleiroOctaedro[i][j] = 0;
        }
    }

    int octaedroPosition[2] = {4,4};
    int octaedroSize = 5;

    createOctaedroEspecial(tabuleiroOctaedro, tamanhoTabuleiroOctaedro, octaedroSize, octaedroPosition[0], octaedroPosition[1]);

    printTabuleiroEspecial(tabuleiroOctaedro);

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


    createConeEspecial(tabuleiro, tamanhoTabuleiroCone, coneSize, conePosition[0], conePosition[1]);
    createCruzEspecial(tabuleiro, tamanhoTabuleiroCruz, cruzPosition[0], cruzPosition[1]);
    createOctaedroEspecial(tabuleiro, tamanhoTabuleiroOctaedro, octaedroSize, octaedroPosition[0], octaedroPosition[1]);
    printTabuleiro(tabuleiro);

    return 0;
}
