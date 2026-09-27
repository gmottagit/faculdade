
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int validaTelefone(char numero[]) {
    int len = strlen(numero);
    if (len == 8 || len == 9 || len == 10 || len == 11) {
        return 1; // Válido
    } else {
        return 0; // Inválido
    }
}

int removeDDD(char numero[]) {
    int len = strlen(numero);
    int numeroFinal;
    if (validaTelefone(numero) == 1) {
        if (len == 10 || len == 11) {
            
            numeroFinal = atoi(&numero[2]);
        } else {
            numeroFinal = atoi(numero);
        }
        return numeroFinal;
    } else {
        return 0;
    }
}

int recebeDDD(char numero[]) {
    char DDD[3];  
    int len = strlen(numero);

    if (validaTelefone(numero)) {
        if (len == 10 || len == 11) {
            DDD[0] = numero[0];  
            DDD[1] = numero[1];  
            DDD[2] = '\0';      
            return atoi(DDD);   
        } else {
            return 0;  
        }
    } else {
        return 0;  
    }
}
int main() {
    char t1[] = "21945732485"; //Celular com DDD
    char t2[] = "40028922"; //Telefone sem DDD
    char t3[] = "271283"; //Número invalido

printf("--- Validar telefone ---\n");
printf("Entrada: %s\nSaida: %d\nEsperado: %d\n\n", t1, validaTelefone(t1), 1 );
printf("Entrada: %s\nSaida: %d\nEsperado: %d\n\n", t2, validaTelefone(t2), 1 );
printf("Entrada: %s\nSaida: %d\nEsperado: %d\n\n", t3, validaTelefone(t3), 0 );

printf("--- Removendo DDD ---\n");
printf("Entrada: %s\nSaida: %d\nEsperado: %d\n\n", t1, removeDDD(t1), 945732485 );
printf("Entrada: %s\nSaida: %d\nEsperado: %d\n\n", t2, removeDDD(t2), 40028922 );
printf("Entrada: %s\nSaida: %d\nEsperado: %d\n\n", t3, removeDDD(t3), 0 );

printf("--- Recebendo DDD ---\n");
printf("Entrada: %s\nSaida: %d\nEsperado: %d\n\n", t1, recebeDDD(t1), 21);
printf("Entrada: %s\nSaida: %d\nEsperado: %d\n\n", t2, recebeDDD(t2), 0);
printf("Entrada: %s\nSaida: %d\nEsperado: %d\n\n", t3, recebeDDD(t3), 0);
    return 0;
}