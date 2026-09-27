#include <stdio.h>
#include <string.h>
#include <time.h>
#include "conta.h"


static Conta conta;
//gerar data/hora no formato "YYYY-MM-DD HH:MM:SS"
    static void gerar_quando(char buf[20]) {
    time_t agora = time(NULL);
    struct tm *info = localtime(&agora);
    strftime(buf, 20, "%Y-%m-%d %H:%M:%S", info);
    }

    static int registrar_transacao(TipoTransacao tipo, long long valor) {

    if (conta.nlog >= MAX_TRANS) {
        return ERRO_CAPACIDADE_LOG;
    }

    int i = conta.nlog;

    conta.log[i].tipo = tipo;
    conta.log[i].valor = valor;

    conta.log[i].saldo_corrente_apos = conta.saldo_corrente;
    conta.log[i].saldo_poupanca_apos = conta.saldo_poupanca;

    gerar_quando(conta.log[i].quando);
    
    conta.nlog++;

    return OK;
    }

    void conta_init(void) {
    conta.saldo_corrente = 0;
    conta.saldo_poupanca = 0;
    conta.nlog = 0;
}

    int depositar(long long valor) {
    if (valor <= 0)
        return ERRO_VALOR_INVALIDO;

    if (conta.nlog >= MAX_TRANS)
        return ERRO_CAPACIDADE_LOG;

    conta.saldo_corrente += valor;

    registrar_transacao(DEP, valor);

    return OK;
    } 
    int sacar(long long valor) {
    if (valor <= 0)
        return ERRO_VALOR_INVALIDO;

    if (valor > conta.saldo_corrente)
        return ERRO_SALDO_INSUFICIENTE;

    if (conta.nlog >= MAX_TRANS)
        return ERRO_CAPACIDADE_LOG;

    conta.saldo_corrente -= valor;

    registrar_transacao(SAQ, valor);

    return OK;
    }


    int aplicar_poupanca(long long valor) {
    if (valor <= 0)
        return ERRO_VALOR_INVALIDO;

    if (valor > conta.saldo_corrente)
        return ERRO_SALDO_INSUFICIENTE;

    if (conta.nlog >= MAX_TRANS)
        return ERRO_CAPACIDADE_LOG;

    conta.saldo_corrente -= valor;
    conta.saldo_poupanca += valor;

    registrar_transacao(APLI, valor);

    return OK;
    }

    int resgatar_poupanca(long long valor) {
    if (valor <= 0)
        return ERRO_VALOR_INVALIDO;

    if (valor > conta.saldo_poupanca)
        return ERRO_SALDO_INSUFICIENTE;

    if (conta.nlog >= MAX_TRANS)
        return ERRO_CAPACIDADE_LOG;

    conta.saldo_poupanca -= valor;
    conta.saldo_corrente += valor;

    registrar_transacao(RESG, valor);

    return OK;
    }

    long long saldo_corrente(void) {
    return conta.saldo_corrente;
    }
    
    long long saldo_poupanca(void){
	return conta.saldo_poupanca;
    }


void extrato_imprimir(void) {
    printf("\n===== EXTRATO VOIDBANK =====\n\n");

    if (conta.nlog == 0) {
        printf("Nenhuma transacao realizada.\n");
        return;
    }

    for (int i = 0; i < conta.nlog; i++) {
        Transacao t = conta.log[i];

        // Nome textual do tipo
        char tipo_txt[10];
        if (t.tipo == DEP)  strcpy(tipo_txt, "DEP");
        else if (t.tipo == SAQ)  strcpy(tipo_txt, "SAQ");
        else if (t.tipo == APLI) strcpy(tipo_txt, "APLI");
        else if (t.tipo == RESG) strcpy(tipo_txt, "RESG");

        printf("[%s] Valor: %.2f | Data/Hora: %s\n",
               tipo_txt,
               t.valor / 100.0,   // converte centavos → reais
               t.quando);

        printf("   Saldo Corrente Após: %.2f\n", t.saldo_corrente_apos / 100.0);
        printf("   Saldo Poupança Após: %.2f\n\n", t.saldo_poupanca_apos / 100.0);
    }

    printf("===== Fim do Extrato =====\n");
}
