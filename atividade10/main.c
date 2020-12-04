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

    int elementos_lidos;
    // lê a qtd de elementos do vetor elementos_lidos
    scanf("%d", &elementos_lidos);
    if(elementos_lidos < 1)
    {
        return -1;
    }

    int *vetor_n, elemento, offset;
    // cria o vetor de tamanho N
    vetor_n = (int *) malloc(sizeof(int) * N);
    // faz os valores do vetor serem igual a -1
    for(int i=0;i < N; ++i)
    {
        vetor_n[i] = -1;
    }

    // armazena o vetor N
    for(int i=0;i < elementos_lidos; ++i)
    {
        scanf("%d",&elemento);
        // se o elemento for negativo, termina o código
        if(elemento < 0)
        {
            return -1;
        }
        offset = 0;
        // enquanto houver valor já inserido na posicao do vetor (enderecamento aberto linear)
        while(vetor_n[(elemento + offset) % N] != -1)
        {
            // se o elemento for repetido, termina o código
            //if(vetor_n[(elemento + offset) % N] == elemento)
            //{
            //    return -1;
            //}
            //incrementa o offset
            offset += 1;
        }
        // adiciona o elemento na posicao vazia
        vetor_n[(elemento + offset) % N] = elemento;
    }

    int D;
    // lê a qtd de remocoes D
    scanf("%d", &D);
    if(D < 1)
    {
        return -1;
    }

    int numero_removido;
    // remove os valores do vetor
    for(int i=0;i < D; ++i)
    {
        scanf("%d",&numero_removido);
        offset = 0;
        // procura o elemento a ser removido no vetor
        while(vetor_n[(elemento + offset) % N] != numero_removido)
        {
            //incrementa o offset
            offset += 1;
            // sai do while quando o offset é maior que os indices do vetor n (elemento nao encontrado)
            if(offset == D)
            {
                break;
            }
        }
        // se o elemento existir no vetor n
        if(vetor_n[(elemento + offset) % N] == numero_removido)
        {
            // remove elemento do vetor
            vetor_n[(elemento + offset) % N] = -1;
        }      

    }

    int B;
    // lê a qtd de buscas B
    scanf("%d", &B);
    if(B < 1)
    {
        return -1;
    }

    int numero_buscado;
    // remove os valores do vetor
    for(int i=0;i < B; ++i)
    {
        scanf("%d",&numero_buscado);
        offset = 0;
        // procura o elemento a ser removido no vetor
        while(vetor_n[(elemento + offset) % N] != numero_buscado)
        {
            //incrementa o offset
            offset += 1;
            // sai do while quando o offset é maior que os indices do vetor n (elemento nao encontrado)
            if(offset == D)
            {
                break;
            }
        }
        // se o elemento existir no vetor n
        if(vetor_n[(elemento + offset) % N] == numero_buscado)
        {
            // printa o indice
            printf("%d ", (elemento + offset) % N);
        }   
        else
        {
            printf("-1 ");
        }
    }
    return 0;
}