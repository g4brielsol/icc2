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

void palavra(int N, char** s){

    for(int i = 0; i < N; i++){
        s[i] = NULL;
        int pos = 0;
        do{
           s[i] = realloc(s[i], pos + 1);  //aloca a palavra de forma dinamica
           s[i][pos] = (char)fgetc(stdin);
           pos++;

        } while(s[i][pos - 1] != '\n');
        s[i][pos - 1] = '\0';
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

void arruma_lista(char** lista, int pos, char* s_copy){

    if(lista[0] == NULL){
        lista[0] = realloc(lista[0], strlen(s_copy)+1);
        strcpy(lista[0], s_copy);
    }else{
        //encontra o primeiro NULL da lista e realoca
        for(int i = pos; i > 0; i--){
            lista[i] = realloc(lista[i], strlen(lista[i-1])+1);
            strcpy(lista[i], lista[i-1]);
        }
        lista[0] = realloc(lista[0], strlen(s_copy)+1);
        strcpy(lista[0], s_copy);
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

    if(max_overlap[1] == 1){

        char* s_copy;

        if(s1_len > s2_len){

            s_copy = (char*)calloc(s1_len+1, sizeof(char));
            lista[max_overlap[3]] = NULL;
            strcpy(s_copy, lista[max_overlap[2]]);
            lista[max_overlap[2]] = NULL;

            int min;
            for(int i = 0; i < N; i++){
                if(lista[i] == NULL){
                    min = i;
                    break;
                }
            }

            arruma_lista(lista, min, s_copy);

            //free(s_copy);

        }else{

            s_copy = (char*)calloc(s2_len+1, sizeof(char));
            lista[max_overlap[2]] = NULL;
            strcpy(s_copy, lista[max_overlap[3]]);
            lista[max_overlap[3]] = NULL;

            int min;
            for(int i = 0; i < N; i++){
                if(lista[i] == NULL){
                    min = i;
                    break;
                }
            }

            arruma_lista(lista, min, s_copy);

            //free(s_copy);
        }
        //print(lista, N);
    }else{
        //caso final-começo

        char* s_copy = (char*)calloc((strlen(lista[max_overlap[2]]) + strlen(lista[max_overlap[3]])  + 1),sizeof(char));

        strncpy(s_copy, lista[max_overlap[2]], s1_len - max_overlap[0]);

        //concatenando e limpando as ja usadas
        strcat(s_copy, lista[max_overlap[3]]);
        lista[max_overlap[3]] = NULL;
        lista[max_overlap[2]] = NULL;

        int min;
        for(int i = 0; i < N; i++){
            if(lista[i] == NULL){
                min = i;
                break;
            }
        }

        arruma_lista(lista, min, s_copy);

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
    palavra(N, lista);

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
