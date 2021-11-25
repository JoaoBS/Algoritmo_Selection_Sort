#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[]) {
	
	int vetor[1000];
	int i, j, min, aux;
	FILE* arquivo;
	
	arquivo = fopen("Ordenado.txt", "w");
	
	srand(time(NULL));
	
	printf("Desordenado:\n");
	fprintf(arquivo, "%s:\n", "Desordenado");
	
	for(i = 0; i < 1000; i++) {
		vetor[i] = rand() % 1000;
		printf("%d ", vetor[i]);
		fprintf(arquivo, "%d ", vetor[i]);
	}
	
	printf("\n============================================================\n");
	
	printf("Ordenado:\n");
	fprintf(arquivo, "\n\n%s\n", "Ordenado:");
	
	for(i = 0; i < sizeof(vetor)/sizeof(int); i++) {
		min = i;
		j = i + 1;
		for(j; j < sizeof(vetor)/sizeof(int); j++) {
			if(vetor[j] < vetor[min]) {
				min = j;
			}
		}
		if(vetor[i] != vetor[min]) {
			aux = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = aux;
		}
		
		printf("%d ", vetor[i]);
		fprintf(arquivo, "%d ", vetor[i]);
	}
	
	return 0;
}
