#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ord_bolha(int tamanho, int* valores);
void ord_selecao(int tamanho, int* valores);
void trocar(int* a, int* b);

int main(void) {
    char opc[8];
    int n, i;
    int* vetor;
    
    scanf("%s", opc);
    scanf("%d", &n);
    
    vetor = (int*) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    if (strcmp(opc, "bolha") == 0) {
        ord_bolha(n, vetor);
    } else if (strcmp(opc, "selecao") == 0) {
        ord_selecao(n, vetor);
    }
    
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
}


void ord_bolha(int tamanho, int* valores) {
    int i, j;

    int ultimaTroca;

    i = tamanho - 1;
    // i é o ponto no vetor até onde realizar comparações, como o bubble ordena do fim até o começo.
    while (i > 0) {
        ultimaTroca = 0;
        // Percorre o vetor até a posição ainda não ordenada, comparando cada
        // posição com a próxima e as trocando caso a de antes seja maior.
        for (j = 0; j < i; j++) {
            printf("C %d %d\n", j, j + 1);
            if (valores[j] > valores[j + 1]) {
                ultimaTroca = j;
                printf("T %d %d\n", j, j + 1);
                trocar(&valores[j], &valores[j + 1]);
            }
        }
        i = ultimaTroca;
    }
}

void ord_selecao(int tamanho, int* valores) {
    int i, j, min;

    // i é o ponto no vetor de onde começar a fazer comparações, como o selection ordena do começo até o fim.
    for (i = 0; i < tamanho - 1; i++) {
        // Procura o menor elemento a partir do i.
        min = i;
        for (j = i + 1; j < tamanho; j++) {
            printf("C %d %d\n", min, j);
            if (valores[j] < valores[min]) {
                min = j;
            }
        }

        if (min != i) {
            printf("T %d %d\n", i, min);
            trocar(&valores[i], &valores[min]);
        }
    }
}

void trocar(int* a, int* b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
