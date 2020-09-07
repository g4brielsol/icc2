//inclui funções de arquivos, exibição e leitura
#include <stdio.h>
//inclui funções de alocação dinâmica de memória
#include <stdlib.h>
#include <string.h>

void main(){
    //char *metodo = (char *) malloc(20*sizeof(char));;
    char metodo[20];
    int elementos;
    FILE *fp;
    fp = fopen("in.txt", "r");
    //lê-se o método
    fscanf(fp, "%s", metodo);
    //lê-se o número de elementos
    fscanf(fp, "%d", &elementos);
    //int quantidade[elementos];
    printf("%s\n", metodo);
    printf("%d\n", elementos);
    int lista[elementos];

    for(int i=0; i < elementos; i++)
    {
        fscanf(fp, "%d",&lista[i]);
    }

    for (int i = 0; i < elementos; i++){
        printf("Number is: %d\n", lista[i]);
    }

    fclose(fp);


}