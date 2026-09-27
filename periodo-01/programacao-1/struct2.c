#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int tabuleiro[N];
	int resultado[N];


	for (int i = 0; i < N; i++) {
		scanf("%d", &tabuleiro[i]);
	}


	for (int i = 0; i < N; i++) {
		int soma = 0;


		if (i > 0)
			soma += tabuleiro[i - 1];


		soma += tabuleiro[i];


		if (i < N - 1)
			soma += tabuleiro[i + 1];

		resultado[i] = soma;
	}


	for (int i = 0; i < N; i++) {
		printf("[%d] ", resultado[i]);
	}

	return 0;
}