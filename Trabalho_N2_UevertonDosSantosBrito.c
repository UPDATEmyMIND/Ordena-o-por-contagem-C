#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TAM 50

// Funcao para verificar se o numero k ja existe no vetor v
// Verifica so ate a posicao n-1
int existe(int n, int v[], int k) {
    for (int i = 0; i < n; i++) {
        if (v[i] == k) {
            return 1; // numero ja existe
        }
    }
    return 0; // numero nao existe
}

int main() {
    int i, j, n, r;
    int vet[MAX_TAM];   // vetor com numeros dos cheques
    int pos[MAX_TAM];   // vetor para guardar a posicao que cada numero tera no vetor ordenado
    int v_ord[MAX_TAM]; // vetor ordenado final

    // --- Bloco comentado para teste com vetor fixo ---
    /*
    int teste_fixado[] = {14, 97, 15, 79, 72, 55, 100, 30, 33, 10, 38, 12, 51, 71,
                         68, 98, 90, 44, 9, 11, 48, 65, 8, 43, 34, 93, 24, 92, 21,
                         74, 49, 23};
    n = 32; // tamanho do vetor fixo

    for (i = 0; i < n; i++) {
        vet[i] = teste_fixado[i];
    }
    */

    // --- Bloco ativado para gerar vetor aleatorio sem repeticao ---
    srand((unsigned)time(NULL)); // inicializa o gerador de numeros aleatorios

    n = (rand() % MAX_TAM) + 1; // define tamanho do vetor entre 1 e MAX_TAM
    i = 0;
    while (i < n) {
        r = (rand() % 100) + 1; // gera numero aleatorio entre 1 e 100
        if (existe(i, vet, r) == 0) { // so adiciona se nao existir no vetor
            vet[i] = r;
            i++;
        }
    }

    // Imprime vetor inicial
    printf("Vetor inicial:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n\n");

    // Ordenacao por contagem:
    // Para cada elemento vet[i], conta quantos elementos sao menores que ele
    for (i = 0; i < n; i++) {
        pos[i] = 0; // zera a posicao inicialmente
        for (j = 0; j < n; j++) {
            if (vet[j] < vet[i]) {
                pos[i]++;
            }
        }
    }

    // Com o vetor pos preenchido, coloca cada elemento na posicao correta do vetor ordenado
    for (i = 0; i < n; i++) {
        v_ord[pos[i]] = vet[i];
    }

    // Imprime vetor ordenado
    printf("Vetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v_ord[i]);
    }
    printf("\n");

    return 0;
}
