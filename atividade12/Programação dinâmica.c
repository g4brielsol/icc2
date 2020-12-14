#include <stdio.h>
#include <stdlib.h>

struct No{
    int destino;
    int amigos;
    struct No* prox;
} typedef NODE;

//indices dos nos de inicio e chegada
struct Aresta{
    int fonte;
    int destino;
    int amigos;
} typedef ARESTA;

//grafo
struct Grafo{
    NODE** lista;
}typedef GRAFO;

GRAFO* cria_grafo(ARESTA* arestas, int num_arestas, int num_nos){

    GRAFO* grafo = (GRAFO*)malloc(sizeof(GRAFO));
    grafo->lista = (NODE**)malloc(num_nos*sizeof(NODE*));
    for(int i = 0; i < num_nos; i++){
        grafo->lista[i] = NULL;
    }
    for(int i = 0; i < num_arestas; i++){
        int fonte = arestas[i].fonte;
        int destino = arestas[i].destino;
        int amigos = arestas[i].amigos;

        NODE* novo_no = (NODE*)malloc(sizeof(NODE));
        novo_no->destino = destino;
        novo_no->amigos = amigos;
        novo_no->prox = grafo->lista[fonte];
        grafo->lista[fonte] = novo_no;
    }
    return grafo;
}

int Maior(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

int max_amigos_rec(int* cache, GRAFO* grafo, ARESTA* arestas, int c, int l, int ind){

    //chegou no final
    if(ind == l*c -1){
        return 0;
    }
    int max = 0;
    if(cache[ind] == -1){
        int max_1 = 0;
        int max_2 = 0;
        if(grafo->lista[ind] != NULL){
            max_1 = grafo->lista[ind]->amigos + max_amigos_rec(cache, grafo, arestas, c, l, grafo->lista[ind]->destino);
        }
        if(grafo->lista[ind]->prox != NULL){
            max_2 = grafo->lista[ind]->prox->amigos + max_amigos_rec(cache, grafo, arestas, c, l, grafo->lista[ind]->prox->destino);
        }
        max = Maior(max_1, max_2);
        cache[ind] = max;
    }else{
        max = cache[ind];
    }

    return max;
}

int max_amigos_pd(GRAFO* grafo, ARESTA* arestas, int c, int l, int ind){

    int* cache = (int*)malloc(l*c*sizeof(int));
    for(int i = 0; i < l*c; i++){
        cache[i] = -1;
    }
    int res = max_amigos_rec(cache, grafo, arestas, c, l, ind);

    free(cache);

    return res;
}

void printGraph(GRAFO* grafo, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        // print current vertex and all its neighbors
        NODE* ptr = grafo->lista[i];
        while (ptr != NULL)
        {
            printf("(%d -> %d)(%d)\t", i, ptr->destino, ptr->amigos);
            ptr = ptr->prox;
        }

        printf("\n");
    }
}

int main(void){

    //linhas e colunas
    int l, c;
    scanf("%d",  &l);
    scanf("%d",  &c);

    //numero de arestas
    int N = 2*c*l - c - l;

    ARESTA* aresta = (ARESTA*)malloc(N*sizeof(ARESTA));

    for(int i = 0; i < N; i++){
        scanf("%d", &aresta[i].fonte);
        scanf("%d", &aresta[i].destino);
        scanf("%d", &aresta[i].amigos);
    }
    GRAFO* grafo_final;
    grafo_final = cria_grafo(aresta, N, c*l);

    //printGraph(grafo_final, c*l);

    int res;
    res = max_amigos_pd(grafo_final, aresta, c, l, 0);
    printf("%d", res);

    free(aresta);

    return 0;
}
