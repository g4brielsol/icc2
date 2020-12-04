#include<stdio.h>
#include<stdlib.h>

//struct para o nó da árvore
struct no
{
    int val;
    struct no *esq;
    struct no *dir;    
};
// funcao para criar um no novo
struct no * novo_no(int x)
{
    struct no *aux = (struct no *) malloc(sizeof(struct no));
    aux->val = x;
    aux->esq = NULL;
    aux->dir = NULL;
    return aux;
}
// inserir nó em uma arvóre
struct no * insere_no(struct no* node, int x)
{
    // se a raiz nao existir, cria a raiz
    if(node == NULL)
    {
        return novo_no(x);
    }
    // se existir raiz
    else
    {
        // se o valor a ser inserido é menor que o atual
        if(x < node->val)
        {
            // chama a recursão no nó da esquerda (menor)
            node->esq = insere_no(node->esq, x);
        }
        // se o valor a ser inserido é maio que o atual
        else
        {
            // chama a recursão no nó da esquerda (menor)
            node->dir = insere_no(node->dir, x);
        }
        //retorna a raiz 
        return node;
    }
}

struct no * busca_no(struct no *node, int x)
{
    // se nao existir nó, retorna -1
    if(node == NULL)
    {
        return NULL;
    }
    // se o nó atual for igual ao x que estamos procurando, retorna 0
    else if(node->val == x)
    {
        return node;
    }
    // se o valor que estamos procurando é menor que o atual
    else if(x < node->val)
    {
        // chama a recursão no nó da esquerda (menor)
        return busca_no(node->esq, x);
    }
    // se o valor que estamos procurando é maior que o atual
    else
    {
        // chama a recursão no nó da direita (maior)
        return busca_no(node->dir, x);
    }
}

int main()
{
    int N;
    // lê a qtd de elementos do vetor N
    scanf("%d", &N);
    int V;
    // lê o primeiro valor de V
    scanf("%d",&V);
    // cria a raiz da arvore com o primeiro valor de V
    struct no *raiz = novo_no(V);
    // decremente o tamanho de N pq já lemos o primeiro elemento de V
    N = N-1;
    int *vetor_v;
    // cria o vetor de tamanho N
    vetor_v = (int *) malloc(sizeof(int) * N);
    // insere os elementos de V na árvore
    for(int i=0;i < N; ++i)
    {
        scanf("%d",&vetor_v[i]);
        raiz = insere_no(raiz, vetor_v[i]);
    }

    int K;
    // lê a qtd de elementos do vetor K
    scanf("%d", &K);
    int *vetor_k;
    vetor_k = (int *) malloc(sizeof(int) * K);
    // armazena o vetor K
    for(int i=0;i < K; ++i)
    {
        scanf("%d", &vetor_k[i]);
    }
    // cria o nó aux e busca o primeiro valor de K na árvore
    struct no *aux = busca_no(raiz, vetor_k[0]);
    if(aux == NULL)
    {
        // se não achou printa 0
        printf("0\n");
    }
    else
    {
        //se achou printa 1
        printf("1\n");
    }
    
    int i;
    // a partir de 1 pq já buscamos o primeiro K
    for(i = 1;i < K; ++i)
    {
        aux = busca_no(raiz, vetor_k[i]);
        if(aux == NULL)
        {
            // se não achou printa 0
            printf("0\n");
        }
        else
        {
            // se achou printa 1
            printf("1\n");
        } 
    }
    return 0;
}