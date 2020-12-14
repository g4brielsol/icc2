#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void palavra(int N, char*** s){
    //recebe a lista de char e a quantidade de palavras a ler
    for(int i = 0; i < N; i++){
        (*s)[i] = NULL;
        int pos = 0;
        do{
            // lê letra por letra
           (*s)[i] = realloc((*s)[i], pos + 1);  //aloca a palavra de forma dinamica
           (*s)[i][pos] = (char)fgetc(stdin);
           pos++;
        /// enquanto nao tiver acabado a linha
        } while((*s)[i][pos - 1] != '\n');
        // escreve \0 ao fim da palavra
        (*s)[i][pos - 1] = '\0';
    }
}

void overlap(int retorno[], char* s1, char* s2){
    // recebe o aux, lista[i] e lista[j]
    // retorna se nao houver lista[i] ou lista[j]
    if(s1 == NULL || s2 == NULL){
        retorno[0] = -1;
        retorno[1] = -1;
        return;
    }

    // tamanho da lista[i]
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    // tamanho da lista[i]
    int max_1 = 0;
    int max_2 = 0;
    int aux;
    //int overlili = 0;
    //armazena o tamanho da menor string em s
    int s;
    if(s1_len > s2_len){
        s = s2_len;
    }else{
        s = s1_len;
    }
    // para i até o tamanho da menor string
    for(int i = 0; i < s; i++){
        aux = 0;
        // para o tamanho de j menor que o tamanho de i
        for(int j = 0; j <=i; j++){
            //printf("%d\n", overlili++);
            // se o tamanho de lista[i][tamanho lista i - 1 - i + j]
            // se o valor de lista[i] != lista[j]
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
    // mexe no tamanho do auxiliar
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
        printf("\narrumar lista [0]\n");
        (*lista)[0] = realloc((*lista)[0],(strlen(s_copy)));
        //(*lista)[0] = (char*) calloc(100,sizeof(char));
        printf("lista 0 len %d\n", strlen(*lista[0]));
        printf("s_copy len %d\n", strlen(s_copy));
        memcpy((*lista)[0], s_copy, (strlen(s_copy) * sizeof(int)));
        printf("lista 0 %s\n", *lista[0]);
        printf("s_copy %s\n", s_copy);
    }
    else{
        printf("\narrumar lista else\n");
        //encontra o primeiro NULL da lista
        for(int i = pos; i > 0; i--){
            (*lista)[i] = realloc((*lista)[i], strlen((*lista)[i-1])+1);
            printf("(*lista)[i-1] %s\n", (*lista)[i-1]);
            strcpy((*lista)[i], (*lista)[i-1]);
            printf("(*lista)[i] %s\n", (*lista)[i]);
        }
        if((*lista)[0])
        {
            printf("teste 1");
            printf("(*lista)[0] %d\n", (*lista)[0]);
        }
        else
        {
            printf("teste 2");
            printf("s_copy %s\n", s_copy);
        }
        (*lista)[0] = realloc((*lista)[0], strlen(s_copy)+1);
        printf("(*lista)[0] %s\n", (*lista)[0]);
        printf("s_copy %s\n", s_copy);
        strcpy((*lista)[0], s_copy);
    }
    // free((*lista)[0]);
    return;
}

int concatenar(char** lista, int N, int it){
    // recebe a lista de palavras, quantidade de palavras e o iterador it

    int max_overlap[4] = {-1,-1,-1,-1};
    int aux[2] = {-1,1};
    // para o i menor que o tamanho N
    //int overlala=0;
    for(int i = 0; i < N; i++){
        // para o j menor que o tamanho N
        for(int j = 0; j < N; j++){
            // se nao for o mesmo indice de N
            if(j!=i){
                // passa o aux[2], lista[i], lista[j]
                overlap(aux, lista[i], lista[j]);
                //printf("%d %d - %s %s - OL = %d - C = %d\n", i, j, lista[i], lista[j], aux[0], aux[1]);
                if(aux[0] > max_overlap[0]){
                    // maximo tamanho de overlap 1 == menor tamanho da lista
                    max_overlap[0] = aux[0];
                    // posicao final comeco ou substring
                    max_overlap[1] = aux[1];
                    // indice das palavras que concatenam
                    max_overlap[2] = i;
                    max_overlap[3] = j;
                }
            }
        }
    }
    //printf("Overlap: %d, Caso: (%d), Par: (%d,%d)\n", max_overlap[0], max_overlap[1], max_overlap[2], max_overlap[3]);

    // tamanho das palavras que concatenam
    int s1_len = strlen(lista[max_overlap[2]]);
    int s2_len = strlen(lista[max_overlap[3]]);

    //caso substring
    //nao acrescenta em nada o problema, pois nao aumentara nem um caracter em nenhum momento do programa
    //entao podemos eliminar

    int min;
    // menor tamanho da lista e posicao substring
    if(max_overlap[2] > max_overlap[3]){
        min = max_overlap[3];
    }else{
        min = max_overlap[2];
    }
    //
    if(max_overlap[1] == 1){

        char* s_copy;
        // se palavra 1 maior que a 2
        if(s1_len > s2_len){
            printf("\noverlap 1 s1 maior %d\n", it);
            s_copy = (char*)calloc(s1_len+1, sizeof(char));
            lista[max_overlap[3]] = NULL;
            //printf("s copy len %s\n", strlen(s_copy));
            //printf("lista[max_overlap[2]] len %s\n", strlen(lista[max_overlap[2]]));
            strcpy(s_copy, lista[max_overlap[2]]);
            printf("s copy %s\n", s_copy);
            lista[max_overlap[2]] = NULL;
            arruma_lista(&lista, min, s_copy);
            //free(s_copy);
        }else{
                printf("\noverlap 1 s2 maior %d\n", it);
            s_copy = (char*)calloc(s2_len+1, sizeof(char));
            lista[max_overlap[2]] = NULL;
            strcpy(s_copy, lista[max_overlap[3]]);
            lista[max_overlap[3]] = NULL;

            arruma_lista(&lista, min, s_copy);

            //free(s_copy);
        }
        //print(lista, N);
    }else{
        printf("\n overlap dif 1 %d\n", it);
        //caso final-come�o

        printf("s1_len - max_overlap[0] + 1 %d\n", s1_len - max_overlap[0] + 1);
        
        char* s_copy = (char*)calloc((s1_len - max_overlap[0] + 1),sizeof(char));
        printf("passou calloc\n");
        if(it > 0)
        {
            s_copy = realloc(s_copy, (s1_len - max_overlap[0] + 1));
        }
        //printf("lista[max_overlap[2]] len %d\n", strlen(lista[max_overlap[2]]));
        //printf("s_copy len %d\n", s1_len - max_overlap[0]);
        // FALTAVA O +1 AQUI
        strncpy(s_copy, lista[max_overlap[2]], s1_len - max_overlap[0] + 1);
        printf("lista[max_overlap[2]]  %s\n", lista[max_overlap[2]]);
        printf("s_copy %s\n", s_copy);
        printf("s_copy %d\n", strlen(s_copy));
        //concatenando e limpando as ja usadas
        strcat(s_copy, lista[max_overlap[3]]);
        printf("s_copy cat %s\n", s_copy);
        printf("s_copy cat %d\n", strlen(s_copy));
        printf("max_overlap[3] %d\n", max_overlap[3]);
        printf("max_overlap[2] %d\n", max_overlap[2]);
        lista[max_overlap[3]] = NULL;
        lista[max_overlap[2]] = NULL;

        arruma_lista(&lista, max_overlap[2], s_copy);

        free(s_copy);
        
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
    // cria um vetor de char
    char** lista = (char**)malloc(N*sizeof(char*));
    // lê a quantidade de palavras
    palavra(N, &lista);

    //numero de iteracoes na funcao de concatenar
    int it = 0;
    while(it < N-1){
        it = concatenar(lista, N, it);
    }
    for(int i = 0; i < N; i++){
        // se nao for null
        if(lista[i] != NULL){
            // printa a concatenacao
            printf("%s", lista[i]);
        }
    }

    // libera tudo
    for(int i = 0; i < N; i++){
        free(lista[i]);
    }
    free(lista);

    return 0;
}
