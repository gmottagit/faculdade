#include <stdio.h>

typedef struct {
	int mat;
	int idade;
	float notas[3];
} tAluno;

int retornaQTD(float vetor[], int tamanho, float n) {
	int qtd = 0;
	for(int i = 0; i < tamanho; i++) {
		if(vetor[i] <= n) {
			qtd++;
		}
	}
	return qtd;
}

int retornaIndice(float medias[], int tamanho) {
	float maiorMedia = medias[0];
	int indiceMaior = 0;
	for(int i = 1; i < tamanho; i++) {
		if(medias[i] > maiorMedia) {
			maiorMedia = medias[i];
			indiceMaior = i;
		}
	}
	return indiceMaior;
}

float media(tAluno a) {
	return (a.notas[0] + a.notas[1] + a.notas[2]) /3;
}

float mediaTurma(float medias[], int tamanho) {
	float mediaTotal = 0.0;
	for(int i = 0; i < tamanho; i++) {
		mediaTotal += medias[i];
	}
	return mediaTotal/tamanho;
}

int lerTurma(tAluno turma[], int tamanho) {
	int opcao = 1;
	int qtd = 0;

	for (int i = 0; i < tamanho && opcao; i++) {
		printf("Digite a matricula:\n");
		scanf("%d", &turma[i].mat);

		printf("Digite a idade:\n");
		scanf("%d", &turma[i].idade);

		printf("Digite a nota1:\n");
		scanf("%f", &turma[i].notas[0]);

		printf("Digite a nota2:\n");
		scanf("%f", &turma[i].notas[1]);

		printf("Digite a nota3:\n");
		scanf("%f", &turma[i].notas[2]);

		qtd++;

		printf("Deseja continuar (1 = sim, 0 = nao)? ");
		scanf("%d", &opcao);
	}

	return qtd;
}


int main()
{	tAluno turma[10];
	float medias[10];
	int qtdAlunos = 0;
	printf("Digite a quantidade de alunos:\n");
	scanf("%d", &qtdAlunos);
	qtdAlunos = lerTurma(turma, qtdAlunos);

	for (int i = 0; i < qtdAlunos; i++) {
		medias[i] = media(turma[i]);
	}
	float mediaGeral = mediaTurma(medias, qtdAlunos);
	int indiceMaior = retornaIndice(medias, qtdAlunos);
	int abaixoMedia = retornaQTD(medias, qtdAlunos, mediaGeral);

	printf("Media da turma: %.2f\n", mediaGeral);
	printf("Aluno com maior media:\n");
	printf("  Matricula: %d\n", turma[indiceMaior].mat);
	printf("  Media: %.2f\n", medias[indiceMaior]);
	printf("Quantidade de alunos abaixo da media: %d\n", abaixoMedia);
	return 0;
}