#include <stdio.h>
#include "conta.h"


void rodar_testes_automaticos() {
    int status;
    long long valor;

    printf("=== TESTES AUTOMATICOS VOIDBANK ===\n\n");

    // 1. Depósito seguido de consulta
    printf("Teste 1: Depósito seguido de consulta\n");
    valor = 10000; // 100 reais
    status = depositar(valor);
    if (status == OK)
        printf("Depósito de R$ %.2f realizado.\n", valor / 100.0);
    else
        printf("Erro no depósito.\n");

    printf("Valor esperado: R$100\n");
    printf("Saldo atual conta corrente: R$ %.2f\n\n", saldo_corrente() / 100.0);

    // 2. Saque acima do saldo (não gera registro)
    printf("Teste 2: Saque acima do saldo\n");
    valor = 20000; // 200 reais, maior que saldo
    status = sacar(valor);
    if (status == ERRO_SALDO_INSUFICIENTE)
        printf("Saque de R$ %.2f não permitido: saldo insuficiente.\n\n", valor / 100.0);
         extrato_imprimir();
    // 3. Execução até 100 transações (gera aviso e encerra)
    printf("Teste 3: Execução até 100 transações\n");
    for (int i = 0; i < 100; i++) {
        status = depositar(100); // R$1 por transação
        if (status == ERRO_CAPACIDADE_LOG) {
            printf("[ALERTA] Capacidade de registros atingida.\n");
            break;
        }
    }

    printf("\nExtrato após testes automáticos:\n");
    extrato_imprimir();

    printf("=== FIM DOS TESTES AUTOMATICOS ===\n\n");
}





int main() {
    conta_init();
    int opcao;
    int status = OK;
    rodar_testes_automaticos();
    conta_init();//zera tudo


    while (1) {

        printf("\n--- VOIDBANK ---\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Aplicar na poupanca\n");
        printf("4. Resgatar da poupanca\n");
        printf("5. Consultar saldo conta corrente\n");
        printf("6. Consultar saldo poupanca\n");
        printf("7. Extrato\n");
        printf("8. Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        switch (opcao) {

            case 1: {
                double valor_double;
                printf("Valor para depositar: ");
                scanf("%lf", &valor_double);

                long long valor_centavos = (long long)(valor_double * 100);

                status = depositar(valor_centavos);

                if (status == OK)
                    printf("Deposito realizado com sucesso.\n");
                else if (status == ERRO_VALOR_INVALIDO)
                    printf("Erro: valor invalido.\n");
                else
                      printf("Erro: capacidade máxima de registros atingida.\n");
                break;
            }

            case 2: {
                double valor_double;
                printf("Valor para sacar: ");
                scanf("%lf", &valor_double);

                long long valor_centavos = (long long)(valor_double * 100);

                status = sacar(valor_centavos);

                if (status == OK)
                    printf("Saque realizado com sucesso.\n");
                else if (status == ERRO_VALOR_INVALIDO)
                    printf("Erro: valor invalido.\n");
                else if (status == ERRO_SALDO_INSUFICIENTE)
                    printf("Erro: saldo insuficiente.\n");
                else
                      printf("Erro: capacidade máxima de registros atingida.\n");
                break;
            }

            case 3: {
                double valor_double;
                printf("Valor para aplicar: ");
                scanf("%lf", &valor_double);
                long long valor_centavos = (long long)(valor_double * 100);
                status = aplicar_poupanca(valor_centavos);
                if (status == OK)
                    printf("Aplicacao realizada com sucesso.\n");
                else if (status == ERRO_VALOR_INVALIDO)
                    printf("Erro: valor invalido.\n");
                else if (status == ERRO_SALDO_INSUFICIENTE)
                    printf("Erro: saldo insuficiente.\n");
                else
                       printf("Erro: capacidade máxima de registros atingida.\n");
                break;
            }

           case 4: {
            double valor_double;
            printf("Valor para resgatar: ");
            scanf("%lf", &valor_double);

            long long valor_centavos = (long long)(valor_double * 100);

            status = resgatar_poupanca(valor_centavos);

            if (status == OK)
            printf("Resgate realizado com sucesso.\n");
            else if (status == ERRO_VALOR_INVALIDO)
            printf("Erro: valor invalido.\n");
            else if (status == ERRO_SALDO_INSUFICIENTE)
            printf("Erro: saldo insuficiente na poupanca.\n");
            else
            printf("Erro: capacidade máxima de registros atingida.\n");
            break;
           }

            case 5: {
            long long s = saldo_corrente();  
            printf("Saldo da conta corrente: %.2f\n", s / 100.0);
            break;
            }

           case 6: {
            long long s = saldo_poupanca();  
            printf("Saldo da poupanca: %.2f\n", s / 100.0);
            break;
            }

            case 7:
            extrato_imprimir();
            break;

            case 8:
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opcao invalida.\n");
                break;
        }

        if (status == ERRO_CAPACIDADE_LOG) {
            printf("\n[ALERTA] Capacidade de registros atingida (100 transacoes).\n");
            printf("O servico do VoidBank saira do ar agora.\n");
            return 0;
        }
    }

    return 0;
}
