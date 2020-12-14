#include <stdio.h>
#include <string.h>

int tamanho_string = 1000;

void substr(char *str, char *sub, int pos0,int len) {
	// passa a string, o char, o i e o tamanho para a funcao
	int i = 0;
	// enquanto o i for menor que o tamanho len
	while(i < len) {
		// o char sera igual a lista posicao i + pos0
		sub[i] = str[i+pos0];
		i++;
	}
	sub[i] = '\0';
}

void sobrepor(char *str1, char *str2, int *overlap, char *resultado) {
	// passa a combinacao lista[i], lista[j], endereco do vetor com qtd de combinacoes e 
	// linha da matriz de combinacoes (pos++)
	// tamanho da lista[i]
	int len1 = strlen(str1);
	// tamanho da lista[j]
	int len2 = strlen(str2);
	
	// se for de tamanho diferente
	if(len1 != len2) {
		char *strMenor;
		char *strMaior;
		int lenMaior;
		int lenMenor;
		// se lista[i] > lista[j] 
		if(len1 > len2) {
			// strMaior = lista[i]
			strMaior = str1;
			// lenMaior = tamanho da lista[i]
			lenMaior = len1;	
			// strMenor = lista[j]
			strMenor = str2;
			// lenMenor = tamanho da lista[j]
			lenMenor = len2;
		} else {
			// strMaior = lista[j]
			strMaior = str2;
			// lenMaior = tamanho lista[j]
			lenMaior = len2;
			// strMenor = lista[i]
			strMenor = str1;
			// lenMenor = tamanho lista[i]
			lenMenor = len1;
		}
		 // char com tamanho do menor
		char sub[lenMenor];
		int i = 0;
		// enquanto o tamanho menor + i for menor que o tamanho maior
		while(i+lenMenor < lenMaior) {
			// passa a string maior, o char de tamanho menor, o i e o tamanho menor para a funcao
			substr(strMaior, sub, i, lenMenor);
			// se o char sub de tamanho menor for igual a string menor
			if(strcmp(sub, strMenor) == 0) {
				// a posicao atual do vetor com frases é igual ao tamanho menor
				*overlap = lenMenor;
				// copia a string maior para o a posicao da matriz frase
				strcpy(resultado, strMaior);
				// volta para a funcao main
				return;
			}
			// soma o i para o while
			i++;
		}
	}
	// char com tamanho da lista[i]
	char sub1[len1];
	// char com tamanho da lista[j]
	char sub2[len2];
	// i = 	tamanho da lista[i] - 1
	int i = len1-1;
	// posicao atual de overlap = 0
	*overlap = 0;
	int overlapTeste = 1;
	// enquanto i for maior ou igual a zero e overlapTeste menor ou igual a tamanho da lista[j]
	while(i >= 0 && overlapTeste <= len2) {
		//passa a lista[i], char com tamanho da lista[i], i, overlapTeste
		substr(str1, sub1, i, overlapTeste);
		//passa a lista[j], char com tamanho da lista[j], 0, overlapTeste
		substr(str2, sub2, 0, overlapTeste);
		// se os char foresm iguais, a posicao do overlap = a do overlapTeste
		if(strcmp(sub1, sub2) == 0) {
			*overlap = overlapTeste;
		}
		overlapTeste++;
		i--;
	}
	
	int j=0;
	i = 0;
	// enquanto o i for menor que o tamanho de lista[i]
	while(i < len1) {
		// o indice do vetor frase vai ser igual ao da lista[i]
		resultado[j] = str1[i];
		j++;
		i++;
	} 
	// igual ao valor do indice de overlap[pos] atual
	i = *overlap;
	// enquanto i for menor que o tamanho do lista[j]
	while(i < len2) {
		// o indice do vetor frase vai ser igual ao da lista[i]
		resultado[j] = str2[i];
		j++;
		i++;
	}
	resultado[j] = '\0';
}

int fatorial(int n) {
	if(n <= 1) {
		return 1;
		
	} else {
		return n*fatorial(n-1);
	}
}

int main(void) {
	
	int n, i, j;
	// quantidaade de palavras
	scanf("%d", &n);
	
	// lista com n palavras de tamanho 1000
	char str[n][tamanho_string];
	// lê as palavras
	for(i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	
	// tamanho de combinações de palavras
	int tam_overlap = n*(n-1);
	
	// vetores com o tamanho de combinacoes
	int overlap[tam_overlap], x[tam_overlap], y[tam_overlap];
	// matriz para armazenar as combinacoes de frase com limite de 1000 caracteres
	char frase[tam_overlap][tamanho_string];
	
	int maior;
	// enquanto existir quantidade de combinações
	while(tam_overlap > 0) {
		int pos = 0;
		// quantidade menor que N palavras
		for(i = 0; i < n; i++) {
			// quantidade menor que N palavras
			for(j = 0; j < n; j++) {
				// se não for a mesma posicao de combinacao
				if(i != j) {
						  // lista[i], lista[j]
					// passa a combinacao i, j, endereco do vetor com qtd de combinacoes e 
					// linha da matriz de combinacoes (pos++)
					sobrepor(str[i], str[j], &overlap[pos], frase[pos]);
					// armazena o indice de combinacoes no x e y
					x[pos] = i;
					y[pos] = j;
					pos++;
				}
			}
		}
		maior = 0;
		for(i = 1; i < tam_overlap; i++) {
			// se o tamanho do vetor naquele indice for maior que o ultimo registrado, salva
			if(overlap[i] > overlap[maior]) {
				maior = i;
			}
		}
		
		// matriz para armazenar n-1 frases
		char aux[n-1][tamanho_string];
		//copia a maior frase pro primeiro indice de aux
		strcpy(aux[0], frase[maior]);
		pos = 1;
		for(i = 0; i < n; i++) {
			// se p i nao for igual tanto no x quanto no y
			if(i != x[maior] && i != y[maior]) {
				// copia a frase da matriz inicial com os valores lidos no scanf
				strcpy(aux[pos], str[i]);
				pos++;
			}
		}
		// diminui a quantidade de elementos lidos
		n = n-1;
		for(i = 0; i < n; i++) {
			// copia o elemento auxiliar no vetor de armazenamento inicial
			strcpy(str[i], aux[i]);
		}
		// diminui o tamanho do overlap
		tam_overlap = n*(n-1);
		printf("%d\n", tam_overlap);
	}
	
	printf("%s", frase[maior]);
	
	return 0;
}
