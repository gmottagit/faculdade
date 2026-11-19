#include <stdio.h>

int buscar(int x, int pai[], int nome[]) {
    int y = x;

    while (pai[y] != 0) {
        y = pai[y];
    }

    return nome[y];
}

void fundir(int a, int b, int raiz[], int tam[], int pai[], int nome[]) {
    int ra = raiz[a];
    int rb = raiz[b];
    int aux;

    if (tam[a] < tam[b]) {
        aux = ra;
        ra = rb;
        rb = aux;
    }

    pai[rb] = ra;
    nome[ra] = a;
    tam[a] = tam[a] + tam[b];
    raiz[a] = ra;
    raiz[b] = 0;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int raiz[n + 1], tam[n + 1], pai[n + 1], nome[n + 1];

    for (int i = 1; i <= n; i++) {
        raiz[i] = i;
        tam[i] = 1;
        pai[i] = 0;
        nome[i] = i;
    }

    int u, v, peso;
    int conjuntoU, conjuntoV;
    int quantidade = 0;
    long long soma = 0;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &peso);

        conjuntoU = buscar(u, pai, nome);
        conjuntoV = buscar(v, pai, nome);

        if (conjuntoU != conjuntoV) {
            soma += peso;
            fundir(conjuntoU, conjuntoV, raiz, tam, pai, nome);
            quantidade++;
        }

        if (quantidade == n - 1) {
            break;
        }
    }

    printf("%lld\n", soma);

    return 0;
}
