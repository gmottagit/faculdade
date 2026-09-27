#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX 100
typedef int bool;
typedef int TIPOCHAVE;
typedef struct {
	char nome[MAX];
	int seg;
	int prod;
	
} REGISTRO;
typedef struct aux {
	REGISTRO reg;
	struct aux* prox;
} ELEMENTO;
typedef ELEMENTO* PONT;
typedef struct {
	PONT inicio;
	PONT fim;
} FILA;
void inicializarFila(FILA* f) {
	f->inicio = NULL;
	f->fim = NULL;
}
int tamanho(FILA* f) {
	PONT end = f->inicio;
	int tam = 0;
	while (end != NULL) {
		tam++;
		end = end->prox;
	}
	return tam;
}

void exibirFila(FILA* f, int k) {
	PONT end = f->inicio;
	int agora = 0;
	while (end != NULL) {
		
		if(agora > end->reg.seg) agora = agora + (end->reg.prod * k) + 10;
		else agora = end->reg.seg + (end->reg.prod * k) + 10;
		printf("\n %s %d %d", end->reg.nome, end->reg.seg, agora);
		end = end->prox;
	}
	printf("\"\n");
}
bool inserirNaFila(FILA* f,REGISTRO reg) {
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	if (novo==NULL) return false;
	novo->reg = reg;
	novo->prox = NULL;
	if (f->inicio==NULL) f->inicio = novo;
	else f->fim->prox = novo;
	f->fim = novo;
	return true;
}
bool excluirDaFila(FILA* f, REGISTRO* reg) {
	if (f->inicio==NULL) return false;
	*reg = f->inicio->reg;
	PONT apagar = f->inicio;
	f->inicio = f->inicio->prox;
	free(apagar);
	if (f->inicio == NULL) f->fim = NULL;
	return true;
}
void reinicializarFila(FILA* f) {
	PONT end = f->inicio;
	while (end != NULL) {
		PONT apagar = end;
		end = end->prox;
		free(apagar);
	}
	f->inicio = NULL;
	f->fim;
}

int main(){
    FILA fila;
    inicializarFila(&fila);

	int k, c;
	printf("Digite a rapidez de atendimento do caixa: ");
	scanf("%d", &k);
	printf("Digite a o número de clientes: ");
	scanf("%d", &c);

	for(int i = 0; i < c; i++) {
	    REGISTRO reg;
		printf("Digite a descrição do cliente no formato \"NOME SEGUNDO_CHEGADA NUMERO_PRODUTOS\": ");
		scanf("%s %d %d", reg.nome , &reg.seg, &reg.prod);
		inserirNaFila(&fila, reg);
		
	}
	exibirFila(&fila, k);

	return 0;
}
