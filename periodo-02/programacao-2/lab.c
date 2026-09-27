#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
	int numero;
	char naipe;
} tCarta;

typedef struct aux {
	tCarta reg;
	struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;
typedef struct {
	PONT topo;
} PILHA;

void inicializarPilha(PILHA* p) {
	p->topo = NULL;
}

/*int tamanho(PILHA* p) {
	PONT end = p->topo;
	int tam = 0;
	while (end != NULL) {
		tam++;
		end = end->prox;
	}
	return tam;
}*/
/*bool estaVazia(PILHA* p) {
	if (p->topo == NULL)
		return true;
	return false;
*/
/*	void exibirPilha(PILHA* p) {
		PONT end = p->topo;
		printf("Pilha: \" ");
		while (end != NULL) {
			printf("%i ", end->reg.chave);
			end = end->prox;
		}
		printf("\"\n");
	}*/
	bool inserirElemPilha(PILHA* p, tCarta reg)
	{
		PONT novo = (PONT) malloc(sizeof(ELEMENTO));
		if (novo==NULL) return false;
		novo->reg = reg;
		novo->prox = p->topo;
		p->topo = novo;
		return true;
	}
	bool excluirElemPilha(PILHA* p, tCarta* reg)
	{
		if ( p->topo == NULL) return false;
		*reg = p->topo->reg;
		PONT apagar = p->topo;
		p->topo = p->topo->prox;
		free(apagar);
		return true;
	}
/*	void reinicializarPilha(PILHA* p) {
		PONT apagar;
		PONT posicao = p->topo;
		while (posicao != NULL) {
			apagar = posicao;
			posicao = posicao->prox;
			free(apagar);
		}
		p->topo = NULL;
	}

*/
	void exibeCarta(tCarta carta) {
		if(carta.numero >=2 && carta.numero <= 10)
			printf("%d", carta.numero);
		else {
			switch(carta.numero) {
			case 11:

				printf("Valete");
				break;

			case 12:

				printf("Dama");
				break;

			case 13:

				printf("Rei");
				break;

			case 1:

				printf("As");
				break;
			default: // 14

				printf("Invalida");

			}
		}
		printf(" de ");
		switch(carta.naipe) {
		case 'o':

			printf("Ouros\n");
			break;
		case 'c':

			printf("Copas\n");
			break;

		case 'p':
			printf("Paus\n");

			break;
		case 'e':
			printf("Espadas\n");
		}
	}

	void empilhaBaralho(PILHA * pilha) {
		for(int i = 1; i < 14; i++) {
			tCarta carta;
			carta.numero = i;
			carta.naipe = 'o';
			inserirElemPilha(pilha, carta);
		}
		for(int i = 1; i < 14; i++) {
			tCarta carta;
			carta.numero = i;
			carta.naipe = 'c';
			inserirElemPilha(pilha, carta);
		}
		for(int i = 1; i < 14; i++) {
			tCarta carta;
			carta.numero = i;
			carta.naipe = 'p';
			inserirElemPilha(pilha, carta);
		}
		for(int i = 1; i < 14; i++) {
			tCarta carta;
			carta.numero = i;
			carta.naipe = 'e';
			inserirElemPilha(pilha, carta);
		}
	}
int buscaCarta( PILHA *pilha, tCarta carta){
    int contador = 0;
    tCarta cartaPilha;
    while(excluirElemPilha(pilha, &cartaPilha)){
        if(carta.numero == cartaPilha.numero && carta.naipe == cartaPilha.naipe) return contador;
        contador ++;
    }
    return contador;
}

int main(){
   
    PILHA *pilha = (PILHA *)malloc(1*sizeof(PILHA));
    inicializarPilha(pilha);
    empilhaBaralho(pilha);
    tCarta carta;
    printf("digite o numero e o naipe da carta: ");
    scanf("%d ", &carta.numero);
    scanf("%c", &carta.naipe);
    exibeCarta(carta);
    int contador = buscaCarta(pilha, carta);
    printf("%d\n", contador);

    return 0;
}

