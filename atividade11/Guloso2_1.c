#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char** lista, int N){
    for(int i = 0; i < N; i++){
        if(lista[i] == NULL){
            printf("NULL\n");
        }else{
            printf("%s\n", lista[i]);
        }
    }
}

void palavra(int N, char*** s){

    for(int i = 0; i < N; i++){
        (*s)[i] = NULL;
        int pos = 0;
        do{
           (*s)[i] = realloc((*s)[i], pos + 1);  //aloca a palavra de forma dinamica
           (*s)[i][pos] = (char)fgetc(stdin);
           pos++;

        } while((*s)[i][pos - 1] != '\n');
        (*s)[i][pos - 1] = '\0';
    }
}

void overlap(int retorno[], char* s1, char* s2){

    if(s1 == NULL || s2 == NULL){
        retorno[0] = -1;
        retorno[1] = -1;
        return;
    }

    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int max_1 = 0;
    int max_2 = 0;
    int aux;

    //tamanho da menor string
    int s;
    if(s1_len > s2_len){
        s = s2_len;
    }else{
        s = s1_len;
    }

    for(int i = 0; i < s; i++){
        aux = 0;
        for(int j = 0; j <=i; j++){
            if(s1[s1_len-1-i+j] != s2[j]){
                break;
            }else{
                aux += 1;
            }
        }
        if(aux == i+1){
            max_1 = i+1;
        }
    }

    int len_dif = abs(s1_len - s2_len);
    //substring
    if(s1_len > s2_len){
        for(int i = 0; i < len_dif; i++){
            aux = 0;
            for(int j = 0; j < s; j++){
                if(s1[j+i] != s2[j]){
                    break;
                }else{
                    aux++;
                }
            }
            if(aux == s){
                max_2 = s;
            }
        }
    }else if(s1_len < s2_len){
        for(int i = 0; i < len_dif; i++){
            aux = 0;
            for(int j = 0; j < s; j++){
                if(s1[j] != s2[j+i]){
                    break;
                }else{
                    aux++;
                }
            }
            if(aux == s){
                max_2 = s;
            }
        }
    }
    if(max_1 < max_2){
        retorno[0] = max_2;
        retorno[1] = 1; //caso substring
    }else{
        retorno[0] = max_1;
        retorno[1] = 0; //caso final-comeco
    }
    return;
}

void arruma_lista(char*** lista, int pos, char* s_copy){

    if((*lista)[0] == NULL){
        //printf("\narrumar lista [0]\n");
        (*lista)[0] = realloc((*lista)[0], strlen(s_copy)+1);
        //printf("lista 0 len %d\n", strlen((*lista)[0]));
        //printf("s_copy len %d\n", strlen(s_copy));
        strcpy((*lista)[0], s_copy);
        //printf("lista 0 %s\n", (*lista)[0]);
        //printf("s_copy %s\n", s_copy);
    }else{
        //printf("\narrumar lista else\n");
        //encontra o primeiro NULL da lista
        for(int i = pos; i > 0; i--){
            (*lista)[i] = realloc((*lista)[i], strlen((*lista)[i-1])+1);
            //printf("(*lista)[i-1] %s\n", (*lista)[i-1]);
            strcpy((*lista)[i], (*lista)[i-1]);
            //printf("(*lista)[i] %s\n", (*lista)[i]);
        }
        if((*lista)[0])
        {
            //printf("teste 1");
            //printf("(*lista)[0] %d\n", (*lista)[0]);
        }
        else
        {
            //printf("teste 2");
            //printf("s_copy %s\n", s_copy);
        }
        (*lista)[0] = realloc((*lista)[0], strlen(s_copy)+1);
        //printf("(*lista)[0] %s\n", (*lista)[0]);
        //printf("s_copy %s\n", s_copy);
        strcpy((*lista)[0], s_copy);
    }
}

int concatenar(char** lista, int N, int it){

    //armazena valor, valor, posicao, posicao
    int max_overlap[4] = {-1,-1,-1,-1};
    int aux[2] = {-1,1};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j!=i){
                overlap(aux, lista[i], lista[j]);
                //printf("%d %d - %s %s - OL = %d - C = %d\n", i, j, lista[i], lista[j], aux[0], aux[1]);
                if(aux[0] > max_overlap[0]){
                    max_overlap[0] = aux[0];
                    max_overlap[1] = aux[1];
                    max_overlap[2] = i;
                    max_overlap[3] = j;
                }
            }
        }
    }
    //printf("Overlap: %d, Caso: (%d), Par: (%d,%d)\n", max_overlap[0], max_overlap[1], max_overlap[2], max_overlap[3]);

    int s1_len = strlen(lista[max_overlap[2]]);
    int s2_len = strlen(lista[max_overlap[3]]);

    //caso substring
    //nao acrescenta em nada o problema, pois nao aumentara nem um caracter em nenhum momento do programa
    //entao podemos eliminar

    int min;
    if(max_overlap[2] > max_overlap[3]){
        min = max_overlap[3];
    }else{
        min = max_overlap[2];
    }

    if(max_overlap[1] == 1){

        char* s_copy;

        if(s1_len > s2_len){
            //printf("\noverlap 1 s1 maior %d\n", it);
            s_copy = (char*)calloc(s1_len+1, sizeof(char));
            lista[max_overlap[3]] = NULL;
            strcpy(s_copy, lista[max_overlap[2]]);
            //printf("s copy %s\n", s_copy);
            lista[max_overlap[2]] = NULL;

            arruma_lista(&lista, min, s_copy);

            //free(s_copy);

        }else{
            //printf("\noverlap 1 s2 maior %d\n", it);
            s_copy = (char*)calloc(s2_len+1, sizeof(char));
            lista[max_overlap[2]] = NULL;
            strcpy(s_copy, lista[max_overlap[3]]);
            lista[max_overlap[3]] = NULL;

            arruma_lista(&lista, min, s_copy);

            //free(s_copy);
        }
        //print(lista, N);
    }else{
        //caso final-come�o
        //printf("\n overlap dif 1: %d\n", it);
        //printf("s1_len - max_overlap[0] + 1: %d\n", s1_len - max_overlap[0] + 1);
        //char* s_copy = (char*)calloc((s1_len - max_overlap[0] + 1),sizeof(char));
        char* s_copy = (char*)calloc((strlen(lista[max_overlap[2]]) + strlen(lista[max_overlap[3]])  + 1),sizeof(char));
        //printf("passou calloc\n");
        // AQUI TÁ SEM O + 1
        strncpy(s_copy, lista[max_overlap[2]], s1_len - max_overlap[0]);
        //printf("lista[max_overlap[2]]  %s\n", lista[max_overlap[2]]);
        //printf("s_copy %s\n", s_copy);
        //printf("s_copy %d\n", strlen(s_copy));
        //concatenando e limpando as ja usadas
        strcat(s_copy, lista[max_overlap[3]]);
        //printf("s_copy cat %s\n", s_copy);
        //printf("s_copy cat %d\n", strlen(s_copy));
        //printf("max_overlap[3] %d\n", max_overlap[3]);
        //printf("max_overlap[2] %d\n", max_overlap[2]);
        lista[max_overlap[3]] = NULL;
        lista[max_overlap[2]] = NULL;

        arruma_lista(&lista, max_overlap[2], s_copy);

        //free(s_copy);

        //print(lista, N);
    }

    it++;
    return it;
}

int main(void){

    //numero de reads
    int N;
    scanf("%d", &N);
    getchar();
    char** lista = (char**)malloc(N*sizeof(char*));
    palavra(N, &lista);

    //numero de iteracoes na funcao de concatenar
    int it = 0;
    while(it < N-1){
        it = concatenar(lista, N, it);
    }
    for(int i = 0; i < N; i++){
        if(lista[i] != NULL){
            printf("%s", lista[i]);
        }
    }

    for(int i = 0; i < N; i++){
        free(lista[i]);
    }
    free(lista);

    return 0;
}
