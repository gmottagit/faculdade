#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void formato_data(char data[9], char resultado[]) {
   
    resultado[0] = '\0';

   
    int xx = (data[0] - '0') * 10 + (data[1] - '0'); 
    int yy = (data[3] - '0') * 10 + (data[4] - '0');
    int zz = (data[6] - '0') * 10 + (data[7] - '0');

    // dd/mm/yy
    if (xx >= 1 && xx <= 31 && yy >= 1 && yy <= 12) {
        strcat(resultado, "dd/mm/yy");
    }

    // mm/dd/yy
    if (xx >= 1 && xx <= 12 && yy >= 1 && yy <= 31) {
        if (strlen(resultado) > 0) strcat(resultado, " ");
        strcat(resultado, "mm/dd/yy");
    }

    // yy/mm/dd
    if (yy >= 1 && yy <= 12 && zz >= 1 && zz <= 31) {
        if (strlen(resultado) > 0) strcat(resultado, " ");
        strcat(resultado, "yy/mm/dd");
    }
}
int main() {
    char resultado[50];
    char d1[] = "98/25/07";
    char d2[] = "01/01/00";
    char d3[] = "00/10/01";
    
    formato_data(d1, resultado);
    printf("Entrada: %s\nSaida: %s\nEsperado: %s\n\n", d1, resultado, "");
    
    formato_data(d2, resultado);
    printf("Entrada: %s\nSaida: %s\nEsperado: %s\n\n", d2, resultado, "dd/mm/yy mm/dd/yy");
    
    formato_data(d3, resultado);
    printf("Entrada: %s\nSaida: %s\nEsperado: %s\n\n", d2, resultado, "yy/mm/dd");
    
    return 0;
}
