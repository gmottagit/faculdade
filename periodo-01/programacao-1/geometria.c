#include <stdio.h>
#include <math.h>

//Formas Básicas:

float area_quadrado(float lado) {
    return lado*lado; //lado * lado funciona também
}

float area_retangulo(float base, float altura) {
    return base*altura;
}

float area_circulo(float raio) {
    return M_PI * raio * raio;
}
float area_triangulo(float l1, float l2, float l3) {
    float p = (l1 + l2 + l3) / 2;
    return sqrt(p * (p - l1) * (p - l2) * (p - l3));
}
float circunferencia(float raio) {
    return M_PI * raio * 2;
}


//Formas tridimensionais:

float area_cubo(float l) {
//A área do cubo é o somatório da área de suas 6 faces.
    return 6*area_quadrado(l);
}

float area_cone(float g, float raio) {
    float areaCirculo = area_circulo(raio);
    return (M_PI * raio * g) + areaCirculo;//Area do cone é igual a soma da área da base com a área lateral.
}

//cálculo de um prisma de base retangular:
float area_prisma(float base, float lado, float altura) {
    float areaRetanguloBase = area_retangulo(base, lado);
    float areaRetanguloLat = area_retangulo(lado, altura);
    return (2*areaRetanguloBase) + (4*areaRetanguloLat);
}

//cálculo de uma pirâmide de base quadrada:
float area_piramide(float l1, float l2, float l3,float lado) {
    float areaLateral = area_triangulo(l1, l2, l3);
    float areaBase = area_quadrado(lado);
    return (4*areaLateral) + areaBase;
}

float area_cilindro(float raio, float altura) {
    float areaCirculo = area_circulo(raio);
    float circ = circunferencia(raio);
    return (2 * areaCirculo) + (circ * altura);
}

int main()
{

    float lado, raio, geratriz, altura, base, l1, l2, l3 ; //Variáveis para receber os valores e calcular a área.

    printf ("---Área do quadrado---\n");
    printf("Digite a medida do lado do quadrado:");
    scanf("%f", &lado);
    printf("Area quadrado: %f", area_quadrado(lado));

    printf ("---Área do retângulo---\n");
    printf("Digite a medida da base do retângulo:");
    scanf("%f", &base);
    printf("Digite a medida da altura do retângulo:");
    scanf("%f", &altura);
    printf("Area retângulo: %f", area_retangulo(base, altura));

    printf ("---Área do circulo---\n");
    printf("Digite a medida do raio:");
    scanf("%f", &raio);
    printf("Area circulo: %f", area_circulo(raio));

    printf ("---Área do triângulo---\n");
    printf("Digite a medida da l1 do triângulo:");
    scanf("%f", &l1);
    printf("Digite a medida da l2 do triângulo:");
    scanf("%f", &l2);
    printf("Digite a medida da l3 do triângulo:");
    scanf("%f", &l3);
    printf("Area triângulo: %f", area_triangulo(l1, l2, l3));

    printf ("---Área do cubo---\n");
    printf("Digite a medida do lado do cubo:");
    scanf("%f", &lado);
    printf("Area cubo: %f", area_cubo(lado));

    printf("\n---Area do cone---\n");
    printf("Digite a medida da geratriz do cone:");
    scanf("%f", &geratriz);
    printf("Digite a medida do raio do cone:");
    scanf("%f", &raio);
    printf("Area cone: %f", area_cone(geratriz, raio));

    printf("\n---Area do prisma---\n");
    printf("Digite a medida da base do prisma:");
    scanf("%f", &base);
    printf("Digite a medida da lado do prisma:");
    scanf("%f", &lado);
    printf("Digite a medida da altura do prisma:");
    scanf("%f", &altura);
    printf("Area prisma: %f", area_prisma(base, lado, altura));

    printf("\n---Area da pirâmide---\n");
    printf("Digite a medida do lado da base da piramide:");
    scanf("%f", &lado);
    printf("Digite a medida da l1 do triângulo:");
    scanf("%f", &l1);
    printf("Digite a medida da l2 do triângulo:");
    scanf("%f", &l2);
    printf("Digite a medida da l3 do triângulo:");
    scanf("%f", &l3);
    printf("Area piramide: %f", area_piramide(l1, l2, l3, lado));

    printf("\n---Area do cilindro---\n");
    printf("Digite a medida do raio do cilindro:");
    scanf("%f", &raio);
    printf("Digite a medida da altura do cilindro:");
    scanf("%f", &altura);
    printf("Area cilindro: %f", area_cilindro(raio, altura));

    return 0;
}
