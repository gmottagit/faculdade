
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

typedef struct No {
    struct No *esq;
    struct No *dir;
    char *info;
    int marcado;
} No;

No *criarNo() {
    No *novo = malloc(sizeof(No));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->info = NULL;
    novo->marcado = 0;
    return novo;
}

char *copiar(char *texto) {
    char *novo = malloc(strlen(texto) + 1);
    strcpy(novo, texto);
    return novo;
}

uint32_t converterIP(char *ip) {
    unsigned int a, b, c, d;

    sscanf(ip, "%u.%u.%u.%u", &a, &b, &c, &d);

    return ((uint32_t)a << 24) | ((uint32_t)b << 16) |
           ((uint32_t)c << 8) | d;
}

void inserir(No *raiz, uint32_t ip, int bits, char *info) {
    No *atual = raiz;

    for (int i = 0; i < bits; i++) {
        int bit = (ip >> (31 - i)) & 1;

        if (bit == 0) {
            if (atual->esq == NULL) atual->esq = criarNo();
            atual = atual->esq;
        } else {
            if (atual->dir == NULL) atual->dir = criarNo();
            atual = atual->dir;
        }
    }

    free(atual->info);
    atual->info = copiar(info);
    atual->marcado = 1;
}

void liberar(No *no) {
    if (no == NULL) return;

    liberar(no->esq);
    liberar(no->dir);
    free(no->info);
    free(no);
}

void unificar(No *no) {
    if (no == NULL) return;

    unificar(no->esq);
    unificar(no->dir);

    if (no->esq != NULL && no->dir != NULL &&
        no->esq->marcado && no->dir->marcado &&
        no->esq->esq == NULL && no->esq->dir == NULL &&
        no->dir->esq == NULL && no->dir->dir == NULL &&
        strcmp(no->esq->info, no->dir->info) == 0) {

        free(no->info);
        no->info = copiar(no->esq->info);
        no->marcado = 1;

        liberar(no->esq);
        liberar(no->dir);

        no->esq = NULL;
        no->dir = NULL;
    }
}

char *buscar(No *raiz, uint32_t ip, int *bits) {
    No *atual = raiz;
    char *melhor = raiz->info;
    *bits = raiz->marcado ? 0 : -1;

    for (int i = 0; i < 32; i++) {
        int bit = (ip >> (31 - i)) & 1;

        if (bit == 0) atual = atual->esq;
        else atual = atual->dir;

        if (atual == NULL) break;

        if (atual->marcado) {
            melhor = atual->info;
            *bits = i + 1;
        }
    }

    return melhor;
}

int separarLinha(char *linha, char *chave, char **info) {
    char *p = linha;

    while (isspace((unsigned char)*p)) p++;
    if (*p == '\0' || *p == '#') return 0;

    int i = 0;
    while (*p != '\0' && !isspace((unsigned char)*p)) {
        chave[i++] = *p++;
    }
    chave[i] = '\0';

    while (isspace((unsigned char)*p)) p++;

    int tamanho = strlen(p);

    while (tamanho > 0 && isspace((unsigned char)p[tamanho - 1])) {
        p[--tamanho] = '\0';
    }

    if (tamanho >= 2 && p[0] == '"' && p[tamanho - 1] == '"') {
        p[tamanho - 1] = '\0';
        p++;
    }

    *info = p;
    return 1;
}

int main() {
    int n;
    char linha[512], chave[64];
    char *info;

    scanf("%d", &n);
    fgets(linha, sizeof(linha), stdin);

    No *raiz = criarNo();

    for (int i = 0; i < n; ) {
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;
        if (!separarLinha(linha, chave, &info)) continue;

        char *barra = strchr(chave, '/');
        if (barra == NULL) continue;

        *barra = '\0';
        int prefixo = atoi(barra + 1);

        if (prefixo >= 0 && prefixo <= 32) {
            inserir(raiz, converterIP(chave), prefixo, info);
            i++;
        }
    }

    unificar(raiz);

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        if (!separarLinha(linha, chave, &info)) continue;

        int prefixo;
        char *resultado = buscar(raiz, converterIP(chave), &prefixo);

        printf("%s %d %s\n", chave, prefixo, resultado);
    }

    liberar(raiz);

    return 0;
}

