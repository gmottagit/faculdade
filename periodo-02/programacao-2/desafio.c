#include <stdio.h>
#include <stdlib.h>

// bubble sort,insertion sort e selection sort.
void bolha(int v[], int tam)
{
    int ult = tam - 1, i, aux;
    if (ult == 0)
    {
        return;
    }
    for (i = 0; i < ult; i++)
        if (v[i] > v[i + 1])
        {
            aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
        }
    bolha(v, tam - 1);
}

void insercao(int v[], int tam, int i)
{
    int aux, j;
    if (i == tam)
    {
        return;
    }

    aux = v[i];
    j = i;
    while ((j > 0) && (aux < v[j - 1]))
    {
        v[j] = v[j - 1];
        j--;
    }
    v[j] = aux;
    insercao(v, tam, i + 1);
}

void selecao(int v[], int tam, int i)
{
    int p, aux, posMenor;
    if (i == tam - 1)
        return;
    posMenor = i;
    for (p = i + 1; p < tam; p++)
        if (v[p] < v[posMenor])
            posMenor = p;
    aux = v[i];
    v[i] = v[posMenor];
    v[posMenor] = aux;
    selecao(v, tam, i + 1);
}

int main()
{
    int numero, i = 0;
    printf("Insira a quantidade de elementos na Lista: ");
    scanf("%d", &numero);
    int *lista = (int *)malloc(numero * sizeof(int));
    for (int i = 0; i < numero; i++)
    {
        printf("[%d] = ", i);
        scanf("%d", &lista[i]);
    }

    //PARA TESTAR, DESCOMENTE AS FUNÇOES DE ORDENAÇÃO
    // bolha(lista, numero);
    // insercao(lista, numero, i);
    //insercao(lista, numero, i);

    printf("Lista ordenada:\n");
    for (int i = 0; i < numero; i++)
    {
        printf("[%d]\n", lista[i]);
    }
    return 0;
}