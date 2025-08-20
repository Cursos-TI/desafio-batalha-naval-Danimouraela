#include <stdio.h>

#define TAMANHO 10   // tamanho tabuleiro (10x10)
#define NAVIO 3      // tamanho dos navios

int main() {
    // 1. Tabuleiro inicializa com 0 (água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Coordenadas iniciais dos navios
    // (linha, coluna)
    int linhaNavioHorizontal = 2;  
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 6;    
    int colunaNavioVertical = 1;

    // 2. Posicionar navio horizontal
    // Checagem: garantir que o navio cabe no tabuleiro
    if (colunaNavioHorizontal + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
        }
    } else {
        printf("Erro: Navio horizontal não cabe no tabuleiro!\n");
        return 1;
    }

    // 3. Posicionar navio vertical
    // Checagem: garantir que o navio cabe e não sobrepõe
    if (linhaNavioVertical + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == 0) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
            } else {
                printf("Erro: Sobreposição de navios detectada!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
        return 1;
    }

    // 4. Exibir o tabuleiro
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}