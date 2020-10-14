#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(int subvetor[], int menor_indice, int maior_indice, int *quick_comparacoes, int *quick_copias)
{

    //printf("menor %d\n", menor_indice);
    //printf("maior %d\n", maior_indice);
    if (menor_indice < maior_indice)
    {
        *quick_comparacoes += 1;
        if(menor_indice >= maior_indice)
        {
            //*quick_comparacoes += 1;
            return;
        }
        else //menor_indice < maior_indice
        {
            *quick_comparacoes += 1;
        }
        
        int meio = (menor_indice + maior_indice) / 2;
        int pivo = subvetor[meio];
        *quick_copias += 1;
        int inicio = menor_indice;
        int fim = maior_indice;
        while(1)
        {
            *quick_comparacoes += 1;
            while(subvetor[inicio] < pivo)
            {
                inicio++;
                //*quick_comparacoes += 1;
            }
            *quick_comparacoes += 1;
            while(subvetor[fim] > pivo)
            {
                fim--;
                //*quick_comparacoes += 1;
            }
            if(fim <= inicio)
            {
                //*quick_comparacoes += 1;
                break;
            }
        //    printf("aquiiiiiiiiiiiiiiiiiiiiiii\n");
            int auxiliar = subvetor[inicio];
            subvetor[inicio] = subvetor[fim];
            subvetor[fim] = auxiliar;
            *quick_copias += 3;
        //    printf("quick copias\n %d", *quick_copias);
            inicio++;
            fim--;     
        }
        quicksort(subvetor, menor_indice, fim, quick_comparacoes, quick_copias);
        quicksort(subvetor, fim + 1, maior_indice, quick_comparacoes, quick_copias);
    }
    else //(menor_indice > maior_indice)
    {
        //*quick_comparacoes += 1;
    }
}

int shell(int subvetor[], int tamanho_vetor)
{
    int gap = 1, comparacoes = 0, copias = 0, resultado = 0;
    int j;
    //comparacoes += 1;
    while(gap <= tamanho_vetor) {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    //copias += 1;
    while(gap > 0) {
        for (int k = 0; k < gap; k++)
        {
            //comparacoes += 1;
            for (int i = k + gap; i < tamanho_vetor; i += gap)
            {
                //copias += 1;
                int x = subvetor[i];
                j = i - gap;
                if(j >= 0 && subvetor[j] <= x)
                {
                    comparacoes += 1;
                }
                while(j >= 0 && subvetor[j] > x) 
                {
                    //resultado += 2;
                    comparacoes += 1;
                    subvetor[j+gap] = subvetor[j];
                    copias += 1;
                    j-=gap;
                }

                subvetor[j+gap] = x;
                copias += 1;
            }
        }
        gap /= 2;
    }
    resultado = comparacoes + copias;
    return resultado;
}

void compara_funcoes(int subvetor[], int tamanho_vetor, int *contador)
{
    int *quick_vetor;
    quick_vetor = (int *) malloc(sizeof(int) * tamanho_vetor);

    for (int i = 0; i < tamanho_vetor; i++)
    {
        quick_vetor[i] = subvetor[i];
    }
    int qtd_shell;
    int quick_comparacoes = 0, quick_copias = 0, quick_resultado = 0;
    qtd_shell = shell(subvetor, tamanho_vetor);
    
    quicksort(quick_vetor, 0, tamanho_vetor - 1, &quick_comparacoes, &quick_copias);
    quick_resultado = quick_copias + quick_comparacoes;

printf("shell %d\n", qtd_shell);
printf("quicksort %d\n", quick_resultado);
    if (*contador == 0)
    {
        *contador += 1;
        if(qtd_shell == quick_resultado)
        {
            printf("-");
        }
        
        else if (qtd_shell > quick_resultado)
        {
           printf("Q");
        }
        
        else if (qtd_shell < quick_resultado)
        {
            printf("S");
        }
    }
    else
    {
        if(qtd_shell == quick_resultado)
        {
            printf(" -");
        }
        
        else if (qtd_shell > quick_resultado)
        {
            printf(" Q");
        }
        
        else if (qtd_shell < quick_resultado)
        {
            printf(" S");
        }
    }

    return;
}

int main(void) {
    int qtd_numeros, *vetor, *sub_vetor;
    int i, j, contador=0;

    scanf("%d", &qtd_numeros);

    vetor = (int *) malloc(sizeof(int) * qtd_numeros);

    for (i = 0; i < qtd_numeros; i++)
    {
        scanf("%d", &(vetor[i]));
    }

    /*for (j = 1; j < qtd_numeros + 1; j++)
    {
        sub_vetor = (int *) malloc(sizeof(int) * j);
        memcpy(sub_vetor, &vetor[0], j*sizeof(*vetor));
        compara_funcoes(sub_vetor, j, &contador);
    }*/
    compara_funcoes(vetor, qtd_numeros, &contador);
    printf("\n");
    return 0;
}
