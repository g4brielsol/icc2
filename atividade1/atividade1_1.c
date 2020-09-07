//inclui funções de arquivos, exibição e leitura
#include <stdio.h>
//inclui funções de alocação dinâmica de memória
#include <stdlib.h>
#include <string.h>

int ord_bolha(int tamanho, int valores[])
{
    int i, j, min;
    int temp;

    for(i = 0; i < tamanho - 1; i++)
    {
        min = i;
        for(j = i + 1; j < tamanho; j++)
        {
            printf("C %d %d\n", min, j);
            if(valores[j] < valores[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            printf("T %d %d\n", i, min);
            temp = valores[i];
            valores[i] = valores[min];
            valores[min] = temp;
        }
    }

    return valores[tamanho];
}

int ord_selecao(int tamanho, int valores[])
{
    int i, j;
    int temp;

    for(i = tamanho - 1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("C %d %d\n", j, j+1);
            if(valores[j] > valores[j + 1])
            {
                printf("T %d %d\n", j, j+1);
                temp = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1]= temp;
            }
        }
    }

    return valores[tamanho];
}


int main(){
    //char *metodo = (char *) malloc(20*sizeof(char));
    char metodo[20];
    int quantidade;
    //FILE *fp;
    //fp = fopen("1.in", "r");
    //lê-se o método
    //fscanf(fp, "%s", metodo);
    scanf("%s", metodo);
    //lê-se o número de quantidade
    //fscanf(fp, "%d", &quantidade);
    scanf("%d", &quantidade);
    //int quantidade[quantidade];
    //printf("%s\n", metodo);
    //printf("%d\n", quantidade);
    int lista[quantidade];
    for(int i=0; i < quantidade; i++)
    {
        //fscanf(fp, "%d",&lista[i]);
        scanf("%d",&lista[i]);
    }
    //printf("%s\n", metodo);
    //printf("%d\n", quantidade);
        for(int i=0; i < quantidade; i++)
    {
        //fscanf(fp, "%d",&lista[i]);
        //printf("%d ",lista[i]);
    }

    //for (int i = 0; i < quantidade; i++){
    //    printf("Number is: %d\n\n", lista[i]);
    //}

    if(strcmp(metodo, "selecao"))
    {
        lista[quantidade] = ord_selecao(quantidade, lista);
    }
    else if(strcmp(metodo, "bola"))
    {
        lista[quantidade] = ord_bolha(quantidade, lista);
    }

   for (int i = 0; i < quantidade; i++){
        if (i != quantidade - 1)
        {
            printf("%d ", lista[i]);
        }
        else{
            printf("%d", lista[i]);
        }

    }

    //fclose(fp);

    return 0;
}