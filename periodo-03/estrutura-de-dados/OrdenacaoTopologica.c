#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
    struct No *prox;
} No;

typedef struct {
    int contador;
    No *prox;
} Cabeca;

typedef struct {
    int n;
    Cabeca *cb;
} Grafo;

void ordenacaoTopologica(Grafo g) {
    int fim = 0;
    int objeto;
    int indice;
    int i;
    No *pt;

    g.cb[0].contador = 0;

    for (i = 1; i <= g.n; i++) {
        if (g.cb[i].contador == 0) {
            g.cb[fim].contador = i;
            fim = i;
        }
    }

    objeto = g.cb[0].contador;

    while (objeto != 0) {
        printf("%d ", objeto);

        pt = g.cb[objeto].prox;

        while (pt != NULL) {
            indice = pt->info;
            g.cb[indice].contador--;

            if (g.cb[indice].contador == 0) {
                g.cb[fim].contador = indice;
                fim = indice;
            }

            pt = pt->prox;
        }

        objeto = g.cb[objeto].contador;
    }
}
int main() {
    Grafo g;
    int m;
    int origem, destino; 
  
    scanf("%d %d", &g.n, &m);
    g.cb = malloc((g.n + 1) * sizeof(Cabeca));

    for (int i = 0; i <= g.n; i++) {
        g.cb[i].contador = 0; 
        g.cb[i].prox = NULL;
    }

   
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &origem, &destino);

        No *novo = malloc(sizeof(No));
        novo->info = destino;
        novo->prox = g.cb[origem].prox;
        g.cb[origem].prox = novo;
        g.cb[destino].contador++;
    }

    ordenacaoTopologica(g);

    free(g.cb);

    return 0;
}
