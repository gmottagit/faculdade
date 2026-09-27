#include <stdio.h>
#include <stdlib.h>

int **aloca_linha(int a){
	int **matriz = (int**)malloc(a*sizeof(int*));
	return matriz;
}

int aloca_colunas(int **matriz, int lin, int col){
	for(int i = 0; i < lin; i++){
	*(matriz + i) = (int*)malloc(col*sizeof(int));
	if(*(matriz + i)== NULL) return 1;
	}
	return 0;
}

void le_dados(int **matriz, int lin, int col){
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++)
		{
			printf("Matriz[%d][%d]: ", i, j);
			scanf("%d", (*(matriz + i) +j));
		}
	}

}

void imprime_matriz(int **matriz, int lin, int col){
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++)
		{
			printf(" [%d] ", *(*(matriz + i) + j));
	
		}
	}

}


void troca_linhas (int **matriz, int linha1, int linha2){
	int *pon, *pon2;
	pon = *(matriz + linha1);
	pon2 = *(matriz + linha2);
	*(matriz + linha2) = pon;
	*(matriz + linha1) = pon2;
}

int main(void){
int **matriz;
int lin, col;
int linha1, linha2;

scanf("%d", &lin);
matriz = aloca_linha(lin);
if (matriz == NULL) return 1;
scanf("%d", &col);
if((aloca_colunas(matriz,lin,col))==1) return 1;
le_dados(matriz, lin, col);
imprime_matriz(matriz, lin, col);
scanf("%d", &linha1);
scanf("%d", &linha2);
troca_linhas(matriz, linha1, linha2);
printf("\n");
imprime_matriz(matriz, lin, col);
return 0;
}
