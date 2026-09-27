#include <stdio.h>
#include <stdlib.h>

int buscaBin(int arr[], int tam, int el, int *menor) {
	int fim = tam-1;
	int ini = 0;
	int meio = (fim + ini)/2;
	while (ini <= fim) {
		int meio = (fim + ini)/2;
		if (arr[meio] < el)
			ini = meio + 1;
		else {
			if (arr[meio] > el)
				fim = meio - 1;
			else return meio;
			
		}
	}
	if(arr[meio] < el && arr[meio +1] > el){
		(*menor)++;
		return meio;
	}
	return tam;
}
void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior) {
    int contador = 0;
	int meio = buscaBin(arr, tam, el, menor);
	while(contador < meio){
	   (*menor)++; 
	   contador ++;
	}
	while(contador < tam - 1){
	    (*maior)++; 
	   contador ++;
	}

}
int main()
{
 int *arr, tam, el, *menor, *maior;
 scanf("%d", &tam);
 scanf("%d", &el);
 arr = (int *)malloc(tam*sizeof(int));
 menor = (int *)calloc(1, sizeof(int));
 maior = (int *)calloc(1, sizeof(int));
 
 for(int i = 0; i < tam; i++) scanf("%d ", (arr+i));
 buscaMenorMaiorBin(arr, tam, el, menor, maior);
 printf("Menor: %d - Maior: %d ", *menor, *maior);
 
	return 0;
}
