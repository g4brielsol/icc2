#include<stdio.h>
#include<stdlib.h>
 
void counting_sort(int vetor[], int contador[], int n, int k)
{
    int i,j;
    int *vetor_ordenado, *compara_contador;
    // vai armazenar o vetor ordenado
    vetor_ordenado = (int *) malloc(sizeof(int) * n);
    // inicializar os elementos com zero
    compara_contador = (int *) calloc(k, sizeof(int));

    // conta quantas vezes cada elemento apareceu
    for(i=0;i<n;++i)
    {
    contador[vetor[i]] = contador[vetor[i]] + 1;
    } 

    int indice_ordenado = 0;
    for(i=0;i<=k;++i)
    {
        // armazena o vetor ordenado, para utilizar seus indices 
        // como ponto de partida para a contagem
        for(j=0;j<contador[i];++j)
        {
            vetor_ordenado[indice_ordenado] = i;
            indice_ordenado += 1;
        }
    }
    // printar no run codes
    for (i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            // se o valor do elemento do vetor original
            // for igual ao elemento do vetor ordenado
            if(vetor[i] == vetor_ordenado[j])
            {
                                           // soma o indice do vetor ordenado com o numero de
                                           // vezes que ele apareceu para printar na resposta
                printf("%d %d\n", vetor[i], j + compara_contador[vetor[i]]);
                // soma quantas vezes o numero ja apareceu
                compara_contador[vetor[i]] +=1;
                break;
            }
        }
    }
    return;
}
 
int main()
{
    int k, n, i;
    scanf("%d", &k);
    scanf("%d",&n);
    // termina o programa se o valor de k ou n for menor que 1
    if((k < 1) || (n < 1))
    {
        return -1;
    }
    int *vetor, *contador;
    vetor = (int *) malloc(sizeof(int) * n);
    // inicializar com zeros
    contador = (int *) calloc(k, sizeof(int));

    // armazena o vetor
    for(i=0;i <n; ++i)
    {
     scanf("%d",&vetor[i]);
     // se não for um valor entre 0 e k-1, termina o programa
     if(vetor[i] >= k)
     {
         return -1;
     }
    }
     
    counting_sort(vetor, contador, n, k-1);
    return 0;
}