/*A sua primeira tarefa é
escrever um programa que descubra qual atleta obteve o
menor tempo total durante o treinamento. O



*/
#include <stdio.h>
#define max 100
#include <string.h>
typedef struct{

char nome[max];
int tempo;
}atleta;



int main(){
	char nome[max];
	char nomearquivo[max];
	int segundosMin = 99999, seg, min, hor, segundoI = 0;
	int atletas, corridas;
	FILE *parq;
	
	printf("Digite nome do arquivo:\n");
	scanf("%99s", nomearquivo);
	
	parq=fopen(nomearquivo, "r");
	if(parq==NULL)
	{
		printf("Erro na abertura do arquivo");
		return -1;
	}
	fscanf(parq, "%d %d\n", &atletas, &corridas);
	atleta pessoa[atletas];
		
		for(int i = 0; i < atletas; i++){
			fscanf(parq, "%s ", nome);
			for(int j = 0; j < corridas; j++){
				fscanf(parq, "%d %d %d", &hor, &min, &seg);
				segundoI = segundoI + seg + ((min*60) + (hor*3600)); 
			
			}
		strcpy(pessoa[i].nome, nome);
		pessoa[i].tempo = segundoI;
		segundoI = 0;
		}
	
		
		atleta atletaMax = pessoa[0];
	int cindice = 0;
	for(int i = 0; i < atletas; i++){
		
		if(pessoa[i].tempo < pessoa[cindice].tempo){
			cindice = i;
		}
	}
	printf("%s = %d segundos", pessoa[cindice].nome, pessoa[cindice].tempo);
	fclose(parq);
}





