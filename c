#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho-1; i++) {
        for (j = 0; j < tamanho-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                trocar(&vetor[j], &vetor[j+1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int vetor[], int tamanho) {
    int i, j, min_idx;
    for (i = 0; i < tamanho-1; i++) {
        min_idx = i;
        for (j = i+1; j < tamanho; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        trocar(&vetor[min_idx], &vetor[i]);
    }
}

// Insertion Sort
void insertionSort(int vetor[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[10] = {64, 25, 12, 22, 11, 36, 7, 98, 45, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    imprimirVetor(vetor, tamanho);

    // Testando Bubble Sort
    bubbleSort(vetor, tamanho);
    printf("Após Bubble Sort: ");
    imprimirVetor(vetor, tamanho);

    // Reinicializando o vetor para os próximos testes
    int vetor2[10] = {64, 25, 12, 22, 11, 36, 7, 98, 45, 3};

    // Testando Selection Sort
    selectionSort(vetor2, tamanho);
    printf("Após Selection Sort: ");
    imprimirVetor(vetor2, tamanho);

    // Reinicializando o vetor para os próximos testes
    int vetor3[10] = {64, 25, 12, 22, 11, 36, 7, 98, 45, 3};

    // Testando Insertion Sort
    insertionSort(vetor3, tamanho);
    printf("Após Insertion Sort: ");
    imprimirVetor(vetor3, tamanho);

    return 0;
}
