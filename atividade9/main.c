#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    int N;
    // lê a qtd de elementos do vetor N
    scanf("%d", &N);
    if(N < 1)
    {
        return -1;
    }
    int *vetor_v;
    // cria o vetor de tamanho N
    vetor_v = (int *) malloc(sizeof(int) * N);
    // armazena o vetor V
    for(int i=0;i < N; ++i)
    {
     scanf("%d",&vetor_v[i]);

    }
    
    int K;
    // lê a qtd de elementos do vetor K
    scanf("%d", &K);
    if(K < 1)
    {
        return -1;
    }
    // cria o vetor de tamanho K
    int *vetor_k;
    vetor_k = (int *) malloc(sizeof(int) * K);

    // armazena o vetor K
    for(int i=0;i < K; ++i)
    {
     scanf("%d",&vetor_k[i]);
    }
    int encontrou;
        // armazena o vetor K
    for(int i=0;i < K; ++i)
    {
        encontrou = 0;
        for(int j=0;j < N; ++j)
        {
            if (vetor_k[i] == vetor_v[j])
            {
                encontrou = 1;
                break;
            }
        }
        if(encontrou)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        
    }
    
    return 0;
}